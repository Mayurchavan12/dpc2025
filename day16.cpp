#include<bits/stdc++.h>
using namespace std;

int main(){

    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    for(int i=1; i>0; i++){
        if(i%num1==0 && i%num2==0){
            cout << "LCM : " << i;
            break; 
        }
    }

    return 0;
}
