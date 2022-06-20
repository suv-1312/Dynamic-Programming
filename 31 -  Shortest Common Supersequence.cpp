/*

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"

*/


class Solution
{
    private:
        int lcs(string str1, string str2, vector<vector < int>> &dp)
        {

            int n = str1.size();
            int m = str2.size();

            for (int idx1 = 0; idx1 <= n; idx1++)
            {
                dp[idx1][0] = 0;
            }

            for (int idx2 = 0; idx2 <= m; idx2++)
            {
                dp[0][idx2] = 0;
            }

            for (int idx1 = 1; idx1 <= n; idx1++)

            {
                for (int idx2 = 1; idx2 <= m; idx2++)
                {

                    if (str1[idx1 - 1] == str2[idx2 - 1])
                    {
                        dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                    }
                    else
                    {
                        int first = dp[idx1 - 1][idx2];
                        int second = dp[idx1][idx2 - 1];
                        dp[idx1][idx2] = max(first, second);
                    }
                }
            }
            return dp[n][m];
        }
    public:
        string shortestCommonSupersequence(string str1, string str2)
        {

            int n = str1.size();
            int m = str2.size();
            vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));

            int lcsLen = lcs(str1, str2, dp);

            int i = n, j = m;
            string ans = "";

            while (i > 0 && j > 0)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                   	//cout<<"Matching is added : "<<str2[j-1]<<endl;
                    ans += str1[i - 1];
                    i--;
                    j--;
                }
                else if (dp[i - 1][j] > dp[i][j - 1])
                {
                   	//cout<<"str1[i-1] is added : "<<str1[i-1]<<endl;
                    ans += str1[i - 1];
                    i--;
                }
                else
                {
                   	//cout<<"str2[j-1] is added : "<<str2[j-1]<<endl;
                    ans += str2[j - 1];
                    j--;
                }
            }

            while (i > 0)
            {
                ans += str1[i - 1];
                i--;
            }

            while (j > 0)
            {
                ans += str2[j - 1];
                j--;
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }
};
