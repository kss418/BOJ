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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
 
bool gravitiy(){
    bool ret = 0;
    for(int i = n - 1;i >= 1;i--){
        for(int j = 0;j < 10;j++){
            if(st[i][j] != '0') continue;
            if(st[i - 1][j] == '0') continue;
            st[i][j] = st[i - 1][j];
            st[i - 1][j] = '0';
            ret = 1;
        }
    }

    return ret;
}

bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= 10;
}

vector <pll> tr;
bool v[MAX][11];
void bfs(ll y, ll x){
    deque <pll> q;
    q.push_back({y, x});
    tr.push_back({y, x});
    v[y][x] = 1;

    while(!q.empty()){
        auto[cy, cx] = q.front(); q.pop_front();

        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            if(st[ny][nx] != st[y][x] || v[ny][nx]) continue;
            q.push_back({ny, nx});
            tr.push_back({ny, nx});
            v[ny][nx] = 1;
        }
    }
}

bool chk(){
    bool ret = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 10;j++){
            if(st[i][j] == '0') continue; 
            if(v[i][j]) continue;
            tr.clear(); bfs(i, j);
            if(tr.size() < m) continue;

            ret = 1;
            for(auto& [cy, cx] : tr) st[cy][cx] = '0';
        }
    }

    return ret;
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];

    while(1){
        memset(v, 0, sizeof(v));
        if(!chk()) break;
        while(gravitiy());
    }

    for(int i = 0;i < n;i++) cout << st[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

