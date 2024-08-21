#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
class _dij {
public:
    ll n; vector <ll> d, pre;
    vector <vector<pll>> adj;
    priority_queue <pll, vector<pll>, greater<pll>> pq;

    _dij(ll n) {
        this->n = n;
        d.resize(n + 1, INF); pre.resize(n + 1, -1);
        adj.resize(n + 1);
    }

    void add(ll st, ll en, ll c = 1) { // 양방향
        adj[st].push_back({ c,en });
        adj[en].push_back({ c,st });
    }

    void addsol(ll st, ll en, ll c = 1) { // 단방향
        adj[st].push_back({ c,en });
    }

    void init(ll st) {
        d[st] = 0;
        pq.push({ d[st], st});

        while (!pq.empty()) {
            auto [cd, cur] = pq.top(); pq.pop();
        
            for (auto& nn : adj[cur]) {
                auto [nd, nxt] = nn;
                if (d[nxt] <= nd + cd) continue;

                d[nxt] = nd + cd;
                pre[nxt] = cur;
                pq.push({ d[nxt], nxt });
            }
;       }
    }

    ll ret(ll n) {
        return d[n];
    }
};


int main()
{
    fastio;
    ll st, en;
    cin >> n >> m >> k >> st >> en;
    _dij dij(2 * n);

    while (m--) {
        ll s, e, c;
        cin >> s >> e >> c;
        dij.add(s, e, c);
        dij.add(s + n, e + n, c);
    }

    while (k--) {
        ll s, e;
        cin >> s >> e;
        dij.addsol(s, e + n, 0);
    }
    dij.init(st);

    cout << min(dij.ret(en), dij.ret(en + n));
  

    return 0;
}