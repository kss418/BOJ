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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[1010101], a[MAX];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++){
        if(a[i] != 1) dp[a[i]] = max(dp[a[i]], dp[1] + 1);
        for(int j = 2;j * j <= a[i];j++){
            if(a[i] % j) continue;
            dp[a[i]] = max(dp[a[i]], dp[j] + 1);
            dp[a[i]] = max(dp[a[i]], dp[a[i] / j] + 1);
        }

        dp[a[i]] = max(dp[a[i]], 1ll);
    }

    ll result = 0;
    for(int i = 1;i < 1010101;i++) result = max(result, dp[i]);

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}