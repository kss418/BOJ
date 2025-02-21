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
constexpr ll MOD = 1e9 + 7;
ll a[MAX], b[MAX], dp[MAX][3];

ll solve(ll cur, ll num){
    ll& ret = dp[cur][num];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret;

    if(!num){
        for(int i = 0;i < 3;i++){
            ret += solve(cur - 1, i) * a[cur];
            ret %= MOD;
        }
    }
    else if(num == 1){
        for(int i = 0;i < 2;i++){
            ret += solve(cur - 1, i) * b[cur - 1];
            ret %= MOD;
        }
        ret += solve(cur - 1, 2) * max(b[cur - 1] - 1, 0ll);
        ret %= MOD;
    }
    else if(num == 2){
        for(int i = 0;i < 3;i++){
            ret += solve(cur - 1, i) * b[cur];
            ret %= MOD;
        }
    }

    return ret %= MOD;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) cin >> b[i];
    dp[0][0] = 1;

    cout << (solve(n, 0) + solve(n, 1)) % MOD;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}