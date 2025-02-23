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
ll a[MAX];
map <string, vector<ll>> arr;
map <string, ll> cnt;
vector <string> result;

void run(){
    cin >> n >> m >> s;
    for(int i = 0;i < s.size() - 2;i++){
        string now = s.substr(i, 3);
        if(now[0] != now[1] && now[1] == now[2]) {
            if(arr[now].empty()) arr[now].push_back(MINF);
            arr[now].push_back(i);
        }
    }
    for(auto& i : arr) i.y.push_back(INF);

    for(int i = 0;i < s.size() - 2;i++){
        for(int j = 0;j < 3;j++){
            for(int k = 0;k < 26;k++){
                if(s[i + j] == k + 'a') continue;
                string now = s.substr(i, 3);
                now[j] = k + 'a';
                if(now[0] != now[1] && now[1] == now[2]) {
                    if(arr[now].empty()){
                        arr[now].push_back(MINF);
                        arr[now].push_back(INF);
                    }

                    ll ub = *upper_bound(all(arr[now]), i);
                    ll lb = *--upper_bound(all(arr[now]), i);
                    if(lb <= i - 3 && ub >= i + 3) cnt[now] = 1;
                }
            }
        }
    }

    for(auto& i : arr){
        if((i.y.size() - 2) + cnt[i.x] >= m) result.push_back(i.x);
    }

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

