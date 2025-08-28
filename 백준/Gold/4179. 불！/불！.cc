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
string st[MAX];
ll jx, jy, fx, fy;
ll d[MAX][MAX][2];
deque <pll> q;
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

bool outrange(ll cy, ll cx){
    if(cy < 0 || cx < 0 || cy >= n || cx >= m) return 1;
    return st[cy][cx] == '#';
}

void run(){
    cin >> n >> m; memset(d, 0x3f, sizeof(d));
    for(int i = 0;i < n;i++){
        cin >> st[i];
        for(int j = 0;j < m;j++){
            if(st[i][j] == 'J') jy = i, jx = j;
            else if(st[i][j] == 'F'){
                q.push_back({i, j});
                d[i][j][0] = 0;
            }
        }
    }

    while(!q.empty()){
        auto [cy, cx] = q.front(); q.pop_front();
        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            if(d[ny][nx][0] <= d[cy][cx][0] + 1) continue;
            d[ny][nx][0] = d[cy][cx][0] + 1;
            q.push_back({ny, nx});
        }
    }

    q.push_back({jy, jx}); d[jy][jx][1] = 0;
    while(!q.empty()){
        auto [cy, cx] = q.front(); q.pop_front();
        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            if(d[ny][nx][1] <= d[cy][cx][1] + 1) continue;
            if(d[cy][cx][1] + 1 >= d[ny][nx][0]) continue;
            d[ny][nx][1] = d[cy][cx][1] + 1;
            q.push_back({ny, nx});
        }
    }   

    ll result = INF;
    for(int i = 0;i < n;i++){
        result = min(result, d[i][0][1] + 1);
        result = min(result, d[i][m - 1][1] + 1);
    }

    for(int i = 0;i < m;i++){
        result = min(result, d[0][i][1] + 1);
        result = min(result, d[n - 1][i][1] + 1);
    }

    if(result >= INF) cout << "IMPOSSIBLE";
    else cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}