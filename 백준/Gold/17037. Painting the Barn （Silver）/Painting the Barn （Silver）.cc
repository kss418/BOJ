#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
ll sum[MAX][MAX], result;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1;i < y2;i++) sum[i][x2]--, sum[i][x1]++;
    }

    for(int i = 0;i <= 1000;i++){
        ll now = 0;
        for(int j = 0;j <= 1000;j++){
            now += sum[i][j];
            if(now == m) result++;
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}