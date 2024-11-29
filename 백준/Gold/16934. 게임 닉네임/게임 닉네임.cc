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
map <string, ll> cnt;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> s; string now, result;
        for(auto& i : s){
            now.push_back(i);
            if(!arr.count(now) && result.empty()) result = now;
            arr.insert(now);
        }
        cnt[s]++;

        if(!result.empty()) cout << result << "\n";
        else if(cnt[s] != 1) cout << s << cnt[s] << "\n";
        else cout << s << "\n";
    }   
    
     
    return 0;
}