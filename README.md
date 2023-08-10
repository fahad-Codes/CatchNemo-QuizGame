# CatchNemo-QuizGame

This is a game I developed as DSA course project in C++ but I've reprogrammed it in Python to make it more efficient and reduced 1800 lines of C++ code into 250 lines of Python code. I've implemented Queues using LinkedList to store the questions I extract from the text file. You can see the C++ code in the following oldsource.cpp file and the new Python code in the source.py file.

# Description

Node and LinkedList Classes:
These classes are used to create and manage a singly linked list, which serves as the underlying data structure for the Queue class.

# Queue Class:
The Queue class utilizes the linked list from the previous step.
It's designed to implement a basic queue data structure, where elements are added (enqueued) to the rear and removed (dequeued) from the front.
The class provides methods to enqueue, dequeue, check if the queue is empty, and display the contents of the queue.

# CatchNemo Class:
This class is responsible for managing the core logic of the "Catch The Nemo" game.
It uses instances of the Queue class to manage questions and answers.

The LoadGames method:

Loads questions and answers from a file based on the specified stage and level.
Enqueues the questions and answers into separate queues.
Presents questions to the player, gets their answers, and checks correctness.
If an answer is incorrect, the player has the option to spend a "Nemo" to skip the question.
Updates the player's Nemo count based on their progress.
Writes game progress to the "records.txt" file.
Recursively loads the next level if not completed.
CatchNemo manages the game's data flow, player interaction, and progress tracking.

# CatchNemoMenu Class:

This class extends CatchNemo and adds a menu-based user interface to the game.

loadPGame method:

Attempts to load saved game progress from "records.txt".
Determines the current stage, level, and Nemo count.
Calls the appropriate LoadGames method based on the saved stage and level.

mainMenu method:

Displays the main menu options to the player, allowing them to choose between difficulty levels, loading a previous game, or exiting.
Handles the user's choice and triggers the corresponding actions.
Creating an Instance and Running the Game:

An instance of CatchNemoMenu is created as catch_nemo_menu.

The mainMenu() method of this instance is called to start the game loop.
Within the game loop, the player can choose to start a new game at different difficulty levels, load a previous game, or exit the game.
The game flow continues until the player chooses to exit.

In summary, this program implements a text-based game where players can catch "Nemo" characters by answering questions correctly. The game is divided into different difficulty levels, each with stages containing questions. The player's progress is tracked through a menu-based interface, and they can continue playing from where they left off in previous sessions. The program demonstrates basic object-oriented programming concepts, data structure usage, file I/O, and user interaction through the console.

![image](https://github.com/fahad-Codes/CatchNemo-QuizGame/assets/111996171/5b9ae495-cc04-4d10-9ab1-0bfd4dc4da51)
