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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX]; ll cnt[MAX];

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
        l[a] = min(l[a], l[b]);
        r[a] = max(r[a], r[b]);
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    ll prv(ll num){ return find(l[find(num)] - 1); }
    ll nxt(ll num){ return find(r[find(num)] + 1); }
};

void run(){
    cin >> n; _uf uf(401);
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        for(int j = a[i].x;j <= a[i].y;j++) {
            cnt[j]++; if(j == a[i].y) break;
        }
    }
    
    for(int i = 1;i < 365;i++){
        if(cnt[i] && cnt[i + 1]) uf.merge(i, i + 1);
    }
    
    ll result = 0;
    for(int i = 1;i <= 365;i++){
        if(!cnt[i]) continue;
        if(uf.find(i) != i) continue;

        ll mx = 0;
        for(int j = uf.l[i];j <= uf.r[i];j++) mx = max(mx, cnt[j]);

        result += mx * (uf.r[i] - uf.l[i] + 1);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}