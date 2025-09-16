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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX], pre[MAX], suf[MAX];

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        ll r = 1;
        for(int l = 1;l <= n;l++){
            while(r < n && a[r + 1].x - a[l].x <= 2 * cur) r++;
            ll mid = (a[r].x + a[l].x) / 2;

            ll lb = lower_bound(a, a + n + 2, pll(mid - cur, MINF)) - a - 1;
            ll ub = upper_bound(a, a + n + 2, pll(mid + cur, INF)) - a;

            ll mx = MINF, mn = INF;
            if(lb >= 1) mx = max(mx, pre[lb].y), mn = min(mn, pre[lb].x);
            if(ub <= n) mx = max(mx, suf[ub].y), mn = min(mn, suf[ub].x);

            if(mn == INF || mx - mn <= 2 * cur) return 1;
        }

        return 0;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

void run(){
    cin >> n; _bs <ll> bs(0, 4e9);
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    for(int i = 1;i <= n;i++) a[i].x *= 2, a[i].y *= 2;

    sort(a + 1, a + n + 1); 
    a[n + 1] = {INF, INF}; a[0] = {MINF, MINF};

    for(int i = 0;i <= n + 1;i++){
        pre[i].x = suf[i].x = INF;
        pre[i].y = suf[i].y = MINF;
    }

    for(int i = 1;i <= n;i++){
        pre[i].x = min(pre[i - 1].x, a[i].y);
        pre[i].y = max(pre[i - 1].y, a[i].y);
    }

    for(int i = n;i >= 1;i--){
        suf[i].x = min(suf[i + 1].x, a[i].y);
        suf[i].y = max(suf[i + 1].y, a[i].y);
    }

    ll ret = bs.ret();
    cout << (ret / 2);
    cout << (ret % 2 ? ".5" : ".0");
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}