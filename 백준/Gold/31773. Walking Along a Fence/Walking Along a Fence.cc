#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll num[1010][1010], cnt;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> a[i].x >> a[i].y;
    a[m + 1] = a[1];

    for(int i = 2;i <= m + 1;i++){
        if(a[i].x == a[i - 1].x){
            if(a[i].y > a[i - 1].y){
                for(int j = a[i - 1].y;j < a[i].y;j++){
                    num[a[i].x][j] = cnt++;
                }
            }
            else{
                for(int j = a[i - 1].y;j > a[i].y;j--){
                    num[a[i].x][j] = cnt++;
                }
            }
        }
        else{
            if(a[i].x > a[i - 1].x){
                for(int j = a[i - 1].x;j < a[i].x;j++){
                    num[j][a[i].y] = cnt++;
                }
            }
            else{
                for(int j = a[i - 1].x;j > a[i].x;j--){
                    num[j][a[i].y] = cnt++;
                }
            }
        }
    }

    while(n--){
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ll mx = max(num[x1][y1], num[x2][y2]);
        ll mn = min(num[x1][y1], num[x2][y2]);
        cout << min(mx - mn, cnt + mn - mx) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}