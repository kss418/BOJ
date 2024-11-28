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
set <string> arr;


int main() {
    fastio;

    cin >> s; vector <pll> a;
    for(int i = 0;i < s.size();i++){
        if(s[i] != '(' && s[i] != ')') continue;
        else if(s[i] == '(') a.push_back({i, 1});
        else a.push_back({i, -1});
    }

    for(int i = 0;i < (1ll << a.size()) - 1;i++){
        vector <ll> er;
        for(int j = 0;j < a.size();j++){
            if(i & (1ll << j)) continue;
            er.push_back(j);
        }

        ll cnt = 0, flag = 1;
        for(auto& j : er) {
            cnt += a[j].y;
            if(cnt < 0) flag = 0; 
        }
        if(cnt || !flag) continue;

        stack <ll> st;
        vector <pll> pr;
        for(auto& j : er){
            if(a[j].y == 1) st.push(j);
            else pr.push_back({st.top(), j}), st.pop();
        }   

        for(auto& i : pr){
            ll l = i.x, r = i.y, cnt = 0;
            for(int idx = l + 1;idx <= r - 1;idx++){
                cnt += a[idx].y;
                if(cnt < 0) flag = 0;
            }
            if(cnt) flag = 0;
        }
        if(!flag) continue;

        ll idx = 0; string cur;
        for(int j = 0;j < s.size();j++){
            if(idx < er.size() && a[er[idx]].x == j) idx++;
            else cur.push_back(s[j]);
        }

        arr.insert(cur);
    }

    for(auto& i : arr) cout << i << "\n";

     
    return 0;
}