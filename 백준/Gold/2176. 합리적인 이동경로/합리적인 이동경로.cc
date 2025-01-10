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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll dp[MAX];

class _dij {
public:
    class node{
    public:
        ll d;
        ll num() const{ return d; }
        bool operator<(const node& ot) const{ return num() < ot.num(); }
        bool operator>(const node& ot) const{ return num() > ot.num(); }
        bool operator==(const node& ot) const{ return num() == ot.num(); }
        bool operator<=(const node& ot) const{ return num() <= ot.num(); }
        node operator+(const node& ot) const{
            return {d + ot.d};
        }
    };
    node mx(){ return {INF}; }
    node mn(){ return {0}; }

    using ptl = pair <node, ll>;
    ll n; vector <node> d;
    vector <ll> pre;
    vector <vector<ptl>> adj;
    priority_queue <ptl, vector<ptl>, greater<ptl>> pq;

    _dij() {}
    _dij(ll n) {
        this->n = n;
        d.resize(n + 1, mx());
        pre.resize(n + 1, -1); adj.resize(n + 1);
    }

    void add(ll st, ll en, node c) { // 양방향
        adj[st].push_back({ c,en });
        adj[en].push_back({ c,st });
    }
    void addsol(ll st, ll en, node c) { // 단방향
        adj[st].push_back({ c,en });
    }

    void init(ll st) {
        pq.push({ mn(), st });

        while (!pq.empty()) {
            auto [cn, cur] = pq.top(); pq.pop();
            if (d[cur] <= cn) continue;
            d[cur] = cn;
            
            for (auto& i : adj[cur]) {
                auto [nn, nxt] = i;
                node pl = nn + cn;
        
                if (d[nxt] <= pl) continue;
                pre[nxt] = cur; pq.push({ pl, nxt });
            }
        }
    }

    node ret(ll n) { return d[n]; }
} dij;

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;

    for(auto& nxt : adj[cur]){
        if(dij.ret(nxt).d >= dij.ret(cur).d) continue;
        ret += solve(nxt);
    }

    return ret;
}

void run(){
    cin >> n >> m; dij = {n};
    memset(dp, -1, sizeof(dp));
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back(e);
        adj[e].push_back(s);
        dij.add(s, e, {c});
    }
    dij.init(2); dp[2] = 1;

    cout << solve(1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

