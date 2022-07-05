/*

Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first increasing, then decreasing.
 

Example 1:

Input: nums = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is
increasing and the sequence {3, 2} is 
decreasing so merging both we will get 
length 5.
Example 2:

Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence 
{1, 2, 10, 4, 2, 1} has length 6.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function LongestBitonicSequence() which takes the array nums[] as input parameter and returns the maximum length of bitonic subsequence.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)
 

Constraints:
1 ≤ length of array ≤ 200
1 ≤ arr[i] ≤ 1000000

*/

// { 	Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int LongestBitonicSequence(vector<int> arr)
        {
           	// code here
            int n = arr.size();
            vector<int> dp1(n, 1);

            int lastIdx = 0;

            for (int i = 0; i < n; i++)
            {

                for (int prev = 0; prev < i; prev++)
                {
                    if (arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i])
                    {
                        dp1[i] = 1 + dp1[prev];
                    }
                }
            }

            vector<int> dp2(n, 1);

            int maxi = 1;

            for (int i = n - 1; i >= 0; i--)
            {

                for (int prev = n - 1; prev > i; prev--)
                {
                    if (arr[prev] < arr[i] && 1 + dp2[prev] > dp2[i])
                    {
                        dp2[i] = 1 + dp2[prev];
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans = max(ans, dp1[i] + dp2[i] - 1);
            }
            return ans;
        }
};

// { 	Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.LongestBitonicSequence(nums);
        cout << ans << "\n";
    }
    return 0;
}	// } Driver Code Ends
