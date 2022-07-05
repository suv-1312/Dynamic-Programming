/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

//--------------------------------------------RECURSION------------------------------------------------

class Solution {
    private:
    
    int LIS(int idx, int prev_idx,vector<int>& nums)
    {
        if(idx == nums.size())
            return 0;
        
        int len = LIS(idx+1,prev_idx,nums);
        
        if(prev_idx == -1 || nums[idx] > nums[prev_idx])
            len = max(len,1+LIS(idx+1,idx,nums,));
        
        return len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        return LIS(0,-1,nums);
    }
};

//--------------------------------------------MEMOIZATION------------------------------------------------

class Solution {
    private:
    
    int LIS(int idx, int prev_idx,vector<int>& nums,vector<vector<int>> &dp)
    {
        if(idx == nums.size())
            return 0;
        
        if(dp[idx][prev_idx+1] != -1)
            return dp[idx][prev_idx+1];
        
        int len = LIS(idx+1,prev_idx,nums,dp);
        
        if(prev_idx == -1 || nums[idx] > nums[prev_idx])
            len = max(len,1+LIS(idx+1,idx,nums,dp));
        
        return dp[idx][prev_idx+1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return LIS(0,-1,nums,dp);
    }
};

//--------------------------------------------TABULATION------------------------------------------------


class Solution
{
    public:
        int lengthOfLIS(vector<int> &nums)
        {

            int n = nums.size();
            vector<vector < int>> dp(n+1, vector<int> (n + 1, 0));

            for (int idx = n - 1; idx >= 0; idx--)
            {
                for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
                {
                    int len = dp[idx + 1][prev_idx+1];

                    if (prev_idx == -1 || nums[idx] > nums[prev_idx]) 
                        len = max(len, 1 + dp[idx + 1][idx + 1]);

                    dp[idx][prev_idx + 1] = len;
                }
            }
            return dp[0][0];
        }
};

//--------------------------------------------SPACE OPTIMISED------------------------------------------------

class Solution
{
    public:
        int lengthOfLIS(vector<int> &nums)
        {

            int n = nums.size();
            vector<int> next(n + 1, 0),curr(n+1);

            for (int idx = n - 1; idx >= 0; idx--)
            {
                for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
                {
                    int len = next[prev_idx+1];

                    if (prev_idx == -1 || nums[idx] > nums[prev_idx]) 
                        len = max(len, 1 + next[idx + 1]);

                    curr[prev_idx + 1] = len;
                }
                next = curr;
            }
            return next[0];
        }
};