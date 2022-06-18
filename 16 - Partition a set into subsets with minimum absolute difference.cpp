/*

Problem Statement
You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.
Note:
1. Each element of the array should belong to exactly one of the subset.

2. Subsets need not be contiguous always. For example, for the array : {1,2,3}, some of the possible divisions are a) {1,2} and {3}  b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset. 
Input Format:
The first line of input contains the integer T, denoting the number of test cases.

The first line of each test case contains an integer N, denoting the size of the array.

The second and the last line of each test case contains N space-separated integers denoting the array elements.
Output Format:
For each test case, return the minimum possible absolute difference in a separate line. 
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10^3
0 <= ARR[i] <= 10^3
0 <= SUM <= 10^4, 

where SUM denotes the sum of all elements in the array for a given test case.

Time Limit: 1sec
Sample Input 1:
1
4
1 2 3 4
Sample Output 1:
0
Explanation For Sample Input 1:
We can partition the given array into {2,3} and {1,4}, as this will give us the minimum possible absolute difference i.e (5-5=0) in this case.
Sample Input 2:
1
3
8 6 5
Sample Output 2:
3
Explanation For Sample Input 2:
We can partition the given array into {8} and {6,5}, as this will give us the minimum possible absolute difference i.e (11-8=3) in this case

*/

//-------------------------------TABULATION----------------------------------------------------------------------------------------------------------


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int sum =0;
    for(auto it : arr)
        sum+=it;
    
    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
    
    for(int i = 0 ; i<n ; i++)
    {
        dp[i][0] = true;
    }
    
    dp[0][arr[0]] = true;
    
    for(int idx = 1 ; idx<n;idx++)
    {
        for(int target = 1 ; target<=sum ;target++)
        {
            bool notPick = dp[idx-1][target];
    
            bool pick = false;
            if(arr[idx]<=target)
                pick = dp[idx-1][target- arr[idx]];
            
              dp[idx][target] = pick || notPick;
        }
    }
    
    int mini = 1e9;
    for(int i =0 ; i<=sum/2 ;i++)
    {
        if(dp[n-1][i])
        {
        int subset1 = i;
        int subset2 = sum - i;
        mini = min(mini,abs(subset1-subset2));
        }
    }
    return mini;
}
