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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
deque <ll> arr[MAX];
string st[MAX];
ll cnt;

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(int j = 0;j < m;j++){
            if(st[i][j] == '_') continue;
            arr[j].push_back(i); cnt++;
        }
    }
    for(int j = 0;j < m;j++) sort(all(arr[j]));

    ll result = 0;
    while(cnt){
        ll mx = n - 1; result++;
        for(int i = m - 1;i >= 0;i--){
            if(arr[i].empty() || arr[i].front() > mx) continue;
            ll fr = arr[i].front();

            while(!arr[i].empty() && arr[i].front() <= mx) {
                arr[i].pop_front(); cnt--;
            }
            mx = fr;
        }
    }

    cout << result << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

