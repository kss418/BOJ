#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, dir;
string st[MAX], tmp[MAX]; ll cy, cx;

void gravity(){
    ll ny = cy + dy[dir], nx = cx + dx[dir];
    if(ny < 0 || nx < 0 || ny >= n || nx >= m) return;
    if(st[ny][nx] == '#') return;
    st[cy][cx] = '.'; cy = ny; cx = nx;
    st[cy][cx] = 'J';
}

void rotate(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) {
            tmp[j][n - i - 1] = st[i][j];
        }
    }
    swap(n, m);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) st[i][j] = tmp[i][j];
    }
}

void run(){
    cin >> n >> m;

    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(int j = 0;j < m;j++){
            if(st[i][j] != 'J') continue;
            cy = i; cx = j;
        }
    }
    cin >> s;

    for(int i = 0;i < max(n, m);i++) {
        tmp[i].resize(max(n, m));
        st[i].resize(max(n, m));
    }

    for(auto& i : s){
        if(i == 'R') dir = (dir + 1) % 4;
        else if(i == 'L') dir = (dir + 3) % 4;
        gravity();
    }

    
    for(int i = 0;i < dir;i++) rotate();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) cout << st[i][j];
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

