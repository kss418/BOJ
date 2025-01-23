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
string st[MAX]; ll d[MAX][MAX];
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
class node{
public:
    ll y, x, d;
};
deque <node> q;

bool outrange(ll cy, ll cx){
    if(cy < 0 || cx < 0 || cy >= n || cx >= m) return 1;
    return st[cy][cx] == 'W';
}

ll bfs(ll y, ll x){
    ll ret = 0;
    q.push_back({y, x, 0}); memset(d, 0x3f, sizeof(d));
    while(!q.empty()){
        auto[cy, cx, cd] = q.front(); q.pop_front();
        if(d[cy][cx] <= cd) continue;
        d[cy][cx] = cd; ret = max(ret, cd);

        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            q.push_back({ny, nx, cd + 1});
        }
    }

    return ret;
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];

    ll result = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) {
            if(outrange(i, j)) continue;
            result = max(result, bfs(i, j));
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

