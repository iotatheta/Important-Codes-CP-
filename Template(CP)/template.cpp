#include <bits/stdc++.h>
using namespace std;

// ----------- FAST IO -------------
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

// -------------- MACROS ---------------
#define ll long long
#define abs llabs
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll N1 = 1e6;

//--------PREFIX SUM-------------
// 1D prefix
vector<ll> prefixSum(vector<ll>& nums) 
{
    int n=nums.size();
    vector<ll> prefix(n+1,0);
    for(int i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+nums[i-1];
    }    
    return prefix;
}

// 2D prefix
vector<vector<ll>> prefixSum2D(vector<vector<ll>>& matrix)
{
    ll n=matrix.size(),m=matrix[0].size();
    vector<vector<ll>> prefix(n+1,vector<ll>(m+1,0));
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
        prefix[i][j]=matrix[i-1][j-1]+prefix[i-1][j]+
                    prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    return prefix;
}
 
// -------- NUMBER THEORY --------------

// GCD
ll gcd(ll a, ll b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

// LCM
ll lcm(ll a, ll b) 
{
    return (a / gcd(a, b)) * b;
}

// Binary Exponentiation
ll power(ll a,ll b,ll mod = MOD)
{
    if(b == 0)
        return 1;
        
    a = a % mod;
    ll res = 1;
    while(b > 0)
    {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res % mod;
}
// Fermat's Little Theorem : a^-1 = a^(m-2) (mod m)
ll inverse(ll a)
{
    return power(a,MOD - 2);
}
// --------- COMBINATORICS -------------
vector<ll> fact(N1+1), invfact(N1+1);
void precomputeFact() 
{
    fact[0] = 1;
    for (int i = 1; i <= N1; i++)
        fact[i] = (fact[i-1] * i) % MOD;

    invfact[N1] = inverse(fact[N1]);
    for (int i = N1; i > 0; i--)
        invfact[i-1] = (invfact[i] * i) % MOD;
}

//nCr
ll C(ll n,ll r,ll mod = 1e9 + 7)
{
    if (r < 0 || r > n) return 0;
    ll res = 1;
    for(ll i=1;i<=r;i++)
    {
        res = (((res * (n - i + 1)) % mod) * inverse(i)) % mod;
    }
    return res % mod;
}
// ll C(ll n, ll r) {
//     if (r < 0 || r > n) return 0;
//     return (((fact[n] * invfact[r]) % mod) * invfact[n-r]) % mod;
// }
// nPr
ll P(ll n, ll r) 
{
    if (r < 0 || r > n) return 0;
    return (fact[n] * invfact[n-r]) % MOD;
}

// ------ PRIME / SIEVE ------------
vector<bool> isprime(N1+1, true);

void sieve() 
{
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= N1; i++) 
    {
        if (isprime[i]) 
        {
            for (int j = i * i; j <= N1; j += i)
                isprime[j] = false;
        }
    }
    // odd sieve
    /*
        for(int i=4;i<=N;i+=2)
        {
            isprime[i] = false;
        }
        for(int i=3;i*i<=N;i+=2)
        {
            if(isprime[i])
            {
                for(int j=i*i;j<=N;j+=2*i)
                {
                    isprime[i] = false;
                }
            }
        }
    */
}

// ------- BINARY SEARCH HELPERS ----------
template <class T>
ll lowerbound(vector<T> &a, T x) 
{
    return lower_bound(a.begin(), a.end(), x) - a.begin();
} // returns index

template <class T>
ll upperbound(vector<T> &a, T x) 
{
    return upper_bound(a.begin(), a.end(), x) - a.begin();
} // returns index

// -------------- DSU -------------

class DisjointSet 
{
    vector<ll> rank, parent, size;
public:
    DisjointSet(ll n) 
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (ll i = 0; i <= n; i++) 
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    ll findUPar(ll node) 
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(ll u, ll v) 
    {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) 
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) 
        {
            parent[ulp_v] = ulp_u;
        }
        else 
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(ll u, ll v) 
    {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) 
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else 
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
// ------------- BITS ---------------
bool isOdd(ll num) { return ((num & 1) == 1); }
bool isEven(ll num) { return ((num & 1) == 0); }
                                      
bool checkIthBit(ll n, ll i) 
{
    return (n & (1LL << i)) != 0;  
}

ll setIthBit(ll n, ll i) 
{
    return n | (1LL << i);
}
   
ll clearIthBit(ll n,ll i) 
{
    return n & ~(1LL << i);
}

ll toggleIthBit(ll n,ll i) 
{
    return n ^ (1LL << i);
}
 
ll removeLastSetBit(ll n) 
{
    return n & (n - 1);
}

ll getRightMostSetBit(ll n) 
{
    return n & -n;
}
 
ll countSetBits(ll n)  
{
    int count = 0;
    while (n) 
    {
        n &= (n - 1); 
        count++;  
    }
    return count;
}

bool isPowerOfTwo(ll n) 
{
    return n > 0 && (n & (n - 1)) == 0;  
}

ll XORtillN(ll n) 
{
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n+1;
    if(n % 4 == 3) return 0;
    return n;
}

ll findRangeXOR(ll l, ll r) 
{			
	return XORtillN(r) ^ XORtillN(l-1);
} // l ans r included

// ---------- CUSTOM COMPARE -----------
// for priority queue
class Compare 
{
public:
    bool operator()(ll a,ll b)
    {
        return a < b; // for max heap
    }
};

// ------------- STL ---------------

void stl() {
// stoi(string) - to convert string to number 
// next_permutation(v.begin(), v.end())
// prev_permutation(v.begin(), v.end());
// *max_element(v.begin(), v.end());
// *min_element(v.begin(), v.end());
// accumulate(v.begin(), v.end(), 0LL);
// binary_search(v.begin(), v.end(), x);
// log2(x & -x) - to calculate trailing zeros in bit
// s.substr(i,len) - i+...+(i+len-1)
// sort(v.begin(),v.end(),[&](int& a,int& b){           string s1 = to_string(a);                        string s2 = to_string(b);                        return s1+s2 > s2+s1;                           }); - custom sorting
// a.find(b)!=string::npos-check if b is present in a
// log(a)+log(b) = log(ab)
// hash[256] and hash[ch] - for lower and upper char.       also can be implemeted using lower[26],upper[26]
// use map when unordered_map fails
// in unordered_map we can't use pair as key (instead use string as ("key,value")) , but can use pair in value section
// always use double in tabulation (dp)

//  vector<string> words;                              string word;                                     stringstream ss(s);                              while (ss >> word) {                                  words.push_back(word);                           word.back(); - return the last char          } - technique to extract words

//  find(data.begin(), data.end(), k) != data.end() - used for if vector (data) contains k 

//  string s;                                   getline(cin,s); - to input a complete sentence
//  s.pop_back();

//  string line, text = "";                          while (getline(cin, line)){                          text += line + '\n';                          } - to take multiple lines string input

//  v.insert(v.begin() + index, value);              v.erase(v.begin() + index);                      s.rbegin() - for reverse begin

// partial_sum(first.begin(),first.end(),result.begin()); - to compute prefix sum
// cout<<fixed<<setprecision(12)<<ans; - to set precision in values in double(ans) 
// *lower_bound(a.begin(), a.end(), x); - > returns the element 
// lower_bound(a.begin(), a.end(), x) - a.begin(); -> returns the index
}
void advice()
{
// don't skip the input (complete the input i.e all cin )
// out of bound access
// divide by 0
// integer overflow
// infinite loop
// forgetting to sort
// forgetting to reset variables for multi-test case
// using int in place of long long
// use prefix sum and precomputation when required
// double gives precesion error
// don't forget to move the iterator
// dry run all possible answers at every step
// use as much less ( % ) as possible
// +,- = very cheap; * = cheap; /,% = expensive
// always delare global variables with (const)
// If there is increasing and decreasing simultaneously then try to make it monotonic
// If there is (mod) then think (Pigeonhole Principle) as it's possibily
// When the answer becomes impossible just look at the constrains
// don't forget to write (divisor[0] = 0), it is very important
// No of integers <= n and divisible by m is given by (n / m)
// don't use stars and bars for different objects
// use precomputation inside the function for variable n in leetcode
// when there is probelm in sum there is prefix sum
// always use res += ch; for adding char as after +, char is converted to int, where res is string
// in (reverse) stl the ending pointer should be after the required index
// when feel a problem rewrite immediately
// instead of sorting an unordered_map use map which is already sorted
// use sieve for spf(smallest prime factor) and spf for prime factorization
// i*i is only applicable for prime sieve not others
// use N = 1e7 for high values
// c++ do not follow BODMAS
}

void solve()
{
    
}

int main() 
{
    fastio();   

    // precomputeFact();   // for combinatorics
    // sieve();  // optional (only if needed)

    int t;
    cin >> t;
    while (t--) 
    {
        solve();
    }
    return 0;
}