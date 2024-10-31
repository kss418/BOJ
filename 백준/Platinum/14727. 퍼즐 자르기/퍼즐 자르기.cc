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
ll a[MAX], result;

void dnc(ll s, ll e){
    if(s == e) {
        result = max(result, a[s]);
        return;
    }

    ll mid = (s + e) >> 1;
    dnc(s, mid); dnc(mid + 1, e);

    ll mn = INF;
    for(int i = s;i <= mid;i++) mn = min(mn, a[i]);
    result = max(result, mn * (mid - s + 1));

    mn = INF;
    for(int i = mid + 1;i <= e;i++) mn = min(mn, a[i]);
    result = max(result, mn * (e - mid));

    ll l = mid, r = mid + 1;
    mn = min(a[l], a[r]); result = max(result, mn * 2);

    while(1){
        if(a[l - 1] >= a[r + 1] && l > s) l--;
        else if(r < e) r++;
        else break;
        
        mn = min({mn, a[l], a[r]});
        result = max(result, mn * (r - l + 1));
    }
}


int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    dnc(1, n);
    cout << result;


    return 0;
}

