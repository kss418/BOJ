#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 111; // SET MAX SIZE
constexpr ll MOD = 998244353;
pld a[MAX];

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

    void add(ll st, ll en, T c = 1) { // 양방향
        adj[st].push_back({ c,en });
        adj[en].push_back({ c,st });
    }

    void addsol(ll st, ll en, T c = 1) { // 단방향
        adj[st].push_back({ c,en });
    }

    void init(ll st, T fi = 0) {
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

ld dist(pld a, pld b){
    ld dx = a.x - b.x;
    ld dy = a.y - b.y;
    return sqrtl(dx * dx + dy * dy);
}

int main() {
    fastio;

    cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y;
    cin >> n; _dij<ld> dij(n + 3);
    for(int i = 2;i <= n + 1;i++) cin >> a[i].x >> a[i].y;

    for(int j = 1;j <= n + 1;j++){
        ld walk = dist(a[0], a[j]) / (ld)5;
        dij.add(0, j, walk);
    }

    for(int i = 1;i <= n + 1;i++){
        for(int j = i + 1;j <= n + 1;j++){
            ld use = fabsl(dist(a[i], a[j]) - (ld)50) / (ld)5 + (ld)2;
            ld walk = dist(a[i], a[j]) / (ld)5;
            dij.add(i, j, min(use, walk));
        }
    }
    dij.init(0);

    cout.precision(15);
    cout << dij.ret(1);

     
    return 0;
}