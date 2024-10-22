#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 501;
constexpr ll MOD = 998244353;
string st[MAX];
ll v[MAX][MAX], dist[MAX][MAX];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

class node{
public:
    ll x, y, h, u, d;
};
deque <node> q;

int main() {
    fastio;

    cin >> n >> m >> k;
    ll cx, cy, lx, ly;
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(int j = 0;j < n;j++){
            if(st[i][j] == 'S') cx = j, cy = i;
            if(st[i][j] == 'E') lx = j, ly = i;
        }
    }
    memset(dist, 0x3f, sizeof(dist));

    q.push_back({cx, cy, m + 1, 0, 0});
    dist[cy][cx] = 0;
    
    while(!q.empty()){
        auto [cx, cy, ch, cu, cd] = q.front(); q.pop_front();
        dist[cy][cx] = min(cd, dist[cy][cx]);

        if(st[cy][cx] == 'E') continue;
        if(st[cy][cx] == 'U') cu = k;
        if(cu) cu--; else ch--;
        if(!ch) { dist[cy][cx] = INF; continue; }
        if(v[cy][cx] >= ch + cu) continue;
        v[cy][cx] = ch + cu;

        for(int i = 0;i < 4;i++){
            ll nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            q.push_back({nx, ny, ch, cu, cd + 1});
        }
    }

    ll ret = dist[ly][lx];
    if(ret >= INF) cout << -1;
    else cout << ret;


    return 0;
}