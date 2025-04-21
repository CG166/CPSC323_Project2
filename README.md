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


# Contributors
* Cindy Garcia
* Tiffany Vy Buu
* Carrie Appelt

# Code Explanation and Design Choices

## Gloabl Variables
**Stack**  
This is the stack that we will be using to parse the input string, it is a stack of strings  
```stack<string> Stack;```  

**ppTable**  
```string ppTable[5][8] = {```  
```{"T E'", "", "", "", "", "T E'", "", ""},```  
```{"", "T + E'", "T - E'", "", "", "", "&", "&"},```  
```{"F T'", "", "", "", "", "F T'", "", ""},```  
```{"", "&", "&", "F * T'", "F / T'", "", "&", "&"},```  
```{"a", "", "", "", "", "( E )", "", ""},```  
```};```

## Functions
### Basic Functions

### Parse Function

## Main

# Dependencies and Version Used

### Dependencies

- **C++ Standard Library**: No external libraries required, uses standard libraries (`<iostream>`, `<string>`, `<stack>`, `<sstream>`, `<vector>`).

### Version Used

- **C++ Standard**: C++17 (default for GCC 13.3.0)
- **Compiler**: GCC (GNU Compiler Collection)
    - Version: `13.3.0` (Ubuntu 13.3.0-6ubuntu2~24.04)
- **Build System**: Command line `g++` used for compilation.

# Reflections

## Challenges
- **Pushing and printing the stack in the correct order:** There was a bit of trouble when we were figuring out how to push the values fetchched from the parsing table into the stack in the correct order. We ending up having the push the values fetched from the parsing table into a vector, and then iterate through the vector in reverse order and push the values into the stack that way. We also ended up using the same technique to print out the contents of the stack in the correct order.

## Bugs
- **Nothing getting pushed to Stack:** There was a bug in our parse function where the values fetched from the parsing table were not getting pushed into the stack. The reason ended up being becasue we had initalized the istringstream we were using the read the values into the stack to the fetched string variable while the fetch variable was still empty. We fixed the bug by not intializing the istringstream until after the fetched variable contains the values fetched from the parsing table.
