/*

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1

*/


//-----------------------------------------------------RECURSION------------------------------------------------

class Solution {
    private:
    int fun(vector<int>& coins, int amount,int idx)
    {
          if(amount == 0)
             return 1;
        
         if(idx < 0 )
         {
                 return 0;
         }
        
        int notPick= fun(coins,amount,idx-1);
        
        int pick = 0;
        
        if(coins[idx]<=amount)
            pick = fun(coins,amount - coins[idx],idx);
        
        return pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
     
        int n = coins.size();
        return fun(coins,amount,n-1);
    }
};

//-----------------------------------------------------MEMOIZATION------------------------------------------------

class Solution {
    private:
    int fun(vector<int>& coins, int amount,int idx,vector<vector<int>> &dp)
    {
          if(amount == 0)
             return 1;
        
         if(idx < 0 )
         {
                 return 0;
         }
        
         if(dp[idx][amount]!=-1)
             return dp[idx][amount];
        
        int notPick= fun(coins,amount,idx-1,dp);
        
        int pick = 0;
        
        if(coins[idx]<=amount)
            pick = fun(coins,amount - coins[idx],idx,dp);
        
        return dp[idx][amount] = pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
     
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return fun(coins,amount,n-1,dp);
    }
};

//-----------------------------------------------------TABULAION------------------------------------------------

class Solution {
    
public:
    int change(int amount, vector<int>& coins) {
     
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
        for(int idx = 0 ;idx<n ;idx++)
        {
            dp[idx][0] = 1;
        }
        
        for(int idx = 0 ; idx<n ;idx++)
        {
            for(int target = 1 ; target<=amount ; target++)
            {
                 
                int notPick = 0;
                if(idx >0)
                 notPick= dp[idx-1][target];
    
                int pick = 0;
        
                if(coins[idx]<=target)
                     pick = dp[idx][target - coins[idx]];
        
                 dp[idx][target] = pick+notPick;
            }
        }
        
        return dp[n-1][amount];
    }
};


//-----------------------------------------------------SPACE OPTIMISED------------------------------------------------