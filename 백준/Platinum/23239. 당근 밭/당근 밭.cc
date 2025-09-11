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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX], b[MAX];

ll get_sq(ll num){
    ll sq = sqrtl(num);
    while((sq + 1) * (sq + 1) <= num) sq++;
    while(sq > 0 && (sq - 1) * (sq - 1) > num) sq--;
    return sq;
}

void run(){
    cin >> n >> m >> k;

    ll result = 0;
    for(ll i = 1;i <= k;i++){
        ll p = k * k - i * i;
        result += get_sq(p);
    }
    result *= 3; result += 2 * k;

    ll d = k - n;
    for(ll i = 0;i <= min(d, 0ll);i++){
        ll p = d * d, now = get_sq(p);
        result += max(now - m, 0ll);
        a[i + n] = {m + 1, max(now, m)};
    }

    for(ll i = 1;i <= d;i++){
        ll p = d * d - i * i;
        ll now = get_sq(p);
        result += now + 1;
        a[i + n] = {0, now};
    }

    d = k - m;
    for(ll i = 0;i <= d;i++){
        ll p = d * d - i * i;
        ll now = get_sq(p);
        result += now + (i <= n ? 0 : 1);
        b[i] = {i <= n ? m + 1 : m, m + now};
    }

    for(int i = n;i <= k - m;i++){
        ll num = max(min(a[i].y, b[i].y) - b[i].x + 1, 0ll);
        result -= num;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}