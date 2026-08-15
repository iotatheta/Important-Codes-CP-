/*
   Composite Game:
   
   Problem: 3 stacks having x, y, and z coins; you can remove 1, 2, or 4 coins from any stack in a move.
   
   [In this code, we generalize for n stacks each having a_i coins, and you can remove c_i coins from any stack in a move. The number of coin denominations is m.]
   
   If A starts the game and both A and B play optimally (alternately), determine whether A will win or lose.
*/

/* 
   Sprague-Grundy Theorem:
   
   For a COMPOSITE GAME, it is a Winning State if the XOR sum of the Grundy numbers of all individual sub-games (stacks) is non-zero (≠ 0). Otherwise, if the XOR sum evaluates to zero (= 0), the first player will definitely lose, no matter what.
*/

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

// Computes the Grundy number for a stack with 'n' coins given the allowed move denominations 'c'.
ll calculate_grundy(const ll &n, const vector<ll>& c)
{
    vector<ll> G(n + 1);
    
    G[0] = 0; // Base case: 0 coins represent a losing state (no moves possible).
    
    for(ll i = 1; i <= n; i++)
    {
        vector<ll> g;
        
        for(auto ci : c)
        {
            if(i - ci >= 0)
            {
                g.push_back(G[i - ci]);
            }
        }
        
        G[i] = mex(g);
    }
    
    return G[n];
}
// TC: O(N * M) - Computes Grundy values up to N, checking M possible moves at each step.
// SC: O(N) - Stores Grundy numbers from 0 up to N in a vector.

// Reads stack sizes and allowed moves, then applies the Sprague-Grundy theorem to output the game outcome.
void solve()
{
    ll n, m;
    cin >> n >> m;
    
    bool all_zero = true;
    
    vector<ll> a(n), c(m);
    
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
        
        if(a[i] != 0)
        {
            all_zero = false;
        }
    }
    
    for(ll i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    
    ll xor_sum = 0;
    
    for(ll i = 0; i < n; i++)
    {
        xor_sum = xor_sum ^ calculate_grundy(a[i], c); 
    }
    
    if(all_zero)
        cout << "Draw" << endl;
    else if(xor_sum != 0)
        cout << "Win" << endl;
    else    
        cout << "Lose" << endl;
}
// TC: O(N * M * max(A)) - Sum of complexities for calculating Grundy numbers across all N stacks.
// SC: O(max(A)) - Auxiliary space proportional to the maximum coin stack size for DP tables.

// Entry point of the program.
int main()
{
    fastio();
    solve();
}
// TC: O(1) - Constant setup time.
// SC: O(1) - Constant auxiliary space.