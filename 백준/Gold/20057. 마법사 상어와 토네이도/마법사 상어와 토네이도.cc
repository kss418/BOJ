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
constexpr ll MAX = 501; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result = 0;
ll mv[9] = {2, 1, 1, 0, 0, 0, 0, -1, -1};
ll hz[9] = {0, 1, -1, 2, -2, 1, -1, 1, -1};
ll mul[9] = {5, 10, 10, 2, 2, 7, 7, 1, 1};

bool chk(ll cy, ll cx){
    return (cx <= 0 || cy <= 0 || cx > n || cy > n);
}

void simulation(ll cy, ll cx, ll dy, ll dx){
    ll rest = a[cy][cx];
    for(int i = 0;i < 9;i++){
        ll nx = cx + mv[i] * dx + abs(dy) * hz[i];
        ll ny = cy + mv[i] * dy + abs(dx) * hz[i];
        ll now = a[cy][cx] * mul[i] / 100;
        if(chk(ny, nx)) result += now;
        else a[ny][nx] += now; rest -= now; 
    }
    
    if(chk(cy + dy, cx + dx)) result += rest;
    else a[cy + dy][cx + dx] += rest; a[cy][cx] = 0;
}

void move(ll cy, ll cx, ll dy, ll dx){
    ll ny = cy + dy, nx = cx + dx;
    simulation(ny, nx, dy, dx);

    if(nx == ny && nx > n / 2 + 1) dx = 0, dy = -1;
    else if(nx + 1 == ny && nx < n / 2 + 1) dx = 0, dy = 1;
    else if(nx + ny == n + 1 && nx < n / 2 + 1) dx = 1, dy = 0;
    else if(nx + ny == n + 1 && nx > n / 2 + 1) dx = -1, dy = 0;

    if(ny == 1 && nx == 1) return;
    move(ny, nx, dy, dx);
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }
    
    ll mid = n / 2 + 1;
    move(mid, mid, 0, -1);

    cout << result;

     
    return 0;
}