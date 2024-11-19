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
pll a[MAX];
ld pre[MAX], suf[MAX], arr[MAX];

ld dist(pll a, pll b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    ld ret = sqrtl(dx * dx + dy * dy);

    if(dy > 0) ret *= (ld)3;
    else if(!dy) ret *= (ld)2;

    return ret;
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].x;
    for(int i = 1;i <= n;i++) cin >> a[i].y;

    for(int i = 2;i <= n;i++){
        arr[i] = dist(a[i], a[i - 1]);
        pre[i] = pre[i - 1] + arr[i];
    } 

    for(int i = n - 1;i >= 1;i--){
        arr[i] = dist(a[i], a[i + 1]);
        suf[i] = suf[i + 1] + arr[i];
    }   

    cout.precision(20);
    while(m--){
        ll s, e; ld now; cin >> s >> e;
        if(s > e) now = suf[e] - suf[s];
        else now = pre[e] - pre[s];

        cout << now << "\n";
    }

    return 0;
}

