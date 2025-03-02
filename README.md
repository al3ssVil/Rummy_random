# Card Game Application

This is a C++ application that simulates a card game with 15 cards, each card having a number and a color. The game involves sorting the cards, finding sequences based on numbers or colors, and identifying the longest possible combination of cards. The program also allows drawing a new card and checking if the game state is ordered correctly.

## Features

- **Card generation**: 14 cards are generated with random numbers and colors (red, blue, black, yellow).
- **Sorting**: The cards are sorted using the QuickSort algorithm based on the number.
- **Card sequences**: The application can find and display sequences of cards with the same color or consecutive numbers.
- **Card drawing**: A new card (the 15th card) is drawn randomly and displayed.
- **Longest sequence**: The application identifies and displays the longest possible sequence of cards, either based on color or consecutive numbers.
- **Verification**: The app checks if the cards are ordered correctly after sorting.

# How it Works
The main logic of the program consists of the following functions:

- ReadPieces: This function generates an array of 14 random cards with random numbers and colors.

- Display: Displays all the cards in the array.

- QuickSort: Sorts the cards array in ascending order based on the card number using the QuickSort algorithm.

- CheckOrdered: Verifies whether the array of cards is ordered correctly after sorting.

- ColorSequence: Finds and prints all the sequences of cards with the same color.

- NumberSequence: Finds and prints all the sequences of cards with consecutive numbers.

- Draw: Draws a 15th random card and prints it.

- LongestFormation: Identifies and prints the longest sequence of cards, either based on color or consecutive numbers.

# Example Output
![image](https://github.com/user-attachments/assets/f9a13ab8-1e5f-497d-a837-624fa82c314d)

