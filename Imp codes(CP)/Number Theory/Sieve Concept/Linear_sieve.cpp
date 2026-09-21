// Linear Sieve 

// An optimized version of the Sieve of Eratosthenes that achieves O(N) time by ensuring each composite number is crossed out exactly once (by its smallest prime factor)

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

vector<int> linear_sieve(int n)
{
    vector<int> spf(n + 1, 0);
    vector<int> primes;

    for(int i = 2; i <= n; i++)
    {
        if(spf[i] == 0)
        {
            spf[i] = i;
            primes.push_back(i);
        }

        for(int p : primes)
        {
            if(p > spf[i] || 1LL * i * p > n)
                break;

            spf[i * p] = p;
        }
    }

    return primes;
}
// TC: O(n)
// SC: O(n)

void solve()
{
    int n;
    cin >> n;

    vector<int> primes = linear_sieve(n);

    for(int p : primes)
    {
        cout << p << " ";
    }

    cout << endl;
}
// TC: O(n) including sieve and output
// SC: O(n)

int main()
{
    fastio();

    solve();
}
// TC: O(n)
// SC: O(n)