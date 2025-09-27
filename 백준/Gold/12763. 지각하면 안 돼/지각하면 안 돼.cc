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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
class node{
public:
    ll nxt, ti, co;
}; vector <node> adj[MAX];

class pq_node{
public:
    ll cur, ti, co;
    bool operator > (const pq_node& ot) const{
        return ti > ot.ti;
    }
};
priority_queue <pq_node, vector<pq_node>, greater<pq_node>> pq;
ll d[MAX][10101];


void run(){
    cin >> n >> m >> k; 
    ll q; cin >> q; memset(d, 0x3f, sizeof(d));
    while(q--){
        ll s, e, ti, co; cin >> s >> e >> ti >> co;
        adj[s].push_back({e, ti, co});
        adj[e].push_back({s, ti, co});
    }


    pq.push({1, 0, 0}); d[1][0] = 0;
    while(!pq.empty()){
        auto[cur, ct, cc] = pq.top(); pq.pop();
        if(d[cur][cc] != ct) continue;

        for(auto& [nxt, nt, nc] : adj[cur]){
            if(cc + nc > k) continue;
            if(d[nxt][cc + nc] <= ct + nt) continue;
            d[nxt][cc + nc] = ct + nt;
            pq.push({nxt, ct + nt, cc + nc});
        }
    }

    ll result = INF;
    for(int i = 0;i <= k;i++){
        if(d[n][i] > m) continue;
        result = i; break;
    }

    cout << (result >= INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}