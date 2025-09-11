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
constexpr ll MAX = 4010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
ld dp[MAX][33];

ld solve(ll cur, ll cnt){
    ld& ret = dp[cur][cnt];
    if(ret > -0.5) return ret; ret = 1e12;
    if(!cur) return ret = 0;
    if(!cnt) return ret;

    ll sum = a[cur], p = a[cur] * a[cur];
    for(int i = cur - 1;i >= 0;i--){
        ld avg = (ld)sum / (ld)(cur - i);
        ld now = (cur - i) * avg * avg - 2 * avg * sum + p;
        ret = min(ret, solve(i, cnt - 1) + now);
        sum += a[i]; p += a[i] * a[i];
    }

    return ret;
}


void run(){
    cin >> n >> m; memset(dp, -2, sizeof(dp));
    for(int i = 1;i <= m;i++) cin >> a[i];
    cout.precision(12);
    cout << solve(m, n);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}