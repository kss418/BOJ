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
constexpr ll MAX = 102; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], c[MAX], sum[MAX];
ll dp[MAX], pre[MAX];
vector <ll> result;

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = INF;
    for(int i = 0;i < cur;i++){
        if(sum[cur] - sum[i] > m) continue;
        if(ret < solve(i) + c[cur]) continue;
        ret = solve(i) + c[cur]; pre[cur] = i;
    }

    return ret;
}

void run(){
    cin >> m >> n; memset(dp, -1, sizeof(dp)); dp[0] = 0;
    for(int i = 1;i <= n + 1;i++) cin >> a[i];
    for(int i = 1;i <= n + 1;i++) sum[i] = sum[i - 1] + a[i];
    for(int i = 1;i <= n;i++) cin >> c[i];

    cout << solve(n + 1) << "\n"; ll cur = n + 1;
    while(cur){
        result.push_back(cur);
        cur = pre[cur];
    }

    reverse(all(result)); result.pop_back();
    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}