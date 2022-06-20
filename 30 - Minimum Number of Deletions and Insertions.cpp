/*

Problem Statement
You are given 2 non-empty strings “str” and “ptr” consisting of lowercase English alphabets only. Your task is to convert string “str” into string “ptr”. In one operation you can do either of the following on “str”:
Remove a character from any position in “str”.
Add a character to any position in “str”.
You have to find the minimum number of operations required to convert string “str” into “ptr”.
For Example:
If str = “abcd”, ptr = “anc”
In one operation remove str[3], after this operation str becomes “abc”.    
In the second operation remove str[1], after this operation str becomes “ac”.
In the third operation add ‘n’ in str[1], after this operation str becomes “anc”.

Hence, the output will be 3.
Input Format :
The first line of the input contains an integer, 'T’, denoting the number of test cases.

The first line of each test case will contain two space-separated non-empty strings “str” and “ptr”.
Output Format :
For each test case, print the minimum number of operations required to convert string “str” into “ptr”.

Print a separate line for each test case.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= str.length, ptr.length <= 100

Time limit: 1 sec
Sample Input 1 :
2
abcd anc
aa aaa
Sample Output 1 :
3
1
Explanation For Sample Output 1:
For the first test case,
str = “abcd”, ptr = “anc”

In one operation remove str[3], after this operation str becomes “abc”.
In the second operation remove str[1], after this operation str becomes “ac”.
In the third operation add ‘n’ in str[1], after this operation str becomes “anc”.

Hence, the output will be 3.

For the second test case,
str = “aaa”, ptr = “aa”

In one operation remove str[2], after this operation str becomes “aa”.

Hence, the output will be 1.
Sample Input 2 :
2
cue dgo
edl xcqja
Sample Output 2 :
6
8

*/


//--------------------------------------------MEMOIZATION------------------------------------------------


int fun(string &text1, string &text2,int idx1,int idx2,vector<vector<int>> &dp)
    {
        if(idx1 == 0 || idx2 == 0)
            return 0;
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(text1[idx1 - 1] == text2[idx2 - 1])
        {
            return dp[idx1][idx2] = 1 + fun(text1,text2,idx1-1,idx2-1,dp);
        }
        else
        {
            int first = fun(text1,text2,idx1-1,idx2,dp);
            int second = fun(text1,text2,idx1,idx2-1,dp);
            return dp[idx1][idx2] = max(first,second);
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(text1,text2,n,m,dp);
    }
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    return str.size() + ptr.size() - 2 * longestCommonSubsequence(str,ptr);
}

