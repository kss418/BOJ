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
constexpr ll MAX = 301; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX];
ll dp[MAX][MAX], pre[MAX][MAX];
vector <ll> result;

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(!cur) return ret = 0;
    if(ret != -1) return ret; ret = INF;

    if(cnt >= 2){
        for(int i = 1;i < cur;i++){
            ll now = max(solve(i, cnt - 1), sum[cur] - sum[i]);
            if(ret <= now) continue;
            ret = now; pre[cur][cnt] = i;
        }
    }
    else ret = sum[cur];

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];

    cout << solve(n, m) << "\n";
    while(n){
        result.push_back(n - pre[n][m]);
        n = pre[n][m]; m--;
    }

    reverse(all(result));
    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}