#include <bits/stdc++.h>
using namespace std;


long long lcs(string s1, string s2, long long m, long long n)
{
    /*
    dynamic programming tabulation 
    time complexity O(m * n) 
    */

    if(m == 0 || n == 0) return 0;

    long long dp[m + 1][n + 1];
    long long i, j;
    for(i = 0; i<= m; i++) dp[i][0] = 0;
    for(i = 0; i<= n; i++) dp[0][i] = 0;

    for(i = 1; i<= m; i++)
    {
        for(j = 1; j<= n; j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{
    string s1, s2;
    cin>>s1;
    cin>>s2;

    long long m = s1.size();
    long long n = s2.size();

    long long res = lcs(s1, s2, m, n);
    cout<<"The longest common subsequence is of Length : "<<res;

    return 0;
}

