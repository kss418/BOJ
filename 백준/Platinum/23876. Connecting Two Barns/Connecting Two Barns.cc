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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll d[MAX][2], now[MAX][2];
deque <ll> q;
vector <ll> adj[MAX];

class _uf { 
public:
    ll n; vector <ll> p, sz;
    
    _uf(){}
    _uf(ll n) {  
        this->n = n;
        p.resize(n + 1, -1); sz.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, sz[a] += sz[b];
    }

    ll size(ll num){ return sz[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    void clear(){ p.assign(n + 1, -1); sz.assign(n + 1, 1); }
}; 

void run(){
    cin >> n >> m; _uf uf(n);
    for(int i = 1;i <= n;i++){
        d[i][0] = d[i][1] = INF;
        adj[i].clear();
        now[i][0] = now[i][1] = INF;
    }
    
    while(m--){
        ll s, e; cin >> s >> e;
        uf.merge(s, e);
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for(int i = 1;i <= n;i++){
        if(!uf.same(1, i)) continue;
        q.push_back(i); d[i][0] = 0;
    }

    while(!q.empty()){
        auto now = q.front(); q.pop_front();
        if(now > 1 && d[now - 1][0] > d[now][0] + 1){
            d[now - 1][0] = d[now][0] + 1;
            q.push_back(now - 1); 
        }

        if(now != n && d[now + 1][0] > d[now][0] + 1){
            d[now + 1][0] = d[now][0] + 1;
            q.push_back(now + 1); 
        }
    }

    for(int i = 1;i <= n;i++){
        if(!uf.same(n, i)) continue;
        q.push_back(i); d[i][1] = 0;
    }

    while(!q.empty()){
        auto now = q.front(); q.pop_front();
        if(now > 1 && d[now - 1][1] > d[now][1] + 1){
            d[now - 1][1] = d[now][1] + 1;
            q.push_back(now - 1); 
        }

        if(now != n && d[now + 1][1] > d[now][1] + 1){
            d[now + 1][1] = d[now][1] + 1;
            q.push_back(now + 1); 
        }
    }

    ll result = INF;
    for(int i = 1;i <= n;i++){
        now[uf.find(i)][0] = min(now[uf.find(i)][0], d[i][0]);
        now[uf.find(i)][1] = min(now[uf.find(i)][1], d[i][1]);
    }

    for(int i = 1;i <= n;i++){
        ll idx = uf.find(i);
        result = min(result, now[idx][0] * now[idx][0] + now[idx][1] * now[idx][1]);
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}