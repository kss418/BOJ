#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 51; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result = INF;
vector <pll> adj[MAX][MAX];


void add(ll cy, ll cx, ll num){
    if(!num) {
        adj[cy][cx].push_back({cy + 1, cx});
        adj[cy][cx].push_back({cy, cx + 1});
    }
    else if(num == 1){
        adj[cy][cx].push_back({cy + 1, cx});
        adj[cy][cx].push_back({cy, cx - 1});
    }
    else if(num == 2){
        adj[cy][cx].push_back({cy - 1, cx});
        adj[cy][cx].push_back({cy, cx + 1});
    }
    else if(num == 3){
        adj[cy][cx].push_back({cy - 1, cx});
        adj[cy][cx].push_back({cy, cx - 1});
    }
    else if(num == 4){
        adj[cy][cx].push_back({cy - 1, cx});
        adj[cy][cx].push_back({cy + 1, cx});
    }
    else{
        adj[cy][cx].push_back({cy, cx - 1});
        adj[cy][cx].push_back({cy, cx + 1});
    }
}

ll simul(ll cy, ll cx, ll py = 1, ll px = 0){
    if(cy == n && cx == n + 1) return 0;
    if(cy <= 0 || cx <= 0 || cy > n || cx > n) return INF;

    ll able = 0;
    for(auto& nxt : adj[cy][cx]){
        auto[ny, nx] = nxt;
        if(ny == py && nx == px) able = 1;
    }

    if(!able) return INF;
    for(auto& nxt : adj[cy][cx]){
        auto[ny, nx] = nxt;
        if(ny == py && nx == px) continue;
        return simul(ny, nx, cy, cx) + 1;
    }
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j]; 
            add(i, j, a[i][j]);
        }
    }

    if(m) for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            ll tmp = a[i][j];
            for(int k = 0;k <= 5;k++){
                if(tmp == k) continue;
                a[i][j] = k;
                adj[i][j].clear();
                add(i, j, k);
                result = min(result, simul(1, 1));
            }
            a[i][j] = tmp;
            adj[i][j].clear();
            add(i, j, a[i][j]);
        }
    }
    else result = simul(1, 1);

    cout << (result >= INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

