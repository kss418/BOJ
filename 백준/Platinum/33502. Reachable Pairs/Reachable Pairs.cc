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
ll a[MAX], now, cnt[MAX];
vector <ll> result, adj[MAX];
bool v[MAX];

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
        cnt[a] += cnt[b];
    }

    ll size(ll num){ return sz[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    void clear(){ p.assign(n + 1, -1); sz.assign(n + 1, 1); }
}; 

void run(){
    cin >> n >> m >> s; _uf uf(n);
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    
    for(int i = 1;i <= n;i++){
        if(s[i - 1] == '0') continue;
        for(auto& j : adj[i]){
            if(s[j - 1] == '0') continue;
            uf.merge(i, j);
        }
    }

    for(int i = n;i >= 1;i--){
        if(s[i - 1] == '0'){
            for(auto& j : adj[i]){
                if(j < i && s[j - 1] == '0') continue;
                ll uj = uf.find(j);
                if(v[uj]) continue; v[uj] = 1;
                ll sz = cnt[uj];
                now -= sz * (sz - 1) / 2;
            }

            for(auto& j : adj[i]) v[uf.find(j)] = 0;
            for(auto& j : adj[i]){
                if(j < i && s[j - 1] == '0') continue;
                uf.merge(i, j);
            }

            cnt[uf.find(i)]++;
            ll sz = cnt[uf.find(i)];
            now += sz * (sz - 1) / 2;
        }
        else{
            now += cnt[uf.find(i)];
            cnt[uf.find(i)]++;
        }
        result.push_back(now);
    }

    reverse(all(result));
    for(auto& i : result) cout << i << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}