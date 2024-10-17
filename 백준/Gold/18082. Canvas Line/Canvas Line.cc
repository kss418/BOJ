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
vector <tll> arr, vec;
ll use[MAX], cnt[MAX];
map <ll, bool> v;
vector <ll> result;

int main() {
    fastio;

    cin >> n; ll flag = 1;
    for(int i = 1;i <= n;i++) {
        ll a, b; cin >> a >> b;
        arr.push_back({a, b, i});
    }
    sort(all(arr));

    cin >> m;
    for(int i = 1;i <= m;i++){
        cin >> k; v[k] = 1;
        for(auto& cur : arr){
            auto [s, e, idx] = cur;
            if(k >= s && k <= e) cnt[idx]++;
            if(cnt[idx] >= 3) flag = 0;
        }
    }

    if(!flag) {
        cout << "impossible";
        return 0;
    }

    auto[cs, ce, ci] = arr[0];
    if(cnt[ci] == 0) {
        ll ts = cs + 1, te = ce - 1;
        use[ci] += 2;
        while(ts <= te){
            if(!v[ts]){
                result.push_back(ts); break;
            }
            ts++;
        }

        ts = cs + 1, te = ce - 1;
        while(ts <= te){
            if(!v[te]){
                result.push_back(te); break;
            }
            te--;
        }
    }
    else if(cnt[ci] == 1){
        ll ts = cs + 1, te = ce - 1;
        use[ci]++;
        while(ts <= te){
            if(!v[te]){
                result.push_back(te); break;
            }
            te--;
        }
    }

    for(int i = 1;i < arr.size();i++){
        auto [cs, ce, ci] = arr[i];
        auto [ps, pe, pi] = arr[i - 1];

        if(cnt[ci] == 2) continue; use[ci] = 2 - cnt[ci];
        if(use[pi] && !v[cs] && pe == cs) result.pop_back(), result.push_back(cs), use[ci]--;
 
        if(use[ci] == 1) {
            ll ts = cs + 1, te = ce - 1;
            while(ts <= te){
                if(!v[te]){
                    result.push_back(te); break;
                }
                te--;
            }
        }
        else if(use[ci] == 2){
            ll ts = cs + 1, te = ce - 1;
             while(ts <= te){
                if(!v[ts]){
                    result.push_back(ts); break;
                }
                ts++;
            }

            ts = cs + 1, te = ce - 1;
            while(ts <= te){
                if(!v[te]){
                    result.push_back(te); break;
                }
                te--;
            }
        }
    }
        
    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " "; 
    

    return 0;
}