#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
ll arr[MAX][MAX], v[MAX][MAX], pre;
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool bfs(){
    memset(v, 0, sizeof(v));
    ll nxt[MAX][MAX]; pre = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) {
            nxt[i][j] = arr[i][j];
            if(arr[i][j]) pre++;
        }
    }

    deque <pll> q;
    q.push_back({0, 0});

    while(!q.empty()){
        auto[cx, cy] = q.front(); q.pop_front();
        if(v[cy][cx]) continue; v[cy][cx] = 1;
        nxt[cy][cx] = 0;

        for(int i = 0;i < 4;i++){
            ll nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx > m || ny > n) continue;
            if(arr[ny][nx]) nxt[ny][nx] = 0;
            else q.push_back({nx, ny});
        }
    }

    ll ret = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) {
            arr[i][j] = nxt[i][j];
            if(arr[i][j]) ret = 1;
        }
    }

    return ret;
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> arr[i][j];
    }

    ll result = 0;
    while(1) {
        result++;
        if(!bfs()) break;
    }

    cout << result << "\n" << pre;


    return 0;
}