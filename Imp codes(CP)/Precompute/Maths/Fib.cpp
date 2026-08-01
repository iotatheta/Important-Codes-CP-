// Precompute Fibonacci (Generally Not Preferred)

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ull unsigned long long
#define endl '\n'

const int N = 93; 
vector<ull> fib(N+1); // the 94th term will exceed ull range

void precompute()
{
    fib[0] = 0 , fib[1] = 1;
    for(int i=2;i<=N;i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
}
// TC: O(N) (N = 93, effectively constant)
// SC: O(N)

void solve()
{
    int n;
    cin >> n;
    cout<< fib[n] << endl;
}
// TC: O(1)
// SC: O(1)

int main()
{
    fastio();
    precompute();
    int t;
    cin >> t;
    while(t-- > 0)
    {
        solve();
    }
}
// TC: O(N + T)
// SC: O(N)
