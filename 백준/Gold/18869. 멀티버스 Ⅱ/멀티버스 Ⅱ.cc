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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> a[MAX];
map <ll, ll> mp;
map <vector<ll>, ll> arr;

void run(){
    cin >> n >> m; ll result = 0;
    for(int i = 1;i <= n;i++) {
        vector <ll> now;
        for(int j = 1;j <= m;j++){
            ll num; cin >> num;
            now.push_back(num);
            a[i].push_back(num);
        }
        sort(all(now)); mp.clear();

        ll cnt = 0;
        for(auto& j : now){
            if(!mp.count(j)) mp[j] = ++cnt;
        }
        for(auto& j : a[i]) j = mp[j];

        result += arr[a[i]];
        arr[a[i]]++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

