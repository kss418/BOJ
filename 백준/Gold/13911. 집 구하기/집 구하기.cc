#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101;
constexpr ll MOD = 1e9 + 7;

template <typename T = ll> // 반환 타입
class _dij {
public:
    using ptl = pair <T, ll>;
    ll n; vector <T> d;
    vector <ll> pre;
    vector <vector<ptl>> adj;
    priority_queue <ptl, vector<ptl>, greater<ptl>> pq;

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
        pq.push({ d[st], st });

        while (!pq.empty()) {
            auto [cd, cur] = pq.top(); pq.pop();

            for (auto& nn : adj[cur]) {
                auto [nd, nxt] = nn;
                if (d[nxt] <= nd + cd) continue;

                d[nxt] = nd + cd;
                pre[nxt] = cur;
                pq.push({ d[nxt], nxt });
            }
        }
    }

    T ret(ll n) {
        return d[n];
    }
};

int main()
{
    fastio;
    cin >> n >> m;
    _dij sb(n + 1), md(n + 1);
    while (m--) {
        ll st, en, c;
        cin >> st >> en >> c;
        sb.add(st, en, c);
        md.add(st, en, c);
    }

    ll num, mn, sn;
    cin >> num >> sn;
    for (int i = 1; i <= num; i++) cin >> k, sb.add(n + 1, k, 0);
  
    cin >> num >> mn;
    for (int i = 1; i <= num; i++) cin >> k, md.add(n + 1, k, 0);
    sb.init(n + 1); md.init(n + 1);

    ll result = INF;
    for (int i = 1; i <= n; i++) {
        if (!md.ret(i) || !sb.ret(i)) continue;
        if (sb.ret(i) > sn || md.ret(i) > mn) continue;
        result = min(result, md.ret(i) + sb.ret(i));
    }

    cout << (result == INF ? -1 : result);

         
    return 0;
}