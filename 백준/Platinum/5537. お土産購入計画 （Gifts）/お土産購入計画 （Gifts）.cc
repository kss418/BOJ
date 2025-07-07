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

constexpr ll INF = 0x3f3f;
constexpr ll MINF = 0xc0c0;
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
short dp[MAX][MAX][4][1ll << 12];
ll mask = (1ll << 12) - 1;
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

short solve(ll cy, ll cx, ll cnt, ll pre){
    if(cy < 0 || cx < 0) return MINF;
    short& ret = dp[cy][cx][cnt][pre];
    if(ret != INF) return ret; ret = MINF;

    if(cy == n && cx == m - 1) return ret = 0;
    if(cy == n - 1 && cx == m) return ret = 0;
    if(cy >= n || cx >= m) return ret = MINF;

    ll str = st[cy][cx];
    if(str == '#') return ret = MINF;

    bool chk = 0;
    ll ty = cy, tx = cx, tp = pre;
    while(tp){
        ll cur = tp & 3ll;
        ty += dy[cur ^ 2]; tx += dx[cur ^ 2];
        if(ty == cy && tx == cx){ chk = 1; break; }
        tp >>= 2ll;
    }

    for(int i = 0;i < 4;i++){
        ll ny = cy + dy[i], nx = cx + dx[i];
        ll nxt = ((pre << 2ll) | i) & mask;
        if(cnt && i >= 2){
            ret = max<short>(ret, solve(ny, nx, cnt - 1, nxt) + (chk || str == '.' ? 0 : str - '0'));
        }
        else if(i <= 1){
            ret = max<short>(ret, solve(ny, nx, cnt, nxt) + (chk || str == '.' ? 0 : str - '0'));
        }
    }

    return ret;
}

void run(){
    cin >> n >> m >> k; memset(dp, 0x3f, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> st[i];

    cout << solve(0, 0, k, 0) << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

