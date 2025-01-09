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
constexpr ll MAX = 404; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX][MAX], z[2];
vector <ll> arr[2];

ll solve(ll a, ll b, ll c, ll ua, ll ub){
    if(a == -1 && b == -1 && !c && !ua && !ub) return 0;
    if(a == -1 && ub == c) return 0;
    if(b == -1 && ua == c) return 0;
    if(a < 0 || b < 0 || !c) return -INF;

    ll& ret = dp[a][b][c];
    if(ret != INF) return ret; 
    ret = -INF;

    ret = max(ret, solve(a - 1, b - 1, c - 1, ua, ub) + arr[0][a] * arr[1][b]);
    if(ua) ret = max(ret, solve(a - 1, b, c - 1, ua - 1, ub));
    if(ub) ret = max(ret, solve(a, b - 1, c - 1, ua, ub - 1));

    return ret;
}

void run(){
    cin >> n; memset(dp, 0x3f, sizeof(dp));
    for(int i = 0;i <= 1;i++){
        for(int j = 0;j < n;j++){
            cin >> m;
            if(m) arr[i].push_back(m);
            else z[i]++;
        }
    }

    cout << solve(arr[0].size() - 1, arr[1].size() - 1, n, z[1], z[0]);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

