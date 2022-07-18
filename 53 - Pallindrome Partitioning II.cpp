/*

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1

*/

//--------------------------------------------RECURSION------------------------------------------------

class Solution {
    bool isPal(string &s,int i ,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s,int idx)
    {
        
        if(idx == s.size())
            return 0;
        
        int mini = INT_MAX;
        for(int j = idx ; j<s.size() ;j++)
        {
            if(isPal(s,idx,j))
            {
                int cuts = 1+solve(s,j+1);
                mini = min(mini,cuts);
            }
            
        }
        return mini;
    }
public:
    int minCut(string s) {
        
        return solve(s,0) - 1;
    }
};

//--------------------------------------------MEMOIZATION------------------------------------------------

class Solution {
    bool isPal(string &s,int i ,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s,int idx,vector<int> &dp)
    {
        
        if(idx == s.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int mini = INT_MAX;
        for(int j = idx ; j<s.size() ;j++)
        {
            if(isPal(s,idx,j))
            {
                int cuts = 1+solve(s,j+1,dp);
                mini = min(mini,cuts);
            }
            
        }
        return dp[idx] = mini;
    }
public:
    int minCut(string s) {
        
        vector<int> dp(s.size(),-1)       ; 
        return solve(s,0,dp) - 1;
    }
};

//--------------------------------------------TABULATION------------------------------------------------


class Solution
{
    bool isPal(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }
        return true;
    }
   public:
        int minCut(string s)
        {

            vector<int> dp(s.size()+1, 0);
            dp[s.size()] = 0;

            for (int idx = s.size() - 1; idx >= 0; idx--)
            {
                int mini = INT_MAX;
                for (int j = idx; j < s.size(); j++)
                {
                    if (isPal(s, idx, j))
                    {
                        int cuts = 1 + dp[j + 1];
                        mini = min(mini, cuts);
                    }
                }
                dp[idx] = mini;
            }

            return dp[0] - 1;
        }
};

//--------------------------------------------SPACE OPTIMISED------------------------------------------------
