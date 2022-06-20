/*
Problem Statement
You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with weight capacity ‘W’. You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.
For Example
Let us say we have 'N' = 3 items and a knapsack of capacity 'W' =  10
'PROFIT' = { 5, 11, 13 }
'WEIGHT' = { 2, 4, 6 }

We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 i.e ‘27’. Therefore maximum profit = 27.
Input Format
The first line contains a single integer ‘T’ denoting the number of test cases.

The first line of each test contains two integers ‘N’ - number of elements in the array and ‘W’ - Capacity of the knapsack.

The second line of each test case contains profiti - profit of the item at the ‘i-th’ index.

The third line of each test case contains weighti - weight of the item at the ‘i-th’ index
Output Format
For each test case, return an integer denoting the maximum profit that can be obtained by filling the knapsack.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints
1 <= T <= 50
1 <= N <= 10^3
1 <= W <= 10^3
1 <= PROFIT[ i ] , WEIGHT[ i ] <= 10^8

Time Limit: 1sec
Sample Input 1
2
3 15
7 2 4
5 10 20
2 3
6 12
4 17
Sample Output 1
21
0
Explanation Of Sample Input 1
Test Case 1:  The given knapsack capacity is 15. We can fill the knapsack as [5, 5, 5] and [10, 5]. We will get a maximum profit of 21.

Test Case 2: We can clearly see that no item has wait less than knapsack capacity. Therefore we can not fill knapsack with any item.
Sample Input 2
2
4 7
3 4 5 1
4 1 2 3
3 9
1 2 3
1 3 5
Sample Output 2
28
9
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
