/*****************************************************************
                            FIBONACCI
*****************************************************************/

//--------------------SIMPLE FIBONACCI--------------------

int fibSimple(int n) {
	if (n == 1 || n == 0)
		return n;

	return fibSimple(n - 1) + fibSimple(n - 2);
}

//-----------FIBONACCI RECURSION + MEMOIATION--------------

int fibTopDownHelp(int n, vector<int> &dp) {
	if (n == 1 || n == 0)
		return dp[n] = n;

	if (dp[n] != 0)
		return dp[n];

	int ans = fibTopDownHelp(n - 1, dp) + fibTopDownHelp(n - 2, dp);
	return dp[n] =  ans;
}

int fibTopDown(int n) {

	vector<int> dp(n + 1, 0);
	return fibTopDownHelp(n, dp);
}


//--------------------------FIBONACCI BOTTOM UP---------------------------


int fibBottomUp(int n) {

	/*vector<int> dp(n + 1, 0);

	dp[1] = 1;

	for (int i = 2 ; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];*/

	int a = 0;
	int b = 1;
	int c = 0;

	int i = 2;
	while (i <= n)
	{
		c = a + b;
		a = b;
		b = c;

		i++;
	}
	return c;
}
