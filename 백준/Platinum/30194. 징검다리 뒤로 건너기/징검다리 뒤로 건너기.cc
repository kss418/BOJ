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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 1e9 + 7;
ll dp[MAX][55];

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;
    if(cur == 1) return ret = (cnt == 1 ? 1 : 0);

    ll nxt = cur - cnt;
    if(!nxt) return ret;

    for(ll i = 1;i <= min(nxt, m);i++){
        ll mn = min(m - (cur - nxt) + 1, i); 
        ret += mn * solve(nxt, i);
        ret %= MOD;
    }

    return ret %= MOD;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    ll result = 0;
    for(int i = 1;i <= m;i++){
        result += solve(n, i);
        result %= MOD;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}