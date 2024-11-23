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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
map <ll, ll> mx, mn;
vector <ll> xv;
vector <ld> dp[2];

ld dist(pll a, pll b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return sqrtl(dx * dx + dy * dy);
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++){
        ll cx, cy; cin >> cx >> cy;
        if(mx.count(cx)) mx[cx] = max(mx[cx], cy);
        else {
            mx[cx] = cy;
            xv.push_back(cx);
        }

        if(mn.count(cx)) mn[cx] = min(mn[cx], cy);
        else mn[cx] = cy;
    }
    sort(all(xv));
    for(int i = 0;i <= 1;i++) dp[i].resize(xv.size());

    for(int i = 1;i < xv.size();i++){
        ll pre = xv[i - 1], cur = xv[i];
        dp[0][i] = max(dp[0][i], dp[1][i - 1] + dist({pre, mx[pre]}, {cur, mn[cur]}));
        dp[0][i] = max(dp[0][i], dp[0][i - 1] + dist({pre, mn[pre]}, {cur, mn[cur]}));
        dp[1][i] = max(dp[1][i], dp[0][i - 1] + dist({pre, mn[pre]}, {cur, mx[cur]}));
        dp[1][i] = max(dp[1][i], dp[1][i - 1] + dist({pre, mx[pre]}, {cur, mx[cur]}));
    }
    
    cout.precision(20);
    cout << max(dp[0][xv.size() - 1], dp[1][xv.size() - 1]);


    return 0;
}

