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
ll n, m, k, t = 1;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 501; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
char ban[MAX][MAX];
ll d[MAX][MAX][2]; pll s, e;
ll dx[2] = {1, -1}, dy[2] = {1, -1};
class node{
public:
    ll y, x, t;
};
deque <pair<node, ll>> q;

void run(){
    cin >> n >> m; memset(d, 0x3f, sizeof(d));
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(int j = 0;j < m;j++){
            if(st[i][j] == 'C') s = {j, i};
            if(st[i][j] == 'D') e = {j, i};
        }
    }

    q.push_back({{s.y, s.x, 0}, 0});
    while(!q.empty()){
        auto[cn, cd] = q.front(); q.pop_front();
        auto[cy, cx, ct] = cn;
        if(d[cy][cx][ct] <= cd) continue;
        d[cy][cx][ct] = cd;

        ll ny = cy + dy[ct];
        if(ny < 0 || ny >= n) continue;
        if(st[ny][cx] != '#') q.push_back({{ny, cx, ct}, cd});
        else{
            for(int i = 0;i < 2;i++){
                ll nx = cx + dx[i];
                if(nx < 0 || nx >= m || st[cy][nx] == '#') continue;
                q.push_back({{cy, nx, ct}, cd});
            }

            q.push_back({{cy, cx, ct ^ 1}, cd + 1});
        }
    }

    ll ret = min(d[e.y][e.x][0], d[e.y][e.x][1]);
    cout << (ret >= INF ? -1 : ret);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

