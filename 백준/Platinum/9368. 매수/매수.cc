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
constexpr ll MAX = 16; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ld dp[1ll << MAX][16], result;

ld solve(ll cur, ll cnt){
    ld& ret = dp[cur][cnt];
    if(ret > -0.5) return ret; ret = 0;

    ll sum = 0;
    for(int i = 0;i < n;i++){
        if(!(cur & (1ll << i))) continue;
        sum += a[i].x;
    }

    if(sum > k) return ret = 0;
    if(cnt == m) return ret = 1;

    for(int i = 0;i < n;i++){
        if(cur & (1ll << i)) continue;
        ll nxt = cur ^ (1ll << i);

        ld now = solve(nxt, cnt) * (100 - a[i].y) / (ld)100;
        now += solve(nxt, cnt + 1) * a[i].y / (ld)100;

        ret = max(ret, now);   
    }

    return ret;
}

void run(){
    cin >> n >> m >> k; memset(dp, -2, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> a[i].x >> a[i].y;

    cout.precision(20);
    cout << solve(0, 0) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}