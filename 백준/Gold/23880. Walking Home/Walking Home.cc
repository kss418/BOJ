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
constexpr ll MAX = 51; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll dp[MAX][MAX][4][2];

ll solve(ll cy, ll cx, ll cnt, ll dir){
    if(cy < 0 || cx < 0) return 0;
    ll&ret = dp[cy][cx][cnt][dir];
    if(ret != -1) return ret;
    if(!cy && !cx) return ret = 1;
    if(st[cy][cx] != '.') return ret = 0; ret = 0;

    if(!dir){
        ret += solve(cy - 1, cx, cnt, dir);
        if(cnt && (cy != n - 1 || cx != n - 1)) ret += solve(cy, cx - 1, cnt - 1, dir ^ 1);
    }
    else{
        ret += solve(cy, cx - 1, cnt, dir);
        if(cnt && (cy != n - 1 || cx != n - 1)) ret += solve(cy - 1, cx, cnt - 1, dir ^ 1);
    }

    return ret;
}   

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];
    ll result = 0; memset(dp, -1, sizeof(dp));
    result += solve(n - 1, n - 1, m, 0);
    result += solve(n - 1, n - 1, m, 1);

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}