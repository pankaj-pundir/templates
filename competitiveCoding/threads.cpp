#include<bits/stdc++.h>
#include<threads.h>
using namespace std;

int i ;
void printData(string name){
    atomic<int>{
        for( i = 0; i< 100; i ++){
            cout<<name<<" "<<i<<"\n";
        }
       
    }
     return ;
    
}

int main(){
    thread th1(printData,"first");
    thread th2(printData,"second");
    th1.join();
    th2.join();
    cout<<"threads complete";
    return 0;
}