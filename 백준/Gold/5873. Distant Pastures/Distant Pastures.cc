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
constexpr ll MAX = 33; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll result;

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

ll num(ll cy, ll cx){
    return cy * n + cx;
}

ll solve(ll cy, ll cx){
    _dij dij(n * n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i != n - 1) dij.add(num(i, j), num(i + 1, j), st[i][j] == st[i + 1][j] ? m : k);
            if(j != n - 1) dij.add(num(i, j), num(i, j + 1), st[i][j] == st[i][j + 1] ? m : k);
        }
    }

    dij.init(num(cy, cx));
    ll ret = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) ret = max<ll>(ret, dij.ret(num(i, j)));
    }

    return ret;
}

void run(){
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) cin >> st[i];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            result = max(result, solve(i, j));
        }
    }
    
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}