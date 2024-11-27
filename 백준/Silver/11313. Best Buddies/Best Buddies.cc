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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pair <string, string> arr[MAX];
map <pair<string, string>, ll> idx;

int main() {
    fastio;

    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i].y >> arr[i].x;
    sort(arr, arr + n);

    for(int i = 0;i < n;i++) idx[arr[i]] = i;

    cin >> m;
    while(m--){
        pair<string, string> cur;
        cin >> cur.y >> cur.x;
        ll num = idx[cur], div = num / 3;

        for(int i = 3 * div;i <= 3 * div + 2;i++){
            if(i == num) continue;
            cout << arr[i].y << " " << arr[i].x << "\n";
        }
    }
    
     
    return 0;
}