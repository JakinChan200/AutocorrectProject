//2019
//Triple for loop checking for every letter in string a, try every 

#ifndef ATTEMPT_1
#define ATTEMPT_1

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minDistance1(string word1, string word2) {
	int longestStreak = 0;
	int streak = 0;
	for(int j = 0; j < word1.length(); j++){
		for(int k = 0; k < word2.length(); k++){
			if(((k < word2.length()) && (j < word1.length())) && ((tolower(word2[k]) == tolower(word1[j]) || ((word2[k] == ' ') && (word1[j] == ' '))))){
				while((k < word2.length() && j < word1.length()) && ((tolower(word2[k]) == tolower(word1[j]) || ((word2[k] == ' ') && (word1[j] == ' '))))){
					streak++;
					k++;
					j++;
				}
				if(streak > longestStreak){
					longestStreak = streak;
				}
			}else{
				streak = 0;
			}
		}
	}
	return longestStreak;
}

vector<string> Attempt1(vector<string> &options, string userInput){
	// vector<string> possibleInputs;
	int minPercentage = (int) (userInput.length() * 0.75);
	priority_queue<pair<int, string>> minHeap;
	// int longestStreak = 0;
	// int streak = 0;

	for(int i = 0; i < options.size(); i++){
		minHeap.push(pair<int, string>(minDistance1(options[i], userInput), options[i]));
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

#endif // ATTEMPT_1

/*vector<string> Attempt1(vector<string> &options, string userInput){
	vector<string> possibleInputs;
	int minPercentage = (int) (userInput.length() * 0.75);
	int longestStreak = 0;
	int streak = 0;

	for(int i = 0; i < options.size(); i++){
		for(int j = 0; j < options[i].length(); j++){
			for(int k = 0; k < userInput.length(); k++){
				if(((k < userInput.length()) && (j < options[i].length())) && ((tolower(userInput[k]) == tolower(options[i][j]) || ((userInput[k] == ' ') && (options[i][j] == ' '))))){
					while((k < userInput.length() && j < options[i].length()) && ((tolower(userInput[k]) == tolower(options[i][j]) || ((userInput[k] == ' ') && (options[i][j] == ' '))))){
						streak++;
						k++;
						j++;
					}
					if(streak > longestStreak){
						longestStreak = streak;
					}
				}else{
					streak = 0;
				}
			}
		}
		if(longestStreak >= minPercentage){
			possibleInputs.push_back(options[i]);
		}
		longestStreak = 0;
	}

	return possibleInputs;
}*/

 /*
        int minPercentage = (int) (userInput.length() * 0.75);
				int longestStreak = 0;
				int streak = 0;

				for(int i = 0; i < options.length; i++){
					for(int j = 0; j < options[i].length(); j++){
						for(int k = 0; k < userInput.length(); k++){
							if(((k < userInput.length()) && (j < options[i].length())) && ((userInput.toLowerCase().charAt(k) == options[i].toLowerCase().charAt(j) || ((userInput.charAt(k) == ' ') && (options[i].charAt(j) == ' '))))){
								while((k < userInput.length() && j < options[i].length()) && ((userInput.toLowerCase().charAt(k) == options[i].toLowerCase().charAt(j) || ((userInput.charAt(k) == ' ') && (options[i].charAt(j) == ' '))))){
									streak++;
									k++;
									j++;
								}
								if(streak > longestStreak){
									longestStreak = streak;
								}
							}else{
								streak = 0;
							}
						}
					}
					if(longestStreak >= minPercentage){
						possibleInputs.add(options[i]);
					}
					longestStreak = 0;
				}
				System.out.println("Sorry, we don't have " + userInput + ", do you mean:");
				
				for(int i = 0; i < possibleInputs.size(); i++){
					String items = possibleInputs.get(i) + "                                   ";
					System.out.println(items.substring(0, 40) + getPrice(possibleInputs.get(i)));
				}*/