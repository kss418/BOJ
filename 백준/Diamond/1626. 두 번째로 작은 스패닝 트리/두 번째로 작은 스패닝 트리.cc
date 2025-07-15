#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <tll> back;
vector <ll> result;

class _lca { // 1-based index
public:
    ll n, m; vector <ll> d;
    vector <vector<ll>> p;
    vector <vector<pll>> adj;

    class node{
    public:
        ll a, b;
        node() : node(MINF, MINF) {}
        node(ll a, ll b) : a(a), b(b) {}

        operator pll(){ // query
            return {a, b};
        }
    };
    vector <vector<node>> arr;

    _lca() {}
    _lca(ll n, bool m = 0) { //n 개수
        this->n = n; this->m = m; 
        p.resize(log2(n + 1) + 1, vector<ll>(n + 1, -1));
        d.resize(n + 1); adj.resize(n + 1);
        fill(d.begin(), d.end(), -1);

        if(m) arr.resize(log2(n + 1) + 1, vector<node>(n + 1, node()));
    }

    void add(ll a, ll b, ll c = 1) { // 양방향
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    void addsol(ll a, ll b, ll c = 1) { // 단방향
        adj[a].push_back({b, c});
    }

    node merge(const node& a, const node& b){
        vector <ll> arr;
        arr.push_back(a.a);
        arr.push_back(a.b);
        arr.push_back(b.a);
        arr.push_back(b.b);
        sort(all(arr));
        arr.erase(unique(all(arr)), arr.end());

        return {
            arr.back(),
            (arr.size() == 1 ? MINF : arr[arr.size() - 2])
        };
    }

    void mktree(ll cur) {
        for (auto& [nxt, co] : adj[cur]) {
            if (d[nxt] != -1) continue;
            p[0][nxt] = cur;
            d[nxt] = d[cur] + 1;

            if(m) arr[0][nxt] = {co, MINF};
            mktree(nxt);
        }
    }

    void init() {
        for(int i = 1;i <= n;i++){
            if(d[i] != -1) continue;
            d[i] = 0; mktree(i);
        }

        for (int i = 1; i <= log2(n); i++) {
            for (int j = 1; j <= n; j++) {
                if (p[i - 1][j] == -1) continue;
                p[i][j] = p[i - 1][p[i - 1][j]];
                if(m) arr[i][j] = merge(arr[i - 1][p[i - 1][j]], arr[i - 1][j]);
            }
        }
    }

    ll shift(ll a, ll diff){
        if(diff <= 0) return a;
        for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)) a = p[i][a];
        }

        return a;
    }

    ll ret(ll a, ll b) {
        if (d[a] < d[b]) swap(a, b);

        a = shift(a, d[a] - d[b]);
        if (a == b) return a;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[i][a] == -1) continue;
            if (p[i][a] == p[i][b]) continue;

            a = p[i][a]; b = p[i][b];
        }

        return p[0][a];
    }

    pll num(ll a, ll b){
        if(!m) return {MINF, MINF};

        node ret = node();
        if (d[a] < d[b]) swap(a, b);

        ll diff = d[a] - d[b];
        if (diff) for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)){
                ret = merge(ret, arr[i][a]);
                a = p[i][a];
            }
        }
        if (a == b) return ret;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[i][a] == -1) continue;
            if (p[i][a] == p[i][b]) continue;

            ret = merge(ret, arr[i][a]);
            ret = merge(ret, arr[i][b]);
            a = p[i][a]; b = p[i][b];
        }

        ret = merge(ret, arr[0][a]);
        ret = merge(ret, arr[0][b]);
        return ret;
    }
}; _lca lca;

template <typename T = ll>
class _mst {
public:
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
    vector <edge> adj;

    _mst(ll n) {
        this->n = n;
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
        adj.push_back({ st, en, c });
    }

    void init(ll num = 0) { // num 만큼 적게 간선 연결
        cnt = 0; result = 0;
        sort(all(adj));
        for(auto& i : adj) {
            auto [st, en, c] = i;
            if (same(st, en)) {
                back.push_back({st, en, c});
                continue; 
            } 
            merge(st, en); lca.add(st, en, c);
            result += c; cnt++;
        }
    }

    T ret() {
        return result;
    }
};

void run(){
    cin >> n >> m; _mst mst(n); lca = {n, 1};
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        mst.add(s, e, c);
    }

    mst.init(); lca.init();
    if(mst.cnt != n - 1){
        cout << -1; return;
    }
    
    result.push_back(mst.ret());
    for(auto& [s, e, c] : back){
        ll l = lca.ret(s, e);
        pll a = lca.num(s, l);
        pll b = lca.num(e, l);

        vector <ll> arr;
        arr.push_back(a.x); arr.push_back(a.y);
        arr.push_back(b.x); arr.push_back(b.y);
        sort(all(arr));
        arr.erase(unique(all(arr)), arr.end());

        for(auto& i : arr) if(i < 0) i = INF;
        ll mn1 = mst.ret() - (arr.size() == 1 ? INF : arr[arr.size() - 2]) + c;
        ll mn2 = mst.ret() - arr.back() + c;
        if(mn1 >= 0) result.push_back(mn1);
        if(mn2 >= 0) result.push_back(mn2);
    }

    sort(all(result));
    result.erase(unique(all(result)), result.end());

    cout << (result.size() <= 1 ? -1 : result[1]);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}