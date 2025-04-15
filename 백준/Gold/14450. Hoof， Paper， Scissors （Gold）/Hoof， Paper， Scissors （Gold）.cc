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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
char c[MAX]; ll dp[MAX][3][21];

ll solve(ll cur, ll num, ll cnt){
    ll& ret = dp[cur][num][cnt];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret;

    if(cnt) for(int i = 0;i < 3;i++) ret = max(ret, solve(cur - 1, i, cnt - 1));
    ret = max(ret, solve(cur - 1, num, cnt));
    if(c[cur] == 'P' && !num) ret++;
    if(c[cur] == 'H' && num == 1) ret++;
    if(c[cur] == 'S' && num == 2) ret++;

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> c[i];
    cout << max({solve(n, 0, m), solve(n, 1, m), solve(n, 2, m)});
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}