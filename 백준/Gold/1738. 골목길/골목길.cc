#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;

class _spfa {
public:
    ll n; vector <ll> pre, d, cnt;
    vector <bool> in;
    deque <ll> q;
    vector <vector <pll>> adj;

    _spfa(ll n) {
        this->n = n;
        pre.resize(n + 1, -1); d.resize(n + 1, INF);
        in.resize(n + 1); adj.resize(n + 1);
        cnt.resize(n + 1);
    }

    void add(ll st, ll en, ll c = 1) { // 단방향
        adj[st].push_back({ c, en });
    }

    ll init(ll st) { // cycle 0 else 1
        d[st] = 0; in[st] = 1;
        q.push_back(st);

        while (!q.empty()) {
            ll cur = q.front(); q.pop_front();
            in[cur] = 0; cnt[cur]++;
            ll cd = d[cur];
            if (cnt[cur] >= n) return 0;

            for (auto& nn : adj[cur]) {
                auto [nd, nxt] = nn;
                if (d[nxt] <= nd + cd) continue;
                d[nxt] = nd + cd;
                pre[nxt] = cur;

                if (in[nxt]) continue;
                in[nxt] = 1;
                q.push_back(nxt);
            }
        }

        return 1;
    }

    ll ret(ll num) { // 거리 반환
        return d[num];
    }

    vector <ll> track(ll st, ll en) { // st -> en 경로 반환
        vector <ll> ret;
        ll cur = en;
        while (cur != -1) {
            ret.push_back(cur);
            cur = pre[cur];
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

int main()
{
    fastio;
    cin >> n >> m;
    _spfa spfa(n);
    _spfa rev(n);

    while (m--) {
        ll st, en, c;
        cin >> st >> en >> c;
        spfa.add(st, en, -c);
        rev.add(en, st);
    }

    spfa.init(1); rev.init(n);
    if (spfa.ret(n) == INF) { cout << -1; return 0; }
    for (int i = 1; i <= n; i++) {
        if (rev.ret(i) == INF) continue;
        if (spfa.cnt[i] >= n && rev.ret(i) != INF) { cout << -1; return 0; }
    }

    vector <ll> result;
    result = spfa.track(1, n);

    for (auto& i : result) cout << i << " ";

         
    return 0;
}