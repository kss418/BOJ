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
constexpr ll MAX = 30101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];

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

deque <pll> q;
set <ll> bs[MAX];
vector <ll> arr[MAX];

void run(){
    cin >> n >> m; _dij dij(n);
    for(int i = 1;i <= m;i++){
        cin >> a[i].x >> a[i].y;
        arr[a[i].x].push_back(a[i].y);
        bs[a[i].x].insert(a[i].y);
    }

    for(int i = 0;i < n;i++){
        arr[i].erase(unique(all(arr[i])), arr[i].end());
        for(auto& j : arr[i]){
            ll l = i - j, r = i + j;
            while(l >= 0){
                dij.addsol(i, l, (i - l) / j);
                if(bs[l].count(j)) break;
                l -= j; 
            }

            while(r < n){
                dij.addsol(i, r, (r - i) / j);
                if(bs[r].count(j)) break;
                r += j;
            }
        }
    }

    dij.init(a[1].x);
    ll ret = dij.ret(a[2].x);
    cout << (ret == INF ? -1 : ret);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

