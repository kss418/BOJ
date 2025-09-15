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
constexpr ll MAX = 252; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll dp[MAX][MAX * MAX];

void ch(ll& a, ll b){
    a = min(a, b);
}

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret = (cnt ? INF : 0);

    if(cnt >= a[cur].x) ch(ret, solve(cur - 1, cnt - a[cur].x));
    ch(ret, solve(cur - 1, cnt) + a[cur].y);

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    ll result = INF;
    for(int i = 0;i < MAX * MAX;i++){
        ch(result, max<ll>(solve(n, i), i));
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}