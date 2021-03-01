#include <bits/stdc++.h>
using namespace std;

int binomialCoefficient(int n, int k)
//space complexity O(n * k)
{
    int table[n+1][k+1];
    
    for(int i = 0 ; i<= n; i++)
    {
        for(int j = 0; j<= min(i, k); j++)
        {
            if(j == 0|| i == j)
            {
                table[i][j] = 1;
            }
            else
            {
                table[i][j] = table[i-1][j-1] + table[i-1][j];
            }
        }
    }
    return table[n][k];
}

int binomialCoefficient2(int n, int k)
//space optimizedn O(k)
{
    int table[k+1];
    for(int i = 0; i<= k; i++)
        table[i] = 0;
    table[0] = 1;

    for(int i = 1; i<= n; i++)
    {
        for(int j = min(i, k); j> 0; j--)
        {
            table[j] = table[j] + table[j-1];
        }
    }
    return table[k];
}

int main()
{
    int n;
    int k;
    cin>>n>>k;
    cout<<"Binomial Coefficient ("<<n<<", "<<k<<") :"<<binomialCoefficient(n, k);
    cout<<endl;
    cout<<"Binomial Coefficient ("<<n<<", "<<k<<") :"<<binomialCoefficient2(n, k);
    return 0;
}