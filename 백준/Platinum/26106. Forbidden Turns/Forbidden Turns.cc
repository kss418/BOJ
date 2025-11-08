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

map <pll, ll> d;
ll result = INF;
vector <pll> adj[MAX];
class node{
public:
    ll cur, pre, d;
    bool operator > (const node& ot) const{
        return d > ot.d;
    }
}; priority_queue <node, vector<node>, greater<node>> pq;
set <tll> ban;

void run(){
    cin >> n >> m >> k;
    ll s, e; cin >> s >> e;
    while(n--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
    }

    while(k--){
        ll a, b, c; cin >> a >> b >> c;
        ban.insert({a, b, c});
    }

    d[{s, -1}] = 0;
    pq.push({s, -1, 0});
    while(!pq.empty()){
        auto[cur, pre, cd] = pq.top(); pq.pop();
        if(d[{cur, pre}] != cd) continue;
        if(cur == e) result = min(result, cd);

        for(auto& [nxt, co] : adj[cur]){
            ll nd = cd + co;
            if(d.count({nxt, cur}) && d[{nxt, cur}] <= nd) continue;
            if(ban.count({pre, cur, nxt})) continue;

            d[{nxt, cur}] = nd;
            pq.push({nxt, cur, nd});
            if(nxt == e) result = min(result, nd);
        }
    }

    cout << (result >= INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}