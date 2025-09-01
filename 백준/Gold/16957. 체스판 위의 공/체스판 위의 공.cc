#include <bits/stdc++.h>
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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], ind[MAX][MAX], dp[MAX][MAX];
vector <pll> adj[MAX][MAX];
ll dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1};
deque <pll> q;

bool outrange(ll cy, ll cx){
    return cy <= 0 || cx <= 0 || cy > n || cx > m;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ll mn = INF, tx = 0, ty = 0;
            for(int k = 0;k < 8;k++){
                ll ny = i + dy[k], nx = j + dx[k];
                if(outrange(ny, nx)) continue;
                if(a[ny][nx] >= a[i][j]) continue;
                if(a[ny][nx] >= mn) continue;
                ty = ny; tx = nx;
                mn = a[ny][nx];
            }

            if(!ty && !tx) continue;
            adj[i][j].push_back({ty, tx});
            ind[ty][tx]++;
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(!ind[i][j]) q.push_back({i, j});
            dp[i][j] = 1;
        }
    }

    while(!q.empty()){
        auto [cy, cx] = q.front(); q.pop_front();
        for(auto& [ny, nx] : adj[cy][cx]){
            dp[ny][nx] += dp[cy][cx];
            if(!--ind[ny][nx]) q.push_back({ny, nx});
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cout << (adj[i][j].empty() ? dp[i][j] : 0) << " ";
        }
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}