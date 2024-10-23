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
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX], inv[MAX];
ll ac[MAX], ic[MAX];
bool v[MAX];

void dfs1(ll cur){
    if(v[cur]) return;
    ac[cur]++; v[cur] = 1;
    for(auto& nxt : adj[cur]) dfs1(nxt);
}

void dfs2(ll cur){
    if(v[cur]) return;
    ic[cur]++; v[cur] = 1;
    for(auto& nxt : inv[cur]) dfs2(nxt);
}

int main() {
    fastio;

    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        inv[e].push_back(s);
    }

    for(int i = 1;i <= n;i++){
        memset(v, 0, sizeof(v)); dfs1(i); 
        memset(v, 0, sizeof(v)); dfs2(i);
        ic[i]--; ac[i]--;
    }
    
    ll result = 0;
    for(int i = 1;i <= n;i++){
        if(max(ic[i], ac[i]) < (n + 1) / 2) continue;
        result++;
    }

    cout << result;
    

    return 0;
}