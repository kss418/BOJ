#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result, use[MAX][MAX];
bool v[MAX][MAX];
vector <pll> adj[MAX][MAX];
deque <pll> q;
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

bool outrange(ll cy, ll cx){
    return cy <= 0 || cx <= 0 || cy > n || cx > m;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        ll cy, cx, ny, nx;
        cin >> cy >> cx >> ny >> nx;
        adj[cy][cx].push_back({ny, nx});
    }
    
    q.push_back({1, 1}); use[1][1] = 1;
    while(!q.empty()){
        auto[cy, cx] = q.front(); q.pop_front();
        if(v[cy][cx]) continue; v[cy][cx] = 1;

        for(auto&[ny, nx] : adj[cy][cx]){
            use[ny][nx] |= 1;
            if(use[ny][nx] == 3) q.push_back({ny, nx});
        }

        for(int i = 0;i < 4;i++){
            ll ny = dy[i] + cy, nx = dx[i] + cx;
            if(outrange(ny, nx)) continue;
            use[ny][nx] |= 2;
            if(use[ny][nx] == 3) q.push_back({ny, nx});
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) result += use[i][j] & 1;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}