#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX], d[MAX][MAX];
vector <ll> adj[MAX], idx;

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret = 0;

    ll now = idx[cur - 1];
    ret = a[now];
    for(int i = 1;i < cur;i++){
        ll nxt = idx[i - 1];
        if(a[now] == a[nxt]) break;
        ret = max(ret, solve(i) + a[now] - d[now][nxt]);
    }

    return ret;
}

void run(){
    cin >> n >> m; 
    memset(d, 0x3f, sizeof(d));
    memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++){
        ll sz; cin >> a[i] >> sz;
        for(int j = 1;j <= sz;j++){
            ll num; cin >> num;
            adj[i].push_back(num);
        }
    }

    for(int i = 1;i <= n;i++){
        deque <pll> q;
        q.push_back({i, 0});

        while(!q.empty()){
            auto[cur, cd] = q.front(); q.pop_front();
            if(d[i][cur] <= cd) continue;
            d[i][cur] = cd;

            for(auto& nxt : adj[cur]) q.push_back({nxt, cd + m});
        }
    }

    idx.resize(n); iota(all(idx), 1);
    sort(all(idx), [](ll l, ll r){
        return a[l] < a[r];
    });

    ll result = 0;
    for(int i = 1;i <= n;i++) result = max(result, solve(i));
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}