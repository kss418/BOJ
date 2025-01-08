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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll x[MAX], y[MAX];
ll dp[MAX][5];
ll dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};

pll pos(ll idx, ll f){
    ll cy = y[idx], cx = x[idx];
    cy += dy[f]; cx += dx[f];
    return {cy, cx};
}

ll dist(pll a, pll b){
    ll ret = abs(a.x - b.x);
    ret += abs(a.y - b.y);
    return ret;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n + 1;i++) cin >> x[i] >> y[i];

    memset(dp, 0x3f, sizeof(dp)); dp[1][4] = 0;
    for(int i = 2;i <= n + 1;i++){
        for(int j = 0;j < 5;j++){
            for(int k = 0;k < 5;k++){
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + dist(pos(i - 1, k), pos(i, j)));
            }
        }
    }

    ll result = INF;
    for(int i = 0;i < 5;i++) result = min(result, dp[n + 1][i]);

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

