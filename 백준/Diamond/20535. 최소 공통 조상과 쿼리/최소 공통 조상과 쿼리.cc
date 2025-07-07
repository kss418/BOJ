#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class _lca { // 1-based index
public:
    ll n, m; vector <ll> d;
    vector <vector<ll>> p;
    vector <vector<pll>> adj;

    class node{
    public:
        ll v;
        node() : node(0) {}
        node(ll v) : v(v) {}

        operator ll(){ // query
            return v;
        }
    };
    vector <vector<node>> arr;

    _lca() {}
    _lca(ll n, bool m = 0) { //n 개수
        this->n = n; this->m = m; 
        p.resize(log2(n + 1) + 1, vector<ll>(n + 1, -1));
        d.resize(n + 1); adj.resize(n + 1);
        fill(d.begin(), d.end(), -1);

        if(m) arr.resize(log2(n + 1) + 1, vector<node>(n + 1, node()));
    }

    void add(ll a, ll b, ll c = 1) { // 양방향
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    void addsol(ll a, ll b, ll c = 1) { // 단방향
        adj[a].push_back({b, c});
    }

    node merge(const node& a, const node& b){
        return {
            max(a.v, b.v)
        };
    }

    node merge(ll a, const node& b){
        return{
            max(a, b.v)
        };
    }

    void mktree(ll cur) {
        for (auto& [nxt, co] : adj[cur]) {
            if (d[nxt] != -1) continue;
            p[0][nxt] = cur;
            d[nxt] = d[cur] + 1;

            if(m) arr[0][nxt] = co;
            mktree(nxt);
        }
    }

    void init() {
        for(int i = 1;i <= n;i++){
            if(d[i] != -1) continue;
            d[i] = 0; mktree(i);
        }

        for (int i = 1; i <= log2(n); i++) {
            for (int j = 1; j <= n; j++) {
                if (p[i - 1][j] == -1) continue;
                p[i][j] = p[i - 1][p[i - 1][j]];
                if(m) arr[i][j] = merge(arr[i - 1][p[i - 1][j]], arr[i - 1][j]);
            }
        }
    }

    ll shift(ll a, ll diff){
        if(diff <= 0) return a;
        for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)) a = p[i][a];
        }

        return a;
    }

    ll ret(ll a, ll b) {
        if (d[a] < d[b]) swap(a, b);

        a = shift(a, d[a] - d[b]);
        if (a == b) return a;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[i][a] == -1) continue;
            if (p[i][a] == p[i][b]) continue;

            a = p[i][a]; b = p[i][b];
        }

        return p[0][a];
    }

    ll num(ll a, ll b){
        if(!m) return MINF;

        node ret = node();
        if (d[a] < d[b]) swap(a, b);

        ll diff = d[a] - d[b];
        if (diff) for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)){
                ret = merge(ret, arr[i][a]);
                a = p[i][a];
            }
        }
        if (a == b) return ret;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[i][a] == -1) continue;
            if (p[i][a] == p[i][b]) continue;

            ret = merge(ret, arr[i][a]);
            ret = merge(ret, arr[i][b]);
            a = p[i][a]; b = p[i][b];
        }

        ret = merge(ret, arr[0][a]);
        ret = merge(ret, arr[0][b]);
        return ret;
    }
};

ll a[MAX], p[MAX], in[MAX], c;
ll dp[MAX], cnt[MAX];
bool chk[MAX];
vector <ll> adj[MAX], arr, vir[MAX];

void dfs(ll cur, ll pre = -1){
    in[cur] = ++c;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        dfs(nxt, cur);
    }
}

_lca lca;
ll solve(ll cur, ll pre = -1){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;

    if(chk[cur]) cnt[cur] = 1;
    vector <ll> arr;
    for(auto& nxt : vir[cur]){
        if(pre == nxt) continue;
        ret += solve(nxt, cur);
        arr.push_back(cnt[nxt]);
        cnt[cur] += cnt[nxt];
    }

    ll now = 0, sum = 0;
    for(auto& i : arr){
        now += sum * i;
        sum += i;
    }

    ret += now * lca.d[cur];
    if(chk[cur]) ret += (cnt[cur] - 1) * lca.d[cur];
    return ret;
}

void run(){
    cin >> n >> m; lca = {n};
    for(int i = 2;i <= n;i++){
        cin >> p[i];
        lca.addsol(p[i], i);
        adj[p[i]].push_back(i);
        adj[i].push_back(p[i]);
    }
    lca.init(); dfs(1);
    memset(dp, -1, sizeof(dp));

    while(m--){
        ll sz; cin >> sz;
        for(int i = 1;i <= sz;i++){
            ll x; cin >> x;
            arr.push_back(x);
            chk[x] = 1;
        }

        sort(all(arr), [&](ll a, ll b){
            return in[a] < in[b];
        });

        ll now = arr.size();
        for(int i = 1;i < now;i++) arr.push_back(lca.ret(arr[i - 1], arr[i]));
        arr.erase(unique(all(arr)), arr.end());

        sort(all(arr), [&](ll a, ll b){
            return in[a] < in[b];
        });

        for(int i = 1;i < arr.size();i++){
            ll pre = lca.ret(arr[i - 1], arr[i]);
            if(pre == arr[i]) continue;
            vir[pre].push_back(arr[i]);
        }
        
        cout << solve(arr[0]) << "\n";
        for(auto& i : arr){
            vir[i].clear();
            chk[i] = cnt[i] = 0;
            dp[i] = -1;
        }
        arr.clear();
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}