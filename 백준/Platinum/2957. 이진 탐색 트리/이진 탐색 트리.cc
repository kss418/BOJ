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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 301010;
constexpr ll MOD = 998244353;
ll lc[MAX], rc[MAX], a[MAX], d[MAX];

class _uf { 
public:
    ll n; vector <ll> p, si, l, r;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1); si.resize(n + 1, -1);
        l.resize(n + 1), r.resize(n + 1);
    }

    ll find(ll num) { 
        if (num <= 0 || num > n) return -1;
        if (p[num] == num) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
        l[a] = min(l[a], l[b]);
        r[a] = max(r[a], r[b]);
    }

    ll size(ll num){
        return si[find(num)];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }
};

int main() {
    fastio;

    cin >> n; _uf uf(n);
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = n;i >= 1;i--){
        uf.p[a[i]] = a[i];
        ll cur = uf.find(a[i]);
        uf.l[cur] = cur - 1; uf.r[cur] = cur + 1;

        if(uf.find(uf.l[cur]) != -1) uf.merge(uf.l[cur], cur);
        if(uf.find(uf.r[cur]) != -1) uf.merge(uf.r[cur], cur);

        cur = uf.find(cur);
        lc[i] = uf.l[cur]; rc[i] = uf.r[cur];
    }
    
    ll result = 0;
    cout << 0 << "\n";
    
    for(int i = 2;i <= n;i++){
        ll cur = a[i];
        d[cur] = max(d[lc[i]], d[rc[i]]) + 1;
        result += d[cur];
        cout << result << "\n"; 
    }
    
    
    return 0;
}