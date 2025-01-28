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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll d[MAX]; deque <pll> q;

ll dist(pll a, pll b){
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

void bfs(ll num){
    memset(d, 0x3f, sizeof(d));
    q.push_back({ 0, 0 });
    while(!q.empty()){
        auto[cur, cd] = q.front(); q.pop_front();
        if(d[cur] <= cd) continue; d[cur] = cd;

        for(ll nxt = 1;nxt <= n + 1;nxt++){
            if(dist(a[cur], a[nxt]) > num * num) continue;
            if(d[nxt] <= d[cur] + 1) continue;
            q.push_back({nxt, cd + 1});
        }
    }
}

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        bfs(10 * cur);
        return d[n + 1] - 1 <= m;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

void run(){
    cin >> n >> m; a[0] = { 0, 0 }; a[n + 1] = { 10000, 10000 };
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    _bs <ll> bs(0, 1e6);

    cout << bs.ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

