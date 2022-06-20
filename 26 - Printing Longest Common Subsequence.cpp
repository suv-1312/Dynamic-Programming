/*
Printing longest common subsequence:
*/

----------------------------------------------------------------------------
string printLcs(string s,string t,vector<vector < int>> &dp,int &n, int &m)
{
    string ans = "";
    int i = n, j = m;
    while(i>0 && j>0)
    {
        if(s[i-1] == t[j-1])
        {
            ans+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            i--;       
        }
        else
        {
            j--;                  
        }
         
    }
     reverse(ans.begin(),ans.end());
     return ans;
}

------------------------------------------------------------------------------

int lcs(string s, string t)
{
	//Write your code here
            int n = s.size();
            int m = t.size();
            vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));

            for (int idx1 = 0; idx1 <= n; idx1++)
            {
                dp[idx1][0] = 0;
            }

            for (int idx2 = 0; idx2 <= m; idx2++)
            {
                dp[0][idx2] = 0;
            }

            for (int idx1 = 1; idx1 <= n; idx1++)
            {
                for (int idx2 = 1; idx2 <= m; idx2++)
                {

                    if (s[idx1 - 1] == t[idx2 - 1])
                    {
                         dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                    }
                    else
                    {
                        int first = dp[idx1 - 1][idx2];
                        int second = dp[idx1][idx2 - 1];
                        dp[idx1][idx2] = max(first, second);
                    }
                }
            }
            
            cout<<printLcs(s,t,dp,n,m);
            return dp[n][m];
}