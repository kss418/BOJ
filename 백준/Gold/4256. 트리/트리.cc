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
ll a[MAX], b[MAX], cnt, idx[MAX];
vector <ll> adj[MAX];

void dnc(ll s, ll e){
    ll cur = a[++cnt], mid = idx[cur];
    if(s <= mid - 1){
        adj[cur].push_back(a[cnt + 1]);
        dnc(s, mid - 1);
    }

    if(mid + 1 <= e){
        adj[cur].push_back(a[cnt + 1]);
        dnc(mid + 1, e);
    }
}

void dfs(ll cur){
    for(auto& nxt : adj[cur]) dfs(nxt);
    cout << cur << " ";
}

void run(){
    cin >> n; cnt = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i], idx[b[i]] = i;
    for(int i = 1;i <= n;i++) adj[i].clear();

    dnc(1, n); dfs(a[1]);
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}