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
class node{
public:
    ll x, y1, y2;
    bool operator < (const node& ot) const{
        return x < ot.x;
    }
} a[MAX];
map <ll, ll> mp;
vector <ll> result;

void run(){
    cin >> n >> m >> k;
    mp.insert({m, 0});
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y1 >> a[i].y2;
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++){
        auto[x, y1, y2] = a[i];
        auto it = mp.lower_bound(y1);
        ll up = INF, down = INF;
        while(it != mp.end() && it->x <= y2){
            up = min(up, it->y + y2 - it->x);
            down = min(down, it->y + it->x - y1);
            it = mp.erase(it);
        }

        mp.insert({y1, down});
        mp.insert({y2, up});
    }

    ll mn = INF;
    for(auto& i : mp) {
        if(i.y > mn) continue;
        if(i.y < mn) mn = i.y, result.clear();
        result.push_back(i.x);
    }

    cout << mn + k << "\n";
    cout << result.size() << " ";
    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}