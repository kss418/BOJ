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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], dp[MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret = 0;

    ll wm = a[cur], em = b[cur];
    for(int i = cur - 1;i >= 0;i--){    
        ret = min(ret, solve(i) + wm * em);
        wm = max(wm, a[i]); em = max(em, b[i]);
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    cout << solve(n);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}