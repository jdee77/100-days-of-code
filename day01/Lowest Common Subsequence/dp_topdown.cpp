#include <bits/stdc++.h>
using namespace std;

long long dp[100][100];
void pre(long long, long long);

long long lcs(string s1, string s2, long long m, long long n)
{
    /*
    dynamic programming memoization 
    time complexity O(m * n) 
    */
   
    if(m == 0 || n == 0) return 0;

    if(dp[m][n] != -1) return dp[m][n];

    if(s1[m-1] == s2[n-1]) dp[m][n] = 1 + lcs(s1, s2, m-1, n-1);
    else dp[m][n] = max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));

    return dp[m][n];
}

int main()
{
    string s1, s2;
    cin>>s1;
    cin>>s2;

    long long m = s1.size();
    long long n = s2.size();

    pre(m, n);

    long long res = lcs(s1, s2, m, n);
    cout<<"The longest common subsequence is of Length : "<<res;

    return 0;
}

void pre(long long m, long long n)
{
    for(long long i = 0; i<= m; i++)
        for(long long j = 0; j<= n; j++)
            dp[i][j] = -1;
}