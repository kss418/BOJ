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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll p[MAX], a[MAX], dp[MAX][2];
vector <ll> adj[MAX];

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;

    if(!cnt){
        for(auto& nxt : adj[cur]){
            ret += max(solve(nxt, 0), solve(nxt, 1));
        }
    }
    else{
        if(adj[cur].size() >= 2){
            ll mx = 0, now = 0;
            for(auto& nxt : adj[cur]){
                ll n0 = solve(nxt, 0), n1 = solve(nxt, 1);
                now += max(n0, n1);
                mx = max(mx, (n0 > n1 ? 0 : n0 - n1) + a[cur] * a[nxt]);
            }

            ret += now + max(mx, 0ll);
        }
        else if(adj[cur].size() == 1){
            ll nxt = adj[cur][0];
            ret += a[cur] * a[nxt] + solve(nxt, 0);
        }
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 2;i <= n;i++) cin >> p[i], adj[p[i]].push_back(i);
    for(int i = 1;i <= n;i++) cin >> a[i];

    cout << max(solve(1, 0), solve(1, 1));
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}