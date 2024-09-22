#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll result[MAX], v[MAX], cnt;

void dfs(ll cur) {
    if (v[cur]) return; v[cur] = 1;
    result[cur] = ++cnt;
    for (auto& nxt : adj[cur]) dfs(nxt);
}


int main() {
    fastio;

    cin >> n >> m >> k;
    while (m--) {
        ll s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        reverse(adj[i].begin(), adj[i].end());
    }
    dfs(k);

    for (int i = 1; i <= n; i++) cout << result[i] << "\n";


    return 0;
}