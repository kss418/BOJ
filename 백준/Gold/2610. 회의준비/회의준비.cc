#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
class _floyd {
public:
    ll n; vector <vector<ll>> d;

    _floyd(ll n) {
        this->n = n;
        d.resize(n + 1, vector<ll>(n + 1, INF));
    }

    void add(ll st, ll en, ll c = 1) { //양방향
        d[st][en] = c; d[en][st] = c;
    }

    void addsol(ll st, ll en, ll c = 1) { //양방향
        d[st][en] = c;
    }

    void init() {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    ll ret(ll st, ll en) {
        return d[st][en];
    }
};

ll v[MAX];
deque <ll> q;
vector <vector<ll>> arr;
vector <ll> result;

int main()
{
    fastio;
    cin >> n >> m;
    _floyd floyd(n);

    while (m--) {
        ll s, e;
        cin >> s >> e;
        floyd.add(s, e);
    }
    floyd.init();
    
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i]) continue;
        vector <ll> vec;
        q.push_back(i);

        while (!q.empty()) {
            ll cur = q.front(); q.pop_front();
            v[cur] = 1; vec.push_back(cur);
            for (int j = 1; j <= n; j++) {
                if (floyd.ret(cur, j) == INF) continue;
                if (v[j]) continue;
                v[j] = 1; q.push_back(j);
            }
        }
        arr.push_back(vec);
    }

    for (auto& i : arr) {
        ll mn = -1, mv = INF;
        for (auto& j : i) {
            ll cur = 0;
            for (auto& k : i) {
                if (floyd.ret(j, k) == INF) continue;
                if (j == k) continue;
                cur = max(floyd.ret(j, k), cur);
            }
            if (cur < mv) mv = cur, mn = j;
        }

        result.push_back(mn);
    }

    cout << result.size() << "\n";
    sort(result.begin(), result.end());
    for (auto& i : result) cout << i << "\n";
         
    return 0;
}