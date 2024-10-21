#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
string st[MAX];
ll dist[MAX][MAX][11][2];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool inq[MAX][MAX][11][2];

class node{
public:
    ll x, y, c, t;
};
deque <node> q;

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) cin >> st[i];

    memset(dist, 0x3f, sizeof(dist));
    q.push_back({0, 0, 0, 1});
    inq[0][0][0][1] = 1; dist[0][0][0][1] = 1;
    
    while(!q.empty()){
        auto [cx, cy, cc, ct] = q.front();
        q.pop_front(); inq[cy][cx][cc][ct] = 0;
        ll cd = dist[cy][cx][cc][ct];

        for(int i = 0;i < 4;i++){
            ll nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        
            if(st[ny][nx] == '1' && ct % 2){
                if(dist[ny][nx][cc + 1][ct ^ 1] > cd + 1 && cc < k){
                    dist[ny][nx][cc + 1][ct ^ 1] = cd + 1;
                    if(!inq[ny][nx][cc + 1][ct ^ 1]){
                        inq[ny][nx][cc + 1][ct ^ 1] = 1;
                        q.push_back({nx, ny, cc + 1, ct ^ 1});
                    }
                }
            }
            
            if(st[ny][nx] == '0') {
                if(dist[ny][nx][cc][ct ^ 1] > cd + 1){
                    dist[ny][nx][cc][ct ^ 1] = cd + 1;
                    if(!inq[ny][nx][cc][ct ^ 1]){
                        inq[ny][nx][cc][ct ^ 1] = 1;
                        q.push_back({nx, ny, cc, ct ^ 1});
                    }
                }
            }
        }

        if(dist[cy][cx][cc][ct ^ 1] > cd + 1){
            dist[cy][cx][cc][ct ^ 1] = cd + 1;
            if(!inq[cy][cx][cc][ct ^ 1]){
                inq[cy][cx][cc][ct ^ 1];
                q.push_back({cx, cy, cc, ct ^ 1});
            }
        }
    }

    ll result = INF;
    for(int i = 0;i <= k;i++) {
        for(int j = 0;j <= 1;j++){
            result = min(result, dist[n - 1][m - 1][i][j]);
        }
    }

    if(result >= INF) cout << -1;
    else cout << result;


    return 0;
}