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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
multiset <ll> num;
ll a[MAX], cnt[MAX];

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) num.insert(0);

    ll flag = 1;
    for(int i = 1;i <= n;i++){
        ll mx = *--num.end(), mn = *num.begin();
        ll diff = a[i] - a[i - 1];
        if(diff > 1 || diff < 0) flag = 0;

        if(!diff){
            num.erase(num.find(mn));
            mn++; num.insert(mn);
        }
        else {
            num.erase(num.find(mx));
            mx++; num.insert(mx);
        }

        ll now = *--num.end();
        if(now != a[i]) flag = 0;
    }

    ll all = n / m; if(n % m) all++;
    ll now = *--num.end();
    if(now > all) flag = 0;

    if(flag) cout << "YES";
    else cout << "NO";
  
     
    return 0;
}