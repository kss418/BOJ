#include <bits/stdc++.h>
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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll c[MAX], all, cnt;
priority_queue <pll, vector <pll>, greater<pll>> pq;
vector <pll> arr;

class node{
public: 
    ll idx, s, e, sz;
    node(ll idx, ll s, ll e, ll sz) : idx(idx), s(s), e(e), sz(sz){}
    bool operator < (const node& ot) const{
        return idx < ot.idx;
    }
}; vector <node> tr;

class _uf { 
public:
    ll n; vector <ll> p, si, l, r;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
        l.resize(n + 1); r.resize(n + 1);
        iota(all(l), 0); iota(all(r), 0);
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

        c[a] = max(c[a], c[b]);
        l[a] = min(l[a], l[b]);
        r[a] = max(r[a], r[b]);
    }

    ll num(ll a){ return c[find(a)]; }
    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    ll prv(ll num){ return find(l[find(num)] - 1); }
    ll nxt(ll num){ return find(r[find(num)] + 1); }
};


void run(){
    cin >> n >> m; _uf uf(n + 1);
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 2;i <= n;i++){
        all += c[n] - c[i - 1];
        if(c[i] == c[i - 1]) uf.merge(i, i - 1);
        else pq.push({c[i] - c[i - 1], i});
    }
    
     while(!pq.empty()){
        auto [cd, cur] = pq.top(); pq.pop();
        ll pre = uf.prv(cur);
        if(!pre) continue;
        if(uf.num(cur) - uf.num(pre) != cd) continue;
        if(uf.same(cur, pre)) continue;
        
        if(uf.same(1, pre)){
            tr.push_back({cnt, uf.num(n) - uf.num(1), uf.num(n) - uf.num(cur), uf.size(pre)});
        }

        cnt += cd * uf.size(pre);
        uf.merge(cur, pre);

        if(uf.prv(cur)) pq.push({uf.num(cur) - uf.num(uf.prv(cur)), uf.l[uf.find(cur)]});
    }

    while(m--){
        cin >> k;
        if(k >= all) cout << 0 << "\n";
        else{
            ll lb = upper_bound(all(tr), node(k, INF, INF, INF)) - tr.begin() - 1;
            if(lb == -1) cout << tr[0].s << "\n";
            else cout << max(tr[lb].s - (k - tr[lb].idx) / tr[lb].sz, tr[lb].e) << "\n";
        }      
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}