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
    ll ret(tll a, tll b, tll c){
        pll pa = {get<1>(a), get<2>(a)};
        pll pb = {get<1>(b), get<2>(b)};
        pll pc = {get<1>(c), get<2>(c)};
        return ret(pa, pb, pc);
    }
};

pll a[MAX];
int main() {
    fastio;

    cin >> t; _ccw ccw;
    while(t--){
        cin >> s; ll cx = 0, cy = 0, cnt = 0;

        for(auto& i : s){
            ++cnt;
            if(i == 'N') cy++;
            else if(i == 'S') cy--;
            else if(i == 'W') cx--;
            else if(i == 'E') cx++;
            a[cnt] = {cx, cy};
        }

        ll result = 0;
        for(int i = 1;i < s.size();i++){
            result += ccw.ret(a[i - 1], a[i], a[i + 1]);
        }

        if(result > 0) cout << "CCW\n";
        else cout << "CW\n";
    }


    return 0;
}

