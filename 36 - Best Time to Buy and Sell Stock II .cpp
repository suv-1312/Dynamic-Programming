/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0

*/

//--------------------------------------------RECURSION------------------------------------------------

class Solution {
private:
	int fun(int idx, int buy, int n, vector<int>& prices)
	{
		if (idx == n)
			return 0;

		int profit = 0;

		if (buy)
		{
			int take = -prices[idx] + fun(idx + 1, 0, n, prices);

			int notTake = fun(idx + 1, 1, n, prices);

			profit = max(take, notTake);
		}
		else
		{
			int sell = prices[idx] + fun(idx + 1, 1, n, prices);
			int notSell = fun(idx + 1, 0, n, prices);

			profit = max(sell, notSell);
		}

		return profit;
	}
public:
	int maxProfit(vector<int>& prices) {

		int n = prices.size();
		return fun(0, 1, n, prices);

	}
};

//--------------------------------------------MEMOIZATION------------------------------------------------

class Solution {
private:
	int fun(int idx, int buy, int n, vector<int>& prices, vector<vector<int>> &dp)
	{
		if (idx == n)
			return 0;

		if (dp[idx][buy] != -1)
			return dp[idx][buy];

		int profit = 0;

		if (buy == 1)
		{
			int take = -prices[idx] + fun(idx + 1, 0, n, prices, dp);

			int notTake = fun(idx + 1, 1, n, prices, dp);

			profit = max(take, notTake);
		}
		else
		{
			int sell = prices[idx] + fun(idx + 1, 1, n, prices, dp);
			int notSell = fun(idx + 1, 0, n, prices, dp);

			profit = max(sell, notSell);
		}

		return dp[idx][buy] = profit;
	}
public:
	int maxProfit(vector<int>& prices) {

		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, -1));
		return fun(0, 1, n, prices, dp);

	}
};

//--------------------------------------------TABULATION------------------------------------------------

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{

		int n = prices.size();
		vector<vector < int>> dp(n + 1, vector<int> (2, 0));

		dp[n][0] = dp[n][1] = 0;
		for (int idx = n - 1; idx >= 0; idx--)
		{
			for (int buy = 0; buy <= 1; buy++)
			{

				int profit = 0;

				if (buy)
				{
					int take = -prices[idx] + dp[idx + 1][0];

					int notTake = dp[idx + 1][1];

					profit = max(take, notTake);
				}
				else
				{
					int sell = prices[idx] + dp[idx + 1][1];
					int notSell = dp[idx + 1][0];

					profit = max(sell, notSell);
				}

				dp[idx][buy] = profit;
			}
		}

		return dp[0][1];
	}
};

//--------------------------------------------SPACE OPTIMISED------------------------------------------------


class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{

		int n = prices.size();
		vector<int> next(2, 0), curr(2, 0);

		next[0] = next[1] = 0;

		next[0] = next[1] = 0;
		for (int idx = n - 1; idx >= 0; idx--)
		{
			for (int buy = 0; buy <= 1; buy++)
			{

				int profit = 0;

				if (buy)
				{
					int take = -prices[idx] + next[0];

					int notTake = next[1];

					profit = max(take, notTake);
				}
				else
				{
					int sell = prices[idx] + next[1];
					int notSell = next[0];

					profit = max(sell, notSell);
				}

				curr[buy] = profit;
			}
			next = curr;
		}

		return next[1];
	}
};