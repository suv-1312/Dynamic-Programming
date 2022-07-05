/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

//--------------------------------------------RECURSION------------------------------------------------

class Solution
{
private:
	int fun(int idx, int buy, int limit, int n, vector<int> &prices)
	{
		if (limit == 0)
			return 0;

		if (idx == n)
			return 0;

		int profit = 0;

		if (buy)
		{
			int take = -prices[idx] + fun(idx + 1, 0, limit, n, prices);

			int notTake = fun(idx + 1, 1, limit, n, prices);

			profit = max(take, notTake);
		}
		else
		{
			int sell = prices[idx] + fun(idx + 1, 1, limit - 1, n, prices);
			int notSell = fun(idx + 1, 0, limit, n, prices);

			profit = max(sell, notSell);
		}

		return profit;
	}
public:
	int maxProfit(vector<int> &prices)
	{
		int n = prices.size();

		return fun(0, 1, 2, n, prices);
	}
};

//--------------------------------------------MEMOIZATION------------------------------------------------

class Solution
{
private:
	int fun(int idx, int buy, int limit, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
	{
		if (limit == 0 || idx == n)
			return 0;

		if (dp[idx][buy][limit] != -1)
			return dp[idx][buy][limit];

		int profit = 0;

		if (buy)
		{
			int take = -prices[idx] + fun(idx + 1, 0, limit, n, prices, dp);

			int notTake = fun(idx + 1, 1, limit, n, prices, dp);

			profit = max(take, notTake);
		}
		else
		{
			int sell = prices[idx] + fun(idx + 1, 1, limit - 1, n, prices, dp);
			int notSell = fun(idx + 1, 0, limit, n, prices, dp);

			profit = max(sell, notSell);
		}

		return dp[idx][buy][limit] = profit;
	}
public:
	int maxProfit(vector<int> &prices)
	{
		int n = prices.size();
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
		return fun(0, 1, 2, n, prices, dp);
	}
};

//--------------------------------------------TABULATION------------------------------------------------

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int n = prices.size();
		vector<vector<vector< int>>> dp(n + 1, vector<vector < int>> (2, vector<int> (3, 0)));

		for (int idx = n - 1; idx >= 0; idx--)
		{
			for (int buy = 0; buy <= 1; buy++)
			{
				for (int limit = 1; limit <= 2; limit++)
				{
					int profit = 0;

					if (buy)
					{
						int take = -prices[idx] + dp[idx + 1][0][limit];

						int notTake = dp[idx + 1][1][limit];

						profit = max(take, notTake);
					}
					else
					{
						int sell = prices[idx] + dp[idx + 1][1][limit - 1];
						int notSell = dp[idx + 1][0][limit];

						profit = max(sell, notSell);
					}

					dp[idx][buy][limit] = profit;
				}
			}
		}

		return dp[0][1][2];
	}
};

//--------------------------------------------SPACE OPTIMISED------------------------------------------------

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int n = prices.size();
		vector<vector < int>> next(2, vector<int> (3, 0));
		vector<vector < int>> curr(2, vector<int> (3, 0));

		for (int idx = n - 1; idx >= 0; idx--)
		{
			for (int buy = 0; buy <= 1; buy++)
			{
				for (int limit = 1; limit <= 2; limit++)
				{
					int profit = 0;

					if (buy == 1)
					{
						int take = -prices[idx] + next[0][limit];

						int notTake = next[1][limit];

						profit = max(take, notTake);
					}
					else
					{
						int sell = prices[idx] + next[1][limit - 1];
						int notSell = next[0][limit];

						profit = max(sell, notSell);
					}

					curr[buy][limit] = profit;
				}
			}
			next = curr;
		}

		return next[1][2];
	}
};