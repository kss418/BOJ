#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 1010;
ll n, m, k;
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
ll d[MAX][MAX], a[MAX][MAX];

const ll INF = 1e9;

class node{
public:
    ll y, x, d;
};
queue <node> q;

bool outrange(ll cy, ll cx){
    if(cy <= 0 || cx <= 0 || cy > n || cx > m) return 1;
    return a[cy][cx] == -1;
}


void bfs(){
    while(!q.empty()){
        auto [cy, cx, cd] = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            if(d[ny][nx] != INF) continue;
            d[ny][nx] = cd + 1;
            q.push({ny, nx, cd + 1});
        }
    }
}


int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> m >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            d[i][j] = INF;

            if(a[i][j] == 1){
                d[i][j] = 0;
                q.push({i, j, 0});
            }
        }
    }

    bfs();
    ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i][j] == -1) continue;
            result = max(result, d[i][j]);
        }
    }

    cout << (result == INF ? -1 : result);

    return 0;
}