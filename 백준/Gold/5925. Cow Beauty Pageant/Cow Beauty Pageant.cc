#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll seq, num[MAX][MAX];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
ll d[MAX][MAX], sum[MAX][MAX];

bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= m;
}

void dfs(ll cy, ll cx, ll seq){
    if(outrange(cy, cx)) return;
    if(st[cy][cx] == '.') return;
    if(num[cy][cx] != -1) return;
    num[cy][cx] = seq;

    for(int i = 0;i < 4;i++){
        ll ny = cy + dy[i], nx = cx + dx[i];
        dfs(ny, nx, seq);
    }
}

ll dist(ll cur){
    deque <pll> q;
    memset(d, 0x3f, sizeof(d));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(num[i][j] != cur) continue;
            q.push_back({i, j});
            d[i][j] = 0;
        }
    }

    while(!q.empty()){
        auto [cy, cx] = q.front(); q.pop_front();
        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            if(d[ny][nx] <= d[cy][cx] + 1) continue;
            q.push_back({ny, nx});
            d[ny][nx] = d[cy][cx] + 1;
        }
    }

    ll ret = INF;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            sum[i][j] += d[i][j];
            if(num[i][j] != (cur + 1) % 3) continue;
            ret = min(ret, d[i][j]);
        }
    }

    return ret - 1;
}

void run(){
    cin >> n >> m; memset(num, -1, sizeof(num));
    for(int i = 0;i < n;i++) cin >> st[i];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '.') continue;
            if(num[i][j] != -1) continue;
            dfs(i, j, seq++);
        }
    }

    vector <ll> arr;
    for(int i = 0;i < 3;i++) arr.push_back(dist(i));
    sort(all(arr));
    ll ret = INF;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) ret = min(ret, sum[i][j] - 2);
    }
    
    cout << min(arr[0] + arr[1], ret);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}