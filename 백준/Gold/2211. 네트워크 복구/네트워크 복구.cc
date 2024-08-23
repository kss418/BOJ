#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
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

    void init(ll st = 1) {
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

set <pll> num;

int main()
{
    fastio;
    cin >> n >> m;
    _dij dij(n);

    while (m--) {
        ll s, e, c;
        cin >> s >> e >> c;
        dij.add(s, e, c);
    }
    dij.init();

    for (int i = 2; i <= n; i++) {
        ll cur = i;
        while (dij.pre[cur] != -1) {
            num.insert({ dij.pre[cur], cur });
            cur = dij.pre[cur];
        }
    }

    cout << num.size() << "\n";
    for (auto& i : num) cout << i.first << " " << i.second << '\n';

    return 0;
}