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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX][MAX];

ll solve(ll cur, ll cnt, ll last){
    if(cnt < 0 || last > cur) return INF;
    ll& ret = dp[cur][cnt][last];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret;
    
    ll pl = (a[cur] != (cur - last));
    if(last == cur){
        for(int i = 0;i < cur;i++) ret = min(ret, solve(cur - 1, cnt - 1, i) + pl);
    }
    else ret = min(ret, solve(cur - 1, cnt, last) + pl);

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> a[i];

    dp[0][0][0] = (a[0] != 0);
    for(int i = 0;i < n;i++){
        ll now = INF;
        for(int j = 0;j < n;j++) now = min(now, solve(n - 1, i, j));
        cout << now << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}