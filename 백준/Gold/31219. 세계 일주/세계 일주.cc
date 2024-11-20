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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
vector <ll> seq;

class _li{
public:
    _li() {}

    ll ccw(pll v1, pll v2, pll v3){
        ll num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1; 
        else if(num < 0) return -1; 
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

ld dist(pll a, pll b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return sqrtl(dx * dx + dy * dy);
}

int main() {
    fastio;

    cin >> n; seq.resize(n); iota(all(seq), 0);
    for(int i = 0;i < n;i++) cin >> a[i].x >> a[i].y;
    a[n] = a[0];

    ld result = 1e15; _li li;
    while(1){
        ll cnt = 0; ld now = 0; seq.push_back(seq[0]);
        for(int i = 0;i < n;i++){
            now += dist(a[seq[i]], a[seq[i + 1]]);
        }

        seq.pop_back();
        result = min(result, now);
        if(!next_permutation(all(seq)))break;
    }

    cout.precision(15);
    if(result == 1e15) cout << -1;
    else cout << result;


    return 0;
}

