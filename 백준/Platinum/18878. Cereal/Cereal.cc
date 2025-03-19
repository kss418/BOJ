#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll use[MAX], now, result[MAX];

void dfs(ll cur, ll idx){
    if(!use[cur]){
        use[cur] = idx;
        now++; return;
    }

    if(use[cur] <= idx) return;
    if(a[use[cur]].x == cur) dfs(a[use[cur]].y, use[cur]);
    use[cur] = idx; return;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    for(int i = n;i >= 1;i--){
        dfs(a[i].x, i);
        result[i] = now;
    }

    for(int i = 1;i <= n;i++) cout << result[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}