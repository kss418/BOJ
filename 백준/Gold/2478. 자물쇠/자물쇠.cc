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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll arr[MAX], num[MAX], org[MAX];
ll st = INF, en;
ll tmp[MAX], ret[MAX];

void init(ll i){
    for(int i = 1;i <= 2 * n;i++) arr[i] = org[i];
    arr[i - 1] = arr[i + n - 1];
    arr[i + n] = arr[i]; st = INF; en = 0;
}

bool chk(ll a, ll s, ll e, ll b){
    for(int i = 1;i <= n;i++) tmp[(i - 1 - a + n) % n + 1] = i;
    reverse(tmp + s, tmp + e + 1);
    for(int i = 1;i <= n;i++) ret[(i - 1 - b + n) % n + 1] = tmp[i];
    
    for(int i = 1;i <= n;i++) if(org[i] != ret[i] - 1) return 0;
    return 1;
}

void run(){
    cin >> n; 
    for(int i = 1;i <= n;i++) cin >> org[i], org[i]--;
    for(int i = n + 1;i <= 2 * n;i++) org[i] = org[i - n];

    for(ll i = 2;i <= n;i++){
        init(i);
        for(ll j = i;j < i + n;j++){
            if(arr[j] == (arr[j - 1] + n - 1) % n || arr[j] == (arr[j + 1] + n + 1) % n) num[j] = 1;
            else num[j] = 0;
            if(!num[j]) continue;
            st = min(st, j); en = max(en, j);
        }
        reverse(arr + st, arr + en + 1);

        if(arr[i] && chk(arr[i], st - i + 1, en - i + 1, n - i + 1)){
            cout << arr[i] << "\n";
            cout << st - i + 1 << " " << en - i + 1 << "\n";
            cout << n - i + 1 << "\n"; return;
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

