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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
class node{
public:
    ll x, y, idx;
}; vector <node> arr[2];
vector <ll> adj[MAX];
ll dist[MAX], result[MAX], dp[MAX], nxt[MAX];

ll solve(ll cur, ll pre = -1){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;

    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        ret += solve(nxt, cur);
    }
    ret += adj[cur].size();
    
    return ret;
}

void run(){
    cin >> n; memset(dist, 0x3f, sizeof(dist));
    memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++){
        char c; ll x, y; cin >> c >> x >> y;
        arr[c == 'N'].push_back({x, y, i});
    }

    sort(all(arr[0]), [](node& l, node& r){
        return l.y < r.y;
    });

    sort(all(arr[1]), [](node& l, node& r){
        return l.x < r.x;
    });

    for(auto& [cx, cy, ci] : arr[0]){
        for(auto& [nx, ny, ni] : arr[1]){
            ll mx = nx, my = cy;
            if(cx > mx || ny > my) continue;

            ll cd = abs(mx - cx) + abs(my - cy);
            if(abs(mx - cx) >= dist[ci]) cd = INF;
            ll nd = abs(mx - nx) + abs(my - ny);
            if(abs(my - ny) >= dist[ni]) nd = INF;

            if(cd == nd) continue;
            if(cd < nd){
                if(dist[ni] <= nd) continue;
                dist[ni] = nd; nxt[ni] = ci;
            }
            else{
                if(dist[ci] <= cd) continue;
                dist[ci] = cd; nxt[ci] = ni;
            }
        }
    }

    for(int i = 1;i <= n;i++) adj[nxt[i]].push_back(i);
    for(int i = 1;i <= n;i++) cout << solve(i) << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}