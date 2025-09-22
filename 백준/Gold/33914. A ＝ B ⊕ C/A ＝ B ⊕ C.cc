#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 1e9 + 7;
ll dp[MAX][MAX];

ll solve(ll c1, ll c0){
    if(c1 < 0 || c0 < 0) return 0;
    ll& ret = dp[c1][c0];
    if(ret != -1) return ret; ret = 0;
    if(!c1 && !c0) return ret = 1;

    ret += 3 * solve(c1 - 2, c0 - 1); ret %= MOD;
    ret += solve(c1, c0 - 3); ret %= MOD;

    return ret %= MOD;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    cout << solve(n, m);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}