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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MID = 250;
ll tem[MAX];
vector <pll> adj[MAX];

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
    ll n; vector <vector <node>> d;
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
        d.resize(n + 1, vector<node>(500, mx())); pre.resize(n + 1, -1); 
        pq.push({ mn(), {st, MID}});
        d[st][MID] = mn();

        while (!pq.empty()) {
            auto [cn, cp] = pq.top(); pq.pop();
            auto [cur, ct] = cp;
            if(cn > d[cur][ct]) continue;
            
            for (auto& i : adj[cur]) {
                auto [nn, nxt] = i;
                node pl = nn + cn;
                
                ll nt = ct;
                if(tem[cur] == 1){
                    if(nt > MID) nt += nn;
                    else if(nt < MID) nt -= nn;
                }
                else {
                    if(!tem[cur]) nt = -nn.d + MID;
                    else if(tem[cur] == 2) nt = nn.d + MID;
                }

                if(nt >= MID + k || nt <= MID - k) nt = MID;
                if(nt > MID && !tem[nxt]) continue;
                if(nt < MID && tem[nxt] == 2) continue;
        
                if (d[nxt][nt] <= pl) continue;
                d[nxt][nt] = pl; pre[nxt] = cur; 
                pq.push({ pl, {nxt, nt}});
            }
        }
    }

    node ret(ll n) { 
        ll ret = INF;
        for(int i = 0;i < 500;i++) ret = min<ll>(ret, d[n][i]);
        return ret;
    }
};

void run(){
    cin >> n >> m >> k; _dij dij(n);
    for(int i = 1;i <= n;i++) cin >> tem[i];
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        dij.add(s, e, c);
    }
    dij.init(1);
    cout << dij.ret(n);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}