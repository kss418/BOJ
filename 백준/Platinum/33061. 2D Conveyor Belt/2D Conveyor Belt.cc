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
char st[MAX][MAX];
bool out[MAX][MAX];
deque <pll> q;
vector <ll> result;

ll dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
char dst[4] = {'D', 'U', 'R', 'L'};

class node{
public:
    ll cy, cx; char c;
}; vector <node> vec;

ll num(ll cy, ll cx){
    return cy * n + cx;
}

bool outrange(ll cy, ll cx){
    return cy <= 0 || cx <= 0 || cy > n || cx > n;
}

void run(){
    cin >> n >> m; ll now = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) st[i][j] = '?';
    }

    while(m--){
        ll cy, cx; char c;
        cin >> cy >> cx >> c;
        st[cy][cx] = c;
        vec.push_back({cy, cx, c});
    }

    for(int i = 1;i <= n;i++){
        if(st[1][i] == 'U'|| st[1][i] == '?') q.push_back({1, i});
        if(st[n][i] == 'D'|| st[n][i] == '?') q.push_back({n, i});
        if(st[i][1] == 'L'|| st[i][1] == '?') q.push_back({i, 1});
        if(st[i][n] == 'R'|| st[i][n] == '?') q.push_back({i, n});
    }

    while(!q.empty()){
        auto[cy, cx] = q.front(); q.pop_front();
        if(out[cy][cx]) continue; out[cy][cx] = 1;

        for(int i = 0;i < 4;i++){
            ll ny = dy[i] + cy, nx = dx[i] + cx;
            if(outrange(ny, nx)) continue;
            if(st[ny][nx] != dst[i] && st[ny][nx] != '?') continue;
            q.push_back({ny, nx});
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) now += out[i][j];
    }
    now = n * n - now;

    reverse(all(vec));
    for(auto& [cy, cx, c] : vec){
        result.push_back(now);
        st[cy][cx] = '?';
        if(out[cy][cx]) continue;

        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) out[cy][cx] = 1;
            else out[cy][cx] |= out[ny][nx];
        }

        if(!out[cy][cx]) continue;
        out[cy][cx] = 0;

        q.push_back({cy, cx});
        while(!q.empty()){
            auto [cy, cx] = q.front(); q.pop_front();
            if(out[cy][cx]) continue; out[cy][cx] = 1; now--;

            for(int i = 0;i < 4;i++){
                ll ny = cy + dy[i], nx = cx + dx[i];
                if(outrange(ny, nx)) continue;
                if(st[ny][nx] != dst[i] && st[ny][nx] != '?') continue;
                q.push_back({ny, nx});
            }
        }
    }

    reverse(all(result));
    for(auto& i : result) cout << i << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}