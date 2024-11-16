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
constexpr ll MAX = 51; // PLZ CHK!
constexpr ll MOD = 998244353;
pll a[MAX];

ld area(pll a, pll b, pll c){
    ll p = a.x * b.y + b.x * c.y + c.x * a.y;
    ll m = a.y * b.x + b.y * c.x + c.y * a.x;

    return abs(p - m) / (ld)2;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    ld result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                result = max(result, area(a[i], a[j], a[k]));
            }
        }
    }

    cout.precision(15);
    cout << result;
    
     
    return 0;
}