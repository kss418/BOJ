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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
class node{
public:
    ll x, y, idx;
    bool operator <(const node& ot) const{
        if(x == ot.x) return y > ot.y;
        return x < ot.x;
    }
};
node a[MAX]; ll cnt[MAX];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> a[i].x >> a[i].y, a[i].idx = i;
        if(a[i].x > a[i].y) a[i].y += n;
    }
    for(int i = m + 1;i <= 2 * m;i++) {
        a[i] = {a[i - m].x + n, a[i - m].y + n};
        a[i].idx = i - m;
    }
    sort(a + 1, a + 2 * m + 1);

    ll mx = -1;
    for(int i = 1;i <= 2 * m;i++){
        if(a[i].y <= mx) cnt[a[i].idx] = 1;
        mx = max(mx, a[i].y);
    }

    for(int i = 1;i <= m;i++) if(!cnt[i]) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

