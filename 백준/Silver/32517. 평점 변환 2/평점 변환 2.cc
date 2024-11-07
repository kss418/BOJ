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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 501010;
constexpr ll MOD = 998244353;
constexpr ll mx = 1e9;
ll a[MAX], b[MAX];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> b[i];

    
    ll sum = 0; a[1] = b[1];
    for(int i = 2;i <= n;i++){
        sum += a[i - 1];
        ll avg = (b[i] + 1) * (i - 1);
        if(avg < sum) {
            a[i] = b[i] + 1; continue;
        }

        avg = b[i] * (i - 1);
        if(avg >= sum){
            a[i] = b[i]; continue;
        }

        cout << -1; return 0;
    }

    for(int i = 1;i <= n;i++){
        if(a[i] >= 1 && a[i] <= mx) continue;
        cout << -1; return 0;
    }

    for(int i = 1;i <= n;i++) cout << a[i] << " ";
    
    
    return 0;
}