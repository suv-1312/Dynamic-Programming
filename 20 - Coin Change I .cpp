/*

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0

*/


//--------------------------------------RECURSION-------------------------------------------------

class Solution {
    private:
    int fun(vector<int>& coins, int amount,int idx)
    {
        if(idx == 0)
        {
            if(amount % coins[idx] == 0)
                return amount/coins[idx];
            
            else 
                return 1e9;
        }
        
        int notPick = fun(coins,amount,idx-1);
        
        int pick = INT_MAX;
        
        if(amount >= coins[idx])
            pick = 1+ fun(coins,amount - coins[idx],idx);
        
        return min(pick,notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        int ans =  fun(coins,amount,n-1,dp);
        
        if(ans == 1e9)
            return -1;
        
        return ans;
    }
};


//--------------------------------------MEMOIZATION-------------------------------------------------

class Solution {
    private:
    int fun(vector<int>& coins, int amount,int idx,vector<vector<int>> & dp)
    {
        if(idx == 0)
        {
            if(amount % coins[idx] == 0)
                return amount/coins[idx];
            
            else 
                return 1e9;
        }
        
        if(dp[idx][amount] != -1)
            return dp[idx][amount];
        
        int notPick = fun(coins,amount,idx-1,dp);
        
        int pick = INT_MAX;
        
        if(amount >= coins[idx])
            pick = 1+ fun(coins,amount - coins[idx],idx,dp);
        
        return dp[idx][amount] =  min(pick,notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans =  fun(coins,amount,n-1,dp);
        
        if(ans == 1e9)
            return -1;
        
        return ans;
    }
};


//---------------------------------------TABULATION-------------------------------------------------


class Solution {
    
public:
    int coinChange(vector<int>& coins, int amount) {
        
        
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
        for(int t = 0 ; t<=amount ;t++)
        {
            if(t % coins[0] == 0)
                dp[0][t] = t/coins[0];
            else
                dp[0][t] = 1e9;
        }
        
        for(int idx = 1; idx<n ;idx++)
        {
            for(int t = 0 ; t<=amount ; t++)
            {  
                
                int notPick = dp[idx-1][t];
        
                int pick = 1e9;
        
                if(t >= coins[idx])
                 pick = 1+ dp[idx][t - coins[idx]];
        
                 dp[idx][t] =  min(pick,notPick);
                
            }
        }
        
        int ans =  dp[n-1][amount];
        
        if(ans == 1e9)
            return -1;
        else
            return ans;
    }
};

//---------------------------------------SPACE OPTIMIZED-------------------------------------------------


class Solution {
    
public:
    int coinChange(vector<int>& coins, int amount) {
        
        
        int n = coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);
        
        for(int t = 0 ; t<=amount ;t++)
        {
            if(t % coins[0] == 0)
                prev[t] = t/coins[0];
            else
                prev[t] = 1e9;
        }
        
        for(int idx = 1; idx<n ;idx++)
        {
            for(int t = 0 ; t<=amount ; t++)
            {  
                
                int notPick = prev[t];
        
                int pick = 1e9;
        
                if(t >= coins[idx])
                 pick = 1+ curr[t - coins[idx]];
        
                 curr[t] =  min(pick,notPick);
                
            }
            prev = curr;
        }
        
        int ans =  prev[amount];
        
        if(ans == 1e9)
            return -1;
        else
            return ans;
    }
};