/*

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1

*/

//--------------------------------------------RECURSION------------------------------------------------

//--------------------------------------------MEMOIZATION------------------------------------------------

class Solution {
    private:
    
    int fun(vector<int> &num, int idx, int tar, vector<vector<int>> &dp)
    {
    if(idx == 0)
    {
        if(tar == 0 && num[0] == 0)
            return 2;
        if(tar == 0 || tar == num[0])
            return 1;
        return 0;
    }

    if (dp[idx][tar] != -1)
        return dp[idx][tar];

    int notPick = fun(num, idx - 1, tar, dp);

    int pick = 0;
    if (num[idx] <= tar)
        pick = fun(num, idx - 1, tar - num[idx], dp);

    return dp[idx][tar] = (pick + notPick);
}
    
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return fun(num, n - 1, tar, dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int total = 0;
    for(auto it : arr)
        total += it;
    
    if(total - d < 0 || (total - d) % 2)
        return 0;
    
    return findWays(arr,(total - d)/2);
}

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return countPartitions(nums.size(),target,nums);
        
    }
};

//--------------------------------------------TABULATION------------------------------------------------


//--------------------------------------------SPACE OPTIMISED------------------------------------------------
