// 1-based Weighted Undirected Graph using Adjacency Matrix 

/*
Eg:
Input:
6 9
1 3 1
1 5 2
2 6 3
3 2 4
3 4 5
3 5 6
3 6 7
4 6 8
5 6 9


Output:
0 0 0 0 0 0 0 
0 0 0 1 0 2 0 
0 0 0 4 0 0 3 
0 1 4 0 5 6 7 
0 0 0 5 0 0 8 
0 2 0 6 0 0 9 
0 0 3 7 8 9 0 

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
    vector<vector<ll>> graph(n+1, vector<ll>(n+1, 0));
    
    for(ll i=0;i < m;i++)
    {
        cin >> u >> v >> wt;
        
        graph[u][v] = wt;
        graph[v][u] = wt; // just neglect this in directed graph 
    }
    
    for(ll i=0;i <= n;i++)
    {
        for(ll j=0;j <= n;j++)
        {
            cout << graph[i][j] << " ";
        }
        
        cout << endl;
    }
}
// TC: O(n^2 + m) = O(n^2)
// SC: O(n^2)

int main()
{
    fastio();
    solve();
}
// TC: O(n^2 + m) = O(n^2)
// SC: O(n^2)
