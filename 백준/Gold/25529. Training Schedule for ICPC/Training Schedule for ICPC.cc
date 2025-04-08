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

class _ts { // 0-based index
public:
    ll l, r;
    _ts(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll ret = cur * cur + n - cur;
        ll div = m / (n - cur + 2), mod = m % (n - cur + 2);
        ret -= div * div * (n - cur - mod + 2);
        ret -= (div + 1) * (div + 1) * mod;
        return ret;
    }

    ll ret() {
        while (r - l > 3) {
            ll st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            if(f(st) < f(en)) l = st;
            else r = en;
        }

        ll result = -INF;
        for(ll cur = l; cur <= r;cur++) result = max(result, f(cur));

        return result;
    }
};

void run(){
    while(1){
        cin >> n >> m;
        if(!n && !m) return;
        if(!n){
            cout << -m * m << "\n";
            continue;
        }

        _ts ts(1, n);
        cout << ts.ret() << "\n";
    }
}   

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

