#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 5; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll v[MAX];
vector <pll> adj[MAX], arr;
bitset <MAX> dp;
bool flag;

void init(){
    for(int i = 1;i <= n;i++) adj[i].clear();
    arr.clear(); flag = 1;
    memset(v, -1, sizeof(v));
    dp.reset();
}

pll dfs(ll cur, ll cnt = 0){
    if(v[cur] != -1 && v[cur] != cnt){
        flag = 0; return {0, 0};
    }

    if(v[cur] != -1) return {0, 0}; v[cur] = cnt;
    pll ret = cnt ? pll(0, 1) : pll(1, 0);

    for(auto& [nxt, co] : adj[cur]){
        pll now = dfs(nxt, cnt ^ co);
        ret.x += now.x; ret.y += now.y;
    }

    return ret;
}

void run(){
    cin >> n >> m; init();
    while(m--){
        ll c, s, e; cin >> c >> s >> e;
        c = c == -1 ? 1 : 0;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    for(int i = 1;i <= n;i++){
        if(v[i] != -1) continue;
        arr.push_back(dfs(i));
    }

    if(!flag){ cout << -1 << "\n"; return; }

    dp[0] = 1;
    for(auto& [l, r] : arr){
        bitset <MAX> tmp;
        tmp |= (dp << l);
        tmp |= (dp << r);
        dp = tmp;
    }

    ll result = INF;
    for(int i = 0;i <= n;i++){
        if(!dp[i]) continue;
        result = min(result, abs(i - (n - i)));
    }

    cout << result << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}