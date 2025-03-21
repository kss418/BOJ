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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 1e9 + 7;
ll a[MAX], b[MAX], dp[MAX], cnt[MAX];
ll pre[MAX], suf[MAX];

void run(){
    cin >> n; dp[0] = cnt[0] = suf[0] = pre[0] = 1;
    for(int i = 1;i <= n;i++) cin >> a[i] >> b[i];
    for(int i = 1;i <= n;i++) {
        cnt[i] = cnt[a[i]] + cnt[b[i]]; cnt[i] %= MOD;
        pre[i] = pre[a[i]] + pre[b[i]] + cnt[b[i]] - 1; pre[i] %= MOD;
        suf[i] = suf[a[i]] + suf[b[i]] + cnt[a[i]] - 1; suf[i] %= MOD;
        dp[i] = dp[a[i]] + dp[b[i]]; dp[i] %= MOD;
        dp[i] += suf[a[i]] * cnt[b[i]]; dp[i] %= MOD;
        dp[i] += pre[b[i]] * cnt[a[i]]; dp[i] %= MOD;
        dp[i] = (dp[i] + MOD - 1) % MOD;
    }

    for(int i = 1;i <= n;i++) cout << dp[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}