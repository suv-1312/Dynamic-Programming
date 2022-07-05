/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

*/

//--------------------------------------------RECURSION------------------------------------------------

//--------------------------------------------MEMOIZATION------------------------------------------------

//--------------------------------------------TABULATION------------------------------------------------


//--------------------------------------------SPACE OPTIMISED------------------------------------------------

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {

		int n = prices.size();
		vector<vector < int>> next(2, vector<int> (k + 1, 0));
		vector<vector < int>> curr(2, vector<int> (k + 1, 0));

		for (int idx = n - 1; idx >= 0; idx--)
		{
			for (int buy = 0; buy <= 1; buy++)
			{
				for (int limit = 1; limit <= k; limit++)
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

		return next[1][k];
	}
};


