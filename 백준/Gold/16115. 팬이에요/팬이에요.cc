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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
vector <ld> num;

ll dist(pll a){
    return a.x * a.x + a.y * a.y;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, [](pll a, pll b){
        return dist(a) < dist(b);
    });

    for(int i = n;i >= 1;i--){
        if(dist(a[n]) != dist(a[i])) break;
        ll cx = a[i].x, cy = -a[i].y;
        ld rad = atan2l(cy, cx);
        ld deg = fmodl((rad * 180.0 / M_PI + 360), 360);
        num.push_back(deg);
    }
    sort(all(num));

    ld mx = 0;
    for(int i = 0;i < num.size() - 1;i++){
        mx = max(num[i + 1] - num[i], mx);
    }
    mx = max(mx, num[0] - num[num.size() - 1] + 360);
    
    cout.precision(10);
    cout << mx;
    
     
    return 0;
}