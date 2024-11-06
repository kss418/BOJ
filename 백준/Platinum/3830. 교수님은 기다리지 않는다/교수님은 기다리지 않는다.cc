#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;

class _uf { 
public:
    ll n; vector <ll> p, d, dis;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); d.resize(n + 1); 
        dis.resize(n + 1);
    }

    pll find(ll num) { 
        if (p[num] == -1) return { num, 0ll };
        auto [pa, diff] = find(p[num]);
        p[num] = pa; d[num] += diff;
        return { p[num], d[num] };
    }

    void merge(ll a, ll b, ll c) {
        auto [pa, da] = find(a);
        auto [pb, db] = find(b);
        if (pa == pb) { dis[pb] |= (db - da - c != 0); return; }
        p[pa] = pb; dis[pb] |= dis[pa];
        d[pa] = db - da - c; 
    }

    pll diff(ll a, ll b){
        auto [pa, da] = find(a);
        auto [pb, db] = find(b);
        if(pa == pb && !dis[pa]) return { 1, db - da };
        else if(pa == pb && dis[pa]) return { 0, -1 };
        else return { 0, 0 };
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }
};

int main() {
    fastio;


    while(1){
        cin >> n >> m;
        if(!n && !m) break;
        _uf uf(n);

        while(m--){
            char c; ll l, r; cin >> c >> l >> r;
            if(c == '!'){
                ll val; cin >> val;
                uf.merge(l, r, val);
            }
            else{
                auto [able, diff] = uf.diff(l, r);
                if(!able) cout << "UNKNOWN\n";
                else cout << diff << "\n";
            }
        }
    }


    return 0;
}

