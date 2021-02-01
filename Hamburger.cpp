#include <iostream>
using namespace std;
long long N = 2e13;
bool isEnough(long long mid,int avail[],int price[],int nBread,int nSous,int nChease,long long r2){
    long long money = r2;
    if(mid * nBread > avail[0]){
        long long diff = (mid*nBread)-avail[0];
        if(money >= diff*price[0]){

            money-=(price[0]*diff);
    }
    else if(money < diff*price[0]){

        return false;
    }
    }
    // Sous
    if(mid * nSous > avail[1]){
         long long diff2 = (mid*nSous)- avail[1];
    if(money >= diff2*price[1]){
        money-=(price[1]*diff2);
    }
    else{
        return false;
    }
    }

    // Chease
    if(mid * nChease > avail[2]){
        long long diff3 = (mid*nChease) - avail[2];
        if(money >= price[2]*diff3){
            money-=(price[2]*diff3);
    }
        else{
        return false;
    }
    }

    return true;
}

long long binarySearch(int avail[],int prices[],int nBread,int nSous,int nChease,long long r2){
    long long l = 0,m,r = N;
    while((r - l)>0){
        m = (l+r+1)/2;
        if(!isEnough(m,avail,prices,nBread, nSous,nChease,r2)){
            r = m-1;
        }
        else{
            l = m;
        }
    }
    return l;
}
int main()
{
    int available[3];
    int prices[3];
    long long r;
    int nBread = 0,nSous = 0,nChease = 0;
    string inger;
    cin>>inger;
    for(int i = 0 ; i<3 ; i++){
        cin>>available[i];
    }
    for(int i = 0 ; i<3 ; i++){
        cin>>prices[i];
    }
    cin>>r;

    for(int i = 0 ;i<inger.length();i++){
        if(inger[i] == 'B'){
            nBread++;
        }
        else if(inger[i] == 'S'){
            nSous++;
        }
        else if(inger[i] == 'C'){
            nChease++;
        }
    }
    cout<<binarySearch(available,prices,nBread,nSous,nChease,r);
    return 0;
}
