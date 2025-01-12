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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y, a[i].y--;
    sort(a + 1, a + n + 1);

    ll result = 0, e = -1;
    for(int i = 1;i <= n;i++){
        ll l = max(a[i].x, e + 1);
        ll cnt = max(a[i].y - l + 1, 0ll) / m;
        cnt += max(a[i].y - l + 1, 0ll) % m ? 1 : 0;

        e = l + m * cnt - 1;
        result += cnt;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}