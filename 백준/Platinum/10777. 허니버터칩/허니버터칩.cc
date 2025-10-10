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
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;
int a[MAX], b[102], dp[MAX][102][102][2];

int solve(ll cur, ll l, ll r, ll cnt){
    int& ret = dp[cur][l][r][cnt];
    if(ret != -1) return ret; ret = 0;
    if(!cur && l > r) return ret;

    if(cnt){
        if(cur) ret = max(ret, solve(cur - 1, l, r, 0) + a[cur]);
        if(l <= r) ret = max(ret, solve(cur, l, r - 1, 0) + b[r]);
    }
    else{
        if(cur){
            ret = max(ret, solve(cur - 1, l, r, 1));
            ret = max(ret, solve(cur - 1, l, r, 0));
        }

        if(l <= r){
            ret = max(ret, solve(cur, l + 1, r, 1));
            ret = max(ret, solve(cur, l + 1, r, 0));
        }
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    
    cin >> m;
    for(int i = 1;i <= m;i++) cin >> b[i];
    sort(b + 1, b + m + 1);

    cout << max(solve(n, 1, m, 0), solve(n, 1, m, 1));
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}