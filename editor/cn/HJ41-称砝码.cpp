#include<iostream>
//#include<bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>

#define emplace_back __emplace_back

using namespace std;

int main(){
    int N;
    cin>>N;

    vector<int> weight;
    vector<int> mount;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        weight.emplace_back(temp);
    }
    for(int i=0;i<N;i++){
        cin>>temp;
        mount.emplace_back(temp);
    }
    int sum=0;
    for(int i=0;i<N;i++){
        sum=sum+weight[i]*mount[i];
    }
    vector<int> Weight;
    for(int i=0;i<N;i++){
        for(int j=0;j<mount[i];j++){
            Weight.emplace_back(weight[i]);
        }
    }
    int len=Weight.size();
    unordered_set<int> ok;
    vector<vector<bool> > dp(len+1,vector<bool>(sum+1, false));
    for(int i=0;i<len+1;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<len+1;i++){
        for(int j=1;j<sum+1;j++){
            if(Weight[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]||dp[i-1][j-Weight[i-1]];
                printf("%d-%-2d:",i,j);
                for(int k=0;k<=sum;k++){
                    cout<<dp[i][k]<<",";
                }
                cout<<">"<<dp[i][j]<<endl;
            }
            if(dp[i][j]){
                 ok.insert(j);
            }
        }
        cout<<i<<"   :";
        for(int k=0;k<=sum;k++){
            cout<<dp[i][k]<<",";
        }
        cout<<endl;
    }
    for (auto it = ok.begin(); it != ok.end(); it++) {
        cout << *it<<",";
    }
    cout<<endl;
    cout<<ok.size()+1<<endl;

    return 0;
}
