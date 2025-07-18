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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll cnt[MAX], result;

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
};

void run(){
    cin >> n; _gcd gcd;
    for(int i = 1;i <= n;i++) cin >> m, cnt[m]++;

    for(int i = 1;i < MAX;i++){
        ll num = 0, mx = 0, g = 0;
        for(int j = 1;j < MAX;j++){
            if(!cnt[j]) continue;
            if(j % i == 0){
                num = gcd.ret(num, j);
                if(cnt[j] > 1) mx = max<ll>(mx, j);
            }
            else g = gcd.ret(g, j);
        }

        if(!num) continue;
        if(!g) g = mx;
        result = max(result, i + g);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

