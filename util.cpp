#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 9000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;
#define PI 3.14159265359
#define endl '\n'
#define itn int
#define cout1(a) cout << a << endl
#define cout2(a, b) cout << a << ' ' << b << endl
#define cout3(a, b, c) cout << a << " " << b << " " << c << endl
#define cout4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
typedef priority_queue<pair<pll, pll>, vector<pair<pll, pll>>, greater<pair<pll, pll>>> pqset;
typedef priority_queue<pll, vector<pll>, greater<pll>> pqset_ll;
#define pb push_back
#define pf push_front
#define fi first
#define mkp make_pair
#define se second

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
typedef tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> os_pair;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repeat(i, start, n) for (ll i = (ll)start; i < (ll)n; i++)
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
ll max(int a, ll b)
{
    return max((ll)a, b);
}
ll min(int a, ll b) { return min((ll)a, b); }
ll min(ll a, int b) { return min(a, (ll)b); }
ll max(ll a, int b) { return max(a, (ll)b); }
ll power(ll a, ll b)
{
    if (a == 1 || b == 0)
        return 1;
    ll c = power(a, b / 2);
    ll res = 1;
    res = c * c;
    if (res >= mod)
        res %= mod;
    if (b % 2)
        res *= a;
    if (res >= mod)
        res %= mod;
    return res;
}
ll power(ll a, ll b, ll mod1)
{
    if (a == 1 || b == 0)
        return 1;
    ll c = power(a, b / 2, mod1);
    ll res = 1;
    res = c * c;
    if (res >= mod1)
        res %= mod1;
    if (b % 2)
        res *= a;
    if (res >= mod1)
        res %= mod1;
    return res;
}
ll modInv(ll a)
{
    return power(a, mod - 2);
}
ll fact[1], inv[1];
void factorial(ll n)
{
    fact[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i;
        if (fact[i] >= mod)
            fact[i] %= mod;
    }
}
void InvFactorial(ll n)
{
    inv[0] = 1;
    for (ll i = 1; i <= n; i++)
        inv[i] = modInv(fact[i]);
}
ll ncr(ll n, ll r)
{
    if (n < r || n < 0 || r < 0)
        return 0;
    ll b = inv[n - r];
    ll c = inv[r];
    ll a = fact[n] * b;
    if (a >= mod)
        a %= mod;
    a *= c;
    if (a >= mod)
        a %= mod;
    return a;
}
bool prime[1];
vector<ll> primes;
void remove_duplicates(vector<pair<int, pint>> &v)
{
    sort(v.begin(), v.end());
    int _size = unique(v.begin(), v.end()) - v.begin();
    v.resize(_size);
}
unsigned int gcd(unsigned int u, unsigned int v)
{
    if (u == 0 || v == 0)
        return max(u, v);
    unsigned int shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do
    {
        v >>= __builtin_ctz(v);
        if (u > v)
            swap(u, v);
        v -= u;
    } while (v != 0);
    return u << shift;
}
void sieve(ll n)
{
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (ll p = 2; p * p <= n; p++)
        if (prime[p])
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
    repeat(i, 2, n + 1) if (prime[i]) primes.pb(i);
}
struct custom_hash
{ // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<int64_t, int64_t> Y) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};