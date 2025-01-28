#include "Attempt1.hpp"
#include "Attempt2.hpp"

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std;

void printRecommendations(vector<string> recs){	
	for(int i = 0; i < recs.size(); i++){
		string items = recs[i] + "                                   ";
		cout << items.substr(0, 40) << "\n";
	}
}

void printTop10Recommendations(vector<string> recs){
    int n = recs.size();
    int numRuns = min(10, n);

  	for(int i = 0; i < numRuns; i++){
		string items = recs[i] + "                                   ";
		cout << items.substr(0, 40) << "\n";
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
    string fileName = "words.txt";

    vector<string> options;
    options = getMenu(fileName);

    string userInput;
    vector<string> recs;
    cout << "Enter an order:" << endl;
    getline(cin, userInput);

    //Attempt 1
    cout << "\n";
    cout << "Running Attempt 1" << endl;
    cout << "------------\n";
    auto start = std::chrono::high_resolution_clock::now();
    recs = Attempt1(options, userInput);
    auto stop = std::chrono::high_resolution_clock::now();

    cout << "Number of recommended words: " << recs.size() << endl;
    cout << "Top Word: " << recs[0] << endl;
    cout << "Top Words: \n"; 
    printTop10Recommendations(recs);

    cout << "Time to run: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " milliseconds" << endl;

    //DP Solution
    //Attempt 1
    cout << "\n";
    cout << "Running Attempt 2 (DP)" << endl;
    cout << "------------\n";
    start = std::chrono::high_resolution_clock::now();
    recs = Attempt2(options, userInput);
    stop = std::chrono::high_resolution_clock::now();

    cout << "Number of recommended words: " << recs.size() << endl;
    cout << "Top Word: " << recs[0] << endl;
    cout << "Top Words: \n"; 
    printTop10Recommendations(recs);

    cout << "Time to run: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " milliseconds" << endl;

    return 0;
}