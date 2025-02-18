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
constexpr ll MAX = 501; // SET MAX SIZE
constexpr ll MOD = 1000;
ll dp[MAX][MAX];
vector <ll> adj[MAX][2];
class node{
public:
    ll s, d, use;
} a[MAX];

ll solve(ll l, ll r){
    ll& ret = dp[l][r];
    if(ret != -1) return ret; ret = 0;

    for(auto& nxt : adj[l][0]){
        if(nxt != n && nxt <= r) break;
        ret += solve(nxt, r);
        ret %= MOD;
    }

    for(auto& nxt : adj[r][1]){
        if(nxt <= l) break;
        ret += solve(l, nxt);
        ret %= MOD;
    }

    return ret %= MOD;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp)); dp[n][n] = 1;
    for(int i = 1;i <= n;i++) cin >> a[i].s >> a[i].d >> a[i].use;
    for(int i = 1;i <= n;i++){
        for(int j = n;j >= i + 1;j--){
            if(a[j].s > a[i].s + a[i].d) continue;;
            adj[i][0].push_back(j);
        }

        for(int j = n;j >= i + 1;j--){
            if(!a[i].use) break;
            if(a[j].s - a[j].d > a[i].s) continue;
            adj[i][1].push_back(j);
        }
    }

    cout << solve(1, 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

