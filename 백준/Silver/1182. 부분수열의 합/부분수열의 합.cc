#include <iostream>
#include <vector>

using namespace std;

int arr[100001];
int isused[100001];
vector <int> nums;
int s,n,check;
int ord = 0;

void bt();

void bt(){
    if(nums.size() == n){
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
        }
        if(sum == s){
            check += 1;
        }
        return;
    }
    else{
        for(int j = 0;j < 2;j++){
            if(j == 0){
                nums.push_back(0);
                ord += 1;
            }
            else{
                nums.push_back(arr[ord]);
                ord += 1;
            }
            bt();
            nums.pop_back();
            ord -= 1;
        }
    }
}

int main() {
    int num;
    cin >> n >> s;
    check = 0;
    for(int i = 0;i < n;i++){
        cin >> num;
        arr[i] = num;
    }
    bt();
    if(!s){
        check -= 1;
    }
    cout << check << endl;

    return 0;
}