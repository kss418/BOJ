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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
multiset <ll> num;

int main() {
    fastio;

    cin >> n;
    ll result = 0, cur = 0;
    num.insert(-INF); num.insert(INF);

    while(n--){
        ll com; cin >> com;
        if(com == 1){
            ll x; cin >> x;
            num.insert(x);
        }
        else{
            while(num.size() > 2){
                ll nxt = *num.lower_bound(cur);
                ll pre = *--num.lower_bound(cur);

                if(nxt - cur < cur - pre){
                    result += nxt - cur;
                    cur = nxt;
                }
                else{
                    result += cur - pre;
                    cur = pre;
                }
                num.erase(num.find(cur));
            }
        }
    }

    cout << result;
    
    
    return 0;
}