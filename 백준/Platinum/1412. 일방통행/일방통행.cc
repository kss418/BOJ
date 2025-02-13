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
constexpr ll MAX = 51; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], flag;
string st[MAX];

class _tsort {
public:
    ll n; vector<vector<ll>> adj;
    vector<ll> ind, sort;
    _tsort(ll n) {
        this->n = n; adj.resize(n + 1);
        ind.resize(n + 1);
    }

    void addsol(ll st, ll en) {
        adj[st].push_back(en);
        ind[en]++;
    }

    void init() {
        deque <ll> q;
        for (int i = 0; i < n; i++) {
            if (ind[i]) continue;
            q.push_back(i);
        }

        while (!q.empty()) {
            ll cur = q.front(); q.pop_front();
            sort.push_back(cur);

            for (auto& nxt : adj[cur]) {
                if (!--ind[nxt]) q.push_back(nxt);
            }
        }
    }

    vector <ll> ret() { return sort; }
};

void run(){
    cin >> n; _tsort ts(n);
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(st[i][j] == 'N') continue;
            if(st[j][i] == 'Y') continue;
            ts.addsol(i, j);
        }
    }

    ts.init();
    for(int i = 0;i < n;i++){
        if(ts.ind[i]) flag = 1;
    }

    cout << (flag ? "NO" : "YES");
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

