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
vector <ll> able;
set <ll> per;
string cur;
ll arr[11];

void bt(){
    if(cur.size() == 4){
        for(int i = 0;i < 4;i++) arr[i] = cur[i] - '0';
        for(int i = 4;i < 8;i++) arr[i] = arr[i - 4];
        
        string now;
        vector <ll> able;
        for(int i = 0;i < 4;i++){
            now.clear();
            for(int j = 0;j < 4;j++) now.push_back(arr[i + j] + '0');
            able.push_back(stoll(now));
        }
        sort(all(able)); per.insert(able[0]);
        
        return;
    }

    for(int i = 1;i <= 9;i++){
        cur.push_back(i + '0');
        bt();
        cur.pop_back();
    }
}

int main() {
    fastio;

    for(int i = 0;i < 4;i++) cin >> arr[i];
    for(int i = 4;i < 8;i++) arr[i] = arr[i - 4];

    for(int i = 0;i < 4;i++){
        cur.clear();
        for(int j = 0;j < 4;j++) cur.push_back(arr[i + j] + '0');
        able.push_back(stoll(cur));
    }
    cur.clear();
    sort(all(able)); bt(); 

    ll result = 0;
    for(auto& i : per){
        result++;
        if(i == able[0]) {
            cout << result; return 0;
        }
    }


    return 0;
}