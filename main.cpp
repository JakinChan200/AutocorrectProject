#include "Attempt1.hpp"

#include<bits/stdc++.h>

using namespace std;

void printRecommendations(vector<string> recs){	
	for(int i = 0; i < recs.size(); i++){
		string items = recs[i] + "                                   ";
		cout << items.substr(0, 40) << endl;
	}
}

vector<string> getMenu(string fileName){
    vector<string> options;

    ifstream input;
    input.open(fileName);
    string current;

    while(!input.eof()){
        getline(input, current);
        options.push_back(current);
    }

    return options;
}


int main(int argv, char** argc){
    string fileName = "words_alpha.txt";

    vector<string> options;
    options = getMenu(fileName);

    string userInput;
    vector<string> recs;
    cout << "Enter an order:" << endl;
    getline(cin, userInput);

    //Attempt 1
    cout << "Running Attempt 1" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    recs = Attempt1(options, userInput);
    auto stop = std::chrono::high_resolution_clock::now();

    cout << "Number of recommended words: " << recs.size() << endl;
    // cout << "Sorry, we don't have " + userInput + ", do you mean:" << endl;
    // printRecommendations(recs);

    cout << "Time to run: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " milliseconds" << endl;

    //DP Solution
    

    return 0;
}