#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 501; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll f[MAX], num[MAX][2];

class _bm { // 1-based index
public:
    ll as, bs; vector<vector<ll>> adj;
    vector<ll> av, bv, v;

    _bm(ll a, ll b) {
        as = a; bs = b;
        av.resize(a + 1, -1); bv.resize(b + 1, -1);
        adj.resize(a + 1); v.resize(a + 1);
    }

    void addsol(ll st, ll en) {
        adj[st].push_back(en);
    }

    bool dfs(ll a) {
        v[a] = 1;
        for (auto& b : adj[a]) {
            if (bv[b] == -1 || !v[bv[b]] && dfs(bv[b])) {
                av[a] = b; bv[b] = a;
                return 1;
            }
        }
        return 0;
    }

    ll ret() {
        memset(&av[0], -1, sizeof(av[0]) * av.size());
        memset(&bv[0], -1, sizeof(bv[0]) * bv.size());
        ll result = 0;

        for (int i = 1; i <= as; i++) {
            if (av[i] != -1) continue;
            memset(&v[0], 0, sizeof(v[0]) * v.size());
            if (dfs(i)) result++;
        }

        return result;
    }

    void clear() {
        for (int i = 1; i <= as; i++) adj[i].clear();
    }
};

ll tf(string& st){
    ll ret = 0;
    for(int i = 1;i < st.size();i++){
        ret *= 10;
        ret += st[i] - '0';
    }

    return ret;
}

void run(){
    cin >> n >> m >> k; _bm bm(k, k);
    for(int i = 1;i <= k;i++){
        string a, b; cin >> a >> b;
        f[i] = (a[0] == 'C' ? 0 : 1);
        num[i][0] = tf(a); num[i][1] = tf(b);
    }

    for(int i = 1;i <= k;i++){
        for(int j = i + 1;j <= k;j++){
            if(f[i] == f[j]) continue;
            if(num[i][0] != num[j][1] && num[i][1] != num[j][0]) continue;

            if(!f[i]) bm.addsol(i, j);
            else bm.addsol(j, i);
        }
    }

    cout << k - bm.ret() << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

