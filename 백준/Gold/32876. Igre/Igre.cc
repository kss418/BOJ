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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX][2], p[MAX], ti[MAX], c[MAX];

ll solve(ll cur, ll use, ll cnt){
    if(use < 0) return MINF;
    ll& ret = dp[cur][use][cnt];
    if(ret != INF) return ret; ret = MINF;
    if(!cur) return ret = use ? MINF : 0;

    if(!cnt){
        ret = max(ret, solve(cur - 1, use, 0));
        ret = max(ret, solve(cur - 1, use, 1));
        ret = max(ret, solve(cur, use - 1, 0));
    }
    else{
        ret = max(ret, solve(cur, use - p[cur] - ti[cur], 0) + c[cur]);
        ret = max(ret, solve(cur, use - ti[cur], 1) + c[cur]);
        ret = max(ret, solve(cur, use - 1, 1)); 
    }
 
    return ret;
}

void run(){
    cin >> n >> m; memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> p[i] >> ti[i] >> c[i];

    cout << max(solve(n, m, 0), solve(n, m, 1));
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

