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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;


int main() {
    fastio;

    pll a1, a2, b1, b2;
    cin >> a1.x >> a1.y >> a2.x >> a2.y;
    cin >> b1.x >> b1.y >> b2.x >> b2.y;

    ll cx = -1, cy = -1;
    cx = max(cx, min(a2.x - b1.x, b2.x - a1.x));
    cy = max(cy, min(a2.y - b1.y, b2.y - a1.y));

    if(cx > 0 && cy > 0) cout << "FACE\n";
    else if((cx > 0 && !cy) || (!cx && cy > 0)) cout << "LINE\n";
    else if(!cx && !cy) cout << "POINT\n";
    else cout << "NULL\n";
    

    return 0;
}

