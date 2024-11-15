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
constexpr ll EPS = 1e-9;
using pld = pair<ld, ld>;
pll a[MAX];

class _li{
public:
    _li() {}

    ll ccw(pll v1, pll v2, pll v3){
        ll num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1; // cw
        else if(num < 0) return -1; // ccw
        return 0;
    }

    bool ret(pair<pll, pll> a, pair<pll, pll> b) {
        return ret(a.x, a.y, b.x, b.y);
    }
    bool ret(pll av1, pll av2, pll bv1, pll bv2){
        ll ac = ccw(av1, av2, bv1) * ccw(av1, av2, bv2);
        ll bc = ccw(bv1, bv2, av1) * ccw(bv1, bv2, av2);

        if(!ac && !bc){
            if(av1 > av2) swap(av1, av2);
            if(bv1 > bv2) swap(bv1, bv2);
            return bv1 <= av2 && av1 <= bv2;
        }

        return ac <= 0 && bc <= 0;
    }
};

int main() {
    fastio;

    cin >> n; ll result = 0; _li li;
    for(int i = 1;i <= n;i++) cin >> a[i].y, a[i].x = i;

    for(int i = 1;i <= n;i++){
        ll cnt = 0;
        for(int j = 1;j <= n;j++){
            if(i == j) continue;
            bool flag = 0;

            if(i < j){
                for(int k = i + 1;k < j;k++){
                    flag |= li.ret({a[i], a[j]}, {{a[k].x, 0}, a[k]});
                }
            }
            else{
                for(int k = j + 1;k < i;k++){
                    flag |= li.ret({a[i], a[j]}, {{a[k].x, 0}, a[k]});
                }
            }

            cnt += flag ^ 1;
        }

        result = max(result, cnt);
    }

    cout << result;


    return 0;
}

