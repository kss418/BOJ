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
constexpr ll MID = 1501;
ld dp[MAX][MAX];

ld solve(ll cur, ll cnt){
    ld& ret = dp[cur][cnt];
    if(ret > -0.5) return ret; ret = 0;

    ll mn = max(cur / 2, 1ll);
    ll mx = min((cur + 1) / 2 + 1, cur);

    for(int i = mn;i <= mx;i++){
        if(i > cnt) ret += solve(i - 1, cnt);
        else if(cnt > i) ret += solve(cur - i, cnt - i);
    }

    ret /= (mx - mn + 1); ret += 1;
    return ret;
} 

void run(){
    ll q; cin >> q; 
    memset(dp, -2, sizeof(dp)); dp[1][1] = 1;

    cout.precision(10);
    while(q--){
        cin >> n >> m >> k;
        cout << solve(m - n + 1, k - n + 1) << "\n";
    }
}

int main() {
    fastio; //cin >> t;
    while(t--) run(); 

    return 0;
}