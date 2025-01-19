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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX], b[MAX];

ll sq(ll a){ return a * a; }
ll dist(pll a, pll b){
    ll dx = a.x - b.x, dy = a.y - b.y;
    return sq(dx) + sq(dy);
}

ll dnc(ll l, ll r){
    if(l >= r) return INF;
    ll mid = (l + r) >> 1ll;
    ll xm = a[mid].x, ret = min(dnc(l, mid), dnc(mid + 1, r));
    
    sort(a + l, a + r + 1, [](pll& a, pll& b){
        if(a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    vector <pll> p;
    for(int i = l;i <= r;i++) if(sq(a[i].x - xm) < ret) p.push_back(a[i]);
    for(int i = 0;i < p.size();i++){
        for(int j = i - 1;j >= 0;j--){
            if(sq(p[i].y - p[j].y) >= ret) break;
            ret = min(ret, dist(p[i], p[j]));
        }
    }

    return ret;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1);

    cout << dnc(1, n);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

