#include <bits/stdc++.h>
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
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll a[MAX], cnt;

ll dfs(ll cur, ll pre){
    ll& ret = a[cur];

    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        ret = max(dfs(nxt, cur) + 1, ret);
    }

    return ret;
}

void init(ll cur, ll pre){
    if(a[cur] < k) return; cnt++;

    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        init(nxt, cur);
    }
}

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    dfs(m, -1); init(m, -1);
    cout << max(2 * cnt - 2, 0ll);
    

    return 0;
}