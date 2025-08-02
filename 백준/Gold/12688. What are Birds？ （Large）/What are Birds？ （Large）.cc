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
vector <pll> arr[3];
ll mnx[2], mxx[2], mny[2], mxy[2], tc;

bool chk(ll x, ll y){
    if(mnx[1] != INF && x >= mnx[1] && x > mxx[0]) return 1;
    if(mxx[1] && x <= mxx[1] && x < mnx[0]) return 1;
    if(mny[1] != INF && y >= mny[1] && y > mxy[0]) return 1;
    if(mxy[1] && y <= mxy[1] && y < mny[0]) return 1;

    return 0;
}

void run(){
    cin >> n; arr[0].clear(); 
    arr[1].clear(); arr[2].clear();

    for(int i = 1;i <= n;i++){
        ll x, y; string c;
        cin >> x >> y >> c;
        if(c == "BIRD") arr[0].push_back({x, y});
        else{
            cin >> c;
            arr[1].push_back({x, y});
        }
    }  

    mnx[0] = mnx[1] = mny[0] = mny[1] = INF;
    mxx[0] = mxx[1] = mxy[0] = mxy[1] = 0;
    for(auto& [x, y] : arr[0]){
        mnx[0] = min(mnx[0], x); mxx[0] = max(mxx[0], x);
        mny[0] = min(mny[0], y); mxy[0] = max(mxy[0], y);
    }

    for(auto& [x, y] : arr[1]){
        if(x <= mxx[0] && x >= mnx[0]){
            if(y < mny[0]) mxy[1] = max(mxy[1], y);
            else mny[1] = min(mny[1], y);
        }
        else if(y <= mxy[0] && y >= mny[0]){
            if(x < mnx[0]) mxx[1] = max(mxx[1], x);
            else mnx[1] = min(mnx[1], x);
        }
        else arr[2].push_back({x, y});
    }

    cin >> m; cout << "Case #" << ++tc << ":\n";
    while(m--){
        ll x, y; cin >> x >> y;
        if(x >= mnx[0] && x <= mxx[0] && y >= mny[0] && y <= mxy[0]){
            cout << "BIRD" << "\n";
        }
        else if(chk(x, y)){
            cout << "NOT BIRD" << "\n";
        }
        else{
            bool flag = 0;
            for(auto& [nx, ny] : arr[2]){
                ll cnt = 0;
                if(mxx[0] && nx > mxx[0] && x >= nx) cnt++;
                else if(mnx[0] != INF && nx < mnx[0] && x <= nx) cnt++;

                if(mxy[0] && ny > mxy[0] && y >= ny) cnt++;
                else if(mny[0] != INF && ny < mny[0] && y <= ny) cnt++;

                if(cnt == 2){
                    flag = 1; break;
                }
            }

            if(!flag) cout << "UNKNOWN" << "\n";
            else cout << "NOT BIRD" << "\n";
        }
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

