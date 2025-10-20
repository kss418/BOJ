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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll result, cnt[MAX][MAX];
ll dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector <pll> arr, tmp;

bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= m;
}

void simulate(){
    for(auto& [cy, cx] : arr) st[cy][cx] = '.';
    for(auto& [cy, cx] : arr){
        for(int i = 0;i < 8;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            if(st[ny][nx] == '.') continue;
            if(++cnt[ny][nx] == st[ny][nx] - '0') tmp.push_back({ny, nx});
        }
    }

    arr.clear();
    for(auto& i : tmp) arr.push_back(i);
    tmp.clear(); result++;
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '.') continue;
            for(int k = 0;k < 8;k++){
                ll ny = i + dy[k], nx = j + dx[k];
                if(outrange(ny, nx)) continue;
                if(st[ny][nx] == '.') cnt[i][j]++;
            }

            if(cnt[i][j] >= st[i][j] - '0') arr.push_back({i, j});
        }
    }

    while(1){
        if(arr.empty()) break;
        simulate();
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}