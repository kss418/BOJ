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
constexpr ll MAX = 16; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[1ll << MAX][MAX], cnt;
ll d1[MAX][MAX], d2[MAX][MAX];

ll solve(ll v, ll st, ll cur){
    ll& ret = dp[v][cur];
    if(ret != -1) return ret; ret = INF;
    if(v == (1ll << n) - 1) return ret = d2[cur][st];

    for(ll nxt = 0;nxt < n;nxt++){
        if(v & (1ll << nxt)) continue;
        ll nv = v | (1ll << nxt);
        ret = min(ret, solve(nv, st, nxt) + d1[cur][nxt]);
    }

    return ret;
}

void run(){
    cin >> n >> s;
    ll result = INF; memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < s.size() / n;k++){
                ll ci = k * n + i;
                ll ni = k * n + j;
                if(s[ci] != s[ni]) d1[i][j]++;
            }
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 1;k < s.size() / n;k++){
                ll ci = (k - 1) * n + i;
                ll ni = k * n + j;
                if(s[ci] != s[ni]) d2[i][j]++;
            }

            d2[i][j]++;
        }
    }

    for(int i = 0;i < n;i++){
        memset(dp, -1, sizeof(dp));
        result = min(result, solve(1ll << i, i, i));
    }

    cout << "Case #" << ++cnt << ": " << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

