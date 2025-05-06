#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll dp[MAX][MAX];

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = INF;
    if(cur == 1) return ret = 0;

    for(int i = 0;i <= cnt;i++){
        if(cur - i - 1 < 1) break;
        ll d = abs(a[cur].x - a[cur - i - 1].x) + abs(a[cur].y - a[cur - i - 1].y);
        ret = min(ret, solve(cur - i - 1, cnt - i) + d);
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    cout << solve(n, m);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}