/*

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

*/

//--------------------------------------------RECURSION------------------------------------------------

class Solution {
    private: 
    int fun(string text1, string text2,int idx1,int idx2)
    {
        if(idx1<0 || idx2<0)
            return 0;
        
        if(text1[idx1] == text2[idx2])
        {
            return 1 + fun(text1,text2,idx1-1,idx2-1);
        }
        else
        {
            int first = fun(text1,text2,idx1-1,idx2);
            int second = fun(text1,text2,idx1,idx2-1);
            return max(first,second);
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        return fun(text1,text2,n-1,m-1);
    }
};

//--------------------------------------------MEMOIZATION------------------------------------------------

--------------
INDEX SHIFTING
--------------


class Solution {
    private: 
    int fun(string &text1, string &text2,int idx1,int idx2,vector<vector<int>> &dp)
    {
        if(idx1 == 0 || idx2 == 0)
            return 0;
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(text1[idx1 - 1] == text2[idx2 - 1])
        {
            return dp[idx1][idx2] = 1 + fun(text1,text2,idx1-1,idx2-1,dp);
        }
        else
        {
            int first = fun(text1,text2,idx1-1,idx2,dp);
            int second = fun(text1,text2,idx1,idx2-1,dp);
            return dp[idx1][idx2] = max(first,second);
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(text1,text2,n,m,dp);
    }
};

//--------------------------------------------TABULATION------------------------------------------------

class Solution
{
    public:
        int longestCommonSubsequence(string text1, string text2)
        {

            int n = text1.size();
            int m = text2.size();
            vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));

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

                    if (text1[idx1 - 1] == text2[idx2 - 1])
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
};

//--------------------------------------------SPACE OPTIMISED------------------------------------------------


class Solution
{
    public:
        int longestCommonSubsequence(string text1, string text2)
        {

            int n = text1.size();
            int m = text2.size();
            vector<int> prev(m + 1,0),curr(m+1,0);

            for (int idx1 = 0; idx1 <= n; idx1++)
            {
                prev[0] = 0;
            }


            for (int idx1 = 1; idx1 <= n; idx1++)
            {
                for (int idx2 = 1; idx2 <= m; idx2++)
                {

                    if (text1[idx1 - 1] == text2[idx2 - 1])
                    {
                         curr[idx2] = 1 + prev[idx2 - 1];
                    }
                    else
                    {
                        int first = prev[idx2];
                        int second = curr[idx2 - 1];
                        curr[idx2] = max(first, second);
                    }
                }
                prev = curr;
            }

            return prev[m];
        }
};