#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll dep[MAX];

void dfs(ll cur, ll d){
    dep[cur] = d;

    for(auto& nxt : adj[cur]){
        if(dep[nxt] <= d + 1) continue;
        dfs(nxt, d + 1);
    }
}

int main() {
    fastio;

    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    memset(dep, 0x3f, sizeof(dep)); dfs(1, 0);

    cin >> k;
    while(k--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
        dfs(s, dep[s]); dfs(e, dep[e]);

        for(int i = 1;i <= n;i++) {
            if(dep[i] == INF) cout << -1 << " ";
            else cout << dep[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}