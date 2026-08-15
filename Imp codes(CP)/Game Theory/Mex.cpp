// Calculate Mex({...}) [mex is the smallest non-negative number ( >= 0) that is not present in the set]

// Never use unordered_set as there may be collisions

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

void solve()
{
    ll n, x;
    cin >> n;
    
    vector<bool> present(n + 1, false); // because the mex can be at max n not more than that
    
    for(ll i = 0; i < n; i++)
    {
        cin >> x;
        
        if(x >= 0 && x <= n)
        {
            present[x] = true;
        }
    }
    
    ll mex_value = 0;
    
    while(present[mex_value])
    {
        mex_value++;
    }
    
    cout << mex_value;
}
// TC: O(N), where N is the number of elements, because we loop N times for input and at most N+1 times for the while loop.
// SC: O(N), to store the boolean presence vector of size n + 1.

int main()
{
    fastio();
    solve();
}
// TC: O(1), constant time for main execution setup
// SC: O(1), constant space