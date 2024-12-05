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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], tmp[MAX][MAX], result;
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool v[MAX][MAX], use[MAX][MAX];

pll bfs(ll cy, ll cx, ll num, bool flag){
    if(cy <= 0 || cx <= 0 || cx > n || cy > n) return {0, 0};
    if(use[cy][cx]) return {0, 0}; use[cy][cx] = 1;
    if(a[cy][cx] && a[cy][cx] != num) return {0, 0};
    if(flag) a[cy][cx] = -2;
    if(a[cy][cx]) v[cy][cx] = 1;

    ll sz = 1, rb = (a[cy][cx]) ? 0 : 1;
    for(int i = 0;i < 4;i++){
        ll ny = cy + dy[i], nx = cx + dx[i];
        auto [csz, crb] = bfs(ny, nx, num, flag);
        sz += csz, rb += crb;
    }

    return {sz, rb};
}

bool ff(){
    ll sz = 0, rb = 0, ry = 0, rx = 0;
    bool ret = 0; memset(v, 0, sizeof(v));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(a[i][j] <= 0) continue;
            if(v[i][j]) continue;
            memset(use, 0, sizeof(use));
            auto [csz, crb] = bfs(i, j, a[i][j], 0);
            if(csz <= 1) continue; ret = 1;

            if(csz > sz) sz = csz, rb = crb, ry = i, rx = j;
            else if(csz == sz){
                if(crb > rb) rb = crb, ry = i, rx = j;
                else if(crb == rb){
                    if(i > ry) ry = i, rx = j;
                    else if(i == ry){
                        if(j > rx) rx = j;
                    }
                }
            }
        }
    }
    
    memset(use, 0, sizeof(use));
    bfs(ry, rx, a[ry][rx], 1);
    result += sz * sz;

    return ret;
}

void gravity(){
    for(int i = n;i >= 2;i--){
        for(int j = 1;j <= n;j++){
            if(a[i][j] != -2) continue;
            ll idx = i - 1;
            while(idx >= 1 && a[idx][j] == -2) idx--;
            if(idx && a[idx][j] != -1) swap(a[i][j], a[idx][j]);
        }
    }
}

void rotate(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            tmp[n - j + 1][i] = a[i][j];
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) a[i][j] = tmp[i][j];
    }
}

bool simulation(){
    bool ret = ff();
    gravity();
    rotate();
    gravity();

    return ret;
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }  

    while(simulation());
    cout << result;
    
     
    return 0;
}