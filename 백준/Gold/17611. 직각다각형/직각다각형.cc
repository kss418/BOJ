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
constexpr ll MID = 500100;
pll a[MAX];
ll sy[1010101], sx[1010101];
ll cy[1010101][2], cx[1010101][2];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].y >> a[i].x;
    a[n + 1] = a[1];

    for(int i = 2;i <= n + 1;i++){
        if(a[i].x == a[i - 1].x){
            if(a[i].y > a[i - 1].y){
                cy[a[i - 1].y + MID][0]++;
                cy[a[i].y + MID][0]--;
            }
            else{
                cy[a[i].y - 1 + MID][1]--;
                cy[a[i - 1].y - 1 + MID][1]++;
            }
        }
        else{
            if(a[i].x > a[i - 1].x){
                cx[a[i - 1].x + MID][0]++;
                cx[a[i].x + MID][0]--;
            }
            else{
                cx[a[i].x - 1 + MID][1]--;
                cx[a[i - 1].x - 1 + MID][1]++;
            }
        }
    }

    ll now = 0;
    for(int i = 0;i < 1010101;i++){
        now += cy[i][0];
        sy[i] += now;
    }

    now = 0;
    for(int i = 1010100;i >= 0;i--){
        now += cy[i][1];
        sy[i] += now;
    }

    now = 0;
    for(int i = 0;i < 1010101;i++){
        now += cx[i][0];
        sx[i] += now;
    }

    now = 0;
    for(int i = 1010100;i >= 0;i--){
        now += cx[i][1];
        sx[i] += now;
    }

    ll result = 0;
    for(int i = 0;i < 1010101;i++){
        result = max(result, sy[i]);
        result = max(result, sx[i]);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

