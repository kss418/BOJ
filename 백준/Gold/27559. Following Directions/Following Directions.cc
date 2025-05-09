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
constexpr ll MAX = 1551; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], dp[MAX][MAX], result;
string st[MAX];

ll solve(ll cy, ll cx){
    ll& ret = dp[cy][cx];
    if(ret != -1) return ret; ret = 0;
    if(cy == n || cx == n) return ret = a[cy][cx];

    if(st[cy][cx] == 'D') ret = solve(cy + 1, cx);
    else ret = solve(cy, cx + 1);

    return ret;
}

void dfs(ll cy, ll cx, ll num){
    result -= dp[cy][cx]; result += num;
    dp[cy][cx] = num;
    if(cx && st[cy][cx - 1] == 'R') dfs(cy, cx - 1, num);
    if(cy && st[cy - 1][cx] == 'D') dfs(cy - 1, cx, num);
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> st[i] >> a[i][n];
    for(int i = 0;i < n;i++) cin >> a[n][i];

    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= n;j++) {
            ll now = solve(i, j);
            if(i != n && j != n) result += now;
        }
    }

    cout << result << "\n"; cin >> m;
    while(m--){
        ll cy, cx; cin >> cy >> cx; cy--; cx--;
        st[cy][cx] = (st[cy][cx] == 'D' ? 'R' : 'D');
        ll now = dp[cy + (st[cy][cx] == 'D')][cx + (st[cy][cx] == 'R')];
        dfs(cy, cx, now); cout << result << "\n";
    }
  
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

