/*

Problem Statement
A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack. There are 'N' items available in the store and the weight and value of each item is known to the thief. Considering the constraints of the maximum weight that a knapsack can carry, you have to find the maximum profit that a thief can generate by stealing items.
Note: The thief is not allowed to break the items.
For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with weight 6, 1 and 3. The total value of knapsack = 3 + 6 + 4 = 13.


Sample Input:
1 
4 5
1 2 4 5
5 4 8 6
Sample Output:
13
Explanation Of Sample Output 1
The most optimal way to fill the knapsack is to choose items with weight 4 and value 8, weight 1 and value 5.

The total value of the knapsack =  8 + 5 = 13.
Sample Input 2:
1
5 100
20 24 36 40 42
12 35 41 25 32
Sample Output 2:
101

*/

//-------------------------------------------RECURSION----------------------------------------------------------

int fun(vector<int> &values, vector<int> &weights, int idx, int w)
{
    if(idx == 0)
    {
        if(weights[0] <= w)
            return values[0]; 
        else
            return 0;
    }
    
    int notPick = fun(values,weights,idx-1,w);
    int pick = -1e9;
    if(weights[idx]<=w)
    {
        pick = values[idx] + fun(values,weights,idx-1,w-weights[idx]);
    }
    
    return max(pick,notPick);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    return fun(values,weights,n-1,w);
}


//-------------------------------------------MEMOIZATION----------------------------------------------------------


int fun(vector<int> &values, vector<int> &weights, int idx, int w,vector<vector<int>> & dp)
{
    if(idx == 0)
    {
        if(weights[0] <= w)
            return values[0]; 
        else
            return 0;
    }
    
    if(dp[idx][w]!=-1)
        return dp[idx][w];
    
    int notPick = fun(values,weights,idx-1,w,dp);
    int pick = -1e9;
    if(weights[idx]<=w)
    {
        pick = values[idx] + fun(values,weights,idx-1,w-weights[idx],dp);
    }
    
    return dp[idx][w] = max(pick,notPick);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return fun(values,weights,n-1,w,dp);
}


//-------------------------------------------TABULATION----------------------------------------------------------


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    
    for(int i = weights[0];i<=w;i++)
    {
            dp[0][i] = values[0];
    }
    
    for(int idx = 1 ; idx<n;idx++)
    {
        for(int W = 0 ; W<=w;W++)
        {
            
            int notPick = dp[idx-1][W];
            int pick = -1e9;
            if(weights[idx]<=W)
            {
                pick = values[idx] + dp[idx-1][W-weights[idx]];
            }
    
             dp[idx][W] = max(pick,notPick);
        }
    }
    return dp[n-1][w];
}


//-------------------------------------------SPACE OPTIMISED----------------------------------------------------------



int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<int> prev(w+1,0),curr(w+1,0);
   
    for(int i = weights[0];i<=w;i++)
    {
            prev[i] = values[0];
    }
    
    for(int idx = 1 ; idx<n;idx++)
    {
        for(int W = 0 ; W<=w;W++)
        {
            
            int notPick = prev[W];
            int pick = -1e9;
            if(weights[idx]<=W)
            {
                pick = values[idx] + prev[W-weights[idx]];
            }
    
             curr[W] = max(pick,notPick);
        }
        prev = curr;
    }
    return prev[w];
}