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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX], num[MAX][MAX], a[MAX];

ll cal(ll l, ll r){
    ll& ret = num[l][r];
    if(ret != -1) return ret; ret = 0;
    if(l >= r) return ret = 0;

    if(l + 1 == r && a[l] == a[r]) ret = 1;
    if(cal(l + 1, r - 1) && a[l] == a[r]) ret = 1;
    return ret;
}

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != INF) return ret; ret = MINF;
    if(!cur) return ret = 0;

    for(int i = 0;i < cur;i++){
        if(cal(i + 1, cur)) ret = max(ret, solve(i) + 1);
    }
    
    return ret;
}   

void run(){
    cin >> n; memset(dp, 0x3f, sizeof(dp));
    memset(num, -1, sizeof(num));
    for(int i = 1;i <= n;i++) cin >> a[i];

    cout << (solve(n) < 0 ? -1 : solve(n));
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

