#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    if(t<1 || t>100){
        return 1;
    }
    for(int l=1; l<=t; l++){
        int m,n,p;
        int steps = 0;
        cin>>m>>n>>p;
        if(n<1 || n>31 || m<2 || m>1000){
            return 1;
        }
        if(p<1 || p>m){
            return 1;
        }
        int arr[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
                if(arr[i][j]>60000){
                    return 1;
                }
            }
        }
        for(int i=0; i<n; i++){
            int maxCol = 0;
            for(int j=0; j<m; j++){
                if(arr[j][i] > maxCol){
                    maxCol = arr[j][i];
                }
            }
            steps = steps + (maxCol - arr[p-1][i]);
        }
        cout<<"Case #"<<l<<": "<<steps<<"\n";
    }
    return 0;
}