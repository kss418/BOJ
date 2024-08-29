#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], result = INF;
vector <ll> adj[MAX];
ll v[MAX], rv, bv;

void dfs(ll cur, ll num, ll n) {
    if (v[cur]) return;
    v[cur] = 1;
    for (auto& nxt : adj[cur]) {
        if (v[nxt]) continue;
        if (num && (n & (1ll << (nxt - 1)))) dfs(nxt, num, n);
        if (!num && (n & (1ll << (nxt - 1))) == 0) dfs(nxt, num, n);
    }
}

void init(ll cur) {
    memset(v, 0, sizeof(v));
    rv = bv = 0;
    ll r = 0, b = 0;

    for (int i = 1; i <= n; i++) {
        if (cur & (1ll << (i - 1))) {
            rv += arr[i];
            if (v[i]) continue;
            r++; dfs(i, 1, cur);
        }
        else {
            bv += arr[i];
            if (v[i]) continue;
            b++; dfs(i, 0, cur);
        }
    }

    if (r == 1 && b == 1) {
        result = min(result, abs(rv - bv));
    }
}

int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 1; j <= m; j++) cin >> k, adj[i].push_back(k);
    }

    for (int i = 1; i < (1 << n); i++) init(i);

    if (result >= INF) cout << -1;
    else cout << result;

    return 0;
}