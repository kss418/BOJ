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
string st[MAX];
ll sum[MAX][MAX][2], dp[MAX][MAX][2];
ll result;

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(st[i - 1][j - 1] == '0') continue;
            sum[i][j][0] = sum[i - 1][j + 1][0] + 1;
            sum[i][j][1] = sum[i - 1][j - 1][1] + 1;
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ll mn = min(sum[i][j][0], sum[i][j][1]);
            for(int k = 1;k <= mn;k++){
                ll ny = i - k + 1;
                ll nx1 = j - k + 1, nx2 = j + k - 1;
                if(ny <= 0 || nx1 <= 0 || nx2 > m) break;
                ll now = min(sum[ny][nx1][0], sum[ny][nx2][1]);
                if(now >= k) result = max<ll>(result, k);
            }
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}