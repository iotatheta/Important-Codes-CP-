// 1-based Weighted Undirected Graph Representation using Adjacency List 

/*
Eg:
Input:
6 9
1 3
1 5
2 6
3 2
3 4
3 5
3 6
4 6
5 6

Output:
1 -> {3, 1} {5, 2} 
2 -> {6, 3} {3, 4} 
3 -> {1, 1} {2, 4} {4, 5} {5, 6} {6, 7} 
4 -> {3, 5} {6, 8} 
5 -> {1, 2} {3, 6} {6, 9} 
6 -> {2, 3} {3, 7} {4, 8} {5, 9} 

*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

void solve()
{
    ll n, m;
    cin >> n >> m;
    
    ll u, v, wt;
    vector<pair<ll, ll>> graph[n+1];
    
    for(ll i=0;i < m;i++)
    {
        cin >> u >> v >> wt;
        
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt}); // Just neglect this for directed graph
    }
    
    for(ll i=1;i <= n;i++)
    {
        cout << i << " -> ";
        
        for(const auto &nbr : graph[i])
        {
            cout << "{" << nbr.first << ", " << nbr.second << "} ";
        }
        
        cout << endl;
    }
}
// TC: O(n + m)
// SC: O(n + m)

int main()
{
    fastio();
    solve();
}
// TC: O(n + m)
// SC: O(n + m)
