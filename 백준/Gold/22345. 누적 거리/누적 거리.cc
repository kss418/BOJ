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
vector <ll> num;
ll ps[MAX], pc[MAX];
ll ss[MAX], sc[MAX];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].y >> a[i].x, num.push_back(a[i].x);
    a[0].x = MINF; sort(a + 1, a + n + 1); num.push_back(MINF);
    pc[1] = a[1].y; sort(all(num));
    for(int i = 2;i <= n;i++){
        ps[i] = ps[i - 1] + pc[i - 1] * (a[i].x - a[i - 1].x);
        pc[i] = pc[i - 1] + a[i].y;
    }

    sc[n] = a[n].y;
    for(int i = n - 1;i >= 1;i--){
        ss[i] = ss[i + 1] + sc[i + 1] * (a[i + 1].x - a[i].x);
        sc[i] = sc[i + 1] + a[i].y;
    }

    while(m--){
        ll v, now = 0; cin >> v;
        ll l = upper_bound(all(num), v) - num.begin() - 1;
        ll r = upper_bound(all(num), v) - num.begin();
        now += ps[l] + (v - num[l]) * pc[l];
        now += ss[r] + (num[r] - v) * sc[r];

        cout << now << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

