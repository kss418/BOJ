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
class node{
public:
    ll x, y; char c;
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

ll num(ll n, ll dir, ll use){
    return 808 * use + 202 * dir + n;
}

void run(){
    cin >> n >> a[n + 1].x >> a[n + 1].y; _dij dij(2010);
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y >> a[i].c;
    }

    for(int i = 0;i <= n;i++){
        ll nx = INF, ny = INF, px = MINF, py = MINF;
        ll nxi = -1, nyi = -1, pxi = -1, pyi = -1;
        for(int j = 1;j <= n + 1;j++){
            if(i == j) continue;
            if(a[i].y == a[j].y){
                if(a[j].x > a[i].x && nx > a[j].x) {
                    nx = a[j].x; nxi = j;
                }

                if(a[j].x < a[i].x && a[j].x > px){
                    px = a[j].x; pxi = j;
                }
            }

            if(a[i].x == a[j].x){
                if(a[j].y > a[i].y && ny > a[j].y){
                    ny = a[j].y; nyi = j;
                }
                
                if(a[j].y < a[i].y && a[j].y > py){
                    py = a[j].y; pyi = j;
                }
            }
        }   

        if(nxi != -1){
            if(a[nxi].c == '/'){
                dij.addsol(num(i, 0, 0), num(nxi, 3, 0), 0);
                dij.addsol(num(i, 0, 1), num(nxi, 3, 1), 0);
                dij.addsol(num(i, 0, 0), num(nxi, 1, 1), nxi);
            }
            else{
                dij.addsol(num(i, 0, 0), num(nxi, 1, 0), 0);
                dij.addsol(num(i, 0, 1), num(nxi, 1, 1), 0);
                dij.addsol(num(i, 0, 0), num(nxi, 3, 1), nxi);
            }
        }

        if(pxi != -1){
            if(a[pxi].c == '/'){
                dij.addsol(num(i, 2, 0), num(pxi, 1, 0), 0);
                dij.addsol(num(i, 2, 1), num(pxi, 1, 1), 0);
                dij.addsol(num(i, 2, 0), num(pxi, 3, 1), pxi);
            }
            else{
                dij.addsol(num(i, 2, 0), num(pxi, 3, 0), 0);
                dij.addsol(num(i, 2, 1), num(pxi, 3, 1), 0);
                dij.addsol(num(i, 2, 0), num(pxi, 1, 1), pxi);
            }
        }

        if(nyi != -1){
            if(a[nyi].c == '/'){
                dij.addsol(num(i, 3, 0), num(nyi, 0, 0), 0);
                dij.addsol(num(i, 3, 1), num(nyi, 0, 1), 0);
                dij.addsol(num(i, 3, 0), num(nyi, 2, 1), nyi);
            }
            else{
                dij.addsol(num(i, 3, 0), num(nyi, 2, 0), 0);
                dij.addsol(num(i, 3, 1), num(nyi, 2, 1), 0);
                dij.addsol(num(i, 3, 0), num(nyi, 0, 1), nyi);
            }
        }

        if(pyi != -1){
            if(a[pyi].c == '/'){
                dij.addsol(num(i, 1, 0), num(pyi, 2, 0), 0);
                dij.addsol(num(i, 1, 1), num(pyi, 2, 1), 0);
                dij.addsol(num(i, 1, 0), num(pyi, 0, 1), pyi);
            }
            else{
                dij.addsol(num(i, 1, 0), num(pyi, 0, 0), 0);
                dij.addsol(num(i, 1, 1), num(pyi, 0, 1), 0);
                dij.addsol(num(i, 1, 0), num(pyi, 2, 1), pyi);
            }
        }
    }

    
    ll result = INF; dij.init(num(0, 0, 0));
    for(int i = 0;i < 4;i++){
        result = min<ll>(result, dij.ret(num(n + 1, i, 0)));
        result = min<ll>(result, dij.ret(num(n + 1, i, 1)));
    }

    cout << (result == INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

