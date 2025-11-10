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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
class node{
public:
    ll x, y, z, idx;
}; node a[MAX];

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

void run(){
    cin >> n >> m; _dij dij(n + m + 1);
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].idx = i;
        dij.addsol(i, n + a[i].z % m + 1, a[i].z);
        dij.addsol(n + (m - a[i].z % m) % m + 1, i, a[i].z);
    }

    sort(a + 1, a + n + 1, [](node& a, node& b){
        return a.x < b.x;
    });
    
    for(int i = 1;i < n;i++){
        dij.add(a[i].idx, a[i + 1].idx, a[i + 1].x - a[i].x);
    }

    sort(a + 1, a + n + 1, [](node& a, node& b){
        return a.y < b.y;
    });

    for(int i = 1;i < n;i++){
        dij.add(a[i].idx, a[i + 1].idx, a[i + 1].y - a[i].y);
    }

    dij.init(1);
    for(int i = 1;i <= n;i++) cout << dij.ret(i) << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}