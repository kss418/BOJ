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
constexpr ll MAX = 10; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll dp[MAX][1ll << MAX];

ll solve(ll cur, ll v){
    ll& ret = dp[cur][v];
    if(ret != -1) return ret; ret = 0;

    ll pl = 0;
    for(int i = 0;i < m;i++){
        if(!(v & (1ll << i))) continue;
        if(i != m - 1 && (v & (1ll << (i + 1)))) return ret = 0;
        if(st[cur][i] == 'x') return ret = 0; pl++;
    }

    if(!cur) return ret += pl;
    for(int i = 0;i < (1ll << m);i++){
        ll flag = 1;
        for(int j = 0;j < m;j++){
            if(!(i & (1ll << j))) continue;
            if(j && (v & (1ll << (j - 1)))) { flag = 0; break; }
            if(j != m - 1 && (v & (1ll << (j + 1)))) { flag = 0; break; }
        }

        if(!flag) continue;
        ret = max(ret, solve(cur - 1, i));
    }

    return ret += pl;
}

void run(){
    cin >> n >> m; ll result = 0; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < (1ll << m);i++) result = max(result, solve(n - 1, i));
    
    cout << result << '\n';
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

