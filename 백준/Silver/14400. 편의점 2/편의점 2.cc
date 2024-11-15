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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MID = 1010000;
pll a[MAX];
ll cx[2010101], cy[2010101];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        cx[a[i].x + MID]++; cy[a[i].y + MID]++;
    }

    ll sx = 0, sy = 0, mx = INF, my = INF;

    for(int i = 1;i <= n;i++) {
        sx += abs(a[i].x + 1000001);
        sy += abs(a[i].y + 1000001);
    }

    ll cnt = -n;
    for(int i = -1000000;i <= 1000000;i++){
        ll cur = MID + i; sx += cnt;
        mx = min(mx, sx);
        cnt += 2 * cx[cur];
    }

    cnt = -n;
    for(int i = -1000000;i <= 1000000;i++){
        ll cur = MID + i; sy += cnt;
        my = min(my, sy);
        cnt += 2 * cy[cur];
    }
   
    cout << mx + my;


    return 0;
}

