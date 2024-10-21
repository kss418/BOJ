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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
ll a[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i = 0;i < n;i++) cin >> a[i];
        deque <ll> num; ll sum = 0;
        for(int i = 0;i < m;i++) num.push_back(a[i]), sum += a[i];
        
        if(n == m){
            if(sum < k) cout << 1 << "\n";
            else cout << 0 << "\n";
            continue;
        }
        ll result = 0;
        
        for(int i = 0;i < n;i++){
            if(sum < k) result++;
            sum -= num.front(); num.pop_front();
            sum += a[(i + m) % n]; num.push_back(a[(i + m) % n]);
        }

        cout << result << '\n';
    }
    

    return 0;
}