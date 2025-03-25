#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll DIV = 1e6;

class node{
public:
    ll nxt, co, fl;
};
vector <node> adj[MAX];
ll d[MAX][MAX];

using ptl = pair<ll, pll>;
priority_queue <ptl, vector<ptl>, greater<ptl>> pq; 

void init(){
    pq.push({0, {1, 1000}});
    while(!pq.empty()){
        auto[cd, cn] = pq.top(); pq.pop();
        auto[cur, cf] = cn;
        if(d[cur][cf] <= cd) continue;
        d[cur][cf] = cd;
        
        for(auto& nn : adj[cur]){
            auto[nxt, co, fl] = nn;
            ll nd = cd + co;
            ll nf = min(cf, fl);
            pq.push({nd, {nxt, nf}});
        }
    }
}

void run(){
    cin >> n >> m; memset(d, 0x3f, sizeof(d));
    while(m--){
        ll s, e, c, f; cin >> s >> e >> c >> f;
        adj[s].push_back({e, c, f});
        adj[e].push_back({s, c, f});
    }   
    init();

    ll result = 0;
    for(ll i = 1;i <= 1000;i++){
        result = max(result, DIV * i / d[n][i]);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}