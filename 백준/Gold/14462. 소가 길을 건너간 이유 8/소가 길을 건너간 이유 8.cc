#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], dp[MAX][MAX];

ll solve(ll l, ll r){
    ll& ret = dp[l][r];
    if(ret != -1) return ret; ret = 0;
    if(!l || !r) return ret;

    ret = max(ret, solve(l - 1, r));
    ret = max(ret, solve(l, r - 1));
    ret = max(ret, solve(l - 1, r - 1) + (abs(a[l] - b[r]) <= 4));

    return ret; 
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    memset(dp, -1, sizeof(dp));

    cout << solve(n, n);
}  

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}