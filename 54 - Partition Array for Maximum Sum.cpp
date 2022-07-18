/*

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length

*/

//--------------------------------------------RECURSION------------------------------------------------

class Solution {
    private:
    
    int solve(vector<int>& arr, int k,int idx,int n)
    {
        if(idx == n)
            return 0;
        
        int len = 0;
        int maxi = INT_MIN;
        int ans = INT_MIN;
        for(int j = idx ; j<min(n,idx+k);j++)
        {
            len++;
            maxi = max(maxi,arr[j]);
            
            int sum = (len* maxi) + solve(arr,k,j+1,n);
            ans = max(sum,ans);
        }
        return  ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      
        int n = arr.size();
        return solve(arr,k,0,n);
    }
};

//--------------------------------------------MEMOIZATION------------------------------------------------

class Solution {
    private:
    
    int solve(vector<int>& arr, int k,int idx,int n,vector<int>& dp)
    {
        if(idx == n)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int len = 0;
        int maxi = INT_MIN;
        int ans = INT_MIN;
        for(int j = idx ; j<min(n,idx+k);j++)
        {
            len++;
            maxi = max(maxi,arr[j]);
            
            int sum = (len* maxi) + solve(arr,k,j+1,n,dp);
            ans = max(sum,ans);
        }
        return dp[idx] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(arr,k,0,n,dp);
    }
};

//--------------------------------------------TABULATION------------------------------------------------

class Solution
{

    public:
        int maxSumAfterPartitioning(vector<int> &arr, int k)
        {

            int n = arr.size();
            vector<int> dp(n + 1, 0);

            dp[n] = 0;

            for (int idx = n - 1; idx >= 0; idx--)
            {

                int len = 0;
                int maxi = INT_MIN;
                int ans = INT_MIN;
                for (int j = idx; j < min(n, idx + k); j++)
                {
                    len++;
                    maxi = max(maxi, arr[j]);

                    int sum = (len *maxi) + dp[j + 1];
                    ans = max(sum, ans);
                }
                dp[idx] = ans;
            }
            return dp[0];
        }
};


//--------------------------------------------SPACE OPTIMISED------------------------------------------------
