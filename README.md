# CPSC323_Project2


# Setup Instructions

**1. Download the file Prog1.cpp**
   - Download the file Prog1.cpp onto your computer and navigate into the directory where the file is located.
   
**2. Compile the program Prog1.cpp**
   - Compile the file using the command *g++ Prog1.cpp -o out*
     
**3. Run the Out file that has been created**
   - Run the Out file using the command *./out*

**4. Enter the Input string**
   - The program should prompt the user to input the string that will be parsed.
   - Type in the string that you wish to be parsed with no additional spaces before or after the string, then press enter.
   - The program should run and parse through the string, as well as output the process.
   - It should look like this -
     - cindy@cindy-Latitude-3310-2-in-1:~/Compilers/CPSC323_Project2$ ./out
      Input: a+a$
      Stack: [$, E]
      
      Top of Stack: E, Current Input: a
      From table: T E'
      New Stack: [$, E', T]
      
      Top of Stack: T, Current Input: a
      From table: F T'
      New Stack: [$, E', T', F]
      
      Top of Stack: F, Current Input: a
      From table: a
      New Stack: [$, E', T', a]


# Contributors
* Cindy Garcia
* Tiffany Vy Buu
* Carrie Appelt

# Code Explanation and Design Choices

# Dependencies and Version Used

# Reflections

