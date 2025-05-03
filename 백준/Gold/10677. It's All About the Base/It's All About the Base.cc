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
ll a[MAX];

ll cal(ll num, ll cur){
    return cur * cur * (num / 100) + cur * ((num % 100) / 10) + num % 10;
}

ll chk(ll cur){
    ll a = m / 100, b = (m % 100) / 10, c = m % 10;
    ll num = cal(n, cur); c -= num;

    if(b * b - 4 * a * c < 0) return 0;

    ll x = (-b + sqrtl(b * b - 4 * a * c)) / (2 * a);
    if(num == cal(m, x)) return x;

    x = (-b - sqrtl(b * b - 4 * a * c)) / (2 * a);
    if(num == cal(m, x)) return x;

    return 0;
}

void run(){
    cin >> n >> m;
    for(int i = 10;i <= 15000;i++){
        ll now = chk(i);
        if(now < 10 || now > 15000) continue;
        cout << i << " " << now << "\n"; 
        return;
    } 
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

