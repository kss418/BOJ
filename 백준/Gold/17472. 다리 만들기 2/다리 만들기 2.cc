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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], num[MAX][MAX];
bool v[MAX][MAX];
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

template <typename T = ll>
class _mst {
public:
    vector<vector<pair<T, ll>>> adj;
    vector<ll> p, size; T result = 0;
    ll n, cnt = 0;
    class edge {
    public:
        ll s, e; T c;
        bool operator>(const edge& ot) const {
            return c > ot.c;
        }

        bool operator<(const edge& ot) const {
            return c < ot.c;
        }
    };
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    _mst() {}
    _mst(ll n) {
        this->n = n;
        adj.resize(n + 1);
        p.resize(n + 1, -1); size.resize(n + 1, 1);
    }

    ll find(ll num) {
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (a > b) swap(a, b);
        p[b] = a, size[a] += size[b];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }

    void add(ll st, ll en, T c = 1) { // 양방향
        adj[st].push_back({ c, en });
        adj[en].push_back({ c, st });
        pq.push({ st, en, c });
        pq.push({ en, st, c });
    }

    void init(ll num = 0) { // num 만큼 적게 간선 연결
        cnt = 0; result = 0;
        while (!pq.empty()) {
            auto [st, en, c] = pq.top(); pq.pop();
            if (same(st, en)) continue; merge(st, en);
            result += c; cnt++;
            if (cnt == n - 1 - num) break;
        }
    }

    T ret() {
        return result;
    }
}; _mst mst;

ll cnt = 1, flag;
void bfs(ll cy, ll cx, ll c){
    if(cy <= 0 || cx <= 0 || cy > n || cx > m) return;
    if(!a[cy][cx]) return;
    if(num[cy][cx]) return;
    flag = 1;

    num[cy][cx] = c;
    for(int i = 0;i < 4;i++){
        ll ny = dy[i] + cy, nx = dx[i] + cx;
        bfs(ny, nx, c);
    }
} 

ll use[MAX][MAX];
void dfs(ll cy, ll cx, ll c, ll d, ll dir){
    if(cy <= 0 || cx <= 0 || cy > n || cx > m) return;
    if(v[cy][cx]) return;
    if(d && num[cy][cx] == c) return;
    if(num[cy][cx] != c && num[cy][cx]) {
        if(d == 2) return;
        mst.add(num[cy][cx], c, d - 1);
        use[num[cy][cx]][c] = 1;
        use[c][num[cy][cx]] = 1;
        return;
    }
    v[cy][cx] = 1;

    ll ny = dy[dir] + cy, nx = dx[dir] + cx;
    dfs(ny, nx, c, d + 1, dir);
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) {
            flag = 0; bfs(i, j, cnt);
            cnt += flag;
        }
    }
    mst = {cnt - 1};

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) {
            if(!num[i][j]) continue;
            for(int k = 0;k < 4;k++) {
                memset(v, 0, sizeof(v));
                dfs(i, j, num[i][j], 0, k);
            }
        }
    }

    for(int i = 1;i < cnt;i++){
        for(int j = 1;j < i;j++){
            if(!use[i][j]) {
                mst.add(i, j, 1e9 + 1);
            }
        }
    }

    mst.init();
    ll ret = mst.ret();
    if(ret >= 1e9) cout << -1;
    else cout << ret;
  
     
    return 0;
}