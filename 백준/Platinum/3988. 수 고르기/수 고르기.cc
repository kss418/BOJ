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
constexpr ll MAX = 1010101;
constexpr ll MOD = 998244353;
ll a[MAX];
deque <ll> q;
multiset <ll> diff;

int main() {
    fastio;

    cin >> n >> m; m = n - m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1 , a + n + 1);
    
    ll result = INF;
    for(int i = 1;i <= n;i++){
        q.push_back(a[i]);
        if(i != 1) diff.insert(a[i] - a[i - 1]);

        if(q.size() > m) {
            q.pop_front();
            if(i > m + 1) diff.erase(diff.find(a[i - m] - a[i - m - 1]));
        }

        if(q.size() == m){
            ll mx = q.back() - q.front();
            ll mn = *diff.begin();
            result = min(result, mx + mn);
        }
    }
    
    cout << result;


    return 0;
}