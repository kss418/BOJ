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
ll result = -1, dp[MAX];

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
            if(ind[i]) continue;
            if(s[i] == 'K') dp[i] = 1;
            if(s[i] == 'D') dp[i] = -1;
            if(s[i] == 'H') dp[i] = 0;
            q.push_back(i);
        }

        while (!q.empty()) {
            ll cur = q.front(); q.pop_front();
            sort.push_back(cur);
            for (auto& nxt : adj[cur]) {
                dp[nxt] = max(dp[nxt], dp[cur] + 1);
                if(!--ind[nxt]) q.push_back(nxt);
            }
        }
    }

    vector <ll> ret() { return sort; }
};

bool chk(ll st, ll en){
    if(s[st] == 'K' && s[en] != 'D') return 0;
    if(s[st] == 'D' && s[en] != 'H') return 0;
    if(s[st] == 'H' && s[en] != 'K') return 0;
    return 1;
}

void run(){
    cin >> n >> m >> s; _tsort ts(n);
    memset(dp, 0xc0, sizeof(dp));
    while(m--){
        ll s, e; cin >> s >> e; s--; e--;
        if(chk(s, e)) ts.addsol(s, e);
        if(chk(e, s)) ts.addsol(e, s);
    }
    ts.init();

    for(int i = 0;i < n;i++) result = max(result, dp[i] / 3);
    for(int i = 0;i < n;i++) if(ts.ind[i]) result = -1;

    cout << (result <= 0 ? -1 : 3 * result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

