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

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; pll a, b;
        ld result = 0;

        for(int i = 1;i <= n;i++){
            cin >> a.y >> a.x >> b.y >> b.x;
            ld da = atan2l(a.y, a.x) * (ld)180 / M_PI;
            ld db = atan2l(b.y, b.x) * (ld)180 / M_PI;
            da = fmodl(da + 360, 360); db = fmodl(db + 360, 360);
            if(da > db) swap(da, db);

            ld diff = min(db - da, da - db + (ld)360) / (ld)360;
            result += diff;
        }

        cout << fixed << setprecision(5);
        cout << result << "\n";
    }


    return 0;
}

