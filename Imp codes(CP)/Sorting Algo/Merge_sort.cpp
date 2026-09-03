// Merge Sort [VVI.]

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long

void merge(vector<ll>& arr, vector<ll>& temp, ll low, ll mid, ll high)
{
    ll i = low, j = mid + 1, k = low;
    
    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while(j <= high)
    {
        temp[k++] = arr[j++];
    }
    
    for(ll i=low;i<=high;i++)
    {
        arr[i] = temp[i];
    }
}
// TC: O(high - low + 1)
// SC: O(1) auxiliary excluding temp

void merge_sort(vector<ll>& arr, vector<ll>& temp, ll low, ll high)
{
    if(low >= high)
        return;
    
    ll mid = low + (high - low) / 2;
    
    merge_sort(arr, temp, low, mid);
    merge_sort(arr, temp, mid + 1, high);
    merge(arr, temp, low, mid, high);
}
// TC: O(n log n)
// SC: O(log n) recursion stack

void solve()
{
    ll n;
    cin >> n;
    
    vector<ll> arr(n), temp(n);
    
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    merge_sort(arr, temp, 0, n-1);
    
    for(ll i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
}
// TC: O(n log n)
// SC: O(n)

int main()
{
    fastio();
    solve();
}
// TC: O(n log n)
// SC: O(n)
