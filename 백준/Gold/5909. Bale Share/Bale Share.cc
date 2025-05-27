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
constexpr ll MAX = 22; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll arr[MAX], all;
char dp[MAX][2010][2010];

char solve(ll cur, ll a, ll b){
    char& ret = dp[cur][a][b];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret;

    if(a >= arr[cur]) ret = max(ret, solve(cur - 1, a - arr[cur], b));
    if(b >= arr[cur]) ret = max(ret, solve(cur - 1, a, b - arr[cur]));
    ret = max(ret, solve(cur - 1, a, b));

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> arr[i], all += arr[i];

    ll result = INF; dp[0][0][0] = 1;
    for(int i = 0;i < 2010;i++){
        for(int j = 0;j <= i;j++){
            ll now = all - i - j;
            if(now > j) continue;
            if(!solve(n, i, j)) continue;
            result = min<ll>(result, i);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}