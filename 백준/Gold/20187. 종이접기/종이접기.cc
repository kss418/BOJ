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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
char c[MAX];
ll a[MAX][MAX];
class node{
public: 
    ll y, x, num;
};
vector <node> arr, tmp;
ll cx, cy, ix, iy;

void mvx(ll sz, ll cnt){
    tmp.clear();
    for(auto& i : arr){
        auto[y, x, num] = i; num ^= 1;
        if(cnt == 1){
            ll s = x / (1ll << sz), e = s + 1;
            s *= 1ll << sz; e *= 1ll << sz;
            e += (1ll << sz) - 1;
            x = e - (x - s);
        }
        else{
            ll e = x / (1ll << sz), s = e - 1;
            s *= 1ll << sz; e *= 1ll << sz;
            e += (1ll << sz) - 1;
            x = e + (s - x);
        }
        tmp.push_back({y, x, num});
    }

    for(auto& i : tmp) arr.push_back(i);
}

void mvy(ll sz, ll cnt){
    tmp.clear();
    for(auto& i : arr){
        auto[y, x, num] = i; num = (num + 2) % 4;
        if(cnt == 1){
            ll s = y / (1ll << sz), e = s + 1;
            s *= 1ll << sz; e *= 1ll << sz;
            e += (1ll << sz) - 1;
            y = e - (y - s);
        }
        else{
            ll e = y / (1ll << sz), s = e - 1;
            s *= 1ll << sz; e *= 1ll << sz;
            e += (1ll << sz) - 1;
            y = e + (s - y);
        }
        tmp.push_back({y, x, num});
    }

    for(auto& i : tmp) arr.push_back(i);
}


void run(){
    cin >> n; cy = cx = n - 1;
    for(int i = 1;i <= 2 * n;i++) cin >> c[i];
    cin >> m;

    for(int i = 1;i <= 2 * n;i++){
        if(c[i] == 'R' || c[i] == 'L'){
            if(c[i] == 'R') ix += (1ll << cx); cx--;
        }
        else{
            if(c[i] == 'D') iy += (1ll << cy); cy--;
        }
    }

    arr.push_back({iy, ix, m}); cy = cx = 0;
    for(int i = 2 * n;i >= 1;i--){
        if(c[i] == 'R' || c[i] == 'L') mvx(cx, (c[i] == 'R' ? -1 : 1)), cx++;
        else mvy(cy, (c[i] == 'D' ? -1 : 1)), cy++;
    }

    for(auto& i : arr){
        auto[y, x, num] = i; a[y][x] = num;
    }

    for(int i = 0;i < (1ll << n);i++){
        for(int j = 0;j < (1ll << n);j++) cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

