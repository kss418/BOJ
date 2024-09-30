#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101;
constexpr ll MOD = 998244353;
vector <ll> arr; ll cnt[MAX];
set <ll> result;
map <ll, ll> num;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> m; 
        if(!cnt[m]) arr.push_back(m);
        cnt[m]++;
    }
    sort(all(arr));

    ll mx = min<ll>(4, arr.size());
    for(int i = 0;i < mx;i++){
        for(int j = i + 1;j < mx;j++){
            ll cc = cnt[arr[i]] * cnt[arr[j]];
            string pre = to_string(arr[i]) + to_string(arr[j]);
            string nxt = to_string(arr[j]) + to_string(arr[i]);
            result.insert(stoll(pre)); result.insert(stoll(nxt));
            num[stoll(pre)] += cc;
            num[stoll(nxt)] += cc;
        }
    }

    for(int i = 0;i < mx;i++){
        ll cc = cnt[arr[i]] * (cnt[arr[i]] - 1);
        string cur = to_string(arr[i]) + to_string(arr[i]);
        result.insert(stoll(cur));
        num[stoll(cur)] += cc;
    }

    ll cur = 0;
    for(auto& i : result){      
        cur += num[i];
        if(cur >= 3){
            cout << i; return 0;
        }
    }


    return 0;
}