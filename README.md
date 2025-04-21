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

## Global Variables
**Stack**   
```stack<string> Stack;```  
This is the stack that we will be using to parse the input string, it is a stack of strings.

**ppTable**  
```cpp
string ppTable[5][8] = {
    {"T E'", "", "", "", "", "T E'", "", ""},
    {"", "T + E'", "T - E'", "", "", "", "&", "&"},
    {"F T'", "", "", "", "", "F T'", "", ""},
    {"", "&", "&", "F * T'", "F / T'", "", "&", "&"},
    {"a", "", "", "", "", "( E )", "", ""},
};
``` 
This 2d array of strings functions as the predictive parsing table in our program.

## Functions
### Basic Functions
**int rowNum**  
```cpp
int rowNum(string top) {
    int row;

    if(top == "E"){
        row = 0;
    }else if(top == "E'") {
        row = 1;
    }else if(top == "T") {
        row = 2;
    }else if(top == "T'") {
        row = 3;
    }else if(top == "F") {
        row = 4;
    }

    return row;
}
```
This function takes in the symbol that is at the top of the Stack as a paramenter, uses a for loop in order to map the symbol to it's corresponding row number, and then returns that row number as an integer.
**in columnNum**
```cpp
int colunmNum(char input) {
    int column;

    if(input == 'a'){
        column = 0;
    }else if(input == '+') {
        column = 1;
    }else if(input == '-') {
        column = 2;
    }else if(input == '*') {
        column = 3;
    }else if(input == '/') {
        column = 4;
    }else if(input == '(') {
        column = 5;
    }else if(input == ')') {
        column = 6;
    }else if(input == '$') {
        column = 7;
    }

    return column;
}
```
**bool isTerminal**
```cpp
bool isTerminal(string top) {
    string terminals[] = {"a", "+", "-", "*", "/", "(", ")", "$"};
    int ntLength = sizeof(terminals) / sizeof(terminals[0]);

    for(int i = 0; i < ntLength; i++) {
        if(top == terminals[i]) {
            return true;
        }
    }
    return false;
}
```
**void printStack**  
```cpp
void printStack() {
    vector<string> arrayStack;
    stack<string> stackCopy(Stack);
    while (!stackCopy.empty()) {
        arrayStack.push_back(stackCopy.top());
        stackCopy.pop();
    }

    cout << "[";
    for (int i = arrayStack.size() - 1; i >= 0; --i) {
        cout << arrayStack[i];
        if (i != 0) cout << ", ";
    }
    cout << "]\n";
}
```


### Parse Function
**void parse(char input, string top)**  
```cpp
void parse(char input, string top) {
    // Variables
    string fetched; // Whatever is retrieved from parsing table
    string symbol;
    int row = rowNum(top);
    int column = colunmNum(input);
    vector<string> arrayStack;

    // Pop the top of the stack
    Stack.pop();

    // Fetch result from parsing table
    fetched = ppTable[row][column];
    if (fetched.empty()) {
        cout << "Rule not found!\n";
        cout << "Output: String is not accepted/ Invalid.\n";
        exit(1);
    } else if(fetched == "&") {
        cout << "From table: epsilon\n";
        cout << "Stack popped!\n";
        // Print new stack
        cout << "New Stack: ";
        printStack();
        return;
    } else { 
        istringstream stream(fetched);
        cout << "From table: " << fetched << "\n";

        // Push new symbols to array
        while (stream >> symbol) {
            arrayStack.push_back(symbol);
        }

        // Push symbols of array into stack in reverse order
        for (int i = arrayStack.size() - 1; i >= 0; --i) {
            Stack.push(arrayStack[i]);
        }
        
        // Print new stack
        cout << "New Stack: ";
        printStack();
    }
}
```


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
