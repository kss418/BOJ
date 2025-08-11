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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[MAX], tc, sum[MAX];

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        memset(sum, 0, sizeof(sum));
        ll now = 0, end = 0;

        for(int i = 1;i <= 10001;i++){
            end += sum[i];

            ll mn = min(max(now - cnt[i], 0ll), end);
            now -= mn; end -= mn;

            if(now > cnt[i]) return 0;
            sum[min(i + cur, 10002ll)] = max(cnt[i] - now, 0ll);
            now = cnt[i];
        }

        now -= end;
        return !now;
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
    cin >> n; memset(cnt, 0, sizeof(cnt));
    for(int i = 1;i <= n;i++) cin >> a[i], cnt[a[i]]++;

    _bs <ll> bs(0, n);
    cout << "Case #" << ++tc << ": " << bs.ret() << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}