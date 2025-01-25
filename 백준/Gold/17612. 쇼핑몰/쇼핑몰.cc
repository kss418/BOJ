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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
class node{
public:
    ll t, num, use;
    bool operator > (const node& ot) const{
        if(t != ot.t) return t > ot.t;
        return use < ot.use;
    }
};
priority_queue <node, vector<node>, greater<node>> pq;
priority_queue <ll, vector<ll>, greater<ll>> use;

void run(){
    cin >> n >> m; ll result = 0, cur = 0, cnt = 1;
    for(int i = 1;i <= m;i++) use.push(i);
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        if(use.empty()){
            auto [ct, cn, cu] = pq.top(); pq.pop();
            use.push(cu); cur = ct; result += cn * cnt; cnt++;
            while(!pq.empty() && pq.top().t == cur){
                auto [ct, cn, cu] = pq.top(); pq.pop();
                use.push(cu); result += cn * cnt; cnt++;
            }
        }

        pq.push({cur + a[i].y, a[i].x, use.top()});
        use.pop();
    }

    while(!pq.empty()){
        auto [ct, cn, cu] = pq.top(); pq.pop();
        result += cn * cnt; cnt++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

