// The mex in a seperate function is better when an unknown or a random set is given 

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long 
#define endl '\n'

ll mex(const vector<ll>& arr)
{
    ll n = arr.size(), x;
    
    vector<bool> present(n + 1, false);
    
    for(ll i = 0; i < n; i++)
    {
        x = arr[i];
        
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
    
    return mex_value;
}
// TC: O(N), where N is the size of the array, iterating through elements and finding the MEX linearly.
// SC: O(N), for the boolean presence vector of size n + 1.

void solve()
{
    ll n;
    cin >> n;
    
    vector<ll> arr(n);
    
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << mex(arr);
}
// TC: O(N), for reading input of size N.
// SC: O(N), to store the input array of size N.

int main()
{
    fastio();
    solve();
}
// TC: O(1), constant overhead for execution setup.
// SC: O(1), constant auxiliary space.