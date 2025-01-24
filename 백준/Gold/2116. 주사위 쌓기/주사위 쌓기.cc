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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][6], op[6] = {5, 3, 4, 1, 2, 0};

ll find(ll cur, ll num){
    for(int i = 0;i < 6;i++) if(a[cur][i] == num) return i;
}

ll dfs(ll cur, ll num){
    if(cur == n + 1) return 0;
    ll idx = find(cur, num);
    ll nxt = a[cur][op[idx]];

    ll mx = 0;
    for(int i = 0;i < 6;i++){
        if(i == idx || i == op[idx]) continue;
        mx = max(mx, a[cur][i]);
    }

    return dfs(cur + 1, nxt) + mx;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < 6;j++) cin >> a[i][j];
    }

    ll result = 0;
    for(int i = 1;i <= 6;i++) result = max(result, dfs(1, i));
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

