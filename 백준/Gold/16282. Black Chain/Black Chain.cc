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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

void run(){
    cin >> n;
    for(ll i = 1;i <= 100;i++){
        ll now = n, mul = i + 1; now -= i;
        for(ll j = 1;j <= i + 1;j++){
            now -= mul; mul *= 2;
            if(now < 0) break;
        }

        if(now > 0) continue;
        cout << i << "\n"; break;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}