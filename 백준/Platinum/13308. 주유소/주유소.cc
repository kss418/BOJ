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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 2510; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

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
    using ptpl = pair <node, pll>;
    ll n; vector <vector<node>> d;
    vector <ll> pre;
    vector <vector<ptl>> adj;
    priority_queue <ptpl, vector<ptpl>, greater<ptpl>> pq;

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
        d.resize(n + 1, vector<node>(2510, mx())); pre.resize(n + 1, -1); 
        pq.push({ mn(), {st, a[st]} });
        d[st][a[st]] = mn();

        while (!pq.empty()) {
            auto [cn, cp] = pq.top(); pq.pop();
            auto [cur, co] = cp;
            if(cn > d[cur][co]) continue;
            
            for (auto& i : adj[cur]) {
                auto [nn, nxt] = i;
                ll nco = min(a[nxt], co);
                node pl = nn * co + cn;
        
                if (d[nxt][nco] <= pl) continue;
                d[nxt][nco] = pl; pre[nxt] = cur; 
                pq.push({ pl, {nxt, nco}});
            }
        }
    }

    node ret(ll n, ll co) { return d[n][co]; }
};


void run(){
    cin >> n >> m; _dij dij(n);
    for(int i = 1;i <= n;i++) cin >> a[i];
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        dij.add(s, e, c);
    }
    dij.init(1); ll result = INF;
    for(int i = 1;i <= 2500;i++) result = min<ll>(result, dij.ret(n, i));
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

