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
constexpr ll MAX = 51; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
bool v[MAX][MAX][2];

bool outrange(ll cy, ll cx){
    if(cy < 0 || cx < 0 || cy >= n || cx >= n) return 1;
    if(st[cy][cx] == '1') return 1;
    return 0;
}

bool outrange(ll cy, ll cx, ll cd){
    bool ret = 1;
    if(outrange(cy, cx)) return 1;
    for(int i = 0;i < 4;i++){
        if(i % 2 != cd) continue;
        ll ny = cy + dy[i], nx = cx + dx[i];
        if(outrange(ny, nx)) return 1;
    }
    return 0;
}

bool disturnable(ll cy, ll cx){
    for(int i = -1;i <= 1;i++){
        for(int j = -1;j <= 1;j++){
            ll ny = cy + i, nx = cx + j;
            if(outrange(ny, nx)) return 1;
        }
    }
    return 0;
}

bool chk(ll cy, ll cx, ll cd){
    bool ret = 1;
    if(outrange(cy, cx, cd)) return 0;
    for(int i = 0;i < 4;i++){
        if(i % 2 != cd) continue;
        ll ny = cy + dy[i], nx = cx + dx[i];
        if(st[ny][nx] != st[cy][cx]) ret = 0;
    }
    return ret;
}

class node{
public:
    ll y, x, d, cnt;
};

int main() {
    fastio;

    cin >> n;
    for(int i = 0;i < n;i++) cin >> st[i];

    ll sy, sx, sd, ey, ex, ed;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(st[i][j] != 'B' && st[i][j] != 'E') continue;
            for(int k = 0;k <= 1;k++) if(chk(i, j, k)){
                if(st[i][j] == 'B') sy = i, sx = j, sd = k;
                else ey = i, ex = j, ed = k;
            }
        }
    }

    deque <node> q; ll result = 0;
    q.push_back({sy, sx, sd, 0});
    while(!q.empty()){
        auto [cy, cx, cd, cnt] = q.front(); q.pop_front();
        if(v[cy][cx][cd]) continue; v[cy][cx][cd] = 1;
        if(cy == ey && cx == ex && cd == ed){
            result = cnt; break;
        }

        for(int i = 0;i < 4;i++){
            ll nx = cx + dx[i], ny = cy + dy[i];
            if(outrange(ny, nx, cd)) continue;
            q.push_back({ny, nx, cd, cnt + 1});
        }

        if(disturnable(cy, cx)) continue;
        q.push_back({cy, cx, cd ^ 1, cnt + 1});
    }   

    cout << result;


    return 0;
}