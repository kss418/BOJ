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
pll a[MAX];

ll dist(pll a, pll b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    
    ll mx = INF, idx = -1;
    for(int i = 1;i <= n;i++){
        ll now = 0;
        for(int j = 1;j <= n;j++){
            now = max(now, dist(a[i], a[j]));
        }

        if(now >= mx) continue;
        mx = now; idx = i;
    }

    cout << a[idx].x << " " << a[idx].y;
    

    return 0;
}

