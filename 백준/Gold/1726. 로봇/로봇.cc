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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], dd[2] = {1, -1};
ll tf[4] = {0, 2, 1, 3};

class _bfs {
public:
    ll n, m;
    ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    ll dd[2] = { 1, -1 };
    // ll dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
    // ll dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    class node {
    public:
        ll y, x, d;
        bool operator <(const node& ot) const{ 
            if(y != ot.y) return y < ot.y;
            if(x != ot.x) return x < ot.x;
            return d < ot.d;
        }
    };
    deque <pair <node, ll>> q; map <node, ll> v;
    _bfs(){}
    _bfs(ll n, ll m) { this->n = n; this->m = m; }

    bool outrange(node cur){
        auto[cy, cx, cd] = cur;
        if(cy <= 0 || cx <= 0 || cy > n || cx > m) return 1;
        if(a[cy][cx]) return 1;
        return 0;
    }

    void init(node st) {
        q.push_back({st, 0});
        while (!q.empty()) {
            auto [cur, cc] = q.front(); q.pop_front();
            auto [cy, cx, cd] = cur;
            if (!v.count(cur)) v[cur] = INF;
            if (v[cur] <= cc) continue; v[cur] = cc;

            for(int i = 1;i <= 3;i++){
                ll nx = cx + dx[cd] * i, ny = cy + dy[cd] * i;
                node nxt = {ny, nx, cd};
                if (outrange(nxt)) break;
                q.push_back({nxt, cc + 1});
            }

            for (int i = 0;i < 2;i++){
                ll nd = (cd + dd[i] + 4) % 4;
                node nxt = {cy, cx, nd};
                if(outrange(nxt)) continue;
                q.push_back({nxt, cc + 1});
            }
        }
    }

    ll ret(node cur) { return v[cur]; }
};

int main() {
    fastio;

    cin >> n >> m; _bfs bfs(n, m);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }

    _bfs::node st, en;
    cin >> st.y >> st.x >> st.d;
    cin >> en.y >> en.x >> en.d;
    st.d--; en.d--;
    st.d = tf[st.d]; en.d = tf[en.d];
    bfs.init(st);

    cout << bfs.ret(en);

     
    return 0;
}