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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MID = 10010101;
ll a[MAX], sum[MAX], cnt;
ll num[20101010];

void run(){
    cin >> n; ll result = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];
    
    num[MID] = 1;
    for(int i = 1;i <= n;i++) {
        sum[i] = sum[i - 1] + a[i];
        for(int j = 0;j * j <= 1e7 + 1;j++){
            ll now = sum[i] - j * j;
            if(now + MID < 0 || now + MID >= 20101010) continue;
            result += num[now + MID];
        }
        num[sum[i] + MID]++;
    }

    for(int i = 1;i <= n;i++) num[sum[i] + MID] = 0;
    cout << "Case #" << ++cnt << ": " << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}