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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

map <vector<ll>, bool> cnt;
ll result;

ll dist(pll a, pll b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool chk(vector <pll>& v){
    bool ret = 0;
    vector <ll> arr;
    for(int i = 0;i < 3;i++){
        arr.push_back(dist(v[i], v[(i + 1) % 3]));
    }
    sort(all(arr));
    
    ret = cnt[arr];
    cnt[arr] = 1;

    return ret;
}

class _ccw{
public:
    _ccw() {}

    ll ret(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
        return ret({x1, y1}, {x2, y2}, {x3, y3});
    }
    ll ret(pll v1, pll v2, pll v3){
        ll num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1; 
        else if(num < 0) return -1; 
        return 0;
    }
};

_ccw ccw;
vector <pll> num;
void bt(){
    if(num.size() == 3){
        vector <pll> now = num;
        if(!ccw.ret(now[0], now[1], now[2])) return;
        
        result += chk(now) ^ 1; return;
    }

    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++){
            num.push_back({i, j});
            bt();
            num.pop_back();
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;
    bt();

    cout << result;
    
     
    return 0;
}