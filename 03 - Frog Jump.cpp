/*

Problem Statement
There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. 
HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, 
the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. 
Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

For Example
If the given ‘HEIGHT’ array is [10,20,30,10], 
the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) 
and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). 
So, the total energy lost is 20.

*/


//-----------------------------------------RECURSION--------------------------------------



int func(int idx,vector<int> &heights)
{
	if(idx == 0)
		return 0;
	
	int one = func(idx-1,heights) + abs(heights[idx] - heights[idx-1]);
	
	int two = 1e7;
	if(idx>1)
		 two = func(idx-2,heights) + abs(heights[idx] - heights[idx-2]);
	
	return min(one,two);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
	return func(n-1,heights);
}

//-----------------------------------------MEMOIATION--------------------------------------


int func(int idx,vector<int> &heights,vector<int> &dp)
{
	if(idx == 0)
		return 0;
	
	if(dp[idx]!=-1)
		return dp[idx];
	
	int one = func(idx-1,heights,dp) + abs(heights[idx] - heights[idx-1]);
	
	int two = 1e7;
	if(idx>1)
		 two = func(idx-2,heights,dp) + abs(heights[idx] - heights[idx-2]);
	
	return dp[idx] = min(one,two);
}
int frogJump(int n, vector<int> &heights)
{
	vector<int> dp(n+1,-1);
	return func(n-1,heights,dp);
}


//-----------------------------------------TABULATION--------------------------------------


int frogJump(int n, vector<int> &heights)
{
	vector<int> dp(n+1,-1);
	dp[0] = 0;
	for(int i = 1; i< n ;i++)
	{
		int one = dp[i-1] + abs(heights[i] - heights[i-1]);
		
		int two = 1e7;
		if(i>1)
			two = dp[i-2] + abs(heights[i] - heights[i-2]);
		
		dp[i] = min(one,two);
	}
	return dp[n-1];
}


//-----------------------------------------SPACE OPTIMISED----------------------------------


int frogJump(int n, vector<int> &heights)
{

	vector<int> dp(n+1,-1);
	int prev1 = 0,prev2 =0;
	for(int i = 1; i< n ;i++)
	{
		int one = prev1 + abs(heights[i] - heights[i-1]);
		
		int two = 1e7;
		if(i>1)
			two = prev2 + abs(heights[i] - heights[i-2]);
		
		int curr = min(one,two);
		
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1;
}



