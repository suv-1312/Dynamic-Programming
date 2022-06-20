/*

Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag

*/

//--------------------------------------------RECURSION------------------------------------------------

//--------------------------------------------MEMOIZATION------------------------------------------------


class Solution {
    private:
    int fun(string s,string t,int i ,int j,vector<vector<int>> &dp)
    {
         if(j == 0)
             return 1;
        
         if(i == 0)
             return 0;
        
         if(dp[i][j]!=-1)
             return dp[i][j];
        
         if(s[i - 1] == t[j - 1])
         {
             return dp[i][j] =  fun(s,t,i-1,j-1,dp) + fun(s,t,i-1,j,dp);
         }
        else
            return dp[i][j] = fun(s,t,i-1,j,dp);
    }
public:
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(s,t,n,m,dp);
        
    }
};

//--------------------------------------------TABULATION------------------------------------------------


class Solution
{
    public:
        int numDistinct(string s, string t)
        {

            int n = s.size();
            int m = t.size();

            vector<vector < double>> dp(n + 1, vector<double> (m + 1, 0));

            for (int i = 0; i <= n; i++)
            {
                dp[i][0] = 1;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (s[i - 1] == t[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    }
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
            return (int)dp[n][m];
        }
};


//--------------------------------------------SPACE OPTIMISED------------------------------------------------
