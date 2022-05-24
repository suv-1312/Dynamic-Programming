/*

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

*/



//---------------------------------RECURSION--------------------------------------


class Solution {
    private:
    
    int countPaths(int i , int j , vector<vector<int>> &grid)
    {
        if(i >=0 && j>=0 && grid[i][j] == 1)
            return 0;
        
        if(i<0 || j<0)
            return 0;
        
        if(i == 0 && j == 0)
            return 1;
        
        
        int up = countPaths(i-1,j,grid);
        int left = countPaths(i,j-1,grid);
        
        return up+left;
            
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        return countPaths(m-1,n-1,grid); 
    }
};


//---------------------------------MEMOIZATION--------------------------------------

class Solution {
    private:
    
    int countPaths(int i , int j , vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(i >=0 && j>=0 && grid[i][j] == 1)
            return 0;
        
        if(i<0 || j<0)
            return 0;
        
        if(i == 0 && j == 0)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up = countPaths(i-1,j,grid,dp);
        int left = countPaths(i,j-1,grid,dp);
        
        return dp[i][j] = up+left;
            
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countPaths(m-1,n-1,grid,dp); 
    }
};


//---------------------------------TABULATION--------------------------------------


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i = 0; i< m ; i++)
        {
            for(int j= 0 ;j<n ; j++)
            {
                if(i == 0 && j == 0)
                {
                    if(grid[i][j] == 1)
                    dp[i][j] = 0;
                    
                    else
                        dp[i][j]= 1;
                }
                else if(i>=0 && j>=0)
                {
                    if(grid[i][j] == 1)
                        dp[i][j] = 0;
                    
                    else
                    {
                        int up = 0,left =0;
                        
                        if(i>0)
                            up = dp[i-1][j];
                        
                        if(j>0)
                            left = dp[i][j-1];
                        
                        dp[i][j] = up+left;
                    }
                }      
            }
        }

        return dp[m-1][n-1];
    }
};

//---------------------------------SPACE OPTIMIZED--------------------------------------

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> prev(n,0);
        
        for(int i = 0; i< m ; i++)
        {
            vector<int> curr(n,0);
            
            for(int j= 0 ;j<n ; j++)
            {
                if(grid[i][j] == 1)
                    curr[j] = 0;
                
                else if(i == 0 && j == 0)
                    curr[j]= 1;
        
                else
                {
                        int up = 0,left =0;
                        
                        if(i>0)
                            up = prev[j];
                        
                        if(j>0)
                            left = curr[j-1];
                        
                        curr[j] = up+left;                
                }     
            }
            prev = curr;
        }
        return prev[n-1];
    }
};