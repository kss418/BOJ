#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
ll a[MAX], c[MAX];
pll b[MAX];

class _ts { // 0-based index
public:
    ll l, r;
    _ts(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll use = 0, ret = 0;
        for(int i = 1;i <= n - cur;i++) use += a[i];
        for(int i = 1;i <= cur;i++) ret += c[i];
        for(int i = 1;i <= m;i++){
            ll mn = min(b[i].y, use);
            use -= mn; ret += b[i].x * mn;
        }
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
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i].y >> b[i].x;
    for(int i = 1;i <= k;i++) cin >> c[i];

    sort(a + 1, a + n + 1, greater<ll>());
    sort(b + 1, b + m + 1, greater<pll>());
    sort(c + 1, c + k + 1, greater<ll>());

    _ts ts(0, min(n, k));
    cout << ts.ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}