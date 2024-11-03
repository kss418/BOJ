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
constexpr ll MAX = 4;
constexpr ll MOD = 998244353;
pll a[MAX];

class _ccw{
public:
    _ccw() {}

    ll ret(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
        return ret({x1, y1}, {x2, y2}, {x3, y3});
    }
    ll ret(pll v1, pll v2, pll v3){
        ll num = v1.x * v2.y + v2.x * v3.y + v3.x * v1.y;
        num -= v1.y * v2.x + v2.y * v3.x + v3.y * v1.x;

        if(num > 0) return 1; // cw
        else if(num < 0) return -1; // ccw
        return 0;
    }
};

int main() {
    fastio;

    _ccw ccw;
    for(int i = 0;i < 4;i++) cin >> a[i].x >> a[i].y;

    ll ret = ccw.ret(a[0], a[1], a[2]) * ccw.ret(a[0], a[1], a[3]);
    
    if(ret < 0) cout << 1;
    else cout << 0;
    
    
    return 0;
}