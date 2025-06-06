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
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][3];

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;
    if(!cur || !cnt) return ret;

    ret = max(ret, solve(cur - 1, cnt));
    ll idx = upper_bound(a + 1, a + n + 1, a[cur] - m - 1) - a;
    ret = max(ret, solve(idx - 1, cnt - 1) + cur - idx + 1);
    
    return ret;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    memset(dp, -1, sizeof(dp));

    cout << solve(n, 2);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

