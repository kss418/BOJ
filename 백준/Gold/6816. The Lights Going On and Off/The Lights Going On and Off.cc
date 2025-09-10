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
constexpr ll MAX = 33; // SET MAX SIZE
constexpr ll MOD = 998244353;
bool dp[MAX][1ll << 8];
ll a[MAX];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < m;j++){
            ll x; cin >> x;
            a[i] += (x << j);
        }
    }

    dp[1][a[1]] = 1;
    for(int i = 2;i <= n;i++){
        dp[i][a[i]] = 1;
        for(int j = 0;j < (1ll << m);j++){
            if(!dp[i - 1][j]) continue;
            dp[i][j ^ a[i]] = 1;
        }
    }

    ll result = 0;
    for(int i = 0;i < (1ll << m);i++){
        if(!dp[n][i]) continue;
        result++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}