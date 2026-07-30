// Product 1 Modulo N
/*
Given an integer n, find the longest subsequence of [1,2,…,n−1] whose product is 1 modulo n
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define endl '\n'

ll gcd(ll a,ll b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
} 
// TC: O(log(min(a,b))) , SC: O(log(min(a,b))) (recursive stack)

void solve()
{
    ll n,prod=1;
    cin>>n;
    vector<ll> res;
    for(ll i=1;i<=n-1;i++)
    {
        if(gcd(i,n) == 1)
        {
            prod = (prod * i) % n;
            res.push_back(i);
        }
    }
    if(prod != 1)
        res.pop_back();
    
    cout<<res.size()<<endl;
    for(ll i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
} 
// TC: O(n log n) , SC: O(φ(n)) (for storing the coprime numbers)

int main()
{
    fastio();
    solve();
} 
// TC: O(n log n) , SC: O(φ(n))