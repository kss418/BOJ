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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll a[MAX][MAX], mx[MAX];

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

void init(){
    for(int i = n - 1;i >= 0;i--){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '#') continue;
            a[i][j] = a[i + 1][j] + 1;
        }
    }

    for(int i = 0;i < n;i++){
        _uf uf = {m + 1};
        vector <pll> arr;
        for(int j = 0;j < m;j++) arr.push_back({a[i][j], j});
        sort(all(arr)); reverse(all(arr));

        for(auto& [v, idx] : arr){
            if(idx && a[i][idx - 1] >= v) uf.merge(idx, idx - 1);
            if(idx != m - 1 && a[i][idx + 1] >= v) uf.merge(idx, idx + 1);
            mx[v] = max<ll>(mx[v], uf.size(idx));
        }
    }
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];
    init();

    cin >> k;
    while(k--){
        ll cy, cx; cin >> cy >> cx;
        cout << (mx[cy] >= cx ? "YES" : "NO") << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

