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
constexpr ll MAX = 21;
constexpr ll MOD = 998244353;
ll dp[MAX][MAX], fac[MAX];

void init(){
    dp[0][0] = 1;
    for(int i = 1;i <= 20;i++){
        for(int j = 1;j <= i;j++){
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * (i - 1);
        }
    }

    fac[0] = 1;
    for(int i = 1;i <= 20;i++) fac[i] = fac[i - 1] * i;
}

class _gcd {
public:
    _gcd() {}

    tll init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
};


int main() {
    fastio;

    cin >> n >> m;
    init(); _gcd gcd;

    ll a = 0;
    for(int i = 1;i <= m;i++) a += dp[n][i];
    ll b = fac[n];

    ll g = gcd.ret(a, b);
    cout << a / g << "/" << b / g;
    
    
    
    return 0;
}