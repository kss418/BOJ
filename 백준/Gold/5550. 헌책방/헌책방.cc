#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX], result, cnt[11];
ll a[11][MAX], sum[11][MAX];

ll solve(ll cur, ll c){
    if(!cur){
        if(!c) return 0;
        return MINF;
    }

    ll& ret = dp[cur][c];
    if(ret != -1) return ret; ret = 0;
    for(ll i = 0;i <= cnt[cur];i++) {
        if(i > c) break;
        ret = max(ret, solve(cur - 1, c - i) + sum[cur][i] + i * (i - 1));
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) {
        ll x, y; cin >> x >> y;
        cnt[y]++; a[y][cnt[y]] = x;
    }

    for(int i = 1;i <= 10;i++) {
        sort(a[i] + 1, a[i] + cnt[i] + 1);
        reverse(a[i] + 1, a[i] + cnt[i] + 1);
        for(int j = 1;j <= cnt[i];j++) sum[i][j] = sum[i][j - 1] + a[i][j];
    }

    cout << solve(10, m);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

