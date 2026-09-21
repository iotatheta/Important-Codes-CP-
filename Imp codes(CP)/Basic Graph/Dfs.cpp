// DFS = Depth First Search 

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

void print_graph(const vector<vector<ll>>& graph, ll n)
{
    for(ll i=1;i<=n;i++)
    {
        cout << i << " -> ";
        
        for(const auto &nbr : graph[i])
        {
            cout << nbr << " ";
        }
        
        cout << endl;
    }
}

void dfs(const vector<vector<ll>>& graph, vector<bool>& vis, ll node)
{
    vis[node] = true;
    
    for(const auto &nbr : graph[node])
    {
        if(!vis[nbr])
        {
            dfs(graph, vis, nbr);
        }
    }
    
}
// TC: O(degree(node)) per call, O(n + 2m) over the complete DFS
// SC: O(n) worst-case recursion stack

void solve()
{
    ll n, m;
    cin >> n >> m;
    
    ll u, v;
    vector<vector<ll>> graph(n+1);  // same as vector<ll> graph[n+1];
    
    for(ll i=0;i < m;i++)
    {
        cin >> u >> v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    print_graph(graph, n); // Just for looking the graph
    
    vector<bool> vis(n+1, false);
    
    for(ll i=1;i <= n;i++)
    {
        if(!vis[i])
        {
            dfs(graph, vis, i);
        }
    }
    
    // Just to see if all nodes are visited
    for(ll i=1;i <= n;i++)
    {
        cout << vis[i] << " ";
    }
}
// TC: O(n + 2m)
// SC: O(n + 2m)

int main()
{
    fastio();
    solve();
}
// TC: O(n + 2m)
// SC: O(n + 2m)
