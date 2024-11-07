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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
ll a[MAX][MAX], v[MAX][MAX];
ll dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
ll dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void bfs(ll cy, ll cx){
    deque <tll> q;
    q.push_back({cy, cx, 0});

    while(!q.empty()){
        auto [cy, cx, cnt] = q.front(); q.pop_front();
        if(cy <= 0 || cx <= 0 || cx > m || cy > n) continue;
        if(v[cy][cx] <= cnt) continue; v[cy][cx] = cnt;

        for(int i = 0;i < 8;i++){
            ll nx = dx[i] + cx, ny = dy[i] + cy;
            if(ny <= 0 || nx <= 0 || nx > m || ny > n) continue;
            q.push_back({ny, nx, cnt + 1});
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }
    memset(v, 0x3f, sizeof(v));

    ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) {
            if(!a[i][j]) continue;
            bfs(i, j);
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            result = max(result, v[i][j]);
        }
    }

    cout << result;
    
    
    return 0;
}