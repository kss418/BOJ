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
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], d[MAX][MAX][MAX];
ll ds[4] = {1, -1, 0, 0}, de[4] = {0, 0, 1, -1};
ll cs, ce, result = INF;
class node{
public:
    ll s, e, num, d;
};
deque <node> q;

bool outrange(ll s, ll e){
    return s <= 0 || e <= 0 || s > n || e > n || s == e;
}

void run(){
    cin >> n >> cs >> ce >> m;
    if(ce > cs) swap(cs, ce);
    for(int i = 1;i <= m;i++) cin >> a[i];
    memset(d, 0x3f, sizeof(d));

    q.push_back({cs, ce, 1, 0});
    while(!q.empty()){
        auto [cs, ce, cn, cd] = q.front(); q.pop_front();
        while((cs == a[cn] || ce == a[cn]) && cn <= m) cn++;
        if(cn == m + 1){ result = min(result, cd); continue; }
        if(d[cs][ce][cn] <= cd) continue;
        d[cs][ce][cn] = cd;

        for(int i = 0;i < 4;i++){
            ll ns = cs + ds[i], ne = ce + de[i];
            if(outrange(ns, ne)) continue;
            q.push_back({ns, ne, cn, cd + 1});
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

