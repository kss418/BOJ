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
ll dp[MAX][1ll << MAX];
string st[MAX];

ll solve(ll cur, ll v){
    ll& ret = dp[cur][v];
    if(ret != -1) return ret; ret = INF;

    ll cnt = 0;
    for(int i = 0;i < 9;i++){
        if(v & (1ll << i)) cnt++;
    }
    if(cnt % 2) return ret = INF;

    if(cur == 2 || cur == 5 || cur == 8){
        for(int i = 0;i < 3;i++){
            ll now = 0;
            for(int j = 0;j < 3;j++){
                ll idx = 3 * i + j;
                now += (v & (1ll << idx) ? 1 : 0);
            }
            
            if(now % 2) return ret = INF;
        }
    }

    if(cur == 8){
        for(int i = 0;i < 9;i++){
            ll now = 0;
            now += (v & (1ll << i) ? 1 : 0);
            if(now % 2) return ret = INF;
        }

        return ret = 0;
    }

    for(int i = 0;i < (1ll << 9);i++){
        ll diff = (v ^ i), cnt = 0;
        for(int j = 0;j < 9;j++){
            if(st[j][cur + 1] - '0' != (diff & (1ll << j) ? 1 : 0)) cnt++;
        }

        ret = min(ret, solve(cur + 1, i) + cnt);
    }

    return ret;
}

void run(){
    for(int i = 0;i < 9;i++) cin >> st[i];
    ll result = INF; memset(dp, -1, sizeof(dp));

    for(int i = 0;i < (1ll << 9);i++){
        ll cnt = 0;
        for(int j = 0;j < 9;j++){
            if(st[j][0] - '0' != (i & (1ll << j) ? 1 : 0)) cnt++;
        }
        result = min(result, solve(0, i) + cnt);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

