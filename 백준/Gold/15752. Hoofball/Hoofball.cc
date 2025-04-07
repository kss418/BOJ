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
constexpr ll MAX = 105; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[MAX], result;
vector <ll> adj[MAX];
bool v[MAX];

void dfs(ll cur){
    if(v[cur]) return; v[cur] = 1;
    for(auto& nxt : adj[cur]) dfs(nxt);
}

void run(){
    cin >> n; a[0] = a[n + 1] = INF;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++){
        ll pre = abs(a[i] - a[i - 1]);
        ll nxt = abs(a[i + 1] - a[i]);

        if(pre <= nxt) adj[i].push_back(i - 1), cnt[i - 1]++;
        else adj[i].push_back(i + 1), cnt[i + 1]++;;
    }

    for(int i = 1;i <= n;i++){
        if(cnt[i]) continue;
        result++; dfs(i);
    }
    
    for(int i = 1;i <= n;i++){
        if(v[i]) continue;
        result++; dfs(i);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}