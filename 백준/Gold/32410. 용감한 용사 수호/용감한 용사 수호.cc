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
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll atk, hp, dp[303][303][303], sum[303][303], result;
pll a[MAX], b[MAX];

void chmax(ll& a, ll b){
    a = max(a, b);
}

void run(){
    cin >> n >> m >> atk >> hp; memset(dp, 0xc0, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    dp[0][0][atk] = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= m;j++){
            for(int k = 0;k <= 300;k++){
                chmax(dp[i + 1][j + 1][min(k + a[i + 1].x, 300ll)], dp[i][j][k] + a[i + 1].y);
                chmax(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }

    cin >> k;
    for(int i = 1;i <= k;i++) cin >> b[i].x >> b[i].y;
    sort(b + 1, b + k + 1);

    for(int i = 1;i <= k;i++) sum[b[i].x][b[i].y]++;

    for(int i = 1;i <= 300;i++){
        for(int j = 1;j <= 300;j++) sum[i][j] += sum[i][j - 1];
        for(int j = 1;j <= 300;j++) sum[i][j] += sum[i - 1][j];
    }

    for(int i = 1;i <= 300;i++){
        ll now = min(dp[n][m][min(i + atk, 300ll)] + hp, 300ll);
        if(now <= 0) continue;
        result = max(result, sum[min(i + atk, 300ll)][now]);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

