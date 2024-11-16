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
using ld = long double; using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
using pld = pair<ld, ld>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // PLZ CHK!
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-6;
pll a[2], b[2];

pld tra(ld cur, pll* a){
    ll dx = a[1].x - a[0].x;
    ll dy = a[1].y - a[0].y;
    ld mul = (ld)cur / (ld)1000;

    return {a[0].x + dx * mul , a[0].y + dy * mul};
}

ld dist(pld a, pld b){
    ld dx = a.x - b.x;
    ld dy = a.y - b.y;
    return sqrtl(dx * dx + dy * dy);
}

template <typename T = ll>
class _ts { // 0-based index
public:
    T l, r;
    _ts(T l, T r) {
        this->l = l; this->r = r;
    }

    T f(T cur) {
       pld an = tra(cur, a), bn = tra(cur, b);
       return dist(an, bn);
    }

    T ret() {
        T result = INF; ll cnt = 0;
        while (++cnt < 100000) {
            T st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            result = min<ld>({result, f(st), f(en)});
            if(f(st) > f(en)) l = st;
            else r = en;
        }

        return result;
    }
};

int main() {
    fastio;

    for(int i = 0;i <= 1;i++) cin >> a[i].x >> a[i].y;
    for(int i = 0;i <= 1;i++) cin >> b[i].x >> b[i].y;
    _ts <ld> ts(0, 1000);

    cout.precision(20);
    cout << ts.ret();
    
     
    return 0;
}