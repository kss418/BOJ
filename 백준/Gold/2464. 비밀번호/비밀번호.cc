#include <bits/stdc++.h>
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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

int main() {
    fastio;

    cin >> n; ll mx = n, mn = n;
    
    ll cnt = 0;
    for(ll i = 0;(1ll << i) <= mx;i++){
        if(!(mx & (1ll << i))) continue; cnt++;
        if(mx & (1ll << (i + 1))) continue;
        cnt--; mx |= (1ll << (i + 1));
        mx &= ~(1ll << i);

        for(ll j = 0;j < i;j++){
            if(cnt-- > 0) mx |= (1ll << j);
            else mx &= ~(1ll << j);
        }
        break;
    }

    cnt = 0;
    for(ll i = 0;(1ll << i) <= mn;i++){
        if(mn & (1ll << i)) { cnt++; continue; }
        if(!(mn & (1ll << (i + 1)))) continue;
        mn |= (1ll << i);
        mn &= ~(1ll << (i + 1));

        for(ll j = i - 1;j >= 0;j--){
            if(cnt-- > 0) mn |= (1ll << j);
            else mn &= ~(1ll << j);
        }
        break;
    }


    if(mn < n) cout << mn << " ";
    else cout << 0 << " ";

    if(mx > n) cout << mx;
    else cout << 0;
    

    return 0;
}