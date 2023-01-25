AttackOfTheRooks

CSC24400 Project #1

Author: Joshua M. Blankley

I split my time developing this project between Visual Studio, Fedora, and WSL 2. 

My Process:
Read and understand the problem
Write out psuedocode to solve the problem
Construct functions that solve each step in my psuedocode to be called in main
Call the functions in main to complete the solution



DEV LOG
--------------------------------------------------------------------------------------------------
Day 1 (1/19/2023)
-----------------
Pseudocode written out. Ended up making some tweaks because I realized I did not need a while loop 
to get the first two values in the text file.

Struggled greatly trying to get either VirtualBox working or WSL w/ Ubuntu but to no avail. Ended 
up falling back on Visual Studio for now. Hopefully I can get that sorted soon.

So far I have the file being read in successfully and stored the first two values in variables to 
be used in the 2d array.

I was able to get the array built with empty char's based on the dimensions pulled from the text
file.

Stopping Point: Tried figuring out how to put char's read from reader into array.


Day 2 (1/21/2023)
-----------------
Stuck on trying to get the text from file into the array. I am getting the right chars printed out
in the console, but they are not in the grid I have created. Giving up for now, gonna get help in 
Monday's office hours.

Stopping Point: Same as before.


Day 3 (1/23/2023)
-----------------
Finally figured out how to read the file and store it in the 2d array. Had to go to office hours.
Added another function called gridRead() that takes in our file and stores it into our 2d array.
My issue was that I was trying to combine this function with a seperate function printGrid.
Another big issue I was running into, was I was treating "reader" like a type and not a variable.
"reader" has a type of ifstream. This info was extremely useful.

Stopping Point: Need to sort array to see if any "R's" intersect on the grid, and there are no "#'s"
between. Also, consider moving our code that is just reading in the text file into it's own function.
