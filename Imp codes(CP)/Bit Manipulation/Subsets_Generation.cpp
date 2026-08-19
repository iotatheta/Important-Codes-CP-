// Standard boilerplate to process all subsets of a string or array or whatever

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'

// Generate all subsets of a string
vector<string> subsets_generator(const string &str)
{
    ll n = str.size();

    vector<string> res;

    ll total_subsets = (1LL << n);

    for(ll mask = 0; mask < total_subsets; mask++)
    {
        string subset;

        for(ll i = 0; i < n; i++)
        {
            if(mask & (1LL << i))
            {
                subset += str[i];
            }
        }

        res.push_back(subset);
    }

    return res;
}
// TC: O(n * 2^n)
// SC: O(n * 2^n)

void solve()
{
    string str;
    cin >> str;
    
    auto res = subsets_generator(str);
    
    for(const auto &ele : res)
    {
        cout << "[" << ele << "]" << endl;
    }
}

int main()
{
    fastio();
    solve();
}