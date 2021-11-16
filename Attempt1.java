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
				}
