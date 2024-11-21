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
ll n, m, k, t;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class _li{
public:
    _li() {}

    ll ccw(pll v1, pll v2, pll v3){
        ll num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1; 
        else if(num < 0) return -1; 
        return 0;
    }

    bool ret(pair<pll, pll> a, pair<pll, pll> b) {
        return ret(a.x, a.y, b.x, b.y);
    }
    bool ret(pll av1, pll av2, pll bv1, pll bv2){
        ll ac = ccw(av1, av2, bv1) * ccw(av1, av2, bv2);
        ll bc = ccw(bv1, bv2, av1) * ccw(bv1, bv2, av2);

        if(!ac && !bc){
            if(av1 > av2) swap(av1, av2);
            if(bv1 > bv2) swap(bv1, bv2);
            return bv1 <= av2 && av1 <= bv2;
        }

        return ac <= 0 && bc <= 0;
    }
}; _li li;

pll s, e;
vector <pair<pll, pll>> arr;
deque <pll> q;
bool v[MAX]; 
ll result;

int main() {
    fastio;

    cin >> n >> m >> k; 
    for(int i = 1;i <= k;i++){
        pll s, e; ll num; cin >> num;
        cin >> s.x >> s.y >> e.x >> e.y;
        arr.push_back({s, e});
    }
    cin >> s.x >> s.y >> e.x >> e.y;

    for(int i = 0;i < arr.size();i++){
        if(li.ret({s, s}, arr[i])) q.push_back({i, 1});
    }

    while(!q.empty()){
        auto[cur, cnt] = q.front(); q.pop_front();
        if(v[cur]) continue; v[cur] = 1;
        if(li.ret(arr[cur], {e, e})){
            result = cnt; break;
        } 

        for(int nxt = 0;nxt < k;nxt++){
            if(v[nxt]) continue;
            if(!li.ret(arr[cur], arr[nxt])) continue;
            q.push_back({nxt, cnt + 1});
        }
    }

    cout << result;
    
     
    return 0;
}