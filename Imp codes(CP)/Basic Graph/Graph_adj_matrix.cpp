// 1-based Undirected Graph using Adjacency Matrix 

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
0 0 0 0 0 0 0 
0 0 0 1 0 1 0 
0 0 0 1 0 0 1 
0 1 1 0 1 1 1 
0 0 0 1 0 0 1 
0 1 0 1 0 0 1 
0 0 1 1 1 1 0 

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
    vector<vector<ll>> graph(n+1, vector<ll>(n+1, 0));
    
    for(ll i=0;i < m;i++)
    {
        cin >> v1 >> v2;
        
        graph[v1][v2] = 1;
        graph[v2][v1] = 1; // Just neglect this in directed graph
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
