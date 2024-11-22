#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> adj[MAX];
ll dp[MAX];

ll solve(ll cur, ll pre = -1){
    ll& ret = dp[cur];
    if(ret != -1) return ret;
    ret = 0;

    for(auto& i : adj[cur]){
        auto [nxt, co] = i;
        if(nxt == pre) continue;
        ret = max(ret, solve(nxt, cur) + co);
    }

    return ret;
}


int main() {
    fastio;

    cin >> n >> m; ll all = 0;
    for(int i = 1;i < n;i++){
        ll s, e, c; cin >> s >> e >> c;
        all += 2 * c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    memset(dp, -1, sizeof(dp));
    cout << all - solve(m);


    return 0;
}

