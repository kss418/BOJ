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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll cnt[21], num[21], a[MAX];
ll dp[21][1ll << 21], c;

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
}; _gcd g;

ll solve(ll cur, ll v){
    ll& ret = dp[cur][v];
    if(ret != -1) return ret;
    ret = 0;

    for(int nxt = 1;nxt <= c;nxt++){
        if(!(v & (1ll << nxt))) continue;
        ret = max(ret, solve(nxt, v & ~(1ll << nxt)) + ((cur) ? g.ret(num[cur], num[nxt]) : 0));
    }

    return ret;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], cnt[a[i]]++;

    ll result = 0, flag = 1;
    for(int i = 1;i <= 20;i++) {
        result += (cnt[i]) ? (cnt[i] - 1) * i : 0;
        if(cnt[i] && (i != 1 && i != 13 && i != 17 && i != 11 && i != 19)) flag = 0;
    }
    if(cnt[1]) result++;
    if(cnt[19]) result++;
    if(cnt[17]) result++;
    if(cnt[13]) result++;
    if(cnt[11]) result++;

    for(int i = 2;i <= 20;i++){
        if(i == 19 || i == 17 || i == 13 || i == 11) continue;
        if(cnt[i]) num[++c] = i;
    }
    
    memset(dp, -1, sizeof(dp));
    cout << solve(0, (1ll << (c + 1)) - 1) + result - flag;

     
    return 0;
}