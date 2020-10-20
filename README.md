# Rubiks-Cube
This is a 2D functioning 3x3 Rubiks Cube that I am developing from scratch.

All code regarding the cube and the game as of right now are in the 'main.cpp' file. All other files are either miscellaneous or blank.

The goal of this project is to further my skills as a software developer, particularily in C++.

As of right now, I have developed a fully functioning Rubiks Cube which responds to commands from the user, moving the faces according how a real 3x3 Rubiks Cube would work.
The next developments to this program will be to develop a simple shuffle function as well as win condition in which the program recognizes when the cube has been solved.

Ultimately, the next step after this is to develop an algorithm which can solve the cube given any possible shuffle of the cube whether the cube is 1 turn from completion or 100. I haven't done any research into what this algorithm may look like, however my current approach includes a function which checks how far the cube is already solved. For example, if already has one side properly solved, then the algorithm should approach the cube as if it's completely shuffled, it should carry on from the progress that's already been made. From here, the algorithm will follow a simple set of moves to solve the cube once it finds that the right conditions have been found for those set moves to bring the cube into the correct next state. If it fails to bring it into the correct next state, it starts again from its last successful state. This means that the algorithm will not be looking for the most optimal solution that has the least amount of moves since there are over 43 quintillion possible configuration and finding optimal solutions requires super computers and brain power that it is out of what I can do alone.
Once the algorithm has solved the cube, the program will present each move and step it took to solve the cube so that the user can follow along. Because of this, I plan to also add a function which will allow the user to detail their exact shuffled cube configuration in order to allow the program to solve it for them and show them each step.
