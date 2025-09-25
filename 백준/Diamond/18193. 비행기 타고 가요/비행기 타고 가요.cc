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
constexpr ll MAX = 251010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll sz = 1, cnt;

class _dij {
public:
    class node{
    public:
        ll d;
        node() : node(0){}
        node(ll d) : d(d){}
        ll num() const{ return d; }
        bool operator<(const node& ot) const{ return num() < ot.num(); }
        bool operator>(const node& ot) const{ return num() > ot.num(); }
        bool operator==(const node& ot) const{ return num() == ot.num(); }
        bool operator<=(const node& ot) const{ return num() <= ot.num(); }
        node operator+(const node& ot) const{
            return {d + ot.d};
        }
        operator ll(){ return d; }
    };
    node mx(){ return {INF}; }
    node mn(){ return {0}; }

    using ptl = pair <node, ll>;
    ll n; vector <node> d;
    vector <ll> pre;
    vector <vector<ptl>> adj;
    priority_queue <ptl, vector<ptl>, greater<ptl>> pq;

    _dij(){}
    _dij(ll n) { this->n = n; adj.resize(n + 1); }

    void add(ll st, ll en, node c) { // 양방향
        adj[st].push_back({ c,en });
        adj[en].push_back({ c,st });
    }
    void addsol(ll st, ll en, node c) { // 단방향
        adj[st].push_back({ c,en });
    }

    void init(ll st) {
        d.clear(); pre.clear();
        d.resize(n + 1, mx()); pre.resize(n + 1, -1); 
        pq.push({ mn(), st });
        d[st] = mn();

        while (!pq.empty()) {
            auto [cn, cur] = pq.top(); pq.pop();
            if(cn > d[cur]) continue;
            
            for (auto& i : adj[cur]) {
                auto [nn, nxt] = i;
                node pl = nn + cn;
        
                if (d[nxt] <= pl) continue;
                d[nxt] = pl; pre[nxt] = cur; 
                pq.push({ pl, nxt });
            }
        }
    }

    node ret(ll n) { return d[n]; }
}; _dij dij;

vector <ll> tmp[2];
void num(ll st, ll en, bool f, bool idx){
    st = max(1ll, st); en = min(sz, en);
    if(st > en) return;

    st += sz - 1; en += sz - 1;
    while(st <= en){
        if(st & 1) tmp[idx].push_back((f ? 2 * sz : 0) + st++);
        if(!(en & 1)) tmp[idx].push_back((f ? 2 * sz : 0) + en--);
        st >>= 1; en >>= 1; 
    }
}

void mkadj(ll sl, ll sr, ll el, ll er, bool sf, bool ef, ll c){
    for(int i = 0;i < 2;i++) tmp[i].clear();
    num(sl, sr, sf, 0); num(el, er, ef, 1);
    for(auto& i : tmp[0]){
        for(auto& j : tmp[1]) dij.addsol(i, j, c);
    }
}

void mkadj2(ll sl, ll sr, ll el, ll er, bool sf, bool ef, ll c){
    for(int i = 0;i < 2;i++) tmp[i].clear();
    num(sl, sr, sf, 0); num(el, er, ef, 1);

    ++cnt;
    for(auto& i : tmp[0]) dij.addsol(i, 4 * sz + cnt, c);
    for(auto& i : tmp[1]) dij.addsol(4 * sz + cnt, i, 0);
}

void mktree(ll st, ll en){
    if(st >= en) return;
    ll mid = (st + en) / 2;

    mkadj(st, en, st, mid, 1, 1, 0);
    mkadj(st, en, mid + 1, en, 1, 1, 0);

    mkadj(st, mid, st, en, 0, 0, 0);
    mkadj(mid + 1, en, st, en, 0, 0, 0);

    mktree(st, mid); mktree(mid + 1, en);
}

void run(){
    cin >> n >> m >> k;
    while(sz < n) sz <<= 1ll;
    dij = {4 * sz + m};

    while(m--){
        ll c, sx, sy, ex, ey;
        cin >> c >> sx >> sy >> ex >> ey;
        mkadj2(sx, sy, ex, ey, 0, 1, c);
    }

    for(int i = 1;i <= n;i++) dij.addsol(i + 3 * sz - 1, i + sz - 1, 0);
    mktree(1, sz); dij.init(k + sz - 1);
    for(int i = 1;i <= n;i++){
        ll ret = dij.ret(i + sz - 1);
        cout << (ret >= INF ? -1 : ret) << " ";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}