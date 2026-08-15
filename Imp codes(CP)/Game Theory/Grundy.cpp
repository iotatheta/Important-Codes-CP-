/*
Simple Game : 
    
    Problem : Reach N with moving 1, 2 or 4 at a move
*/

// Grundy Numbers (Nimbers): Determines the winning or losing state of a game.
// Grundy number 0 represents a losing state, while positive values represent a winning state.

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long 
#define endl '\n'

// Calculates the Minimum Excluded (MEX) value from a given set of numbers.
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
// TC: O(K) - Iterates through the input array of size K.
// SC: O(K) - Uses a boolean vector of size K + 1.

// Computes the Grundy number for state N using state transition options (i-1, i-2, i-4).
ll calculate_grundy(ll n) 
{
    vector<ll> G(n + 1); // G represent the grundy numbers
    
    G[0] = 0;
    
    for(ll i = 1; i <= n; i++)
    {
        vector<ll> g;
        
        if(i - 1 >= 0)
            g.push_back(G[i - 1]);
            
        if(i - 2 >= 0)
            g.push_back(G[i - 2]);
            
        if(i - 4 >= 0)
            g.push_back(G[i - 4]);
        
        G[i] = mex(g);
    }
    
    return G[n];
}
// TC: O(N) - Single loop running N times with constant-time MEX evaluations.
// SC: O(N) - Stores Grundy values from 0 up to N in a vector.

// Handles input reading and determines whether the game state is a Win or Lose.
void solve()
{
    ll n;
    cin >> n;
    
    if(calculate_grundy(n) != 0)
        cout << "Win" << endl;
    else
        cout << "Lose" << endl;
}
// TC: O(N) - Dominated by the nimbers(n) function computation.
// SC: O(N) - Dominated by the auxiliary space used inside nimbers(n).

// Entry point of the program.
int main()
{
    fastio();
    solve();
}
// TC: O(1) - Constant setup time.
// SC: O(1) - Constant auxiliary space.