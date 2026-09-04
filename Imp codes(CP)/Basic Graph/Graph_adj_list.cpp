// 1-based Undirected Graph Representation using Adjacency List 

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
1 -> 3 5 
2 -> 6 3 
3 -> 1 2 4 5 6 
4 -> 3 6 
5 -> 1 3 6 
6 -> 2 3 4 5 

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
    
    ll v1, v2;
    vector<ll> graph[n+1];
    
    for(ll i=0;i < m;i++)
    {
        cin >> v1 >> v2;
        
        graph[v1].push_back(v2);
        graph[v2].push_back(v1); // Just neglect this for directed graph
    }
    
    for(ll i=1;i <= n;i++)
    {
        cout << i << " -> ";
        
        for(const auto &nbr : graph[i])
        {
            cout << nbr << " ";
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
