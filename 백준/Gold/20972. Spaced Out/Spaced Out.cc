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
ll a[MAX][MAX], result;

void run(){
    cin >> n; 
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    ll sum = 0;
    for(int j = 1;j <= n;j += 2){
        ll mx = 0;
        for(int k = 0;k < 4;k++){
            for(int l = k + 1;l < 4;l++){
                if((k & 1) == (l & 1)) continue; ll now = 0;
                for(int i = 1;i <= n;i += 2){
                    now += a[i + (k >> 1ll)][j + (k & 1)];
                    now += a[i + (l >> 1ll)][j + (l & 1)];
                }
                mx = max(mx, now);
            }
        }
        sum += mx;
    }

    result = sum; sum = 0;
    for(int i = 1;i <= n;i += 2){
        ll mx = 0;
        for(int k = 0;k < 4;k++){
            for(int l = k + 1;l < 4;l++){
                if((k >> 1) == (l >> 1)) continue; ll now = 0;
                for(int j = 1;j <= n;j += 2){
                    now += a[i + (k >> 1ll)][j + (k & 1)];
                    now += a[i + (l >> 1ll)][j + (l & 1)];
                }
                mx = max(mx, now);
            }
        }
        sum += mx;
    }
    result = max(result, sum);

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

