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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

class _gcd {
public:
    _gcd() {}

    tll init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
}; _gcd g;

void run(){
    cin >> n; ll num = a[1];
    for(int i = 1;i <= n;i++) cin >> a[i], num = g.ret(num, a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++) a[i] /= num;  
    
    ll div = a[2], mx = -1, dis = -1;
    for(int i = 3;i <= n;i++) div = g.ret(a[i], div);
    if(a[1] % div) mx = div * num, dis = a[1] * num;

    div = a[1];
    for(int i = 3;i <= n;i++) div = g.ret(a[i], div);
    if(a[2] % div && mx < div * num) mx = div * num, dis = a[2] * num;

    if(mx == -1){ cout << -1; return; }
    cout << mx << " " << dis;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}


