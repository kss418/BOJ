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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll p[MAX], a[MAX], c[MAX];
ll dp[MAX][30101], use[MAX][30101];
vector <ll> track;

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret = 1;

    for(int i = 0;i <= 100;i++){
        if(cnt < i * c[cur]) break;
        ll now = solve(cur - 1, cnt - i * c[cur]) * min(p[cur] + i * a[cur], 100ll);
        if(now < ret) continue;
        ret = now; use[cur][cnt] = i;
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> p[i] >> a[i] >> c[i];
    cout << solve(n, m) << "\n";

    for(int i = n;i >= 1;i--){
        ll now = use[i][m];
        track.push_back(now);
        m -= now * c[i];
    }

    reverse(all(track));
    for(auto& i : track) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}