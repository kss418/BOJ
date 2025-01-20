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
constexpr ll MAX = 151; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll num[MAX][MAX], dp[MAX][MAX];

ll solve(ll l, ll r){
    if(l > r) return 0;
    ll& ret = dp[l][r];
    if(ret != -1) return ret; ret = 0;
    ret = max(solve(l + 1, r), solve(l, r - 1));
    for(int mid = l + 1;mid < r - 1;mid++) ret = max(ret, solve(l, mid) + solve(mid + 1, r));

    return ret += num[l][r];
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) {
        cin >> m >> k; if(m > k) swap(m, k); 
        num[m][k] = 1; 
        if(m <= 50) num[k][m + 100] = 1;
        if(m <= 50 && k <= 50) num[m + 100][k + 100] = 1;
    }

    ll result = 0;
    for(int i = 1;i <= 50;i++) result = max(result, solve(i, i + 100));

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

