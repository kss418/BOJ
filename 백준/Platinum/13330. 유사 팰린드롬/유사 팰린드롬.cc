#include <bits/stdc++.h>
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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
short a[MAX][MAX], dp[MAX];

short num(ll l, ll r){
    short& ret = a[l][r];
    if(ret != -1) return ret; ret = 0;
    if(l - 1 == r || l == r) return ret = 0;
    if(s[l - 1] == s[r - 1]) ret = max<short>(ret, num(l + 1, r - 1) + 2); 

    return ret;
}

short solve(ll cur){
    short& ret = dp[cur];
    if(ret != -1) return ret; ret = 0x3f3f;
    if(!cur) return ret = 0;

    for(int i = 0;i < cur;i++){
        short now = num(i + 1, cur), len = cur - i;
        if(m * len > k * now) continue;
        ret = min<short>(ret, solve(i) + 1);
    }

    return ret;
}

void run(){
    cin >> n >> m >> k >> s;
    memset(a, -1, sizeof(a));
    memset(dp, -1, sizeof(dp));

    short ret = solve(n);
    cout << (ret >= 0x3f3f ? 0 : ret);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}