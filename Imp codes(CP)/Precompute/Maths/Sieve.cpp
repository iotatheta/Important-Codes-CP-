// Sieve Of Eratosthenes
// Odd Sieve
// i <= N / i is highly recommended to avoid overflow

// N * (1/2 + 1/3 + 1/5 + 1/7 ... + 1/N) = O(N log log N)
// Sum of reciprocal of primes give TC: O(log log N)

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define endl '\n'

const int N = 1e6 ;

vector<bool> isprime(N+1,true) ;

void sieve()
{
    isprime[0] = isprime[1] = false ; 
    
    // mark all even (except 2) as false
    
    for(int i=4; i<=N; i+=2)
    {
        isprime[i] = false ;
    }
    
    // only check for odd (odd + even = odd)
    
    for(int i=3; i<=N / i; i+=2) // or i*i<=N
    {
        if(isprime[i]) // Prime Check
        {
            for(int j=i*i;j<=N;j+=2*i)
            {
                isprime[j] = false ;
            }
        }
    }
}
// TC: O(N log log N)
// SC: O(N)

void solve()
{
    int n ;
    cin >> n ;
    
    if(isprime[n])
        cout << "YES" << endl ;
    else
        cout << "NO" << endl ;
}
// TC: O(1)
// SC: O(1)

int main()
{
    fastio();
    sieve();
    
    int t ;
    cin >> t ;
    while(t-- > 0)
    {
        solve();
    }
}
// TC: O(N log log N + T)
// SC: O(N)
