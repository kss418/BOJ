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
constexpr ll MAX = 22; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll fac[MAX];

void run(){
    cin >> n;
    ll result = 0, f = 0;
    for(int i = n;i >= 0;i--){
        ll now = fac[i];
        now *= fac[n] / (fac[n - i] * fac[i]);
        result += now * (f ? -1 : 1); f ^= 1;
    }

    cout << result << "\n"; 
}

int main() {
    fastio; cin >> t; fac[0] = 1;
    for(int i = 1;i <= 20;i++) fac[i] = fac[i - 1] * i;
    while(t--) run(); 

    return 0;
}