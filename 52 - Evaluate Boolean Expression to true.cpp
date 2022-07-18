/*

Problem Statement
You are given an expression ‘EXP’ in the form of a string where operands will be : (TRUE and FALSE) and operators will be : (AND, OR, XOR). Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.
Note :
‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.
For example :
 Input: 
 'EXP’ = T|T & F
 There are total 2  ways to parenthesize this expression:
 (i) (T | T) & (F) = F
 (ii) (T) | (T & F) = T
 Out of 2 ways, one will result in True, so we will return 1.

 Output :
 1
Note :
As the answer can be very large, return the output modulo 1000000007.
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The second line of each test case contains a string representing the expression ‘EXP’.
Output format:
For each test case, print a single integer representing the number of ways we can parenthesize the expression such that it evaluates to true.   

Print the output of each test case in a separate line. 
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
3 <= |‘EXP’| <= 200    
Where |EXP| denotes the length of 'EXP'.

Time Limit: 1 sec
Sample Input 1 :
2
T&T
T^T^F    
Sample Output 1 :
1
0
Explanation For Sample Input 1:
For the first test case:
There is only one  way to parenthesize this expression:
(T&T) = T
So we will return 1.

For the second test case:
There are total 2  ways to parenthesize this expression:
(i) (T^T)^(F) = F
(ii) (T)^(T^F) = F
Both the ways will result in False, so we will return 0.
Sample Input 2 :
2
F|T^F
F&T
Sample Output 2 :
2
0
Explanation For Sample Input 2:
For the first test case:
There are total 2  ways to parenthesize this expression:
(i) (F|T)^(F) = T
(ii) (F)|(T^F) = T
Both the ways will result in True, so we will return 2.

For the second test case:
There is only one  way to parenthesize this expression:
(F&T) = F
So we will return 0.

*/

//--------------------------------------------RECURSION------------------------------------------------


#define ll long long 
#define mod 1000000007
ll solve(int i ,int j ,int isTrue,string &a)
{
    if(i>j)
        return 0;
    
    if(i == j)
    {
        if(isTrue)
            return a[i] == 'T';
        else
            return a[i] == 'F';
    }
    ll ways = 0; 
    for(int idx = i+1 ; idx<=j-1 ;idx+=2 )
    {
        ll lT = solve(i,idx-1,1,a);
        ll lF = solve(i,idx-1,0,a);
        ll rT = solve(idx+1,j,1,a);
        ll rF = solve(idx+1,j,0,a);
        
        if(a[idx] == '&')
        {            
            if(isTrue)
                ways = (ways + (rT * lT)%mod)%mod;
            else
                ways = (ways + (rT * lF)%mod + (lT * rF)%mod + (rF * lF)%mod)%mod;
        }
        else if(a[idx] == '|')
        {
            if(isTrue)
                ways = (ways + (rT * lF)%mod + (lT * rF)%mod + (rT * lT)%mod)%mod;
            else
                 ways = (ways + (rF * lF)%mod)%mod;
        }
        else
        {
            if(isTrue)
            ways = (ways+(lT * rF)%mod + (rT * lF)%mod)%mod;
            else
                ways = (ways+(lT * rT)%mod + (rF * lF)%mod)%mod;
        }
    }
    return ways;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
    return solve(0,n-1,1,exp);
}


//--------------------------------------------MEMOIZATION------------------------------------------------

#define ll long long 
#define mod 1000000007
ll solve(int i ,int j ,int isTrue,string &a,vector<vector<vector<ll>>> &dp)
{
    if(i>j)
        return 0;
    
    if(i == j)
    {
        if(isTrue)
            return a[i] == 'T';
        else
            return a[i] == 'F';
    }
    
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    
    ll ways = 0; 
    for(int idx = i+1 ; idx<=j-1 ;idx+=2 )
    {
        ll lT = solve(i,idx-1,1,a,dp);
        ll lF = solve(i,idx-1,0,a,dp);
        ll rT = solve(idx+1,j,1,a,dp);
        ll rF = solve(idx+1,j,0,a,dp);
        
        if(a[idx] == '&')
        {            
            if(isTrue)
                ways = (ways + (rT * lT)%mod)%mod;
            else
                ways = (ways + (rT * lF)%mod + (lT * rF)%mod + (rF * lF)%mod)%mod;
        }
        else if(a[idx] == '|')
        {
            if(isTrue)
                ways = (ways + (rT * lF)%mod + (lT * rF)%mod + (rT * lT)%mod)%mod;
            else
                 ways = (ways + (rF * lF)%mod)%mod;
        }
        else
        {
            if(isTrue)
            ways = (ways+(lT * rF)%mod + (rT * lF)%mod)%mod;
            else
                ways = (ways+(lT * rT)%mod + (rF * lF)%mod)%mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    return solve(0,n-1,1,exp,dp);
}

//--------------------------------------------TABULATION------------------------------------------------


//--------------------------------------------SPACE OPTIMISED------------------------------------------------
