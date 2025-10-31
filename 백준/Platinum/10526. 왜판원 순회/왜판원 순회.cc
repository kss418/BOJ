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
constexpr ll MAX = 14; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], mask;
unordered_map <ll, vector <ll>> arr[MAX];
bool result;

void dfs1(ll cur, ll v, ll co = 0, ll cnt = 1){
    if(cnt == n / 2 + 1){
        arr[cur][v].push_back(co);
        return;
    }

    for(int i = 0;i < n;i++){
        if(v & (1ll << i)) continue;
        dfs1(i, v | (1ll << i), co + a[cur][i], cnt + 1);
    }
}

void dfs2(ll cur, ll v, ll co = 0, ll cnt = 1){
    if(result) return;
    if(cnt == (n + 1) / 2 + 1){
        auto& vec = arr[cur][(mask & ~v) | 1 | (1ll << cur)];
        ll lb = lower_bound(all(vec), m - co) - vec.begin();
        if(lb == vec.size() || vec[lb] != m - co) return;
        result = 1; return;
    }

    for(int i = 0;i < n;i++){
        if(v & (1ll << i)) continue;
        dfs2(i, v | (1ll << i), co + a[i][cur], cnt + 1);
    }
}

void run(){
    cin >> n >> m; mask = (1ll << n) - 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) cin >> a[i][j];
    }

    dfs1(0, 1);
    for(int i = 0;i < n;i++){
        for(auto&[k, v] : arr[i]) sort(all(v));
    }

    dfs2(0, 1);
    cout << (result ? "possible" : "impossible");
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}