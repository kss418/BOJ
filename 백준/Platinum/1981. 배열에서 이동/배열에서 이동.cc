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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], dp[MAX][MAX][201];
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

class node{
public:
    ll y, x, mn;
};
deque <pair<node, ll>> q;

bool outrange(ll cy, ll cx){
    return (cy <= 0 || cx <= 0 || cy > n || cx > n);
}

void run(){
    cin >> n; memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    q.push_back({{1, 1, a[1][1]}, a[1][1]});
    while(!q.empty()){
        auto [cn, mx] = q.front(); q.pop_front();
        auto [cy, cx, mn] = cn;
        if(dp[cy][cx][mn] <= mx) continue;
        dp[cy][cx][mn] = mx;
        
        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            q.push_back({{ny, nx, min(mn, a[ny][nx])}, max(mx, a[ny][nx])});
        }
    }

    ll result = INF;
    for(int i = 0;i <= 200;i++) result = min(result, dp[n][n][i] - i);

    cout << result;
}   

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

