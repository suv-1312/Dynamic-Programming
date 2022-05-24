/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.


Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/

//--------------------------------RECURSION-----------------------------------


class Solution {

	long long minPathSum(int i, int j, vector<vector<int>>& grid )
	{
		if (i == 0 && j == 0)
			return grid[i][j];

		if (i < 0 || j < 0)
			return INT_MAX;

		long long up = grid[i][j] + minPathSum(i - 1, j, grid);
		long long left = grid[i][j] + minPathSum(i, j - 1, grid);

		return min(up, left);
	}

public:
	int minPathSum(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();
		return minPathSum(m - 1, n - 1, grid);
	}
};


//--------------------------------MEMOIZATION-----------------------------------

class Solution {

	long long minPathSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp )
	{
		if (i == 0 && j == 0)
			return grid[i][j];

		if (i < 0 || j < 0)
			return INT_MAX;

		if (dp[i][j] != -1)
			return dp[i][j];

		long long up = grid[i][j] + minPathSum(i - 1, j, grid, dp);
		long long left = grid[i][j] + minPathSum(i, j - 1, grid, dp);

		return dp[i][j] = min(up, left);
	}

public:
	int minPathSum(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, -1));
		return minPathSum(m - 1, n - 1, grid, dp);
	}
};


//--------------------------------TABULATION-----------------------------------


class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, -1));

		for (int i = 0 ; i < m; i++)
		{
			for (int j = 0 ; j < n; j++)
			{
				if (i == 0 && j == 0)
					dp[i][j] = grid[0][0];
				else
				{
					int up = grid[i][j] , left = grid[i][j];

					if (i > 0)
						up +=  dp[i - 1][j];
					else
						up += 1e7;

					if (j > 0)
						left +=  dp[i][j - 1];
					else
						left += 1e7;

					dp[i][j] = min(up, left);
				}
			}
		}

		return dp[m - 1][n - 1];
	}
};

//--------------------------------SPACE OPTIMIZED-----------------------------------

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, -1));
		vector<int> prev(n, 0);
		for (int i = 0 ; i < m; i++)
		{
			vector<int> curr(n, 0);
			for (int j = 0 ; j < n; j++)
			{
				if (i == 0 && j == 0)
					curr[j] = grid[0][0];
				else
				{
					int up = grid[i][j] , left = grid[i][j];

					if (i > 0)
						up +=  prev[j];
					else
						up += 1e7;

					if (j > 0)
						left +=  curr[j - 1];
					else
						left += 1e7;

					curr[j] = min(up, left);
				}
			}
			prev = curr;
		}

		return prev[n - 1];
	}
};