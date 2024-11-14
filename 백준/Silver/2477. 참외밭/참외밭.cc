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
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= 6;i++) cin >> a[i].x >> a[i].y;
    for(int i = 7;i <= 12;i++) a[i] = a[i - 6];

    ll mx = 0, mn = 0;
    for(int i = 1;i <= 12;i++){
        if(a[i].x != a[i + 2].x) continue;
        if(a[i + 1].x != a[i + 3].x) continue;
        mn = a[i + 1].y * a[i + 2].y;
        mx = a[i + 4].y * a[i + 5].y;
        break;
    }

    cout << n * (mx - mn);


    return 0;
}

