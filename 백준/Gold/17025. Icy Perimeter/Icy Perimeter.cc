#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
ll sq, len = INF, num, now;
bool v[MAX][MAX], use[MAX][MAX];
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

bool outrange(ll cy, ll cx){
    return cx < 0 || cy < 0 || cx >= n || cy >= n;
}

void dfs(ll cy, ll cx){
    if(v[cy][cx]) return;
    if(st[cy][cx] == '.') return;
    v[cy][cx] = 1; num++;
    for(int i = 0;i < 4;i++){
        ll ny = cy + dy[i], nx = cx + dx[i];
        if(outrange(ny, nx)) continue;
        dfs(ny, nx);
    }
}

void cal(ll cy, ll cx){
    if(use[cy][cx]) return;
    if(st[cy][cx] == '.') return;
    use[cy][cx] = 1;
    for(int i = 0;i < 4;i++){
        ll ny = cy + dy[i], nx = cx + dx[i];
        if(outrange(ny, nx) || st[ny][nx] == '.') now++;
        else cal(ny, nx);
    }
}

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(v[i][j] || st[i][j] == '.') continue;
            num = 0; dfs(i, j);
            if(num < sq) continue;
            now = 0; cal(i, j);
            if(num > sq) len = now;
            else len = min(len, now); 
            sq = num;
        }
    }

    cout << sq << " " << len;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}