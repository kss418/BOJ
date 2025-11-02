#include <bits/stdc++.h>
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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result;
bool use[MAX];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        ll cnt = 0, la = -1;
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            if(!a[i][j]) continue;
            la = j; cnt++;
        }

        if(!cnt) continue;
        if(cnt == 1 && !use[la]){ use[la] = 1; continue; }
        result++;
    }

    cout << max(result - 1, 0ll);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}