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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
bool tmp[MAX][MAX], flag = 1;
vector <ll> adj[MAX];
vector <pll> arr;
ll v[MAX];
bitset <MAX> dp;

pll dfs(ll cur, ll cnt = 0){
    if(v[cur] != -1 && v[cur] != cnt){
        flag = 0; return {0, 0};
    }

    if(v[cur] == cnt) return {0, 0};

    pll ret = (cnt ? pll(0, 1) : pll(1, 0));
    v[cur] = cnt;
    for(auto& nxt : adj[cur]){
        pll now = dfs(nxt, cnt ^ 1);
        ret.x += now.x; ret.y += now.y;
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(v, -1, sizeof(v));
    memset(tmp, 1, sizeof(tmp));
    while(m--){
        ll s, e; cin >> s >> e;
        tmp[s][e] = tmp[e][s] = 0;
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(tmp[i][j] && i != j) adj[i].push_back(j);
        }
    }   

    for(int i = 1;i <= n;i++){
        if(v[i] != -1) continue;
        arr.push_back(dfs(i));
    }

    if(!flag){ cout << -1; return; }

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

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}