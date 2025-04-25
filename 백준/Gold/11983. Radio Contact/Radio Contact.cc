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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll by[MAX], bx[MAX], fy[MAX], fx[MAX];
string sb, sf;
map <char, ll> dy, dx;
ll dp[MAX][MAX];

ll dist(ll cf, ll cb){
    ll dy = fy[cf] - by[cb];
    ll dx = fx[cf] - bx[cb];
    return dx * dx + dy * dy;
}

ll solve(ll cf, ll cb){
    ll& ret = dp[cf][cb];
    if(ret != -1) return ret; ret = INF;

    if(cf) ret = min(ret, solve(cf - 1, cb) + dist(cf, cb));
    if(cb) ret = min(ret, solve(cf, cb - 1) + dist(cf, cb));
    if(cf && cb) ret = min(ret, solve(cf - 1, cb - 1) + dist(cf, cb));

    return ret;
}

void run(){
    cin >> n >> m;
    cin >> fx[0] >> fy[0] >> bx[0] >> by[0];
    cin >> sf >> sb;

    dy['N'] = 1; dy['S'] = -1;
    dx['E'] = 1; dx['W'] = -1;

    for(int i = 0;i < n;i++){
        fy[i + 1] = fy[i] + dy[sf[i]];
        fx[i + 1] = fx[i] + dx[sf[i]];
    }

    for(int i = 0;i < m;i++){
        by[i + 1] = by[i] + dy[sb[i]];
        bx[i + 1] = bx[i] + dx[sb[i]];
    }

    memset(dp, -1, sizeof(dp)); dp[0][0] = 0;
    cout << solve(n, m);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

