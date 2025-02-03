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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll org[MAX], a[MAX], result = INF;
ll cnt[3][3];
vector <ll> vec = {0, 1, 2};

void init(){
    for(int i = 1;i <= n;i++) a[i] = org[i];
    memset(cnt, 0, sizeof(cnt));
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> org[i], org[i]--;
    while(1){
        init(); sort(a + 1, a + n + 1, [](ll a, ll b){
            return vec[a] < vec[b];
        });

        ll now = 0, rest = 0;
        for(int i = 1;i <= n;i++) cnt[a[i]][org[i]]++;
        for(int i = 0;i < 3;i++){
            for(int j = i + 1;j < 3;j++){
                if(!cnt[i][j] || !cnt[j][i]) continue;
                ll mn = min(cnt[i][j], cnt[j][i]);
                now += mn; cnt[i][j] -= mn; cnt[j][i] -= mn;
            }
        }
        now += 2 * (cnt[0][1] + cnt[0][2]);
        
        result = min(result, now);
        if(!next_permutation(all(vec))) break;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}