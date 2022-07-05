/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0


Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

*/

//--------------------------------------------RECURSION------------------------------------------------

class Solution {
private:
	int fun(int idx, int buy, int n, vector<int>& prices, vector<vector<int>> &dp)
	{
		if (idx >= n )
			return 0;

		int profit = 0;

		if (buy == 1)
		{
			int take = -prices[idx] + fun(idx + 1, 0, n, prices);

			int notTake = fun(idx + 1, 1, n, prices);

			profit = max(take, notTake);
		}
		else
		{
			int sell = prices[idx] + fun(idx + 2, 1, n, prices);
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
		if (idx >= n )
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
			int sell = prices[idx] + fun(idx + 2, 1, n, prices, dp);
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
		vector<vector < int>> dp(n + 2, vector<int> (2, 0));

		dp[n][0] = dp[n][1] = 0;
		for (int idx = n - 1; idx >= 0; idx--)
		{
			for (int buy = 0; buy <= 1; buy++)
			{

				int profit = 0;

				if (buy == 1)
				{
					int take = -prices[idx] + dp[idx + 1][0];

					int notTake = dp[idx + 1][1];

					profit = max(take, notTake);
				}
				else
				{
					int sell = prices[idx] + dp[idx + 2][1];
					int notSell = dp[idx + 1][0];

					profit = max(sell, notSell);
				}

				dp[idx][buy] = profit;
			}
		}

		return dp[0][1];
	}
};


