// Bit Manipulation operations

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define endl '\n'


bool isOdd(const ll &num)
{
    return num & 1LL;
}
// TC=O(1) 
// SC=O(1)

bool isEven(const ll &num) 
{ 
    return !(num & 1LL); 
}
// TC=O(1)
// SC=O(1)
                                      
bool checkIthBit(const ll &n, const ll &i) 
{
    return (n & (1LL << i)) != 0;  
}
// TC=O(1) 
// SC=O(1)

ll setIthBit(const ll &n, const ll &i) 
{
    return n | (1LL << i);
}
// TC=O(1)
// SC=O(1)
   
ll clearIthBit(const ll &n, const ll &i) 
{
    return n & ~(1LL << i);
}
// TC=O(1)
// SC=O(1)

ll toggleIthBit(const ll &n, const ll &i) 
{
    return n ^ (1LL << i);
}
// TC=O(1)
// SC=O(1)
 
ll removeLastSetBit(const ll &n) 
{
    return n & (n - 1);
}
// TC=O(1)
// SC=O(1)

ll getRightMostSetBit(const ll &n) 
{
    return n & (~n + 1); // -n = (~n + 1)
}
// TC=O(1)
// SC=O(1)
 
ll countSetBits(ll n)  
{
    int count = 0;
    while (n)  
    {
        n = n & (n - 1); 
        count++;  
    }
    return count;
} // __builtin_popcountll(x); [recommended]
// TC: O(k), where k = number of set bits
//     For long long: O(64) = O(1)
// SC: O(1)

bool isPowerOfTwo(const ll &n) 
{
    return n > 0 && (n & (n - 1)) == 0;  
}
// TC=O(1)
// SC=O(1)

ll XORtillN(const ll &n) 
{
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n+1;
    if(n % 4 == 3) return 0;
    return n;
}
// TC=O(1)
// SC=O(1)

ll findRangeXOR(const ll &l, const ll &r) 
{			
	return XORtillN(r) ^ XORtillN(l-1);
} // l ans r included
// TC=O(1)
// SC=O(1)

void solve()
{
    // Some Code
}

int main()
{
    fastio();
    solve();
}