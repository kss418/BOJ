#include <bits/stdc++.h>
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
constexpr ld EPS = 1e-15;

int main() {
    fastio;

    cin >> n; n >>= 1;
    ll result = 0;
    for (ll i = -n + 1; i <= 0; i++) {
        ll cur = n * n - i * i;
        ll pre = n * n - (i - 1) * (i - 1);

        ll sqc = sqrtl(cur), sqp = sqrtl(pre);
        if (sqc * sqc != cur) sqc++;

        result += sqc - sqp;
    }

    cout << 4 * result;


    return 0;
}