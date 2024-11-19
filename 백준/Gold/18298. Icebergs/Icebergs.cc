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

class _area{
public:
    _area() {}

    ll ret(vector <pll>& v){ // div by 2
        ll num = 0;
        for(int i = 0;i < v.size();i++){
            auto [x1, y1] = v[i];
            auto [x2, y2] = v[(i + 1) % v.size()];
            num += x1 * y2 - x2 * y1;
        }

        return abs(num);
    }
};

int main() {
    fastio;

    cin >> t; ll sum = 0; _area area;
    while(t--){
        cin >> n; vector <pll> arr;
        for(int i = 1;i <= n;i++) {
            cin >> a[i].x >> a[i].y;
            arr.push_back(a[i]);
        }
        
        sum += area.ret(arr);
    }

    cout << (sum >> 1);


    return 0;
}

