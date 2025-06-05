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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], dp[MAX][MAX][2];
ll y, x;

ll solve(ll cy, ll cx, ll cnt){
    ll& ret = dp[cy][cx][cnt];
    if(ret != INF) return ret; ret = MINF;
    if(cy == y && cx == x && !cnt) return ret;
    if(!cy || !cx) return ret;

    ret = max(ret, solve(cy - 1, cx, cnt) + a[cy][cx]);
    ret = max(ret, solve(cy, cx - 1, cnt) + a[cy][cx]);

    if(cy == y && cx == x && cnt){
        ret = max(ret, solve(cy - 1, cx, 0) + a[cy][cx]);
        ret = max(ret, solve(cy, cx - 1, 0) + a[cy][cx]);
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    cin >> y >> x; dp[1][1][0] = a[1][1];
    cout << solve(n, n, 1) << " " << solve(n, n, 0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}