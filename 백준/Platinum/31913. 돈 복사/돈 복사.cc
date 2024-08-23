#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;

template <typename T = ll>
class _spfa {
public:
    using ptl = pair <T, ll>;
    ll n; vector <ll> pre, cnt;
    vector <T> d; vector <bool> in;
    deque <ll> q;
    vector <vector <ptl>> adj;

    _spfa(ll n) {
        this->n = n;
        pre.resize(n + 1, -1); d.resize(n + 1, INF);
        in.resize(n + 1); adj.resize(n + 1);
        cnt.resize(n + 1);
    }

    void addsol(ll st, ll en, T c = 1) { // 단방향
        adj[st].push_back({ c, en });
    }

    ll init(ll st, ll fi = 0) { // cycle 0 else 1 / fi = d[st]
        d[st] = fi; in[st] = 1;
        q.push_back(st);

        while (!q.empty()) {
            ll cur = q.front(); q.pop_front();
            in[cur] = 0; cnt[cur]++;
            ll cd = d[cur];
            if (cnt[cur] >= n) return 0;

            for (auto& nn : adj[cur]) {
                auto [nd, nxt] = nn;
                if (d[nxt] <= nd + cd || nd + cd > 0) continue;
                d[nxt] = nd + cd;
                pre[nxt] = cur;

                if (in[nxt]) continue;
                in[nxt] = 1;
                q.push_back(nxt);
            }
        }

        return 1;
    }

    T ret(ll num) { // 거리 반환
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
    _spfa spfa(n + 1);

    while (m--) {
        ll num, co, st, en;
        cin >> num;
        if (num == 1) {
            cin >> co >> en;
            spfa.addsol(0, en, co);
        }
        else if (num == 2) {
            cin >> st >> co;
            spfa.addsol(st, 0, -co);
        }
        else if (num == 3) {
            cin >> st >> en;
            spfa.addsol(st, en, 0);
        }
        else if (num == 4) {
            cin >> st >> co >> en;
            spfa.addsol(st, en, co);
        }
        else {
            cin >> st >> en >> co;
            spfa.addsol(st, en, -co);
        }
    }

    ll st = 0, en = 4000000;
    while (st < en) {
        ll mid = (st + en) >> 1;
        fill(spfa.cnt.begin(), spfa.cnt.end(), 0);
        fill(spfa.d.begin(), spfa.d.end(), INF);
 
        if (!spfa.init(0, -mid)) en = mid;
        else st = mid + 1;
    }

    if (en == 4000000) cout << "INF";
    else cout << en;
    

    return 0;
}