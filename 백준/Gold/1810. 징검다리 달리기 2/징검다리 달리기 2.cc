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
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
map <ll, set<ll>> cnt;
map <pll, ll> num;

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
        d.resize(n + 1, 1e12); pre.resize(n + 1, -1);
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

int main() {
    fastio;

    cin >> n >> m; _dij <double> dij(n + 1);
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        cnt[a[i].x].insert(a[i].y);
        num[a[i]] = i;
    }

    for(int i = 0;i <= n;i++){
        for(int dx = 0;dx <= 2;dx++){
            for(int dy = -2;dy <= 2;dy++){
                if(!dx && !dy) continue;
                ll nx = a[i].x + dx;
                ll ny = a[i].y + dy;
                if(!num.count({nx, ny})) continue;
                ll j = num[{nx, ny}];

                dij.add(i, j, sqrtl(dx * dx + dy * dy));
            }
        }
    }
    dij.init(0);
    
    double ret = 1e12;
    for(int i = 1;i <= n;i++){
        if(a[i].y != m) continue;
        ret = min(ret, dij.ret(i));
    }

    cout << fixed << setprecision(0);
    if(ret == 1e12) cout << -1;
    else cout << ret;



    return 0;
}

