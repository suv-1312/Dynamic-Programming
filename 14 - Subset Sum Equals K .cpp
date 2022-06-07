/*

Problem Statement
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.

Sample Input 1:
2
4 5
4 3 2 1
5 4
2 5 1 6 7

Sample Output 1:
true
false

Explanation For Sample Input 1:
In example 1, ‘ARR’ is {4,3,2,1} and ‘K’ = 5. There exist 2 subsets with sum = 5. These are {4,1} and {3,2}. Hence, return true.
In example 2, ‘ARR’ is {2,5,1,6,7} and ‘K’ = 4. There are no subsets with sum = 4. Hence, return false.

Sample Input 2:
2
4 4
6 1 2 1
5 6
1 7 2 9 10

Sample Output 2:
true
false

Explanation For Sample Input 2:
In example 1, ‘ARR’ is {6,1,2,1} and ‘K’ = 4. There exist 1 subset with sum = 4. That is {1,2,1}. Hence, return true.
In example 2, ‘ARR’ is {1,7,2,9,10} and ‘K’ = 6. There are no subsets with sum = 6. Hence, return false.

*/


//-------------------------------------RECURSION--------------------------------------------


bool fun(int idx,int target,vector<int> &arr)
{
    if(target == 0)
        return true;
    
    if(idx == 0)
        return (arr[0] == target);
    
    bool notPick = fun(idx-1,target,arr);
    
    bool pick = false;
    if(arr[idx]<=target)
        pick = fun(idx-1,target- arr[idx],arr);
    
    return pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    
    return fun(n-1,k,arr);
}

//-------------------------------------MEMOIZATION--------------------------------------------

bool fun(vector<vector<int>> &dp,int idx,int target,vector<int> &arr)
{
    if(target == 0)
        return true;
    
    if(idx == 0)
        return (arr[0] == target);
    
    if(dp[idx][target]!=-1)
        return dp[idx][target];
    bool notPick = fun(dp,idx-1,target,arr);
    
    bool pick = false;
    if(arr[idx]<=target)
        pick = fun(dp,idx-1,target- arr[idx],arr);
    
    return dp[idx][target] = pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    
    vector<vector<int>> dp(1e3+1,vector<int>(1e3+1,-1));
    return fun(dp,n-1,k,arr);
}

//-------------------------------------TABULATION---------------------------------------------

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i = 0 ; i<n ; i++)
    {
        dp[i][0] = true;
    }
    
    dp[0][arr[0]] = true;
    
    for(int idx = 1 ; idx<n;idx++)
    {
        for(int target = 1 ; target<=k ;target++)
        {
            bool notPick = dp[idx-1][target];
    
            bool pick = false;
            if(arr[idx]<=target)
                pick = dp[idx-1][target- arr[idx]];
            
              dp[idx][target] = pick || notPick;
        }
    }
    return dp[n-1][k];
}

//-------------------------------------SPACE OPTIMISED----------------------------------------

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    
    vector<bool> prev(k+1,0),curr(k+1,0);
    
    prev[0] = curr[0] = true;
    
    if(arr[0]<=k)
       prev[arr[0]] = true;
    
    for(int idx = 1 ; idx<n;idx++)
    {
        for(int target = 1 ; target<=k ;target++)
        {
            bool notPick = prev[target];
    
            bool pick = false;
            if(arr[idx]<=target)
                pick = prev[target- arr[idx]];
            
              curr[target] = pick || notPick;
        }
        prev = curr;
    }
    return prev[k];
}