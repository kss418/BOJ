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
    cin >> n >> m >> k;
    if(k < n) cout << "Bob\n";
    else if(k <= n + 2 * m - 2) cout << "Alice\n";
    else if(n <= 2 * m - 1 && k >= 3 * n && k <= n + 4 * m - 2) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}