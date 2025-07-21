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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][61], result;

void run(){
    cin >> n; memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i], dp[i][a[i]] = i;

    for(int i = 1;i <= 60;i++){
        for(int j = 1;j <= n;j++){
            if(dp[j][i] >= n) continue;
            ll mid = dp[j][i] + 1;
            ll end = dp[mid][i];
            if(end > n) continue;
            dp[j][i + 1] = end;
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 60;j++){
            if(dp[i][j] > n) continue;
            result = max<ll>(result, j);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}