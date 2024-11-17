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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class node{
public: 
    ld x, y, z;
};
node a[3];

ld dist(node a, node b){
    ld dx = a.x - b.x;
    ld dy = a.y - b.y;
    ld dz = a.z - b.z;

    return sqrtl(dx * dx + dy * dy + dz * dz);
}

class _ts { // 0-based index
public:
    ld l, r;
    _ts(ld l, ld r) {
        this->l = l; this->r = r;
    }

    ld f(ld cur) {
        ld mul = cur / (ld)100;
        ld cx = a[0].x + (a[1].x - a[0].x) * mul;
        ld cy = a[0].y + (a[1].y - a[0].y) * mul;
        ld cz = a[0].z + (a[1].z - a[0].z) * mul;

        node now = {cx, cy, cz};
        return dist(now, a[2]);
    }

    ld ret() {
        ld result = INF;
        ll cnt = 0;
        while (++cnt < 10000) {
            ld st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            result = min({result, f(st), f(en)});
            if(f(st) > f(en)) l = st;
            else r = en;
        }

        return result;
    }
};



int main() {
    fastio;

    for(int i = 0;i < 3;i++) cin >> a[i].x >> a[i].y >> a[i].z;
    _ts ts((ld)0, (ld)100);

    cout.precision(15);
    cout << ts.ret();


    return 0;
}

