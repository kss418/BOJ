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
constexpr ll MAX = 150101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll sq, mx, result[50101]; 

class node{
public:
    ll s, e, idx;
    bool operator < (const node& ot) const{
        if(e != ot.e) return e > ot.e;
        return s < ot.s;
    }
}; vector <node> query;

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
}; _uf pre[400];

void merge(_uf& a, _uf& b){
    for(int i = 1;i <= n;i++){
        if(b.p[i] == -1) continue;
        a.merge(i, b.p[i]);
    }
}

void run(){
    cin >> n >> m; sq = sqrtl(m);
    for(int i = 1;i <= m;i++) cin >> a[i].x >> a[i].y;

    mx = (m + sq - 1) / sq;
    for(int i = 1;i <= mx;i++){
        pre[i] = {n}; 
        for(int j = (i - 1) * sq + 1;j <= min<ll>(i * sq, m);j++){
            pre[i].merge(a[j].x, a[j].y);
        }
    }

    for(int i = 2;i <= mx;i++) merge(pre[i], pre[i - 1]);

    ll q; cin >> q;
    for(int i = 1;i <= q;i++){
        ll s, e; cin >> s >> e;
        query.push_back({s, e, i});
    }
    sort(all(query));

    ll l = 0, r = m, la = 1;
    _uf uf = {n}, tmp = {n};
    for(auto& [s, e, idx] : query){
        while(r > e){
            uf.merge(a[r].x, a[r].y); 
            l = 0; la = 1; r--; tmp.clear();
        }

        _uf now = {n};
        while(l + sq < s) l += sq, tmp.clear();
        la = max(la, l + 1);
        while(la < s) tmp.merge(a[la].x, a[la].y), la++;

        if(l) merge(now, pre[(l - 1) / sq + 1]);
        merge(now, tmp);
        merge(now, uf);

        ll cnt = 0;
        for(int i = 1;i <= n;i++) cnt += (now.find(i) == i);
        result[idx] = cnt;
    }

    for(int i = 1;i <= q;i++) cout << result[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}