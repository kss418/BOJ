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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll pre[MAX][22];
ll now[MAX], len[MAX];
char ch[MAX];
ll cnt, la;

void init(){
    for(int i = 0;i < MAX;i++){
        for(int j = 0;j < 22;j++) pre[i][j] = {-1, -1};
    }
}

void run(){
    cin >> m; init();
    while(m--){
        char op; cin >> op;
        if(op == 'T'){
            char c; cin >> c; ++cnt;
            now[cnt] = cnt;
            len[cnt] = len[la] + 1;
            ch[cnt] = c;

            pre[cnt][0].y = now[la];
        }
        else if(op == 'U'){
            ll v, num = cnt; cin >> v; cnt++;;
            for(int i = 22;i >= 0;i--){
                if(!(v & (1ll << i))) continue;
                v -= (1ll << i);
                num = pre[num][i].x;
            }

            now[cnt] = now[num];
            ch[cnt] = ch[num];
            len[cnt] = len[num];
            pre[cnt][0].y = pre[num][0].y;
        }   
        else{
            ll v, num = cnt; cin >> v; 
            v = len[cnt] - v - 1;
            if(!v){ cout << ch[cnt] << "\n"; continue; }

            for(int i = 22;i >= 0;i--){
                if(!(v & (1ll << i))) continue;
                v -= (1ll << i);
                num = pre[num][i].y;
            }

            cout << ch[num] << "\n";
            continue;
        }

        pre[cnt][0].x = la;
        for(int j = 1;j < 22;j++){
            ll px = pre[cnt][j - 1].x, py = pre[cnt][j - 1].y;
            pre[cnt][j] = {(px == -1 ? -1 : pre[px][j - 1].x), (py == -1 ? -1 : pre[py][j - 1].y)};
        }

        la = cnt;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}