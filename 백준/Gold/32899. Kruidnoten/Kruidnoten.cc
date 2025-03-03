#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
class line{
public:
    ll s, e, c;
}; line a[MAX];

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
};

class node{
public:
    ll idx; ld per; ll d;
    bool operator < (const node& ot) const{
        return d < ot.d;
    }
}; node b[MAX];

void run(){
    cin >> n >> m >> k; _dij dij[2];
    dij[0] = dij[1] = {n};
    for(int i = 1;i <= m;i++){
        cin >> a[i].s >> a[i].e >> a[i].c;
        for(int j = 0;j <= 1;j++) dij[j].add(a[i].s, a[i].e, a[i].c);
    }
    dij[0].init(1); dij[1].init(n);

    ld result = -1e12, mul = 1;
    for(int i = 1;i <= k;i++){
        ll idx; ld per; cin >> idx >> per;
        if(to_string(per) == "1.000000") result = 0;
        ll d = dij[0].ret(idx) + dij[1].ret(idx);
        d = min<ll>(d, dij[1].ret(idx) + dij[0].ret(idx));
        b[i] = {idx, per, d};
    }
    sort(b + 1, b + k + 1);
    if(result < -1e11){
        cout << "impossible"; return;
    }
    
    for(int i = 1;i <= k;i++){
        auto[idx, per, d] = b[i];
        result += (ld)d * mul * per;
        mul *= (ld)1 - per;
    }

    cout.precision(20);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}