/*

Printing Longest Increasing Subsequence

*/

int longestIncreasingSubsequence(int arr[],int n)
{

	vector<int> dp(n,1);
	vector<int> hash(n);

        int maxi = 1;
	int lastIdx = 0;

	for(int i = 0 ; i< n ;i++)
	{
	    hash[i] = i;
	    for(int prev = 0 ; prev<i;prev++)
	    {
                if(arr[prev]<arr[i] && 1+dp[prev] > dp[i])
		{
		   dp[i] = 1+dp[prev];
                   hash[i] = prev;  
		}
	    }

	   if(dp[i] > maxi)
	   {
              maxi = dp[i];
	      lastIdx = i;
	   }
 	}
 
     
     vector<int> lis;
     lis.push_back(nums[lastIdx]);

     while(hash[lastIdx]!=lastIdx)
     {
        lastIdx = hash[lastIdx];  
	lis.push_back(arr[lastIdx]);
     }
     reverse(lis.begin(),lis.end());

     for(auto it: lis)
     {
        cout<<it<<" ";
     }
     return maxi;  
}




