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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll org[MAX], pos[MAX], two, cnt, a[MAX];
pll result[2];

void init(){
    for(int i = 1;i <= n;i++) pos[a[i]] = i;
}

void print(){
    for(int i = 0;i < 2;i++) {
        if(!result[i].x) result[i] = {1, 1};
        cout << result[i].x << " " << result[i].y << "\n";
    }
}

bool chk(){
    for(int i = 1;i <= n;i++) if(a[i] != i) return 0;
    return 1;
}

void run(){
    cin >> n; a[0] = -1; a[n + 1] = -1;
    for(int i = 1;i <= n;i++) cin >> org[i]; 
    for(int i = 1;i <= n;i++) a[i] = org[i]; init();

    for(int i = 1;i <= n;i++){
        if(a[i] == i) continue;
        result[cnt].x = i; result[cnt].y = pos[i]; 
        if(result[cnt].x > result[cnt].y) swap(result[cnt].x, result[cnt].y);
        reverse(a + result[cnt].x, a + result[cnt].y + 1); cnt++;
        if(cnt == 2) break; init();
    }
    if(chk()){ print(); return; }

    for(int i = 1;i <= n;i++) a[i] = org[i]; cnt = 0; init();
    for(int i = n;i >= 1;i--){
        if(a[i] == i) continue;
        result[cnt].x = i; result[cnt].y = pos[i];
        if(result[cnt].x > result[cnt].y) swap(result[cnt].x, result[cnt].y);
        reverse(a + result[cnt].x, a + result[cnt].y + 1); cnt++;
        if(cnt == 2) break; init();
    }
    if(chk()){ print(); return; }

    for(int i = 1;i <= n;i++) a[i] = org[i]; cnt = 0; init();
    for(int i = 1;i <= n;i++){
        if(a[i] == i) continue;
        result[cnt].x = i; result[cnt].y = pos[i]; 
        if(result[cnt].x > result[cnt].y) swap(result[cnt].x, result[cnt].y);
        reverse(a + result[cnt].x, a + result[cnt].y + 1); init(); cnt++;
        if(cnt == 1) break;
    }

    for(int i = n;i >= 1;i--){
        if(a[i] == i) continue;
        result[cnt].x = i; result[cnt].y = pos[i];
        if(result[cnt].x > result[cnt].y) swap(result[cnt].x, result[cnt].y);
        reverse(a + result[cnt].x, a + result[cnt].y + 1); cnt++;
        if(cnt == 2) break;
    }
    if(chk()){ print(); return; }

    for(int i = 1;i <= n;i++) a[i] = org[i]; cnt = 0; init();
    for(int i = n;i >= 1;i--){
        if(a[i] == i) continue;
        result[cnt].x = i; result[cnt].y = pos[i];
        if(result[cnt].x > result[cnt].y) swap(result[cnt].x, result[cnt].y);
        reverse(a + result[cnt].x, a + result[cnt].y + 1); init(); cnt++;
        if(cnt == 1) break;
    }

    for(int i = 1;i <= n;i++){
        if(a[i] == i) continue;
        result[cnt].x = i; result[cnt].y = pos[i];
        reverse(a + result[cnt].x, a + result[cnt].y + 1); cnt++;
        if(cnt == 2) break;
    }
    if(chk()){ print(); return; }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

