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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 111; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll v[MAX][MAX];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void destroy(ll cur, bool dir){
    cur = n - cur; ll idx = -1;
    if(dir){
        idx = 0;
        while(st[cur][idx] == '.' && idx < m) idx++;
    }
    else{
        idx = m - 1;
        while(st[cur][idx] == '.' && idx >= 0) idx--;
    }

    if(idx >= 0 && idx < m) st[cur][idx] = '.';
}

bool outrange(ll cy, ll cx){
    return (cy < 0 || cx < 0 || cy > n || cx >= m);
}

void bfs(){
    memset(v, 0, sizeof(v));
    deque <pll> q;
    for(int i = 0;i < m;i++) q.push_back({n, i});

    while(!q.empty()){
        auto[cy, cx] = q.front(); q.pop_front();
        if(st[cy][cx] == '.') continue;
        if(v[cy][cx]) continue; v[cy][cx] = 1;

        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            q.push_back({ny, nx});
        } 
    }
}

void move(){
    for(int i = n - 2;i >= 0;i--){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '.') continue;
            if(v[i][j]) continue;
            swap(st[i + 1][j], st[i][j]);
        }
    }
}

void gravity(){
    while(1){
        bool flag = 1; ll cnt = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m; j++){
                if(st[i][j] == '.') continue;
                if(v[i][j]) continue;
                if(st[i + 1][j] == 'x' && v[i + 1][j]) flag = 0;
                cnt++;
            }
        }

        if(!flag || !cnt) break;
        move();
    }
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];
    st[n].resize(m, 'x');
    
    cin >> k;
    for(int i = 1;i <= k;i++){
        cin >> t;
        destroy(t, i & 1);
        bfs();
        gravity();
    }

    for(int i = 0;i < n;i++) cout << st[i] << "\n";
  
     
    return 0;
}