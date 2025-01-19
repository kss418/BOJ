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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 40101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX]; vector <ll> h;
ll mx[MAX], result;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        if(a[i].x != a[i - 1].x) {
            for(int j = 1;j <= a[i].x - a[i - 1].x;j++) h.push_back(a[i].y), result += a[i].y;
        }
    }

    cin >> m;
    while(m--){
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ll l = x1, r = x1;
        while(l >= 0) y1 = min(y1, h[l]), mx[l] = max(mx[l], y1), l--;
        while(r < h.size()) y2 = min(y2, h[r]), mx[r] = max(mx[r], y2), r++;
    }

    for(int i = 0;i < h.size();i++) result -= mx[i];
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

