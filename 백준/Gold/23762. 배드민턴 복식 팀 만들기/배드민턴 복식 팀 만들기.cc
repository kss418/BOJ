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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll dp[MAX][4];
pll tr[MAX][4];

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(!cur) return (cnt ? INF : 0);
    if(ret != -1) return ret; ret = INF;

    if(cnt) {
        ll now = solve(cur - 1, cnt - 1);
        if(ret >= now){
            ret = now;
            tr[cur][cnt] = {cur - 1, cnt - 1};
        }
    }
    if(cur >= 4){
        ll now = solve(cur - 4, cnt) + a[cur].x - a[cur - 3].x;
        if(ret >= now){
            ret = now;
            tr[cur][cnt] = {cur - 4, cnt};
        }
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i].x, a[i].y = i - 1;
    sort(a + 1, a + n + 1);

    cout << solve(n, n % 4) << "\n";
    ll cur = n, cnt = n % 4;
    while(cur){
        auto[nxt, nc] = tr[cur][cnt];
        if(nc != cnt) cout << a[cur].y << "\n";
        cur = nxt; cnt = nc;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}