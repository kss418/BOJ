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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll mn = INF;
ll a, b;

void run(){
    cin >> n;
    for(int i = 1;i * i <= n;i++){
        if(n % i) continue;
        ll ca = i, cb = n / i;
        if(ca + cb >= mn) continue;
        a = ca; b = cb;
        mn = a + b;
    }

    ll fi = max(a, b), se = min(a, b);
    cout << mn << "\n";
    for(int i = 1;i < fi;i++){
        cout << i << " " << i + 1 << "\n";
    }

    for(int i = se;i >= 1;i--){
        cout << fi - i + 1 << " " << fi + i << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}