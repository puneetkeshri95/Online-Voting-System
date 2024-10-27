#include<iostream>
using namespace std;
int count=0;
void print(){
    if(count==3){
        return ;
    }
    cout<<count<<" ";
    count++;
    print();
}
int main(){
    print();
}