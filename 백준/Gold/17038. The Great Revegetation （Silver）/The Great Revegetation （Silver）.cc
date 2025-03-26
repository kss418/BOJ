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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
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
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

void run(){
    cin >> n >> m; _uf uf(2 * n);
    while(m--){
        char c; ll s, e; cin >> c >> s >> e;
        if(c == 'S') uf.merge(s, e), uf.merge(s + n, e + n);
        else uf.merge(s, e + n), uf.merge(s + n, e);
    }

    ll result = 1;
    for(int i = 1;i <= n;i++){
        if(uf.find(i) == i) result++;
    }

    for(int i = 1;i <= n;i++){
        if(uf.same(i, i + n)) result = 0;
    }
    
    if(!result) cout << 0;
    else {
        cout << 1;
        for(int i = 1;i < result;i++) cout << 0;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}