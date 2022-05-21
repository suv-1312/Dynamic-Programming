
/*****************************************************************
                       MINIMUM SEPS TO ONE
*****************************************************************/

int minStepsTo1Simple(int n) {

	if (n <= 1)
		return 0;

	int x = INT_MAX;
	int y = INT_MAX;
	int z = INT_MAX;

	x = minStepsTo1Simple(n - 1);

	if (n % 2 == 0)
		y = minStepsTo1Simple(n / 2);

	if (n % 3 == 0)
		z = minStepsTo1Simple(n / 3);

	return 1 + min(x, min(y, z));
}


//---------------------------TOP DOWN--------------------------

int minStepsTo1TopDownHelp(int n, std::vector<int> &dp)
{
	if (n <= 1)
		return 0;

	if (dp[n] != 0)
		return dp[n];

	int x = INT_MAX;
	int y = INT_MAX;
	int z = INT_MAX;

	x = minStepsTo1Simple(n - 1);

	if (n % 2 == 0)
		y = minStepsTo1Simple(n / 2);

	if (n % 3 == 0)
		z = minStepsTo1Simple(n / 3);

	return dp[n] = 1 + min(x, min(y, z));
}

int minStepsTo1TopDown(int n)
{
	std::vector<int> dp(n + 1, 0);
	return minStepsTo1TopDownHelp(n, dp);
}

//------------------------BOTTOM UP-------------------------------------

int minStepsTo1BottomUp(int n )
{
	vector<int> dp(n + 1);
	vector<string> path(n + 1, "");

	dp[0] = 0;
	dp[1] = 0;
	path[1] = " end ";

	for (int i = 2; i <= n ; i++)
	{
		int x = INT_MAX, y = INT_MAX, z = INT_MAX;

		x = dp[i - 1];

		if (i % 2 == 0)
			y = dp[i / 2];


		if (i % 3 == 0 )
			z = dp[i / 3];

		dp[i] = 1 + min(x, min(y, z));

		if (x <= y && x <= z)
			path[i] = " sub 1 --> " + path[i - 1];

		if (y <= z && y <= x)
			path[i] = " div 2 --> " + path[i / 2];

		if (z <= x && z <= y)
			path[i] = " div 3 --> " + path[i / 3];
	}

	cout << path[n] << endl;

	return dp[n];
}
