/*

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6


Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104

*/

//--------------------------------------------RECURSION------------------------------------------------

class Solution {
private:
	int fun(int idx, int buy, int n, vector<int>& prices, int fee)
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
			int sell = prices[idx] - fee + fun(idx + 1, 1, n, prices);
			int notSell = fun(idx + 1, 0, n, prices);

			profit = max(sell, notSell);
		}

		return profit;
	}
public:
	int maxProfit(vector<int>& prices, int fee) {

		int n = prices.size();
		return fun(0, 1, n, prices);

	}
};


//--------------------------------------------MEMOIZATION------------------------------------------------

class Solution {
private:
	int fun(int idx, int buy, int n, vector<int>& prices, vector<vector<int>> &dp, int fee)
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
			int sell = prices[idx] - fee + fun(idx + 1, 1, n, prices, dp);
			int notSell = fun(idx + 1, 0, n, prices, dp);

			profit = max(sell, notSell);
		}

		return dp[idx][buy] = profit;
	}
public:
	int maxProfit(vector<int>& prices, int fee) {

		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, -1));
		return fun(0, 1, n, prices, dp);

	}
};


//--------------------------------------------TABULATION------------------------------------------------

class Solution
{
public:
	int maxProfit(vector<int> &prices, int fee)
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
					int sell = prices[idx] - fee + dp[idx + 1][1];
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
	int maxProfit(vector<int> &prices, int fee)
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
					int sell = prices[idx] - fee + next[1];
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