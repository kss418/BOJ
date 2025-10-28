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
constexpr ll MAX = 22; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX][MAX];

ll solve(ll cur, ll l, ll r){
    ll& ret = dp[cur][l][r];
    if(ret != -1) return ret; ret = 0;
    if(cur == n) return (ret = (l == m && r == k ? 1 : 0));

    ret += solve(cur + 1, l, r + 1);
    ret += solve(cur + 1, l + 1, r);
    ret += max(n - cur - 1, 0ll) * solve(cur + 1, l, r);

    return ret;
}

void run(){
    cin >> n >> m >> k; memset(dp, -1, sizeof(dp));
    cout << solve(1, 1, 1) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}