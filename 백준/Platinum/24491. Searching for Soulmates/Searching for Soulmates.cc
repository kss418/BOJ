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

ll a(){
    ll result = INF, cnt = 0, div = 0;
    while(n > m){
        if(n % 2) n++, cnt++;
        n >>= 1ll; cnt++;
    }

    while(n){
        while(m / 2 >= n){
            if(m % 2) div++;
            m >>= 1ll, div++;
        }

        result = min(result, cnt + div + m - n);
        if(n == 1) break;
        if(n % 2) n++, cnt++;
        n >>= 1ll; cnt++;
    }

    return result;
}

ll b(){
    ll cnt = 0, result = INF;
    while(m >= n){
        result = min(result, m - n + cnt);
        if(m == 1) break;
        if(m % 2) cnt++;
        m >>= 1ll; cnt++;
    }

    result = min(result, a() + cnt);
    return result;
}

void run(){
    cin >> n >> m; 
    
    if(n > m) cout << a() << "\n";
    else cout << b() << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}