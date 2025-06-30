#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll p, q, d[MAX][MAX], mx[201010];
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
pll a[201010], b[201010];
string st[MAX];
map <pll, ll> co;
vector <pll> adj[201010];
vector <ll> arr;

class _lca {
public:
    ll n; vector <ll> d;
    vector <vector<ll>> p, adj;
    _lca(){}
    _lca(ll n) { //n 개수
        this->n = n;
        p.resize(n + 1, vector<ll>(log2(n + 1) + 1, -1));
        d.resize(n + 1); adj.resize(n + 1);
        fill(d.begin(), d.end(), -1);
    }

    void add(ll a, ll b) { // 양방향
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void addsol(ll a, ll b) { // 단방향
        adj[a].push_back(b);
    }

    void mktree(ll cur) {
        for (auto& nxt : adj[cur]) {
            if (d[nxt] != -1) continue;
            p[nxt][0] = cur;
            d[nxt] = d[cur] + 1;
            mktree(nxt);
        }
    }

    void init() {
        for(auto& i : arr){
            if(d[i] != -1) continue;
            d[i] = 0; mktree(i);   
        }

        for (int i = 1; i <= log2(n); i++) {
            for (int j = 0;j < n;j++) {
                if (p[j][i - 1] == -1) continue;
                p[j][i] = p[p[j][i - 1]][i - 1];
            }
        }
    }

    ll ret(ll a, ll b) {
        if (d[a] < d[b]) swap(a, b);

        ll diff = d[a] - d[b];
        for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)) a = p[a][i];
        }
        if (a == b) return a;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[a][i] == -1) continue;
            if (p[a][i] == p[b][i]) continue;

            a = p[a][i]; b = p[b][i];
        }

        return p[a][0];
    }
}; _lca lca;

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= m;
}

class node{
public:
    ll y, x, c;
};
ll cnt; _uf uf;

void merge(ll a, ll b, ll cost){
    if(uf.same(a, b)) return;
    a = uf.find(a); b = uf.find(b);

    ll mn = min(a, b);
    ll mx = max(a, b);
    pll now = {mn, mx};

    uf.merge(a, b); cnt--;
    if(!co.count(now)) co[now] = INF;
    co[now] = min<ll>(co[now], cost);
}

void bfs1(){
    deque <node> q, now;
    memset(d, -1, sizeof(d));
    for(int i = 0;i < p;i++){
        q.push_back({a[i].x, a[i].y, 0});
        d[a[i].x][a[i].y] = i;
    }

    for(int i = 0;;i++){
        if(cnt == 1 || q.empty()) break;
        while(!q.empty()){
            auto [cy, cx, cnt] = q.front();
            if(cnt != i) break;
            q.pop_front();

            for(int j = 0;j < 4;j++){
                ll ny = cy + dy[j], nx = cx + dx[j];
                if(outrange(ny, nx)) continue;
                if(st[ny][nx] == '#') continue;
                if(d[ny][nx] != -1) merge(d[ny][nx], d[cy][cx], 2 * i + 1);

                if(d[ny][nx] == -1){
                    q.push_back({ny, nx, cnt + 1});
                    now.push_back({ny, nx, cnt + 1});
                }
                d[ny][nx] = d[cy][cx];
            }
        }

        while(!now.empty()){
            auto[cy, cx, cnt] = now.front();
            now.pop_front();

            for(int k = 0;k < 4;k++){
                ll ny = cy + dy[k], nx = cx + dx[k];
                if(outrange(ny, nx)) continue;
                if(st[ny][nx] == '#') continue;

                if(d[ny][nx] == -1) continue;
                merge(d[ny][nx], d[cy][cx], 2 * i + 2);
            }
        }
    }
}

void bfs2(){
    deque <pll> q;
    memset(d, -1, sizeof(d));
    for(int i = 0;i < p;i++){
        q.push_back({a[i].x, a[i].y});
        d[a[i].x][a[i].y] = i;
    }

    while(!q.empty()){
        auto [cy, cx] = q.front(); q.pop_front();
        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            if(st[ny][nx] == '#') continue;

            if(d[ny][nx] == -1) continue;
            merge(d[ny][nx], d[cy][cx], 0);
        }
    }
}

void run(){
    cin >> n >> m >> p >> q; 
    lca = {p}; uf = {p}; cnt = p;
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < p;i++){
        cin >> a[i].x >> a[i].y;
        a[i].x--; a[i].y--;
    }
    bfs2(); bfs1();

    for(int i = 0;i < p;i++) arr.push_back(i);
    for(auto& i : co){
        auto& [line, c] = i;
        auto& [s, e] = line;

        lca.add(s, e);
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
        mx[s] = max(mx[s], c);
        mx[e] = max(mx[e], c);
    }

    sort(all(arr), [](ll a, ll b){
        return mx[a] > mx[b];
    });
    lca.init();

    for(int i = 0;i < q;i++){
        ll s, e; cin >> s >> e;
        s--; e--;

        ll now = -1;
        ll l = lca.ret(s, e);

        if(l != -1){
            for(auto& [nxt, co] : adj[l]){
                if(lca.d[nxt] < lca.d[l]) continue;
                ll a = lca.ret(nxt, s);
                ll b = lca.ret(nxt, e);
                if(a == nxt || b == nxt){
                    now = max(now, co); 
                }
            }
        }

        cout << now << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}