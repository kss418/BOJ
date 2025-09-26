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
ll a[MAX], dp[MAX];

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        memset(dp, 0, sizeof(dp));
        ll mx = 0, result = 0;
        for(int i = 1;i <= n;i++){
            dp[i] = mx + a[i];
            result = max(result, dp[i]);
            if(i >= cur) mx = max(mx, dp[i - cur]);
        }

        return result >= m;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) / (T)2;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};

void run(){
    cin >> n >> m; _bs <ll> bs(0, n); 
    ll mx = MINF, sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i]; sum += a[i];
        mx = max(mx, a[i]);
    }

    if(mx >= m) { cout << "Free!"; return; }
    if(m > sum) { cout << -1; return; }
    cout << bs.ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}