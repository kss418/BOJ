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
constexpr ll MAX = 201010; // PLZ CHK!
constexpr ll MOD = 998244353;
ll a[MAX];

int main() {
    fastio;

    ll x, y; cin >> x >> y >> n >> m;
    ld dist = sqrtl(x * x + y * y);

    ld result = dist, now = 0;
    if(2 * n > dist) result = min<ld>(result, 2 * m);

    while(dist > 0){
        now += m; dist -= n;
        if(2 * n > dist) result = min<ld>(result, now + 2 * m);
        result = min(result, now + fabs(dist));
    }

    cout.precision(20);
    cout << result;
    
     
    return 0;
}