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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX];

ll lb(ll num){
    return lower_bound(a + 1, a + n + 1, num) - a;
}

ll ub(ll num){
    return upper_bound(a + 1, a + n + 1, num) - a;
}

ll cal(ll l, ll r, ll num){
    return abs(sum[r] - sum[l - 1] - (r - l + 1) * num);
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];

    while(m--){
        ll l, r; cin >> l >> r;
        ll li = lb(l), ri = ub(r) - 1;
        ll cnt = ri - li + 1;
        if(cnt <= 1) cout << 0 << "\n";
        else{
            ll mx = max(cal(li + 1, ri, a[li]), cal(li, ri - 1, a[ri]));
            ll mid = (li + ri) / 2;

            ll fi = cal(mid + 1, ri, a[mid]) + cal(li, mid - 1, a[mid]);
            ll se = cal(mid + 2, ri, a[mid + 1]) + cal(li, mid, a[mid + 1]);

            cout << mx - min(fi, se) << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}