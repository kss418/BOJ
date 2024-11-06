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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
constexpr ld eps = 1e-9;

int main() {
    fastio;

    cin >> t;
    while(t--){
        ld cur, mul, num; cin >> mul >> cur >> num;
        cur += eps; num += eps;
        cur *= 100; num *= 100;

        ll n = cur, m = num;
        if(!n) {
            cout << 0 << "\n";
            continue;
        }

        ll cnt = 0;
        while(cnt++ <= 1300){
            ld pl = (ld)n * ((ld)mul / (ld)100) + (ld)0.5;
            n += floor(pl + eps); n -= m;
            if(n <= 0) break;
        }

        if(cnt > 1200) cout << "impossible\n";
        else cout << cnt << "\n";
    }
    
    
    return 0;
}