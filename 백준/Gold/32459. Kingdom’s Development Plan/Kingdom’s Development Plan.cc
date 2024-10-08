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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX], result;
ll ind[MAX];
set <ll> q;

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e); ind[e]++;
    }

    for(int i = 1;i <= n;i++){
        if(!ind[i]) q.insert(i);
    }

    while(!q.empty()){
        ll cur = *q.begin(); q.erase(q.begin());
        result.push_back(cur);

        for(auto& nxt : adj[cur]){
            if(!--ind[nxt]) q.insert(nxt);
        }
    }

    if(result.size() != n) cout << "IMPOSSIBLE";
    else for(auto& i : result) cout << i << " ";
    

    return 0;
}