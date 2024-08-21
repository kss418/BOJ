#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
pll arr[MAX]; ll co[MAX];
ll mx[MAX][21], mn[MAX][21];
vector <vector<ll>> p;

class _lca {
public:
    ll n; vector <ll> d;
    vector <vector<ll>> p, adj;
    _lca(ll n) { //n 개수
        this->n = n;
        p.resize(n + 1, vector<ll>(log2(n + 1) + 1, -1));
        d.resize(n + 1); adj.resize(n + 1);
        fill(d.begin(), d.end(), -1);
    }

    void add(ll a, ll b) { // 양방향
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void mktree(ll cur) {
        for (auto& nxt : adj[cur]) {
            if (d[nxt] != -1) continue;
            p[nxt][0] = cur;
            d[nxt] = d[cur] + 1;
            mktree(nxt);
        }
    }

    void init(ll root) {
        d[root] = 0;
        mktree(root);

        for (int i = 1; i <= log2(n); i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j][i - 1] == -1) continue;
                p[j][i] = p[p[j][i - 1]][i - 1];
            }
        }
    }

    ll ret(ll a, ll b) {
        if (d[a] < d[b]) swap(a, b);

        ll diff = d[a] - d[b];
        for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)) a = p[a][i];
        }
        if (a == b) return a;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[a][i] == -1) continue;
            if (p[a][i] == p[b][i]) continue;

            a = p[a][i]; b = p[b][i];
        }

        return p[a][0];
    }
};

ll ret1(ll a, ll b) {
    ll ret = INF;
    for (int i = log2(b); i >= 0; i--) {
        if (b & (1ll << i)) {
            ret = min(ret, mn[a][i]);
            a = p[a][i];
        }
    }

    return ret;
}

ll ret2(ll a, ll b) {
    ll ret = 0;
    for (int i = log2(b); i >= 0; i--) {
        if (b & (1ll << i)) {
            ret = max(ret, mx[a][i]);
            a = p[a][i];
        }
    }

    return ret;
}


int main()
{
    fastio;
    cin >> n;

    _lca lca(n);

    for (int i = 1; i < n; i++) cin >> arr[i].first >> arr[i].second >> co[i];
    for (int i = 1; i < n; i++) lca.add(arr[i].first, arr[i].second);
    lca.init(1);
    p = lca.p;

    for (int i = 1; i < n; i++) {
        ll p = -1, s = -1;
        if (lca.p[arr[i].first][0] == arr[i].second) p = arr[i].second, s = arr[i].first;
        else p = arr[i].first, s = arr[i].second;

        mn[s][0] = co[i]; mx[s][0] = co[i];
    }

    for (int i = 0; i < log2(n); i++) {
        for (int j = 1; j <= n; j++) {
            if (lca.p[j][i] == -1) continue;
            mn[j][i + 1] = min(mn[lca.p[j][i]][i], mn[j][i]);
            mx[j][i + 1] = max(mx[lca.p[j][i]][i], mx[j][i]);
        }
    }


    cin >> m;
    while (m--) {
        ll a, b;
        cin >> a >> b;
        ll l = lca.ret(a, b);
        ll da = lca.d[a] - lca.d[l];
        ll db = lca.d[b] - lca.d[l];

        cout << min(ret1(a, da), ret1(b, db)) << " ";
        cout << max(ret2(a, da), ret2(b, db)) << "\n";
    }


    return 0;
}