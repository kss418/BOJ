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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

class _dij {
public:
    class node{
        public:
        ll d, v, cnt;
        ll num() const{
            if(cnt) return d - v;
            return d;
        }
        bool operator<(const node& ot) const{ return num() < ot.num(); }
        bool operator>(const node& ot) const{ return num() > ot.num(); }
        bool operator==(const node& ot) const{ return num() == ot.num(); }
        bool operator<=(const node& ot) const{ return num() <= ot.num(); }
        node operator+(const node& ot) const{
            return {d + ot.d, max(v, ot.v), max(cnt, ot.cnt)};
        }
    };
    node mx(ll cnt){ return {INF, 0, cnt}; }
    node mn(){ return {0, 0, 0}; }

    using ptl = pair <node, ll>;
    ll n; vector <node> d[2];
    vector <ll> pre;
    vector <vector<ptl>> adj;
    priority_queue <ptl, vector<ptl>, greater<ptl>> pq;

    _dij(ll n) {
        this->n = n;
        d[0].resize(n + 1, mx(0)); d[1].resize(n + 1, mx(1));
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

            if (d[cn.cnt][cur] <= cn) continue;
            d[cn.cnt][cur] = cn;
            
            for (auto& i : adj[cur]) {
                auto [nn, nxt] = i;
                node pl = nn + cn;
                if(!pl.cnt){
                    if (d[0][nxt] > pl){
                        pre[nxt] = cur;
                        pq.push({ pl, nxt });
                    }
                }
                
                pl.cnt = 1;
                if (d[1][nxt] <= pl) continue;
                pre[nxt] = cur;
                pq.push({ pl, nxt });
            }
        }
    }

    node ret(ll n) {
        return min(d[0][n], d[1][n]);
    }
};

int main() {
    fastio;
    
    cin >> n >> m; _dij dij(n);
    while(m--){
        ll s, e, c, v; cin >> s >> e >> c >> v;
        dij.add(s, e, {c, v, 0});
    }
    dij.init(1);

    for(int i = 2;i <= n;i++){
        auto [d, v, cnt] = dij.ret(i);
        if(cnt) cout << d - v << "\n";
        else cout << d << "\n";
    }
    
     
    return 0;
}