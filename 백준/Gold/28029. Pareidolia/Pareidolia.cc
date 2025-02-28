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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
pll dp[MAX][6];
string bessie = "bessie";

void run(){
    cin >> s; n = s.size();
    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < 6;j++) dp[i][j] = {MINF, 0};
    }
    dp[0][0] = {0, 0};

    for(int i = 0;i < n;i++){
        for(int j = 0;j < 6;j++){
            pll pre = dp[i][j];
            dp[i + 1][j] = max(dp[i + 1][j], {pre.x, pre.y - (j ? a[i] : 0)});
            if(bessie[j] == s[i]){
                ll nxt = (j + 1) % 6;
                dp[i + 1][nxt] = max(dp[i + 1][nxt], {pre.x + 1, pre.y});
            }
        }
    }

    pll result = {MINF, 0};
    for(int i = 0;i < 6;i++) result = max(result, {dp[n][i].x / 6, dp[n][i].y});
    cout << result.x << "\n" << -result.y;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}