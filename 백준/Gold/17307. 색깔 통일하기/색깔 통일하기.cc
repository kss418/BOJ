#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], pre[MAX], suf[MAX];


int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    a[0] = a[1]; a[n + 1] = a[n];

    for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + (a[i - 1] - a[i] + m) % m;
    for(int i = n;i >= 1;i--) suf[i] = suf[i + 1] + (a[i + 1] - a[i] + m) % m;

    ll result = INF, idx = -1;
    for(int i = 1;i <= n;i++) {
        ll now = max(suf[i], pre[i]);
        if(now >= result) continue;
        result = now; idx = i;
    }

    cout << idx << "\n" << result;


    return 0;
}

