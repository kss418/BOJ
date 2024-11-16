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
constexpr ll MAX = 1501; // PLZ CHK!
constexpr ll MOD = 998244353;
pll a[MAX];
ll diff[3];

bool chk(pll a, pll b, pll c){
    pll da = {a.x - b.x, a.y - b.y};
    pll db = {b.x - c.x, b.y - c.y};
    pll dc = {c.x - a.x, c.y - a.y};

    diff[0] = da.x * da.x + da.y * da.y;
    diff[1] = db.x * db.x + db.y * db.y;
    diff[2] = dc.x * dc.x + dc.y * dc.y;

    bool ret = 0;
    for(int i = 0;i < 3;i++) {
        ret |= (diff[i] + diff[(i + 1) % 3]) == diff[(i + 2) % 3];
    }

    return ret;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++) result += chk(a[i], a[j], a[k]);
        }
    }

    cout << result;
    
     
    return 0;
}