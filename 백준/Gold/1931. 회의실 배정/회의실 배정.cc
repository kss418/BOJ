#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 101010;
ll n;
pair <ll, ll> a[MAX];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].second >> a[i].first;
    sort(a + 1, a + n + 1);

    ll la = -1, result = 0;
    for(int i = 1;i <= n;i++){
        if(a[i].second < la) continue;
        la = a[i].first; result++;
    }

    cout << result;
    return 0;
}