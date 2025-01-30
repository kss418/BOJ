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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> a[MAX];
pll arr[MAX];

ll lb(ll cy, ll cx){
    return lower_bound(all(a[cy]), cx) - a[cy].begin();
}

ll ub(ll cy, ll cx){
    return upper_bound(all(a[cy]), cx) - a[cy].begin();
}

ll cal(ll cy, ll cx, ll sy, ll sx){
    ll ret = 0;
    for(int i = cy;i <= cy + sy;i++){
        ret += ub(i, cx + sx) - lb(i, cx);
    }

    return ret;
}

ll solve(ll cur, ll sx){
    ll sy = m - sx, ret = 0;
    for(int i = arr[cur].x - sy;i <= arr[cur].x;i++) {
        ret = max(ret, cal(i, arr[cur].y, sy, sx));
    }
    return ret;
}   

void run(){
    cin >> n >> m >> k; m >>= 1;
    for(int i = 1;i <= k;i++) {
        ll y, x; cin >> y >> x;
        arr[i] = {y, x};
        a[y].push_back(x);
    }
    for(int i = 0;i <= n;i++) sort(all(a[i]));

    ll result = 0;
    for(int i = 1;i <= k;i++){
        for(int j = 1;j < m;j++){
            result = max(result, solve(i, j));
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

