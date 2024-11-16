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
ll t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // PLZ CHK!
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9;
ld n, m, k;

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        ld ay = sqrtl(n * n - cur * cur);
        ld by = sqrtl(m * m - cur * cur);

        ld aa = -ay / cur, ba = by / cur;
        ld cy = ba * (ay / (ba - aa));
        
        if(fabs(cy - k) <= EPS) return 1;
        return cy >= k;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (fabs(hi - lo) > EPS) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) lo = mid;
            else hi = mid;
        }

        return lo;
    }
};

int main() {
    fastio;

    cin >> n >> m >> k;
    _bs<ld> bs(0, 3e9 + 1);

    cout.precision(17);
    cout << bs.ret();    
     
    return 0;
}