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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll l[MAX], r[MAX];

class _st { // 1-base index
public:
    ll n, m; vector <vector<ll>> num;
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
};

void run(){
    cin >> n >> m >> k; _st st(n, k);
    for(int i = 1;i <= n;i++) cin >> l[i] >> r[i];
    while(m--){
        char c; cin >> c;
        s.push_back(c);
    }

    for(int i = 1;i <= n;i++){
        ll cur = i;
        for(auto& j : s){
            cur = (j == 'L' ? l[cur] : r[cur]);
        }

        st.add(i, cur);
    }

    st.init();
    cout << st.ret(1, k);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

