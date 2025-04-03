#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[2 * MAX], dp[2 * MAX][2], sum[2 * MAX];

ll q(ll s, ll e){
    if(s <= 0) return sum[e];
    return sum[e] - sum[s - 1];
}

ll solve(ll cur, ll cnt){
    if(cur <= 0) return 0;
    ll& ret = dp[cur][cnt];
    if(ret != INF) return ret; ret = MINF;
    if(cnt){
        ret = max(ret, solve(cur - 1, 1) + a[cur]);
        ret = max(ret, solve(cur - m, 1) + q(cur - m + 1, cur));
        ret = max(ret, solve(cur - m, 0) + q(cur - m + 1, cur));
    }
    else ret = max({ret, solve(cur - 1, 0), solve(cur - 1, 1)});

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n + m;i++) sum[i] = sum[i - 1] + a[i];

    cout << max(solve(n + m - 1, 1), solve(n + m - 1, 0));
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

