/*
Problem Statement
There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi
There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K. 
Here, a cost of |h_i - h_j| is incurred, where j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone N.

Example 1:

Input:
5 3
10 30 40 50 20

Output:
30

Example 2:

Input:
10 4
40 10 20 70 80 10 20 70 80 60

Output:
40


*/




#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define MAX 10000000
using namespace std;

//-------------------------RECURSION----------------------------------

int frogJumpRec(int idx, vector<int> &heights, int k, vector<int> &dp)
{

  if (idx == 0)
    return 0;

  int ans = INT_MAX;

  for (int i = 1 ; i <= k; i++)
  {
    if (idx - i >= 0)
    {
      int temp = frogJumpRec(idx - i, heights, k, dp) + abs(heights[idx] - heights[idx - i]);
      ans = min(ans, temp);
    }
  }

  return ans;

}


//-------------------------MEMOIZATION----------------------------------


int frogJumpMemo(int idx, vector<int> &heights, int k, vector<int> &dp)
{

  if (idx == 0)
    return 0;

  if (dp[idx] != -1)
    return dp[idx];

  int ans = INT_MAX;

  for (int i = 1 ; i <= k; i++)
  {
    if (idx - i >= 0)
    {
      int temp = frogJumpMemo(idx - i, heights, k, dp) + abs(heights[idx] - heights[idx - i]);
      ans = min(ans, temp);
    }
  }

  return dp[idx] = ans;

}

//-------------------------TABULATION----------------------------------


int frogJumpTab(int n, vector<int> &heights, int k)
{
  vector<int> dp(n, -1);
  dp[0] = 0;

  for (int i = 1 ; i < n ; i++)
  {
    int ans = INT_MAX;
    for (int j = 1; j <= k ; j++)
    {
      if (i - j >= 0)
      {
        int temp = dp[i - j] + abs(heights[i] - heights[i - j]);
        ans = min(ans, temp);
      }
      dp[i] = ans;
    }
  }
  return dp[n - 1];
}

//----------------------------------------------------------------------------------------------


int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, k;
  cin >> n >> k;

  vector<int> heights(n);
  for (int i = 0; i < n ; i++)
  {
    cin >> heights[i];
  }

  cout << frogJumpTab(n, heights, k);


  return 0;
}
