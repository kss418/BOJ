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
ld a[MAX];

class line{
public:
    ld a, b;
    line(){}
    line(pld v1, pld v2){
        ld dx = v2.x - v1.x;
        ld dy = v2.y - v1.y;
        if(v2.x == v1.x) a = 1e12 + 1;
        else a = dy / dx;

        if(a >= 1e12) b = 0;
        else b = -a * v1.x + v1.y;
    }

    ld integral(ld s, ld e){ return integral(e) - integral(s); }
    ld integral(ld x){
        return (a * x * x) / (ld)2 + b * x;
    }
};

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    line f1, f2;
    if(2 * k > n * m){
        f1 = {{0, -m}, {n / (ld)2, -k / (ld)n}};
        f2 = {{n, -m}, {n / (ld)2, -k / (ld)n}};
    }
    else{
        f1 = {{0, 0}, {n / (ld)2, -k / (ld)n}};
        f2 = {{n, 0}, {n / (ld)2, -k / (ld)n}};
    }

    ld r1 = 0, r2 = 0;
    for(int i = 1;i <= n;i++){
        r1 += abs(f1.integral(i - 1, i)) * a[i];
        r2 += abs(f2.integral(i - 1, i)) * a[i];
    }

    cout.precision(20);
    cout << min(r1, r2);

     
    return 0;
}