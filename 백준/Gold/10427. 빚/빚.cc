#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 5010;
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX];


int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
        
        ll result = 0;
        for(int i = 1;i < n;i++){
            ll cur = INF;
            for(int st = 1;st + i <= n;st++){
                cur = min(cur, a[st + i]* (i + 1) - (sum[st + i] - sum[st - 1]));
            }
            result += cur;
        }

        cout << result << "\n";    
    }
    

    return 0;
}