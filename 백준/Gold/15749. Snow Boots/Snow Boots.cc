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
constexpr ll MAX = 303; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX];
pll b[MAX];

ll solve(ll cur, ll cnt){
    if(cur <= 0 || cnt <= 0) return 0;
    ll& ret = dp[cur][cnt];
    if(cur == 1) return ret = 1;
    if(ret != -1) return ret; ret = 0;

    if(b[cnt].x < a[cur]) return ret = 0;
    for(int i = 1;i <= b[cnt].y;i++) ret = max(ret, solve(cur - i, cnt));
    for(int i = 1;i < cnt;i++) ret = max(ret, solve(cur, i));
    
    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i].x >> b[i].y;

    for(int i = 1;i <= m;i++){
        if(!solve(n, i)) continue;
        cout << i - 1; return;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}