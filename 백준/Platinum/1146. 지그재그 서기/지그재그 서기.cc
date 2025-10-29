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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 1e6;
ll dp[MAX][2][2], result, c[MAX][MAX];


ll solve(ll cur, ll l, ll r){
    ll& ret = dp[cur][l][r];
    if(ret != -1) return ret; ret = 0;
    if(cur == 1) return ret = (l == 0 && r == 0 ? 1 : 0);

    for(int i = 1;i < cur - 1;i++){
        ll now = solve(i, l, 0) * solve(cur - i - 1, 0, r);
        now *= c[cur - 1][i]; now %= MOD;
        ret += now; ret %= MOD;
    }

    if(l) ret += solve(cur - 1, 0, r); ret %= MOD;
    if(r) ret += solve(cur - 1, l, 0); ret %= MOD;

    return ret %= MOD;
}

void init(){
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= i;j++){
            if(j == 0 || i == j) c[i][j] = 1;
            else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] %= MOD;
        }
    }
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp)); init();
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            result += solve(n, i, j);
            result %= MOD;
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}