#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 5010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][2];

ll solve(ll cur, ll cnt){
    if(cur > n) return 0;
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = cur;
    ret = max(ret, solve(cur + m, cnt));
    ret = max(ret, solve(cur + k, cnt));
    if(cnt) ret = max(ret, solve(cur / 2, 0));

    return ret;
}

void run(){
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}