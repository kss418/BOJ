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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];

bool outrange(ll cy, ll cx){
    if (cy < 0 || cx < 0 || cy >= n || cx >= m) return 1;
    return st[cy][cx] == 'x';
}

bool dfs(ll cy, ll cx){
    if(outrange(cy, cx)) return 0;
    st[cy][cx] = 'x';
    if(cx == m - 1) return 1;

    ll ret = 0;
    for(int i = -1;i <= 1;i++){
        ll now = dfs(cy + i, cx + 1);
        if(!now) continue;
        ret = 1; break;
    }

    return ret;
}   

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];

    ll result = 0;
    for(int i = 0;i < n;i++) result += dfs(i, 0);
    
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}