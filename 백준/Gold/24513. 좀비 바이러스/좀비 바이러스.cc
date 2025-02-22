#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result[4];
ll r[MAX][MAX], d[MAX][MAX];
bool v[MAX][MAX];
ll dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
class node{
public:
    ll y, x, num, cnt;
};
deque <node> q, wait;

bool outrange(ll cy, ll cx){
    if(cy <= 0 || cx <= 0 || cy > n || cx > m) return 1;
    return (a[cy][cx] == -1); 
}

void run(){
    cin >> n >> m; memset(d, 0x3f, sizeof(d));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            if(a[i][j] <= 0) continue;
            q.push_back({i, j, a[i][j], 1});
            r[i][j] = a[i][j]; d[i][j] = 1;
        }
    }

    while(!q.empty() || !wait.empty()){
        auto[cy, cx, num, cc] = q.front(); q.pop_front();
        if(a[cy][cx] == -1 || d[cy][cx] != cc) continue;
        if(r[cy][cx] == 3 || v[cy][cx]) continue; v[cy][cx] = 1;
        
        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            if(d[ny][nx] < cc + 1) continue;
            q.push_back({ny, nx, num, cc + 1});
            r[ny][nx] |= num; d[ny][nx] = cc + 1;
        }
    }   

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) result[r[i][j]]++;
    }

    for(int i = 1;i <= 3;i++) cout << result[i] << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

