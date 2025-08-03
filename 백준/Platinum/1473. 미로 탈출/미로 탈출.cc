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
constexpr ll MAX = 7; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll d[MAX][MAX][1ll << 14];
ll dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= m;
}

ll cnt(ll cy, ll cx, ll cs){
    if(st[cy][cx] == 'A') return 3;
    if(st[cy][cx] == 'B') return 0;

    ll y = (cs & (1ll << cy) ? 1 : 0);
    ll x = (cs & (1ll << (cx + n)) ? 1 : 0);
    bool c = (x + y) % 2;

    if(c) return (st[cy][cx] == 'C' ? 2 : 1);
    return (st[cy][cx] == 'C' ? 1 : 2);
}

class node{
public:
    ll y, x, state;
};
deque <node> q;

void run(){
    cin >> n >> m; memset(d, 0x3f, sizeof(d));
    for(int i = 0;i < n;i++) cin >> st[i];

    q.push_back({0, 0, 0}); d[0][0][0] = 0;
    while(!q.empty()){
        auto [cy, cx, cs] = q.front(); q.pop_front();
        if(d[cy][cx][cs ^ (1ll << cy) ^ (1ll << (cx + n))] > d[cy][cx][cs] + 1){
            d[cy][cx][cs ^ (1ll << cy) ^ (1ll << (cx + n))] = d[cy][cx][cs] + 1;
            q.push_back({cy, cx, cs ^ (1ll << cy) ^ (1ll << (cx + n))});
        }

        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            
            if(i == 1 || i == 3){
                if(cnt(cy, cx, cs) < 2 || cnt(ny, nx, cs) < 2) continue;
                if(d[ny][nx][cs] <= d[cy][cx][cs] + 1) continue;
                d[ny][nx][cs] = d[cy][cx][cs] + 1;
                q.push_back({ny, nx, cs});
            }
            else{
                if(!(cnt(cy, cx, cs) & 1) || !(cnt(ny, nx, cs) & 1)) continue;
                if(d[ny][nx][cs] <= d[cy][cx][cs] + 1) continue;
                d[ny][nx][cs] = d[cy][cx][cs] + 1;
                q.push_back({ny, nx, cs});
            }
        }
    }

    ll result = INF;
    for(int i = 0;i < (1ll << (n + m));i++){
        result = min(result, d[n - 1][m - 1][i]);
    }

    cout << (result == INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

