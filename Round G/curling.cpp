#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

float distance(int x, int y){
    return sqrt(pow(x,2)+pow(y,2));
}
int main(){
    int t;
    cin>>t;
    if(t<1 || t>100){
        return 1;
    } 
    for(int s = 1; s<=t; s++){
        int Rs,Rh;
        cin>>Rs>>Rh;
        if(Rs>10000 || Rs < 1 || Rh > 10000 || Rh < 1){
            return 1;
        }
        int n,m;
        cin>>n;
        if(n>8 || n<0){
            return 1;
        }
        int red[n][2];
        for(int i=0; i<n; i++){
            cin>>red[i][0]>>red[i][1];
            if(abs(red[i][0])>20000 || abs(red[i][1])>20000){
                return 1;
            }
        }
        cin>>m;
        if(m>8 || m < 0){
            return 1;
        }
        int yellow[m][2];
        for(int i=0; i<m; i++){
            cin>>yellow[i][0]>>yellow[i][1];
            if(abs(yellow[i][0])>20000 || abs(yellow[i][1])>20000){
                return 1;
            }
        }
        vector<float> red_stones,yellow_stones;
        for(int i=0; i<n; i++){
            red_stones.push_back(distance(red[i][0],red[i][1]));
        }
        for(int i=0; i<m; i++){
            yellow_stones.push_back(distance(yellow[i][0],yellow[i][1]));
        }
        int red_score=0,yellow_score=0;

        for(int i=0; i<red_stones.size(); i++){
            int score = 1;
            if(red_stones[i]<=Rs+Rh){
                for(int j=0; j<yellow_stones.size(); j++){
                    if(yellow_stones[j]<red_stones[i]){
                        score = 0;
                        break;
                    } 
                }
                red_score = red_score + score;
            }
        }
        for(int i=0; i<yellow_stones.size(); i++){
            int score = 1;
            if(yellow_stones[i]<=(Rs+Rh)){
                for(int j=0; j<red_stones.size(); j++){
                    if(red_stones[j]<yellow_stones[i]){
                        score = 0;
                        break;
                    } 
                }
                yellow_score = yellow_score + score;
            }
        }
        cout<<"Case #"<<s<<": "<<red_score<<" "<<yellow_score<<"\n";

    }
    return 0;
}