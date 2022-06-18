/*

Problem Statement
You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number “tar”.
Note:
Two ways are considered different if sets of indexes of elements chosen by these ways are different.

Input is given such that the answer will fit in a 32-bit integer.
For Example:
If N = 4 and tar = 3 and the array elements are [1, 2, 2, 3], then the number of possible ways are:
{1, 2}
{3}
{1, 2}
Hence the output will be 3.
Input Format :
The first line of the input contains an integer, 'T’, denoting the number of test cases.

The first line of each test case will contain two space-separated integers ‘N’ and “tar”, denoting the size of the array and the target sum.

The second line of each test case contains ‘N’ space-separated integers denoting elements of the array.
Output Format :
For each test case, print the number of ways that satisfy the condition mentioned in the problem statement.

Print a separate line for each test case.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 100
1 <= nums[i] <= 1000
1 <= tar <= 1000

Time limit: 1 sec
Sample Input 1 :
2
4 3
1 2 2 3
2 3
1 2
Sample Output 1 :
 3
 1
Explanation For Sample Output 1:
For the first test case, N = 4 and tar = 3 and array elements are [1, 2, 2, 2,3] then the number of possible ways of making sum = 5 are:
{1,2}
{3}
{1,2}

Hence the output will be 3.

For the second test case, N = 2 and tar = 3 and array elements are [1, 2], there is only one way of making sum = 3 which is {1,2}.

Hence the output will be 1.
Sample Input 2 :
2
3 4
12 1 3
2 41
2 34
Sample Output 2 :
1
0

*/

//--------------------------------------------RECURSION------------------------------------------------

int fun(vector<int> &num, int idx, int tar)
{
	if (idx == 0)
	{
		if (tar == 0 && num[0] == 0)
			return 2;
		if (tar == 0 || tar == num[0])
			return 1;
		return 0;
	}

	int notPick = fun(num, idx - 1, tar);

	int pick = 0;
	if (num[idx] <= tar)
		pick = fun(num, idx - 1, tar - num[idx]);

	return pick + notPick;
}
int findWays(vector<int> &num, int tar)
{
	// Write your code here.
	int n = num.size();
	return fun(num, n - 1, tar);
}

//--------------------------------------------MEMOIZATION------------------------------------------------

int fun(vector<int> &num, int idx, int tar, vector<vector<int>> &dp)
{

	if (idx == 0)
	{
		if (tar == 0 && num[0] == 0)
			return 2;
		if (tar == 0 || tar == num[0])
			return 1;
		return 0;
	}


	if (dp[idx][tar] != -1)
		return dp[idx][tar];

	int notPick = fun(num, idx - 1, tar, dp);

	int pick = 0;
	if (num[idx] <= tar)
		pick = fun(num, idx - 1, tar - num[idx], dp);

	return dp[idx][tar] = pick + notPick;
}
int findWays(vector<int> &num, int tar)
{
	// Write your code here.
	int n = num.size();
	vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
	return fun(num, n - 1, tar, dp);
}

//--------------------------------------------TABULATION------------------------------------------------

int findWays(vector<int> &num, int tar)
{
	// Write your code here.
	int n = num.size();
	vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

	for (int idx = 0 ; idx < n ; idx++)
	{
		dp[idx][0] = 1;
	}

	if (num[0] <= tar)
		dp[0][num[0]] = 1;

	for (int idx = 1 ; idx < n; idx++)
	{
		for (int t = 0 ; t <= tar; t++)
		{
			int notPick = dp[idx - 1][t];

			int pick = 0;
			if (num[idx] <= t)
				pick = dp[idx - 1][t - num[idx]];

			dp[idx][t] = pick + notPick;
		}
	}
	return dp[n - 1][tar];
}

//--------------------------------------------SPACE OPTIMISED------------------------------------------------

int findWays(vector<int> &num, int tar)
{
	// Write your code here.
	int n = num.size();
	vector<int> prev(tar + 1, 0), curr(tar + 1, 0);

	for (int idx = 0 ; idx < n ; idx++)
	{
		prev[0] = 1;
	}

	if (num[0] <= tar)
		prev[num[0]] = 1;

	for (int idx = 1 ; idx < n; idx++)
	{
		for (int t = 0 ; t <= tar; t++)
		{
			int notPick = prev[t];

			int pick = 0;
			if (num[idx] <= t)
				pick = prev[t - num[idx]];

			curr[t] = pick + notPick;
		}
		prev = curr;
	}
	return prev[tar];
}