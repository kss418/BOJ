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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], pre[2 * MAX];

class _st { // 1-base index
public:
    ll n, m; vector <vector<ll>> num;
    _st(){};
    _st(ll n, ll m) { //n 개수 m 깊이
        this->n = n; this->m = m;
        num.resize(log2(m + 1) + 1, vector<ll>(n + 1, 0));
    }

    void add(ll st, ll en) {
        num[0][st] = en;
    }

    void init() {
        for (int i = 1; i <= log2(m + 1); i++) {
            for (int j = 1; j <= n; j++) num[i][j] = num[i - 1][num[i - 1][j]];
        }
    }

    ll ret(ll n, ll d) { //n 노드 d 깊이
        for (int i = log2(m + 1); i >= 0; i--) {
            if (d & (1ll << i)) n = num[i][n];
        }

        return n;
    }
}; _st st;

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r, idx;
    _bs(T l, T r, T idx) {
        this->l = l; this->r = r;
        this->idx = idx;
    }

    bool f(T cur) {
        ll nxt = st.ret(idx, cur);
        if(!nxt || nxt >= idx + n) return 1;
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
    cin >> n >> m; st = {2 * n + 1, 2 * n + 1};
    for(int i = 1;i <= n;i++) cin >> a[i]; 
    for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
    for(int i = n + 1;i <= 2 * n;i++) pre[i] = pre[i - 1] + a[i - n];
    pre[2 * n + 1] = INF;

    for(int i = 1;i <= 2 * n;i++){
        ll lb = lower_bound(pre + 1, pre + 2 * n + 2, pre[i - 1] + m) - pre;
        st.add(i, lb + 1);
    }
    st.init();

    for(int i = 1;i <= n;i++){
        _bs <ll> bs(1ll, n, i);
        cout << bs.ret() - 1 << " ";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}