#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX], ret[MAX];

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1); si.resize(n + 1);
        fill(all(p), -1);
        fill(all(si), 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (a < b) swap(a, b);
        
        ret[a] += ret[b] + sum[a] * sum[b];
        sum[a] += sum[b];
        p[b] = a, si[a] += si[b];
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

    cin >> n >> m; _uf uf(n);
    for(int i = 1;i <= n;i++) {
        cin >> a[i]; sum[i] = a[i];
    }

    while(m--){
        ll l, r; cin >> l >> r;
        uf.merge(l, r);
        cout << ret[uf.find(l)] << "\n";
    }


    return 0;
}

