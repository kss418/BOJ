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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], dp[MAX][1ll << 16];

ll solve(ll cur, ll sum, ll v){
    ll& ret = dp[sum][v];
    if(ret != -1) return ret; ret = 0; 
    if(v == (1ll << n) - 1) return ret = b[sum];


    for(ll nxt = 0;nxt < n;nxt++){
        if(v & (1ll << nxt)) continue;
        ll nv = v | (1ll << nxt);
        ret = max(ret, solve(nxt, a[nxt], nv) + b[sum]);
        
        ll ns = sum + a[nxt];
        if(ns > m){
            ret = max(ret, solve(nxt, ns - m, nv) + b[m]);
        }
        else{
            ret = max(ret, solve(nxt, ns, nv) + b[0]);
        }
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i <= m;i++) cin >> b[i];

    ll result = 0;
    for(int i = 0;i < n;i++){
        result = max(result, solve(i, a[i], 1ll << i));
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

