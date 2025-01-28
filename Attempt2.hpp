//2025
//Edit distance

#ifndef ATTEMPT_2
#define ATTEMPT_2

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <omp.h>

using namespace std;

void print2DVector(vector<vector<int>> nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            cout << " " << nums[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int minDistance(string word1, string word2) {
    int m=word1.size();
    int n=word2.size();
    vector<int>curr(n+1,0);
    vector<int>prev(n+1,0);

    for(int i=0;i<=n;i++)
        prev[i]=i;
    
    for(int i=1;i<=m;i++){
        curr[0]=i;
        for(int j=1;j<=n;j++){
            if(word1[i-1]==word2[j-1])
                curr[j]=prev[j-1];
            else
                curr[j]=1+min(prev[j], min(prev[j-1], curr[j-1]));
        }
        prev=curr;
    }
    return prev[n];
}

vector<string> Attempt2(vector<string> &options, string userInput){
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> minHeap;

    #pragma omp parallel for
    for(string word : options){
        minHeap.push(pair<int, string>(minDistance(word, userInput), word));
    }

    if(minHeap.top().second == userInput){
        return {userInput};
    }

    //Only return the top 10 results
    vector<string> closestMatch;
    for(int i = 0; i < 10; i++){
        closestMatch.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return closestMatch;
} 

// int main(int argc, char** argv){
//     string word1 = "horse";
//     string word2 = "ros";


//     cout << minDistance(word1, word2);
//     return 0;
// }

#endif