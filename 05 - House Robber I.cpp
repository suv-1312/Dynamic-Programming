/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can
rob tonight without alerting the police.
 

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

*/


//-----------------------------------------RECURSION----------------------------------------

class Solution {
    private:
    int rob(vector<int> &nums,int idx)
    {
        if(idx == 0)
            return nums[idx];

        if(idx<0)
            return 0;
      
        int a = nums[idx] + rob(nums,idx-2);
        int b = 0+rob(nums,idx-1);
        
        return max(a,b);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return rob(nums,n-1);
    }
};


//-------------------------------------------MEMOIZATION------------------------------------


class Solution {
    private:
    int rob(vector<int> &nums,int idx,vector<int> &dp)
    {
        if(idx == 0)
            return nums[idx];

        if(idx<0)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int a = nums[idx] + rob(nums,idx-2,dp);
        int b = 0+rob(nums,idx-1,dp);
        
        return dp[idx] = max(a,b);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return rob(nums,n-1,dp);
    }
};

//-------------------------------------------TABULATION------------------------------------


class Solution {
   
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        
        dp[0] = nums[0];
        int neg = 0;
        
        for(int i = 1; i<n;i++)
        {
            
            int a = nums[i]; 
            if(i>1)
                a+=dp[i-2];
            
            int b = dp[i-1];
            
            dp[i] = max(a,b);
        }
        return dp[n-1];
    }
};


//-------------------------------------------SPACE OPTIMISED------------------------------------


class Solution {
   
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        
        for(int i = 1; i<n;i++)
        {
            
            int a = nums[i]; 
            if(i>1)
                a+=prev2;
            
            int b = prev1;
            
            int curr = max(a,b);
            
            prev2 = prev1;
            prev1 = curr;
            
        }
        return prev1;
    }
};