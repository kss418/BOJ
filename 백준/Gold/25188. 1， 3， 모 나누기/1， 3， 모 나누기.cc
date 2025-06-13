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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][7], sum[MAX];

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != INF) return ret; ret = MINF;
    if(!cnt) return ret = (cur ? MINF : 0);

    for(int i = 0;i <= cur;i++){
        ret = max(ret, solve(i, cnt - 1) + (cnt % 2 ? sum[cur] - sum[i] : 0));
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];

    cout << solve(n, 6);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

