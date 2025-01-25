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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result, num[MAX][MAX], cnt;
ll dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool outrange(ll cy, ll cx){
    return cy <= 0 || cx <= 0 || cy > n || cx > n;
}

void chk(ll cy, ll cx, ll cur, ll c){
    if(a[cy][cx] <= cur) return;
    if(num[cy][cx]) return;
    num[cy][cx] = c;

    for(int i = 0;i < 4;i++){
        ll ny = cy + dy[i], nx = cx + dx[i];
        if(outrange(ny, nx)) continue;
        chk(ny, nx, cur, c);
    }
}

void dfs(ll cur){
    memset(num, 0, sizeof(num)); cnt = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) {
            if(a[i][j] <= cur) continue;
            if(num[i][j]) continue;
            chk(i, j, cur, ++cnt);
        }
    }

    result = max(result, cnt);
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    for(int i = 0;i <= 100;i++) dfs(i);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

