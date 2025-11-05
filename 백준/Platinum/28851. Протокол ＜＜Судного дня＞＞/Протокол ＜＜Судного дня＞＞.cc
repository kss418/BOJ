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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> org[MAX], adj[MAX], rev[MAX];
ll d[MAX];

void mn(ll& a, ll b){
    if(d[a] < d[b]) return;
    a = b;
}

class _st { // 1-base index
public:
    ll n, m; vector <vector<ll>> num;
    _st(){}
    _st(ll n, ll m) { //n 개수 m 깊이
        this->n = n; this->m = m;
        num.resize(log2(m + 1) + 1, vector<ll>(n + 1));
        for(int i = 0;i <= log2(m + 1);i++){
            for(int j = 1;j <= n;j++) num[i][j] = j;
        }
    }

    void add(ll st, ll en) {
        mn(num[0][st], en);
    }

    void init() {
        for (int i = 1; i <= log2(m + 1); i++) {
            for (int j = 1; j <= n; j++){
                mn(num[i][j], num[i - 1][num[i - 1][j]]);
            }
        }
    }

    void merge(ll st, ll en){
        for(int i = 0;i <= log2(m + 1);i++){
            mn(num[i][st], num[i][en]);
        }

        for (int i = 1; i <= log2(m + 1); i++){
            mn(num[i][st], num[i - 1][num[i - 1][st]]);
        }
    }

    ll ret(ll n, ll d) { //n 노드 d 깊이
        for (int i = log2(m + 1); i >= 0; i--) {
            if (d & (1ll << i)) n = num[i][n];
        }

        return n;
    }
}; _st st;

void init(ll cur = 1, ll pre = -1){
    for(auto& nxt : org[cur]){
        if(pre == nxt) continue;
        d[nxt] = d[cur] + 1;
        adj[cur].push_back(nxt);
        init(nxt, cur);
    }
}

void dfs(ll cur = 1){
    for(auto& nxt : adj[cur]){
        dfs(nxt);
        st.merge(cur, nxt);
    }
}

void run(){
    cin >> n; d[1] = 1;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        org[s].push_back(e);
        org[e].push_back(s);
    }
    init();

    cin >> m; st = {n, m};
    while(m--){
        ll s, e; cin >> s >> e;
        st.add(s, e); st.add(e, s);
    }

    st.init(); dfs(); st.init();
    cin >> k;
    while(k--){
        ll s, c; cin >> s >> c;
        cout << st.ret(s, c) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
