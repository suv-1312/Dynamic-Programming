/*

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

*/

//--------------------------------------------RECURSION------------------------------------------------

class Solution {
    int longestCommonSubsequence(string &a,string &b,int idx1,int idx2,vector<vector<int>> &dp)
    {
        if(idx1<0 || idx2<0)
            return 0;
        
        if(a[idx1] == b[idx2])
        {
            return 1+longestCommonSubsequence(a,b,idx1-1,idx2-1);
        }
        else
        {
            int first = longestCommonSubsequence(a,b,idx1-1,idx2);
            int second = longestCommonSubsequence(a,b,idx1,idx2-1);
            return max(first,second);
        }
    }
public:
    int longestPalindromeSubseq(string s) {
           
          int n = s.size();
          string s2 = s;
          reverse(s2.begin(),s2.end());
          return longestCommonSubsequence(s,s2,n-1,n-1);
    }
};


//--------------------------------------------MEMOIZATION------------------------------------------------


class Solution {
    int longestCommonSubsequence(string &a,string &b,int idx1,int idx2,vector<vector<int>> &dp)
    {
        if(idx1<0 || idx2<0)
            return 0;
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(a[idx1] == b[idx2])
        {
            return dp[idx1][idx2] =  1+longestCommonSubsequence(a,b,idx1-1,idx2-1,dp);
        }
        else
        {
            int first = longestCommonSubsequence(a,b,idx1-1,idx2,dp);
            int second = longestCommonSubsequence(a,b,idx1,idx2-1,dp);
            return dp[idx1][idx2] =  max(first,second);
        }
    }
public:
    int longestPalindromeSubseq(string s) {
           
          int n = s.size();
          string s2 = s;
          reverse(s2.begin(),s2.end());
          vector<vector<int>> dp(n,vector<int>(n,-1));
          return longestCommonSubsequence(s,s2,n-1,n-1,dp);
    }
};

//--------------------------------------------TABULATION------------------------------------------------

class Solution
{
    public:
        int longestPalindromeSubseq(string s)
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
};

//--------------------------------------------SPACE OPTIMISED------------------------------------------------
