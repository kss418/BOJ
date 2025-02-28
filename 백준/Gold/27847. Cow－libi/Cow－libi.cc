#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
class node{
public:
    ll x, y, t;
    bool operator < (const node& ot) const{
        return t < ot.t;
    }
};
vector <node> a, b;

bool chk(node& a, node &b){
    if(abs(b.t) >= INF - 10) return 1;
    ll dx = abs(a.x - b.x), dy = abs(a.y - b.y);
    ll dt = abs(a.t - b.t);

    return (dx * dx + dy * dy > dt * dt ? 0 : 1);
}

void run(){
    cin >> n >> m;
    a.push_back({INF, INF, INF});
    a.push_back({MINF, MINF, MINF});
    for(int i = 1;i <= n;i++){
        ll x, y, t; cin >> x >> y >> t;
        a.push_back({x, y, t});
    }
    sort(all(a));
    for(int i = 1;i <= m;i++){
        ll x, y, t; cin >> x >> y >> t;
        b.push_back({x, y, t});
    }

    ll result = 0;
    for(auto& cur : b){
        auto ub = *lower_bound(all(a), cur);
        auto lb = *--lower_bound(all(a), cur);
        if(!chk(cur, ub) || !chk(cur, lb)) result++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}