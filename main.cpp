#include "Attempt1.hpp"
#include <iostream>
#include <vector>
#include <fstream>

#include<bits/stdc++.h>

using namespace std;

void printRecommendations(vector<string> recs){	
	for(int i = 0; i < recs.size(); i++){
		string items = recs[i] + "                                   ";
		cout << items.substr(0, 40) << endl;
	}
}


int main(int argv, char** argc){
    vector<string> options;
    string fileName = "orderOptions.txt";

    ifstream input;
    input.open(fileName);
    string current;

    while(!input.eof()){
        getline(input, current);
        options.push_back(current);
    }

    string userInput;
    vector<string> recs;
    cout << "Enter an order:" << endl;
    getline(cin, userInput);

    cout << "Sorry, we don't have " + userInput + ", do you mean:" << endl;
    recs = Attempt1(options, userInput);

    printRecommendations(recs);
}