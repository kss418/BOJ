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
constexpr ll MAX = 22; // SET MAX SIZE
constexpr ll MOD = 998244353;
int a[MAX][MAX], pre[MAX][MAX], suf[MAX][MAX], all;
int dp[MAX][MAX][40101], tr[MAX][MAX][40101];

int solve(ll cur, ll cnt, ll diff){
    int& ret = dp[cur][cnt][diff];
    if(ret != -1) return ret; ret = 0x3f3f3f3f;
    if(cur == n) return ret = abs(2 * diff - all);

    for(int i = cnt;i <= n;i++){
        int nxt = solve(cur + 1, i, diff + pre[cur + 1][i]);
        if(ret <= nxt) continue; 
        ret = nxt; tr[cur][cnt][diff] = i;
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp)); 
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[j][i], all += a[j][i];
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) pre[i][j] = pre[i][j - 1] + a[i][n - j + 1];
    }

    cout << solve(0, 0, 0) << "\n";
    int idx = 0, cnt = 0, diff = 0;
    while(idx < n){
        cnt = tr[idx][cnt][diff]; idx++;
        diff += pre[idx][cnt] - suf[idx][cnt + 1];
        cout << cnt << " ";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

