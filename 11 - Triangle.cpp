/*

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10

*/

//--------------------------------RECURSION--------------------------------------

class Solution {
    
    private:
    int minimumTotal(int i,int j, int m ,int n,vector<vector<int>>& triangle)
    {
         if(i == m-1)
             return triangle[i][j];
        
         int down = triangle[i][j] + minimumTotal(i+1,j,m,n,triangle);
         int diagonal = triangle[i][j] + minimumTotal(i+1,j+1,m,n,triangle);
        
         return min(down,diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[0].size();
        return minimumTotal(0,0,m,n,triangle);
    }
};


//--------------------------------MEMOIZATION--------------------------------------


class Solution {
    
    private:
    int minimumTotal(int i,int j, int m ,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
         if(i == m-1)
             return triangle[i][j];
        
         if(dp[i][j]!=-1)
             return dp[i][j];
        
         int down = triangle[i][j] + minimumTotal(i+1,j,m,n,triangle,dp);
         int diagonal = triangle[i][j] + minimumTotal(i+1,j+1,m,n,triangle,dp);
        
         return dp[i][j] = min(down,diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[0].size();
        
        vector<vector<int>> dp(m,vector<int>(m,-1));
        
        return minimumTotal(0,0,m,n,triangle,dp);
    }
};

//--------------------------------TABULATION--------------------------------------

class Solution {
   
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[0].size();
        
        vector<vector<int>> dp(m,vector<int>(m,-1));
        
        for(int j = 0 ;j<m ;j++)
        {
            dp[m-1][j] = triangle[m-1][j];
        }
        
        for(int i = m-2 ;i>=0 ;i--)
        {
            for(int j = i; j>=0 ;j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(down,diagonal);
            }
        }
        
        return dp[0][0];
    }
};

//--------------------------------SPACE OPTIMISED--------------------------------------


class Solution {
   
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[0].size();
        
        vector<int> front(m,0),curr(m,0);
        
        for(int j = 0 ;j<m ;j++)
        {
            front[j] = triangle[m-1][j];
        }
        
        for(int i = m-2 ;i>=0 ;i--)
        {
            for(int j = i; j>=0 ;j--)
            {
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j+1];
                
                curr[j] = min(down,diagonal);
            }
            front = curr;
        }
        
        return front[0];
    }
};