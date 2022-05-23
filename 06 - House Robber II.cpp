/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile
, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses 
were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob 
tonight without alerting the police.
 

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [1,2,3]
Output: 3

*/


class Solution {
    private:
    
     int help(vector<int>& nums) {
        
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
    
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> a,b;
        
        for(int i=0;i<n;i++)
        {
              if(i!=0)
                  a.push_back(nums[i]);
            
              if(i!=n-1)
                  b.push_back(nums[i]);
        }
        
        return max(help(a),help(b));
    }
};