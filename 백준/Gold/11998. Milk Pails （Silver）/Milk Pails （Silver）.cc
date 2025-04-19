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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX][MAX], tx, ty;

ll solve(ll x, ll y, ll cnt){
    ll& ret = dp[x][y][cnt];
    if(ret != -1) return ret; ret = abs(m - x - y);
    if(cnt == n) return ret;
    
    ret = min(ret, solve(tx, y, cnt + 1));
    ret = min(ret, solve(x, ty, cnt + 1));
    ret = min(ret, solve(0, y, cnt + 1));
    ret = min(ret, solve(x, 0, cnt + 1));

    ret = min(ret, solve(min(tx, x + y), max(x + y - tx, 0ll), cnt + 1));
    ret = min(ret, solve(max(x + y - ty, 0ll), min(ty, x + y), cnt + 1));

    return ret;
}

void run(){
    cin >> tx >> ty >> n >> m;
    ll result = INF; memset(dp, -1, sizeof(dp));

    cout << solve(0, 0, 0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

