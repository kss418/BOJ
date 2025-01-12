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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], mn[4];

void init(){
    mn[2] = min({a[5] + a[1], a[1] + a[2], a[2] + a[6], a[5] + a[6]});
    mn[3] = min(mn[2] + a[3], mn[2] + a[4]);
    for(auto i : {1, 2, 5, 6}){
        for(auto j : {3, 4}) mn[2] = min(mn[2], a[i] + a[j]);
    }
}

void run(){
    cin >> n; init();
    for(int i = 1;i <= 6;i++) cin >> a[i]; init();
    sort(a + 1, a + 7);

    ll one = max((n - 2) * (n - 1), 0ll) * 4 + max((n - 2) * (n - 2), 0ll);
    ll two = 4 * (n - 1) + 4 * max(n - 2, 0ll);
    ll th = 4;

    if(n == 1) cout << a[1] + a[2] + a[3] + a[4] + a[5];
    else cout << a[1] * one + mn[2] * two + mn[3] * th;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}