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
constexpr ll MAX = 25; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> a;
set <ll> arr[MAX];
ll cnt;

void init(){
    a.clear(); cnt = 0;
    for(int i = 1;i <= 24;i++) arr[i].clear();
}

void run(){
    while(1){
        init();
        while(1){
            cin >> n >> m;
            if(n <= 0) break;
            a.push_back({n, m});
        }

        if(a.empty()) break;
        for(auto& i : a){
            auto[x, y] = i;
            arr[x].insert(y); cnt++;
        }

        ll result = 0;
        while(cnt){
            ll mx = 24; result++;
            for(int i = 24;i >= 1;i--){
                auto idx = arr[i].upper_bound(mx);
                if(idx == arr[i].begin()) continue; idx--;

                ll num = *idx + 1; mx = *arr[i].begin();
                while(!arr[i].empty() && *arr[i].begin() < num) {
                    arr[i].erase(arr[i].begin()); cnt--;
                }
            }
        }

        cout << result << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

