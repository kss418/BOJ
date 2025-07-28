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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result[MAX][MAX], sum[MAX][MAX];

ll cal(ll sy, ll sx, ll ey, ll ex){
    ll ret = sum[ey][ex];
    ret -= sum[ey][max(sx - 1, 0ll)] + sum[max(sy - 1, 0ll)][ex];
    ret += sum[max(sy - 1, 0ll)][max(sx - 1, 0ll)];

    return ret;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    ll mid = m / 2;
    for(int i = 1;i <= n;i++){
        if(i + mid > n) break;

        for(int j = 1;j <= n;j++){
            if(j + mid > n) break;
            sum[i + mid][j + mid] = sum[i + mid][j + mid - 1] + sum[i + mid - 1][j + mid];
            sum[i + mid][j + mid] -= sum[i + mid - 1][j + mid - 1];
            result[i + mid][j + mid] = -a[i][j] - cal(i - mid, j - mid, i + mid, j + mid);
            
            sum[i + mid][j + mid] = sum[i + mid][j + mid - 1] + sum[i + mid - 1][j + mid];
            sum[i + mid][j + mid] += -sum[i + mid - 1][j + mid - 1] + result[i + mid][j + mid];
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cout << result[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

