// Code to flip and reverse bits

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define ull unsigned long long
#define endl '\n'

ull flipingBits(ull n)
{
    ull mask = ((ull) LLONG_MAX << 1) | 1;
    
    return n ^ mask; // Xor with large number toggles each bit
    
    // return ~n; [recommended]
}
// TC: O(1)
// SC: O(1)

ull reverseBits(ull n)
{
    ull res = 0;

    for (ll i = 0; i < 64; i++)
    {
        res = res << 1; // shift res to left to make room for new bit

        res = res | (n & 1ULL); // extract the rightmost bit of n and add it to res

        n = n >> 1; // shift n to right to process the next bit
    }

    return res;
}
// TC: O(64) = O(1)
// SC: O(1)

void solve()
{
    // Code here    
}

int main()
{
    fastio();
    solve();
}