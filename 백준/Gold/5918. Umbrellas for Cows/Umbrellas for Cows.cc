#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll x[MAX], c[101010], dp[MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = INF;

    for(int i = 0;i < cur;i++){
        ret = min(ret, solve(i) + c[x[cur] - x[i + 1] + 1]);
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> x[i];
    for(int i = 1;i <= m;i++) cin >> c[i];
    sort(x + 1, x + n + 1);

    for(int i = m - 1;i >= 1;i--) c[i] = min(c[i], c[i + 1]);
    dp[0] = x[0] = 0;
    cout << solve(n);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}