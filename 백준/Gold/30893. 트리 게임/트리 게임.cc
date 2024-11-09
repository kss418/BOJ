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
vector <ll> adj[MAX];
bool flag = 0;
ll tr[MAX], nxt[MAX], st, en;

void dfs(ll cur, ll pre){
    tr[cur] = pre;
    for(auto& nxt : adj[cur]){
        if(pre == nxt) continue;
        dfs(nxt, cur);
    }
}

bool solve(ll cur, bool turn){
    bool ret = 1;
    if(cur == en) return ret;
    if(!turn) if(adj[cur].size() > 2) ret = 0;

    ret &= solve(nxt[cur], turn ^ 1);
    return ret;
}   

int main() {
    fastio;

    cin >> n >> st >> en;
    for(int i = 1;i < n;i++){
        ll l, r; cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    dfs(st, -1);
    ll now = en;
    while(now != -1){
        nxt[tr[now]] = now;
        now = tr[now];
    }

    if(solve(st, 1)) cout << "First";
    else cout << "Second";
    

    return 0;
}

