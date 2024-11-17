#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

template <typename T = ll>
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

    void init(ll st, T fi = 0) {
        memset(&d[0], 0x3f, sizeof(d[0]) * d.size());
        d[st] = fi;
        pq.push({ d[st], st });

        while (!pq.empty()) {
            auto [cd, cur] = pq.top(); pq.pop();
            if (cd > d[cur]) continue;

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

bool tel[MAX];
pll a[MAX];

ll dist(pll a, pll b){
    ll dx = abs(a.x - b.x);
    ll dy = abs(a.y - b.y);
    return dx + dy;
}

int main() {
    fastio;

    cin >> n >> m; _dij dij(n);
    for(int i = 1;i <= n;i++) {
        cin >> tel[i] >> a[i].x >> a[i].y;
    }

    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(tel[i] && tel[j]) dij.add(i, j, min(m, dist(a[i], a[j])));
            else dij.add(i, j, dist(a[i], a[j]));
        }
    }

    cin >> k;
    while(k--){
        ll s, e; cin >> s >> e;
        dij.init(s);

        cout << dij.ret(e) << "\n";
    }


    return 0;
}

