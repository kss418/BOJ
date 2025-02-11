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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], cnt[MAX];
ll result, flag;
pll pos[MAX];

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

ll num(ll a){
    return (a > n ? a - n : a);
}

void run(){
    cin >> n; _uf uf(n);
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        (pos[a[i]].x ? pos[a[i]].y : pos[a[i]].x) = i;
        (pos[b[i]].x ? pos[b[i]].y : pos[b[i]].x) = i + n;
    }

    for(int i = 1;i <= n;i++){
        auto[x, y] = pos[i];
        uf.merge(num(x), num(y));
    }

    for(int i = 1;i <= n;i++){
        if(pos[i].x > n || pos[i].y > n) continue;
        cnt[uf.find(pos[i].x)]++;
    }

    for(int i = 1;i <= n;i++){
        if(i != uf.find(i)) continue;
        if(cnt[i] >= 2) flag = 1;
        if(uf.size(i) != 1) result += uf.size(i) + 1;
    }

    cout << (flag ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

