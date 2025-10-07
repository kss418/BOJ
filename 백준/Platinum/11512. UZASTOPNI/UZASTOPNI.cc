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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
vector <ll> adj[MAX], v[102];
vector <pll> num[MAX];
bitset <102> bs[MAX][102];

void dfs(ll cur){
    for(auto& nxt : adj[cur]) dfs(nxt);

    for(int i = 1;i <= 100;i++) v[i].clear();
    for(auto& nxt : adj[cur]){
        for(auto& [l, r] : num[nxt]) v[l].push_back(r);
    }

    for(int l = 100;l >= 1;l--){
        if(l == a[cur]){
            bs[cur][l] |= bs[cur][l + 1];
            bs[cur][l].set(l);
        }
        else for(auto& r : v[l]){
            if(r >= a[cur] && l <= a[cur]) continue;
            bs[cur][l] |= bs[cur][r + 1];
            bs[cur][l].set(r);
        }

        for(int r = 100;r >= l;r--){
            if(a[cur] < l || a[cur] > r) continue;
            if(bs[cur][l].test(r)) num[cur].push_back({l, r});
        }
    }
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
    }

    dfs(1);
    cout << num[1].size();
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}