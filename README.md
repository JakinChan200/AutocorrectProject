# AutocorrectProject

Overall, the goal of the project is to streamline the process of outputting a close match String based on the input.

This idea as a whole formed when I worked on the project found [here](https://github.com/PostAPProject/BobaFridaysForm). 
The team project in short involve the program compiling and streamlining the a boba ordering process. In this project,
I worked on a feature where the program prints a list of closely matching menu items when the user enters 
something not on the menu.

## Attempt 1

Attempt 1 is just a copy of the feature that I implemented in 2019. I used a weight system to decide the closest matches
and printed those with the highest weights. The weight system consists of counting matching letters.

First, I wanted to print the menu items with the most matching letters with the user's input.
 - But entering the whole alphabet prints the entire menu

Then I wanted to print the menu items that have the most matching letters in the same spots.
 - But a missing letter in the beginning of the user input makes the slots an off by one error

Lastly, I decided to just print the menu items where at least 50% of the word is a common substring.

Pros 😄
 - If the program outputs something, the correct answer is among them
 - Typing the entire alphabet does not print the entire menu

Cons ☹️
 - Time complexity is horrendous
 - Gave a 50% common substring threshold in order to be considered
   - Intended to limit the amount of common menu items like "Milk Tea" popping up as many menu items share the same words
   - Only counters one or two typos or errors, and only if the error is not exactly in the center of the input
   - Sometimes no suggested menu items are printed

