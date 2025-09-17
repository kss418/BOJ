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
constexpr ll MAX = 201; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
int dp[606][606];

int solve(ll cy, ll cx){
    if(cy < 0 || cx < 0) return 0x3f3f3f3f;
    int& ret = dp[cy][cx];
    if(ret != -1) return ret; ret = cx * cy;

    for(int i = 1;i < cy;i++) ret = min(ret, solve(i, cx) + solve(cy - i, cx));
    for(int i = 1;i < cx;i++) ret = min(ret, solve(cy, i) + solve(cy, cx - i));

    return ret;
}

void run(){
    cin >> n >> m >> k; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= k;i++){
        cin >> a[i].x >> a[i].y;
        dp[a[i].x][a[i].y] = 0;
    }

    cout << solve(n, m);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}