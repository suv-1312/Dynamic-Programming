/*

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.


Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

*/

//--------------------------------------------RECURSION------------------------------------------------

//--------------------------------------------MEMOIZATION------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

bool isAllStars(string & S1, int i) {
	for (int j = 0; j <= i; j++) {
		if (S1[j] != '*')
			return false;
	}
	return true;
}

bool wildcardMatchingUtil(string & S1, string & S2, int i, int j, vector < vector < bool >> & dp) {

	//Base Conditions
	if (i < 0 && j < 0)
		return true;
	if (i < 0 && j >= 0)
		return false;
	if (j < 0 && i >= 0)
		return isAllStars(S1, i);

	if (dp[i][j] != -1) return dp[i][j];

	if (S1[i] == S2[j] || S1[i] == '?')
		return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);

	else {
		if (S1[i] == '*')
			return wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
		else return false;
	}
}

bool wildcardMatching(string & S1, string & S2) {

	int n = S1.size();
	int m = S2.size();

	vector < vector < bool >> dp(n, vector < bool > (m, -1));
	return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);

}

int main() {

	string S1 = "ab*cd";
	string S2 = "abdefcd";

	if (wildcardMatching(S1, S2))
		cout << "String S1 and S2 do match";
	else cout << "String S1 and S2 do not match";
}

//--------------------------------------------TABULATION------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

bool isAllStars(string & S1, int i) {

	// S1 is taken in 1-based indexing
	for (int j = 1; j <= i; j++) {
		if (S1[j - 1] != '*')
			return false;
	}
	return true;
}

bool wildcardMatching(string & S1, string & S2) {

	int n = S1.size();
	int m = S2.size();

	vector < vector < bool >> dp(n + 1, vector < bool > (m, false));

	dp[0][0] = true;

	for (int j = 1; j <= m; j++) {
		dp[0][j] = false;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = isAllStars(S1, i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];

			else {
				if (S1[i - 1] == '*')
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

				else dp[i][j] = false;
			}
		}
	}

	return dp[n][m];

}

int main() {

	string S1 = "ab*cd";
	string S2 = "abdefcd";

	if (wildcardMatching(S1, S2))
		cout << "String S1 and S2 do match";
	else cout << "String S1 and S2 do not match";
}

//--------------------------------------------SPACE OPTIMISED------------------------------------------------
