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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[3];

class line{
public:
    ld a, b;
    ld f(ll x){
        ld ret = (a * a * x * x * x) / (ld)3;
        ret += a * b * x * x;
        ret += b * b * x;
        return ret;
    }

    ld integral(ll s, ll e) { return (f(e) - f(s)) * M_PI; }
};
line arr[3];
vector <pair<pll, ld>> num;

ld cal(pll p1, pll p2){
    ll dx = p2.x - p1.x;
    ll dy = p2.y - p1.y;

    line line; ld ig = 0;
    if(!dx) line.a = INF;
    else line.a = dy / (ld)dx;

    if(line.a != INF){
        line.b = -line.a * p1.x + p1.y;
        ig = line.integral(p1.x, p2.x);
    }
    
    return ig;
}

ld ret(){
    ld ret = 0;
    ret += cal(a[0], a[1]);
    ret += cal(a[1], a[2]);
    ret -= cal(a[0], a[2]);

    return fabs(ret);
}

int main() {
    fastio;

    ld rx, ry;
    for(int i = 0;i < 3;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1); rx = ret();

    for(int i = 0;i < 3;i++) swap(a[i].x, a[i].y);
    sort(a + 1, a + n + 1); ry = ret();
    
    cout.precision(15);
    cout << rx << " " << ry;
    
     
    return 0;
}