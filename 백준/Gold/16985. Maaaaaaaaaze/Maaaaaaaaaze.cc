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
constexpr ll MAX = 6; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll org[MAX][MAX][MAX], a[MAX][MAX][MAX];
ll tmp[MAX][MAX], result = INF;
ll v[MAX][MAX][MAX];
ll dx[6] = {1, -1, 0, 0, 0, 0};
ll dy[6] = {0, 0, 1, -1, 0, 0};
ll dz[6] = {0, 0, 0, 0, 1, -1};
vector <ll> num, seq;

void init(){
    memset(v, 0x3f, sizeof(v));
    for(int i = 1;i <= 5;i++){
        for(int j = 1;j <= 5;j++){
            for(int k = 1;k <= 5;k++) a[i][j][k] = org[seq[i - 1]][j][k];
        }
    }
}

void rotate(ll cur){
    for(int i = 1;i <= 5;i++){
        for(int j = 1;j <= 5;j++) tmp[j][5 - i + 1] = a[cur][i][j];
    }

    for(int i = 1;i <= 5;i++){
        for(int j = 1;j <= 5;j++) a[cur][i][j] = tmp[i][j];
    }
}

bool outrange(ll cz, ll cy, ll cx){
    if(cz <= 0 || cz > 5) return 1;
    if(cy <= 0 || cy > 5) return 1;
    if(cx <= 0 || cx > 5) return 1;
    return 0;
}

class node{
public:
    ll z, y, x, cnt;
};
void bfs(ll sz, ll sy, ll sx){
    deque <node> q;
    q.push_back({sz, sy, sx, 0});

    while(!q.empty()){
        auto [cz, cy, cx, cnt] = q.front(); q.pop_front();
        if(!a[cz][cy][cx]) continue;
        if(v[cz][cy][cx] != INF) continue; v[cz][cy][cx] = cnt;
        if(cz == 5 && cy == 5 && cx == 5) return;
        
        for(int i = 0;i < 6;i++){
            ll nz = cz + dz[i], ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(nz, ny, nx)) continue;
            q.push_back({nz, ny, nx, cnt + 1});
        }   
    }
}

void bt(){
    if(num.size() == 5){
        init();
        for(int i = 0;i < 5;i++){
            for(int j = 1;j <= num[i];j++) rotate(i + 1);
        }
    
        bfs(1, 1, 1); result = min(result, v[5][5][5]);
        return;
    }

    for(int i = 0;i < 4;i++){
        num.push_back(i);
        bt();
        num.pop_back();
    }
}

int main() {
    fastio;

    for(int i = 1;i <= 5;i++){
        for(int j = 1;j <= 5;j++){
            for(int k = 1;k <= 5;k++) cin >> org[i][j][k];
        }
    }
    
    seq.resize(5); iota(all(seq), 1);
    while(1){ bt(); if(!next_permutation(all(seq))) break; }
    
    if(result >= INF) result = -1;
    cout << result;

     
    return 0;
}