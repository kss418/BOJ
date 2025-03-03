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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], d[MAX][MAX];

bool chk(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < m;j++){
            d[i][j] = a[i][j] - a[i][j + 1];
        }
    }

    for(int j = 1;j < m;j++){
        for(int i = 2;i <= n;i++){
            if(d[i][j] < d[i - 1][j]) return 0;
        }
    }
    return 1;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }

    cout << (chk() ? "YES" : "NO") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}