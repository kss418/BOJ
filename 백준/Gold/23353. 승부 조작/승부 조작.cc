#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX];
ll y[MAX][MAX][2], x[MAX][MAX][2];
ll pd[MAX][MAX][2], nd[MAX][MAX][2];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            y[i][j][0] = a[i][j] == 1 ? y[i - 1][j][0] + 1 : 0;
            x[i][j][0] = a[i][j] == 1 ? x[i][j - 1][0] + 1 : 0;
            pd[i][j][0] = a[i][j] == 1 ? pd[i - 1][j - 1][0] + 1 : 0;
            nd[i][j][0] = a[i][j] == 1 ? nd[i - 1][j + 1][0] + 1 : 0;
        }   
    }

    for(int i = n;i >= 1;i--){
        for(int j = n;j >= 1;j--){
            y[i][j][1] = a[i][j] == 1 ? y[i + 1][j][1] + 1 : 0;
            x[i][j][1] = a[i][j] == 1 ? x[i][j + 1][1] + 1 : 0;
            pd[i][j][1] = a[i][j] == 1 ? pd[i + 1][j + 1][1] + 1 : 0;
            nd[i][j][1] = a[i][j] == 1 ? nd[i + 1][j - 1][1] + 1 : 0;
        }   
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            result = max(result, x[i][j][0]);
            result = max(result, y[i][j][0]);
            result = max(result, pd[i][j][0]);
            result = max(result, nd[i][j][0]);

            if(a[i][j] != 2) continue;
            result = max(result, y[i - 1][j][0] + y[i + 1][j][1] + 1);
            result = max(result, x[i][j - 1][0] + x[i][j + 1][1] + 1);
            result = max(result, pd[i - 1][j - 1][0] + pd[i + 1][j + 1][1] + 1);
            result = max(result, nd[i - 1][j + 1][0] + nd[i + 1][j - 1][1] + 1);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}