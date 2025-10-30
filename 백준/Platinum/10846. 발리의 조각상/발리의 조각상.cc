#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result = (1ll << 62) - 1;
pll dp[MAX];

void init(){
    for(int i = 0;i <= n;i++) dp[i] = {-1, -1};
}

pll solve(ll cur){
    pll& ret = dp[cur];
    if(ret != pll(-1, -1)) return ret; ret = {INF, 0};
    if(!cur) return ret = {0, 0};

    ll sum = a[cur];
    for(int i = cur - 1;i >= 0;i--){
        if((sum | result) == result){
            pll nxt = solve(i);
            if(nxt.x < INF){
                ret.x = min(ret.x, nxt.x + 1);
                ret.y = max(ret.y, nxt.y + 1);
            }
        }
        sum += a[i];
    }

    return ret;
}

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 61;i >= 0;i--){
        result ^= (1ll << i);
        init(); pll now = solve(n);
        if(now.x > k || now.y < m) result ^= (1ll << i);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}