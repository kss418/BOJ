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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], dp[MAX][MAX];
ll sum[MAX], result[MAX];

ll solve(ll l, ll r){
    ll& ret = dp[l][r];
    if(ret != -1) return ret; ret = 0;
    if(l > r) return ret;
    if(l == r) return ret = (a[l] == b[r]);
    ret = solve(l + 1, r - 1) + (a[l] == b[r]) + (a[r] == b[l]);
    
    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + (a[i] == b[i]);
    }

    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            ll now = sum[i - 1] + (sum[n] - sum[j]) + solve(i, j);
            result[now]++;
        }
    }

    for(int i = 0;i <= n;i++) cout << result[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

