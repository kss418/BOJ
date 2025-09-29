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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

void run(){
    cin >> n >> m; 
    ll num = 0, result = 0;
    for(ll i = 62;i >= 0;i--){
        ll now = 1ll << i;
        if(num + now <= m) num += now;
        if(num >= n) break;
    }

    while(num){
        if(num & 1){
            result++;
            num >>= 1ll;
            if(!num) break;
            num++;
        }
        else num >>= 1ll;
    }

    cout << result - 1 << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}