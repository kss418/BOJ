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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 16; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[1ll << MAX][101], a[MAX], cnt[MAX];
string st[MAX];

class _pow {
public:
	_pow() {}

	ll ret(ll a, ll b){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a;
            a *= a; b >>= 1;
        }      
        return ret;
    }

	ll ret(ll a, ll b, ll p){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a % p, ret %= p;
            a *= a; a %= p; b >>= 1;
        }      
        return ret;
    }
};

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

ll solve(ll v, ll mod){
    ll& ret = dp[v][mod]; 
    if(v == (1ll << (n + 1)) - 1) return ret = (mod % m == 0);
    if(ret != -1) return ret; ret = 0;

    for(ll nxt = 1;nxt <= n;nxt++){
        if(v & (1ll << nxt)) continue;
        ret += solve(v | (1ll << nxt), ((mod * cnt[nxt]) % m + a[nxt]) % m);
    }

    return ret;
}

void run(){
    cin >> n; _gcd gcd; _pow pow;
    for(int i = 1;i <= n;i++) cin >> st[i];
    cin >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++){
        cnt[i] = pow.ret(10, st[i].size(), m);
        for(auto& j : st[i]){
            a[i] *= 10; a[i] %= m;
            a[i] += j - '0'; a[i] %= m;
        }
    }

    ll fi = solve(1, 0), se = 1;
    for(int i = 1;i <= n;i++) se *= i;
    ll g = gcd.ret(fi, se); fi /= g; se /= g;
    cout << fi << "/" << se;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

