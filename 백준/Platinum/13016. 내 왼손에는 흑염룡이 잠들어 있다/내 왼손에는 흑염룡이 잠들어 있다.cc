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
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> adj[MAX];
ll dp1[MAX], dp2[MAX];

ll solve1(ll cur, ll pre = -1){
    ll& ret = dp1[cur];
    if(ret != -1) return ret; ret = 0;

    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        ret = max(ret, solve1(nxt, cur) + co);
    }

    return ret;
}

ll solve2(ll cur, ll mx, ll pre = -1){
    ll& ret = dp2[cur];
    if(ret != -1) return ret; ret = max(dp1[cur], mx);

    vector <pll> arr; 
    for(int i = 0;i < adj[cur].size();i++){
        auto[nxt, co] = adj[cur][i];
        if(nxt == pre) continue;
        arr.push_back({solve1(nxt, cur) + co, i});
    }
    sort(all(arr), greater<pll>());

    for(int i = 0;i < arr.size();i++){
        auto[num, idx] = arr[i];
        auto[nxt, co] = adj[cur][idx];
        ll now = mx;

        if(!i && arr.size() >= 2) now = max(now, arr[1].x);
        else if(i) now = max(now, arr[0].x);
        solve2(nxt, now + co, cur);
    }

    return ret;
}

void run(){
    cin >> n;
    for(int i = 1;i < n;i++){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    solve1(1); solve2(1, 0);

    for(int i = 1;i <= n;i++) cout << solve2(i, 0) << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}