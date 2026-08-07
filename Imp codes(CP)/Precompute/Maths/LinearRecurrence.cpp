// Precomputation with the help of Matrix Exponentiation
// ele[i] stores T^(i-1)

/*===============================================================
★ PRECOMPUTE TRANSITION MATRICES (FIXED MATRIX OPTIMIZATION) ★

Applicable when the transition matrix is fixed and there are many
queries.

Instead of computing T^n for every query using matrix exponentiation,
precompute and store the required powers (or all consecutive powers)
of the transition matrix once.

For Fibonacci, simple DP precomputation is more memory-efficient due
to its special identities. However, this preprocessing technique
generalizes well to arbitrary linear recurrences where no such
simplification exists.
===============================================================*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e6;
const int MOD = 1e9 + 7;

vector<int> ele00(N+1), ele01(N+1), ele10(N+1), ele11(N+1);

vector<vector<int>> multiply(const vector<vector<int>> &a, const vector<vector<int>> &b)
{
    int r1 = a.size(), r2 = b.size(), c2 = b[0].size();
    
    vector<vector<int>> c(r1,vector<int>(c2));
    
    for(int i=0;i<r1;i++)
    {
        for(int k=0;k<r2;k++)
        {
            for(int j=0;j<c2;j++)
            {
                c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    
    return c;
}
// TC: O(1) // O(R1 × R2 × C2) for general matrices
// SC: O(1)     // O(R1 × C2) for general matrices

void precompute()
{
    vector<vector<int>> trans = {{1,1},{1,0}}, res = trans;
    ele00[2] = 1, ele01[2] = 1, ele10[2] = 1, ele11[2] = 0;
    
    for(int i=3;i<=N;i++)
    {
        res = multiply(res, trans);
        
        ele00[i] = res[0][0];
        ele01[i] = res[0][1];
        ele10[i] = res[1][0];
        ele11[i] = res[1][1];
    }
}
// TC: O(N)
// SC: O(N)

int fib(int n)
{
    if(n < 0)
        return 0;
        
    if(n <= 1)
        return n;
        
    vector<vector<int>> trans = {{ele00[n], ele01[n]},{ele10[n], ele11[n]}};
    vector<vector<int>> f1 = {{1},{0}};
    
    auto res = multiply(trans,f1);
    
    return res[0][0];
}
// TC: O(1)
// SC: O(1)

void solve()
{
    int n;
    cin >> n;
    
    cout << fib(n);
}
// TC: O(1)
// SC: O(1)

int main()
{
    fastio();
    precompute();
    
    solve();
}
// TC: O(N)
// SC: O(N)
