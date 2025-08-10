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
constexpr ll MAX = 222; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX][11];

ll solve(ll cur, ll mx, ll cnt){
    ll& ret = dp[cur][mx][cnt];
    if(ret != -1) return ret; ret = 0;
    if(cnt == m) return ret = (cur >= mx);

    for(int i = mx;i <= cur;i++){
        ret += solve(cur - i, i, cnt + 1);
    }

    return ret;
}

void run(){
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));

    ll sum = n, la = 1;
    for(int i = 2;i <= m;i++){
        for(int j = la;j <= sum;j++){
            ll now = solve(sum - j, j, i);
            if(k > now) k -= now;
            else{
                sum -= j; la = j;
                cout << j << "\n";
                break;
            }
        }
    }
    cout << sum << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}