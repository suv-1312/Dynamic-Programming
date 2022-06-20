/*

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

*/

//--------------------------------------------RECURSION------------------------------------------------


class Solution {
    private:
    int lcs(string &a,string &b,int idx1,int idx2)
    {
         if(idx1<0 || idx2<0)
             return 0;
        
        if(a[idx1] == b[idx2])
        {
            return 1+lcs(a,b,idx1-1,idx2-1,dp);
        }
        else
        {
            int option1 = lcs(a,b,idx1-1,idx2);
            int option2 = lcs(a,b,idx1,idx2-1);
            return max(option1,option2);
        }
    }
    
    int lps(string s)
    {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return lcs(s,s2,n-1,n-1);
        
    }
        
public:
    int minInsertions(string s) {
        
        int len = s.size();
        return len - lps(s);
    }
};


//--------------------------------------------MEMOIZATION------------------------------------------------

class Solution {
    private:
    int lcs(string &a,string &b,int idx1,int idx2,vector<vector<int>> &dp)
    {
         if(idx1<0 || idx2<0)
             return 0;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        if(a[idx1] == b[idx2])
        {
            return 1+lcs(a,b,idx1-1,idx2-1,dp);
        }
        else
        {
            int option1 = lcs(a,b,idx1-1,idx2,dp);
            int option2 = lcs(a,b,idx1,idx2-1,dp);
            return dp[idx1][idx2] = max(option1,option2);
        }
    }
    
    int lps(string s)
    {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return lcs(s,s2,n-1,n-1,dp);
        
    }
        
public:
    int minInsertions(string s) {
        
        int len = s.size();
        return len - lps(s);
    }
};

//--------------------------------------------TABULATION------------------------------------------------


class Solution
{
    public:
        int longestPalindromeSubsequence(string s)
        {

            int n = s.size();
            string s2 = s;
            reverse(s2.begin(), s2.end());
            vector<vector < int>> dp(n + 1, vector<int> (n + 1, -1));

            for (int idx2 = 0; idx2 < n; idx2++)
                dp[0][idx2] = 0;

            for (int idx1 = 0; idx1 < n; idx1++)
                dp[idx1][0] = 0;

            for (int idx1 = 0; idx1 <= n; idx1++)
            {
                for (int idx2 = 0; idx2 <= n; idx2++)
                {
                    if (idx1 > 0 && idx2 > 0)
                    {
                        if (s[idx1 - 1] == s2[idx2 - 1])
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
            }

            return dp[n][n];
        }


     int minInsertions(string s) {
        
        int len = s.size();
        return len - lps(s);
    }
};


//--------------------------------------------SPACE OPTIMISED------------------------------------------------
