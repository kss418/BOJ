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
ll a[MAX][MAX], dp[MAX], tr[MAX];
ll s1[MAX][MAX], s2[MAX][MAX];
vector <ll> ret;

ll cal(ll s, ll e){
    ll ret = 0;
    ret += s2[e][e] - s2[e][s - 1] - s2[s - 1][e] + s2[s - 1][s - 1];
    ret += s1[e][n] - s1[s - 1][n] - s1[e][e] + s1[s - 1][e];

    return ret;
}

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = INF;
    for(int i = 0;i < cur;i++){
        ll now = solve(i) + cal(i + 1, cur);
        if(now >= ret) continue;
        ret = now; tr[cur] = i;
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++){
        while(1){
            ll num; cin >> num;
            if(!num) break;
            a[i][num] = 1;
        }
    }

    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            s1[i][j] = s1[i - 1][j] + s1[i][j - 1] - s1[i - 1][j - 1];
            if(a[i][j] && j > i) s1[i][j]++;
            s2[i][j] = s2[i - 1][j] + s2[i][j - 1] - s2[i - 1][j - 1];
            if(!a[i][j] && j > i) s2[i][j]++;
        }
    }

    cout << solve(n) << "\n";
    while(n){
        ret.push_back(n - tr[n]);
        n = tr[n];
    }

    reverse(all(ret));
    cout << ret.size() << " ";
    for(auto& i : ret) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}