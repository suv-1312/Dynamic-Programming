/*

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

*/

//-----------------------------------------RECURSION---------------------------------------------

class Solution {
    private:
    
    int fun(int i ,int j, vector<vector<int>>& matrix)
    {
        if(j<0 || j >= matrix[0].size())
             return 1e8;
        
         if(i == 0)
             return matrix[0][j];
         
         int up = matrix[i][j] + fun(i-1,j,matrix);
         int ld = matrix[i][j] + fun(i-1,j-1,matrix);
         int rd = matrix[i][j] + fun(i-1,j+1,matrix);
        
         return min(up,min(ld,rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      
        int r = matrix.size();
        int c = matrix[0].size();
        int mini = 1e8;
        
        for(int j =0;j<c;j++)
        {
            mini = min(mini,fun(r-1,j,matrix));
        }
        return mini;
    }
};

//----------------------------------------MEMOIZATION---------------------------------------------

class Solution {
    private:
    
    int fun(vector<vector<int>> &dp,int i ,int j, vector<vector<int>>& matrix)
    {
        if(j<0 || j >= matrix[0].size())
             return 1e8;
        
         if(i == 0)
             return matrix[0][j];
        
         if(dp[i][j]!=-1)
             return dp[i][j];
         
         int up = matrix[i][j] + fun(dp,i-1,j,matrix);
         int ld = matrix[i][j] + fun(dp,i-1,j-1,matrix);
         int rd = matrix[i][j] + fun(dp,i-1,j+1,matrix);
        
         return dp[i][j] = min(up,min(ld,rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      
        int r = matrix.size();
        int c = matrix[0].size();
        int mini = 1e8;
        
        vector<vector<int>> dp(r,vector<int>(c,-1));
        for(int j =0;j<c;j++)
        {
            mini = min(mini,fun(dp,r-1,j,matrix));
        }
        return mini;
    }
};


//----------------------------------------TABULATION---------------------------------------------

class Solution {
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      
        int r = matrix.size();
        int c = matrix[0].size();
        int mini = 1e8;
        
        vector<vector<int>> dp(r,vector<int>(c,0));
        
        for(int j =0;j<c ;j++)
            dp[0][j] = matrix[0][j];
        
        for(int i =1;i<r;i++)
        {
           for(int j = 0 ; j<c ;j++)
           {
               int up = matrix[i][j] + dp[i-1][j];
               
               int ld = matrix[i][j];
               if(j-1>=0)
                   ld+=dp[i-1][j-1];
               else
                   ld+=1e8;
               
               int rd = matrix[i][j];
               if(j+1<c)
                   rd+=dp[i-1][j+1];
               else
                   rd+=1e8;
               
               dp[i][j] = min(up,min(ld,rd));
           }
            
        }
        
        for(int j = 0 ; j<c ;j++)
        {
            mini = min(mini,dp[r-1][j]);
        }
        
        return mini;
    }
};

//----------------------------------------SPACE OPTIMISED---------------------------------------------

class Solution {
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      
        int r = matrix.size();
        int c = matrix[0].size();
        int mini = 1e8;
        
        vector<int> prev(c,0),curr(c,0);
        
        for(int j =0;j<c ;j++)
            prev[j] = matrix[0][j];
        
        for(int i =1;i<r;i++)
        {
           for(int j = 0 ; j<c ;j++)
           {
               int up = matrix[i][j] + prev[j];
               
               int ld = matrix[i][j];
               if(j-1>=0)
                   ld+=prev[j-1];
               else
                   ld+=1e8;
               
               int rd = matrix[i][j];
               if(j+1<c)
                   rd+=prev[j+1];
               else
                   rd+=1e8;
               
               curr[j] = min(up,min(ld,rd));
           }
            prev = curr;
        }
        
        for(int j = 0 ; j<c ;j++)
        {
            mini = min(mini,prev[j]);
        }
        
        return mini;
    }
};