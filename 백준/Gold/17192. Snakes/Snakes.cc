#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 404; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX];

ll solve(ll cur, ll cnt){
    if(cnt == -1) return INF;
    ll& ret = dp[cur][cnt];
    if(!cur && cnt) return ret = INF;
    if(ret != -1) return ret; ret = INF;
    
    for(int i = 1;i <= cur;i++){
        ll mx = 0, sum = 0;
        for(int j = i;j <= cur;j++){
            mx = max(mx, a[j]);
            sum += a[j];
        }

        ret = min(ret, solve(i - 1, cnt - 1) + mx * (cur - i + 1) - sum);
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];
    
    cout << solve(n, m + 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}