#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 20101; // SET MAX SIZE
constexpr ll MOD = 998244353;

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
        d.clear(); 
        d.resize(n + 1, mx()); 
        pq.push({ mn(), st });
        d[st] = mn();

        while (!pq.empty()) {
            auto [cn, cur] = pq.top(); pq.pop();
            if(cn > d[cur]) continue;
            
            for (auto& i : adj[cur]) {
                auto [nn, nxt] = i;
                node pl = nn + cn;
        
                if (d[nxt] <= pl) continue;
                d[nxt] = pl;  
                pq.push({ pl, nxt });
            }
        }
    }

    node ret(ll n) { return d[n]; }
};

class node{
public:
    ll s, e, c;
};
node a[MAX];
ll hub[MAX], idx[MAX];
vector <pll> adj[MAX];

void run(){
    ll q; cin >> n >> m >> k >> q;
    _dij dij[202] = {};

    for(int i = 1;i <= m;i++){
        cin >> a[i].s >> a[i].e >> a[i].c;
        adj[a[i].s].push_back({a[i].e, a[i].c});
    }

    for(int i = 1;i <= k;i++) dij[i] = {MAX};
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= k;j++){
            dij[j].addsol(a[i].s, a[i].e, a[i].c);
        }
    }

    for(int i = 1;i <= k;i++){
        cin >> hub[i];
        idx[hub[i]] = i;
        dij[i].init(hub[i]);
    }

    ll cnt = 0, sum = 0;
    while(q--){
        ll s, e; cin >> s >> e;
        ll result = INF;
        if(idx[s]) result = dij[idx[s]].ret(e);
        else{
            for(auto& [nxt, co] : adj[s]){
                if(!idx[nxt]) continue;
                ll now = dij[idx[nxt]].ret(e);
                result = min(result, now + co);
            }
        }  

        if(result >= INF) continue;
        cnt++; sum += result;
    }

    cout << cnt << "\n" << sum;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}