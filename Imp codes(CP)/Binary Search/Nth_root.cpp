// Nth Root 

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

double eps = 1e-10; // epsilon
// eps = 1 for normal BS
// in most qn (eps = 1e-6)

double power(double a, ll b)
{
    if(b == 0)
        return 1.0;
        
    double res = 1.0;
    
    while(b > 0)
    {
        if(b & 1)
            res = 1.0 * res * a;
        a = 1.0 * a * a;
        b = b >> 1;
    }
    
    return res;
}
// TC = O(log n) 
// SC=O(1)

bool check(double root, ll n, double x)
{
    return power(root, n) <= x;
}
// TC: O(log n)
// SC: O(1)

double nth_root(double x, ll n)
{
    double low = 0.0 , high = x, mid;
    
    while(high - low > eps)
    {
        mid = low + (high - low) / 2;
        
        if(check(mid, n, x))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    
    return low;
}
// TC: O(log((x - 0) / eps) * log n)
// SC: O(1)

void solve()
{
    double x;
    ll n;
    cin >> x >> n;
    
    cout << fixed << setprecision(10) << nth_root(x, n) << endl;
    
    cout << pow(x, 1.0 / n) ;
}
// TC: O(log((x - 0) / eps) * log n)
// SC: O(1)

int main()
{
    fastio();
    solve();
}
// TC: O(log((x - 0) / eps) * log n)
// SC: O(1)
