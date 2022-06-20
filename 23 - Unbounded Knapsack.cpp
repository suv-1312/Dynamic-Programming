/*

*/

//--------------------------------------------RECURSION------------------------------------------------

int fun(int idx, int wt, vector<int> &profit, vector<int> &weight)
{
	if (idx == 0)
	{
		return (int)(wt / weight[0]) * profit[0];
	}

	int notPick = fun(idx - 1, wt, profit, weight);
	int pick = 0;
	if (weight[idx] <= wt)
		pick = profit[idx] + fun(idx, wt - weight[idx], profit, weight);

	return max(pick, notPick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	// Write Your Code Here.

	return fun(n - 1, w, profit, weight);
}


//--------------------------------------------MEMOIZATION------------------------------------------------

int fun(int idx, int wt, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
	if (idx == 0)
	{
		return (int)(wt / weight[0]) * profit[0];
	}

	if (dp[idx][wt] != -1)
		return dp[idx][wt];

	int notPick = fun(idx - 1, wt, profit, weight, dp);
	int pick = 0;
	if (weight[idx] <= wt)
		pick = profit[idx] + fun(idx, wt - weight[idx], profit, weight, dp);

	return dp[idx][wt] = max(pick, notPick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	// Write Your Code Here.

	vector<vector<int>> dp(n, vector<int>(w + 1, -1));
	return fun(n - 1, w, profit, weight, dp);
}


//--------------------------------------------TABULATION------------------------------------------------

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	// Write Your Code Here.

	vector<vector<int>> dp(n, vector<int>(w + 1, -1));
	for (int W = 0 ; W <= w ; W++)
		dp[0][W] = (int)(W / weight[0]) * profit[0];

	for (int idx = 1 ; idx < n ; idx++)
	{
		for (int W = 0 ; W <= w ; W++)
		{
			int notPick = dp[idx - 1][W];
			int pick = 0;

			if (weight[idx] <= W)
				pick = profit[idx] + dp[idx][W - weight[idx]];

			dp[idx][W] = max(pick, notPick);
		}
	}
	return dp[n - 1][w];
}


//--------------------------------------------SPACE OPTIMISED------------------------------------------------


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	// Write Your Code Here.

	vector<int> prev(w + 1, 0), curr(w + 1, 0);
	for (int W = 0 ; W <= w ; W++)
		prev[W] = (int)(W / weight[0]) * profit[0];

	for (int idx = 1 ; idx < n ; idx++)
	{
		for (int W = 0 ; W <= w ; W++)
		{
			int notPick = prev[W];
			int pick = 0;

			if (weight[idx] <= W)
				pick = profit[idx] + curr[W - weight[idx]];

			curr[W] = max(pick, notPick);
		}
		prev = curr;
	}
	return prev[w];
}
