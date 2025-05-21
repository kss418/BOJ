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
ll a[6];

void run(){
    cin >> n;
    a[1] = (n - 2) * (n - 1);
    a[2] = n - 1;
    a[3] = (n - 2) * (n - 1) / 2;
    a[4] = 2 * (n - 1);
    a[5] = 1;

    cout << a[1] * 7 + a[2] * 14 + a[3] * 21 + a[4] * 28 + a[5] * 35;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

