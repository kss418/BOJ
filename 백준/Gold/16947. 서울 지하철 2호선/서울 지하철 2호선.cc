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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 3010;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
stack <ll> st;
bool v[MAX], cycle[MAX], flag;

void dfs(ll cur, ll pre){
    if(flag) return;
    if(v[cur]) {
        cycle[cur] = 1; flag = 1;
        while(st.top() != cur){
            cycle[st.top()] = 1; st.pop();
        }
        return; 
    }
    v[cur] = 1; st.push(cur);

    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        dfs(nxt, cur);
    }

    if(!st.empty()) st.pop(); v[cur] = 0;
}
ll result[MAX];

void init(ll cur, ll cnt){
    if(result[cur] <= cnt) return;
    result[cur] = cnt;

    for(auto& nxt : adj[cur]){
        init(nxt, cnt + 1);
    }
}


int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    dfs(1, -1); memset(result, 0x3f, sizeof(result));
    for(int i = 1;i <= n;i++){
        if(!cycle[i]) continue; init(i, 0);
    }

   for(int i = 1;i <= n;i++) cout << result[i] << " ";
    
    
    return 0;
}