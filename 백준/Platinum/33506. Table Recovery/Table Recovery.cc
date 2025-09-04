#include <bits/stdc++.h>
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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], cnt[2 * MAX];
ll num[2 * MAX], result[MAX][MAX][2];
vector <pll> arr;

bool chk(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(result[i][j][0] == result[i][j][1]) continue;
            return result[i][j][1] < result[i][j][0];
        }
    }

    return 0;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            ll now = a[i][j];

            if(cnt[now] == n) num[now] = n + 1;
            if(cnt[now] != 1) continue;
            arr.push_back({i, j});
        }
    }
    sort(all(arr));

    if(!arr.empty()) for(int i = 1;i <= n;i++){
        ll now = a[arr[0].x][i];
        ll l = 1 + cnt[now], r = 2 * n - cnt[now] + 1;
        num[a[arr[0].x][i]] = l;
    }

    if(arr.size() >= 2) for(int i = 1;i <= n;i++){
        ll now = a[arr[1].x][i];
        ll l = 1 + cnt[now], r = 2 * n - cnt[now] + 1;
        num[a[arr[1].x][i]] = r;
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            result[i][j][0] = num[a[i][j]];
            result[i][j][1] = 2 * n - num[a[i][j]] + 2;
        }
    }

    bool cnt = chk();
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cout << result[i][j][cnt] << " ";
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}