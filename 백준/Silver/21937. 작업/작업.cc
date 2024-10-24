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
bool v[MAX];

ll dfs(ll cur){
    if(v[cur]) return 0; v[cur] = 1;
    ll ret = 0;
    for(auto& nxt : adj[cur]){
        ret += dfs(nxt);
    }

    return ++ret;
}

int main() {
    fastio;

    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[e].push_back(s);
    }
    cin >> k; cout << dfs(k) - 1;

    
    return 0;
}