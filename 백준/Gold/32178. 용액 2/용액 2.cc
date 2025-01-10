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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX];
vector <pll> arr;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) {
        sum[i] = sum[i - 1] + a[i];
        arr.push_back({sum[i], i});
    }
    arr.push_back({0, 0});
    sort(all(arr)); 
    
    ll result = INF, l = -1, r = -1;
    for(int i = 0;i < n;i++){
        pll pre = arr[i], nxt = arr[i + 1];
        if(pre.y > nxt.y) swap(pre, nxt);

        ll now = nxt.x - pre.x;
        if(abs(now) >= abs(result)) continue;
        result = now; 
        l = pre.y; r = nxt.y;
    }

    cout << result << "\n";
    cout << l + 1 << " " << r;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

