/*

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/

//--------------------------------------------RECURSION------------------------------------------------

class Solution {
    private:
    int solve(int i,int j,string &word1, string &word2)
    {
        if(i<0)
            return j+1;
        
        if(j<0)
            return i+1;
        
        if(word1[i] == word2[j])
            return solve(i-1,j-1,word1,word2);
        
        int op1 = 1+solve(i-1,j,word1,word2);//delete
        int op2 = 1+solve(i,j-1,word1,word2);//insert
        int op3 = 1+solve(i-1,j-1,word1,word2);//replace
        
        return min(op1,min(op2,op3));
    }
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size(),m = word2.size();
        return solve(n-1,m-1,word1,word2);
    }
};

//--------------------------------------------MEMOIZATION------------------------------------------------

class Solution {
    private:
    int solve(int i,int j,string &word1, string &word2,vector<vector<int>> &dp)
    {
        if(i<0)
            return j+1;
        
        if(j<0)
            return i+1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(word1[i] == word2[j])
            return solve(i-1,j-1,word1,word2,dp);
        
        int op1 = 1+solve(i-1,j,word1,word2,dp);//delete
        int op2 = 1+solve(i,j-1,word1,word2,dp);//insert
        int op3 = 1+solve(i-1,j-1,word1,word2,dp);//replace
        
        return dp[i][j]=min(op1,min(op2,op3));
    }
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size(),m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,word1,word2,dp);
        
    }
};

//--------------------------------------------TABULATION------------------------------------------------

class Solution
{
    
    public:
        int minDistance(string word1, string word2)
        {

            int n = word1.size(), m = word2.size();
            vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));
 
            for (int j = 0; j <= m; j++)
                dp[0][j] = j;

            for (int i = 0; i <= n; i++)
                dp[i][0] = i;

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (word1[i - 1] == word2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];

                    else
                    {
                        int op1 = 1 + dp[i - 1][j];	//delete
                        int op2 = 1 + dp[i][j - 1];	//insert
                        int op3 = 1 + dp[i - 1][j - 1];	//replace

                        dp[i][j] = min(op1, min(op2, op3));
                    }
                }
            }

            return dp[n][m];
        }
};

//--------------------------------------------SPACE OPTIMISED------------------------------------------------


class Solution
{
    
    public:
        int minDistance(string word1, string word2)
        {

            int n = word1.size(), m = word2.size();
            vector<int> prev(m + 1, 0),curr(m+1,0);
 
            for (int j = 0; j <= m; j++)
                prev[j] = j;


            for (int i = 1; i <= n; i++)
            {
                curr[0] = i;
                for (int j = 1; j <= m; j++)
                {
                    if (word1[i - 1] == word2[j - 1])
                        curr[j] = prev[j - 1];

                    else
                    {
                        int op1 = 1 + prev[j];	//delete
                        int op2 = 1 + curr[j - 1];	//insert
                        int op3 = 1 + prev[j - 1];	//replace

                        curr[j] = min(op1, min(op2, op3));
                    }
                }
                prev = curr;
            }

            return prev[m];
        }
};