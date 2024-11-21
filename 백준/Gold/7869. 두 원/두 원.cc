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

class circle{
public: 
    ld x, y, r;
    ld dist(circle &ot){
        ld dx = x - ot.x;
        ld dy = y - ot.y;
        return sqrtl(dx * dx + dy * dy);
    }

    ld area(){
        return r * r * M_PI;
    }
};


ld deg(circle a, circle b){
    ld d = a.dist(b);
    ld ret = 2 * acosl((d * d + a.r * a.r - b.r * b.r) / ((ld)2 * d * a.r));
    ret *= (ld)180 / M_PI;
    return ret;
}

int main() {
    fastio;

    circle a, b;
    cin >> a.x >> a.y >> a.r >> b.x >> b.y >> b.r;
    
    cout << fixed << setprecision(3);
    if(a.dist(b) > a.r + b.r) cout << "0.000";
    else if(a.dist(b) <= abs(a.r - b.r)) cout << min(a.area(), b.area());
    else{
        ld ac = deg(a, b) * a.area() / (ld)360;
        ld bc = deg(b, a) * b.area() / (ld)360;

        ld at = sin(deg(a, b) * M_PI / (ld)180) * a.r * a.r / (ld)2;
        ld bt = sin(deg(b, a) * M_PI / (ld)180) * b.r * b.r / (ld)2;

        cout << ac + bc - at - bt;
    }

     
    return 0;
}