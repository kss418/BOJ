#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
class node{
public:
    ll l, r, idx;
    bool operator <(const node& ot) const{
        if(l == ot.l) return r < ot.r;
        return l < ot.l;
    }
} a[MAX];

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
    cin >> n >> m; _uf uf(n);
    for(int i = 1;i <= n;i++) cin >> a[i].l >> a[i].r >> k, a[i].idx = i;
    sort(a + 1, a + n + 1);

    ll cur = 2;
    for(int i = 1;i <= n;i++){
        while(cur <= n){
            if(a[i].r < a[cur].l) break;
            uf.merge(a[i].idx, a[cur].idx); cur++;
        }
    }


    while(m--){
        ll l, r; cin >> l >> r;
        cout << uf.same(l, r) << '\n';
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

