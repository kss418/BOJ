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
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];

ll solve(ll cur){
    ll ret = 0;
    for(int i = 0;i < n;i++){
        ll a = 0, b = 0;
        for(int j = 0;j < n;j++){
            if(cur & (1ll << j)) (st[i][j] == 'T' ? a : b) += 1;
            else (st[i][j] == 'T' ? b : a) += 1;
        }
        ret += min(a, b);
    }

    return ret;
}

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> st[i];

    ll result = INF;
    for(int i = 0;i < (1ll << n);i++) result = min(result, solve(i));

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}