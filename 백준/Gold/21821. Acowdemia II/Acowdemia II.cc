#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], v[MAX];
string st[MAX];
char result[MAX][MAX];
map <string, ll> num;
vector <ll> arr;

void init(){
    v[m - 1] = 0;
    for(int i = m - 2;i >= 0;i--){
        if(st[arr[i]] > st[arr[i + 1]]) v[i] = v[i + 1] + 1;
        else v[i] = v[i + 1];
    }

    for(int i = 0;i < m;i++){
        for(int j = i + 1;j < m;j++){
            if(v[i] == v[j]) continue;
            result[arr[i]][arr[j]] = (v[i] > v[j] ? '0' : '1');
            result[arr[j]][arr[i]] = (v[i] > v[j] ? '1' : '0');
        }
    }
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> st[i], num[st[i]] = i;

    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= m;j++) result[i][j] = (i == j ? 'B' : '?');
    }


    for(int i = 1;i <= n;i++){
        arr.clear();
        for(int j = 1;j <= m;j++){
            cin >> s; arr.push_back(num[s]);
        }   
        init();
    }

    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= m;j++) cout << result[i][j];
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}