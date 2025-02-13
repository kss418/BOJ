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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> result;
map <pll, pll> tr;
ll cx, cy, nx, ny;

ll dfs(ll cx, ll cy, ll cnt){
    if(cnt == -1) return (cx != n || cy != m ? INF : 1);
    ll r1 = dfs(cx, cy, cnt - 1);

    ll now = (1ll << cnt);
    ll nx = cx + now * (cx < n ? 1 : -1);
    ll ny = cy + now * (cy < m ? 1 : -1);
    ll r2 = dfs(nx, ny, cnt - 1) + 1;

    if(r1 > r2) tr[{cx, cy}] = {nx, ny};
    return min(r1, r2);
}

void run(){
    cin >> n >> m;
    if((n % 2) ^ (m % 2)){ cout << -1; return; }
    
    ll ret = dfs(0, 0, 27);
    if(ret >= INF){ cout << -1; return; }

    cout << ret << "\n";
    ll cx = 0, cy = 0;
    while(cx != n && cy != m){
        cout << cx << "," << cy << "\n";
        pll nxt = tr[{cx, cy}];
        cx = nxt.x; cy = nxt.y;
    }
    cout << n << "," << m << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

