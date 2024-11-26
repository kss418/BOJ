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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

template <typename T = ll>
class _ts { // 0-based index
public:
    T l, r; function<ld(ld)> f;
    _ts(T l, T r, function<ld(ld)> f) {
        this->l = l; this->r = r; this->f = f;
    }

    T ret() {
        while (r - l > 1e-12) {
            T st = (2 * l + r) / (ld)3, en = (l + 2 * r) / (ld)3;
            if(f(st) > f(en)) l = st;
            else r = en;
        }

        return r;
    }
};

ld dist(ld x1, ld y1, ld z1, ld x2, ld y2, ld z2){
    ld dx = x1 - x2, dy = y1 - y2, dz = z1 - z2;
    return sqrtl(dx * dx + dy * dy + dz * dz);
}

ld x[2], y[2], z[2], r[2], dx[2], dy[2], dz[2];
ld f1(ld cur){
    ld cx[2], cy[2], cz[2];
    for(int i = 0;i < 2;i++){
        cx[i] = x[i] + dx[i] * cur;
        cy[i] = y[i] + dy[i] * cur;
        cz[i] = z[i] + dz[i] * cur;
    }
    
    return dist(cx[0], cy[0], cz[0], cx[1], cy[1], cz[1]);
}

ld f2(ld cur){
    ld cx[2], cy[2], cz[2];
    for(int i = 0;i < 2;i++){
        cx[i] = x[i] + dx[i] * cur;
        cy[i] = y[i] + dy[i] * cur;
        cz[i] = z[i] + dz[i] * cur;
    }
    ld ret = dist(cx[0], cy[0], cz[0], cx[1], cy[1], cz[1]);
    ret = fabsl(ret - r[0] - r[1]);

    return ret;
}


int main() {
    fastio;

    cin >> t;
    while(t--){
        for(int i = 0;i <= 1;i++){
            cin >> x[i] >> y[i] >> z[i] >> r[i] >> dx[i] >> dy[i] >> dz[i];
        }
        _ts <ld> ts1(0, 1000, f1);
        _ts <ld> ts2(0, ts1.ret(), f2);

        cout.precision(10);
        if(f1(ts1.ret()) > r[1] + r[0]) cout << "No collision\n";
        else cout << ts2.ret() << "\n";
    }

     
    return 0;
}