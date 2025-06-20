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
ll a[MAX], pre[MAX], suf[MAX], dp[MAX][2];

ll solve1(ll cur){
    if(cur < 0) return INF;

    ll& ret = dp[cur][0];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret = 0;

    for(int i = 1;i <= 3;i++){
        ret = min(ret, solve1(cur - i) + 1);
    }

    if(pre[cur] >= m) ret = min(ret, solve1(cur - m) + 1);
    return ret;
}

ll solve2(ll cur){
    if(cur > n + 1) return INF;

    ll& ret = dp[cur][1];
    if(ret != -1) return ret; ret = INF;
    if(cur == n + 1) return ret = 0;

    for(int i = 1;i <= 3;i++){
        ret = min(ret, solve2(cur + i) + 1);
    }

    if(suf[cur] >= m) ret = min(ret, solve2(cur + m) + 1);
    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];

    a[0] = MINF; a[n + 1] = INF;
    for(int i = 1;i <= n;i++){
        if(abs(a[i] - a[i - 1]) == 1) pre[i] = pre[i - 1] + 1;
        else pre[i] = 1;
    }

    for(int i = n;i >= 1;i--){
        if(abs(a[i] - a[i + 1]) == 1) suf[i] = suf[i + 1] + 1;
        else suf[i] = 1;
    }

    ll result = INF;
    for(int i = 1;i <= n + 1;i++){
        result = min(result, solve1(i - 1) + solve2(i));
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

