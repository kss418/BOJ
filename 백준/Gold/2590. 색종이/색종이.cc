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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result;

void run(){
    for(int i = 1;i <= 6;i++) cin >> a[i];
    result += a[6]; result += a[5]; 
    a[1] = max(a[1] - a[5] * 11, 0ll);

    result += a[4]; ll rest = 20 * a[4];
    if(rest >= 4 * a[2]) {
        rest -= 4 * a[2]; a[2] = 0;
        a[1] = max(a[1] - rest, 0ll);
    }
    else a[2] -= 5 * a[4];
    
    result += a[3] / 4; a[3] %= 4;
    if(a[3]) result++;
    
    if(a[3] == 1){
        ll rest = 27 - 4 * min(a[2], 5ll); a[2] = max(a[2] - 5, 0ll);
        a[1] = max(a[1] - rest, 0ll);
    }
    else if(a[3] == 2){
        ll rest = 18 - 4 * min(a[2], 3ll); a[2] = max(a[2] - 3, 0ll);
        a[1] = max(a[1] - rest, 0ll);
    }
    else if(a[3] == 3){
        ll rest = 9 - 4 * min(a[2], 1ll); a[2] = max(a[2] - 1, 0ll);
        a[1] = max(a[1] - rest, 0ll);
    }

    result += a[2] / 9; a[2] %= 9;
    if(a[2]){
        result++;
        rest = 36 - a[2] * 4;
        a[1] = max(a[1] - rest, 0ll);
    }

    result += a[1] / 36; a[1] %= 36;
    if(a[1]) result++;
    

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

