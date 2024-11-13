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
constexpr ll MAX = 5; // PLZ CHK!
constexpr ll MOD = 998244353;
ll a[MAX][MAX];
ll win[MAX], gs[MAX], sc[MAX];
ll cx, cy;
vector <ll> arr(4);

bool cmp(ll a, ll b){
    if(win[a] != win[b]) return win[a] > win[b];
    if(gs[a] != gs[b]) return gs[a] > gs[b];
    if(sc[a] != sc[b]) return sc[a] > sc[b];   
    return a < b;
}

class _bs { // 0-based index
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    void init(){
        memset(win, 0, sizeof(win));
        memset(gs, 0, sizeof(gs));
        memset(sc, 0, sizeof(sc));
    }

    ll f(ll cur) {
        init();
        a[cy][cx] = cur;

        for(int i = 1;i <= 4;i++){
            for(int j = i + 1;j <= 4;j++){
                if(i == j) continue;

                ll diff = a[i][j] - a[j][i];
                gs[i] += diff; gs[j] -= diff;
                sc[i] += a[i][j]; sc[j] += a[j][i];

                if(diff > 0) win[i] += 3;
                else if(diff < 0) win[j] += 3;
                else win[i]++, win[j]++;
            }
        }

        sort(all(arr), cmp); 
        return (arr[0] == n) | (arr[1] == n);
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) >> 1ll;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};


int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= 4;i++) {
        for(int j = 1;j <= 4;j++) {
            cin >> a[i][j];
            if(a[i][j] != -1) continue;
            cx = j; cy = i;
        }
    }

    iota(all(arr), 1); 
    _bs bs(0, m + 1);
    ll ret = bs.ret();

    if(ret > m) cout << -1;
    else cout << ret;
     
    return 0;
    }