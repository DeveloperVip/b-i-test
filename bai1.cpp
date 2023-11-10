#include<iostream>
using namespace std;

int tong(int n){
    unsigned int sum = 1;
    for(int i = 2; i <= n; i++){
        if(n% i==0){
            sum+=i;
        }
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    while (n--){
        unsigned int a;
        cin >> a;
        cout << tong(a) << endl;
    }
    return 0;
}