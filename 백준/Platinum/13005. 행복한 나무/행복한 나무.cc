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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], p[MAX], c[MAX];
ll sum[MAX], mn[MAX], result;
vector <pll> adj[MAX];
bool chk[MAX];

void init(ll cur){
    for(auto& [nxt, co] : adj[cur]){
        sum[nxt] = sum[cur] + co;
        mn[nxt] = min(mn[cur], sum[cur]);
        init(nxt);
    }
}

void cal(ll cur){
    if(chk[cur]) return; result++;
    for(auto& [nxt, co] : adj[cur]) cal(nxt);
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 2;i <= n;i++){
        cin >> p[i] >> c[i];
        adj[p[i]].push_back({i, c[i]});
    }

    init(1);
    for(int i = 1;i <= n;i++){
        if(sum[i] - mn[i] > a[i]) chk[i] = 1;
    }

    cal(1);
    cout << n - result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}