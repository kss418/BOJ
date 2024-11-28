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
constexpr ll MAX = 20101; // SET MAX SIZE
constexpr ll MOD = 998244353;
set <string> num;
set <pair<string, ll>> arr;
string a[MAX];

int main() {
    fastio;

    cin >> n; ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        string st; cin >> st;
        if(num.count(st)) continue;
        num.insert(st);
        arr.insert({st, ++cnt});
        a[cnt] = st;
    }

    ll mx = -1, result = -1;
    for(auto& i : arr){
        if(arr.find(i) == --arr.end()) continue;
        auto cit = arr.find(i);
        auto nit = ++cit; cit--;

        string cur = cit->x, nxt = nit->x; ll idx = 0;
        for(int i = 0;i < min(cur.size(), nxt.size());i++){
            if(cur[i] != nxt[i]) break; idx = i + 1;
        }

        if(idx > mx){
            mx = idx; result = min(cit->y, nit->y);
        }
        else if(idx == mx){
            result = min({result, cit->y, nit->y});
        }
    }
    
    ll idx = -1;
    for(int i = 1;i <= arr.size();i++){
        if(result == i) continue;
        string& cur = a[result], &nxt = a[i];
        ll cnt = 0;
        for(int i = 0;i < min(cur.size(), nxt.size());i++){
            if(cur[i] != nxt[i]) break; cnt = i + 1;
        }

        if(cnt == mx) { idx = i; break; }
    }

    if(idx < result) swap(idx, result);
    cout << a[result] << "\n" << a[idx];
    
     
    return 0;
}