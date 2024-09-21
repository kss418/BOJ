#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 401010;
constexpr ll MOD = 1e9 + 7;
vector <ll> adj[MAX];
ll dep[MAX];

void dfs(ll cur, ll pre, ll d) {
    if (cur <= m) {
        dep[cur] = d;
        return;
    }

    for (auto& nxt : adj[cur]) {
        if (nxt == pre) continue;
        dfs(nxt, cur, d + 1);
    }
}

int main() {
    fastio;

    cin >> n >> m >> k;
    for (int i = 1; i < n; i++) {
        ll st, en;
        cin >> st >> en;
        adj[st].push_back(en);
        adj[en].push_back(st);
    }

    dfs(k, -1, 0);
    sort(dep + 1, dep + m + 1);

    cout << n - dep[1] - dep[2] - 1;


    return 0;
}