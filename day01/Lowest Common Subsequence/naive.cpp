#include <bits/stdc++.h>
using namespace std;

long long lcs(string s1, string s2, long long m, long long n)
{
    /*
    devide and conquer 
    time complexity O(2^n) exponential
    stack space 
    */
   
    if(m == 0 || n == 0) return 0;

    if(s1[m-1] == s2[n-1]) return 1 + lcs(s1, s2, m-1, n-1);
    else return max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
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
