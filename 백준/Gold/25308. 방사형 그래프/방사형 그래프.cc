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
constexpr ll MAX = 11; // PLZ CHK!
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9;
ll a[MAX];

template <typename T = ll>
class _ccw{
public:
    using ptl = pair<T, T>;
    _ccw() {}

    T ret(T x1, T y1, T x2, T y2, T x3, T y3){
        return ret({x1, y1}, {x2, y2}, {x3, y3});
    }
    ll ret(ptl v1, ptl v2, ptl v3){
        T num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1; // cw
        else if(num < 0) return -1; // ccw
        return 0;
    }
};

using pld = pair <ld, ld>;
pld tra(pll a, ll angle){
    ld rad = -angle * (ld)45 * M_PI / (ld)180;
    ld rx = cos(rad) * a.x - sin(rad) * a.y;
    ld ry = sin(rad) * a.x + cos(rad) * a.y;
    
    return {rx, ry};
}

int main() {
    fastio;

    for(int i = 0;i < 8;i++) cin >> a[i];
    vector <ll> seq(8); iota(all(seq), 0);

    ll result = 0; _ccw <ld> ccw;
    while(1){
        bool flag = 1;
        for(int i = 0;i < 8;i++){
            pld fi = tra({0, a[seq[i]]}, i);
            pld se = tra({0, a[seq[(i + 1) % 8]]}, (i + 1) % 8);
            pld th = tra({0, a[seq[(i + 2) % 8]]}, (i + 2) % 8);

            if(ccw.ret(fi, se, th) <= 0) continue;
            flag = 0; break;
        }

        result += flag;
        if(!next_permutation(all(seq))) break;
    }
    
    cout << result;

     
    return 0;
}