#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 20101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX];
vector <pll> q;
vector <pll> adj[MAX];

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        // if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

void init(ll cur, ll v = 0){
    sum[cur] = v;
    for(auto& [nxt, co] : adj[cur]){
        init(nxt, v + co);
    }
}

void run(){
    cin >> n; _uf uf(n); q.clear();
    for(int i = 1;i <= n;i++) adj[i].clear();

    while(1){
        char op; cin >> op;
        if(op == 'O') break;
        ll idx, p; cin >> idx;

        if(op == 'E'){
            q.push_back({uf.find(idx), idx});
        }
        else{
            cin >> p;
            uf.merge(p, idx);
            adj[p].push_back({idx, abs(p - idx) % 1000});
        }
    }

    for(int i = 1;i <= n;i++){
        if(uf.find(i) != i) continue;
        init(i);
    }

    for(auto& [s, e] : q){
        cout << sum[e] - sum[s] << "\n";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}