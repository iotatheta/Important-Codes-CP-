// GCD and LCM for n numbers

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

ll gcd(ll a, ll b)
{
    a = llabs(a);
    b = llabs(b);
    
    while(b != 0)
    {
        ll rem = a % b;
        a = b;
        b = rem;
    }
    
    return a;
}
// TC: O(log(min(a,b)))
// SC: O(1)

ll lcm(ll a, ll b)
{
    if(a == 0 || b == 0)
        return 0;
        
    ll d = gcd(a, b);
    
    return llabs((a / d) * b);
}
// TC: O(log(min(a,b)))
// SC: O(1)

void solve()
{
    ll n, d = 0, l = 1;
    cin >> n;
    
    ll x;
    for(ll i=0;i<n;i++)
    {
        cin >> x;
        d = gcd(d, x);
        l = lcm(l, x);
    }
    
    cout << "GCD : " << d << "  " << "LCM : " << l;
}
// TC: O(n log V) , where V = max∣ai∣
// SC: O(1)

int main()
{
    fastio();
    solve();
}
// TC: O(n log V) , where V = max∣ai∣
// SC: O(1)
