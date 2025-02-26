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
constexpr ll MAX = 801; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result, dp[MAX][MAX];
ll adj[MAX][MAX];

void run(){
    cin >> n;
    for(int i = 0;i < n - 1;i++){
        cin >> s;
        for(int j = i;j < n;j++) a[i][j] = s[j - i - 1] - '0';
    }

    for(int i = n - 1;i >= 0;i--){
        for(int j = i + 1;j < n;j++){
            ll num = 0;
            for(int k = i + 1;k < j;k++) num ^= a[i][k] * dp[k][j];
            dp[i][j] = a[i][j] ^ num;
            result += dp[i][j];
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}