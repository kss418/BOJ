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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX];
vector <ll> arr;

void init(ll cur, ll dep, ll st, ll en){
    if(dep > en) return;

    init(2 * cur, dep + 1, st, en);
    if(dep >= st) arr.push_back(a[cur]);
    init(2 * cur + 1, dep + 1, st, en);
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll result = MINF;
    for(int i = 1;(1ll << i) - 1 <= n;i++){
        for(int j = i;(1ll << j) - 1 <= n;j++){
            arr.clear(); arr.push_back(0);
            init(1, 0, i - 1, j - 1); memset(dp, 0xc0, sizeof(dp)); dp[0] = 0;
            for(int i = 1;i < arr.size();i++){
                dp[i] = max(dp[i - 1] + arr[i], arr[i]);
                result = max(result, dp[i]);
            }
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}