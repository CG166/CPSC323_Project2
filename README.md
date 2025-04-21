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
**int rowNum(string top)**  
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
This function takes in the symbol that is at the top of the Stack as a paramenter, uses a for loop in order to map the symbol to it's corresponding row number in the predictive parsing table, and then returns that row number as an integer.  

**int columnNum(char input)**
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
This function takes in the symbol that is at the current input symbol as a paramenter, uses a for loop in order to map the symbol to it's corresponding colunm number in the predictive parsing table, and then returns that colunm number as an integer.  

**bool isTerminal(string top)**
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
This function takes in the symbol that is at the top of the Stack as a paramenter, uses a for loop to check it against an array containing every terminal symbol, and returns as true if there is a match (because a match confirms that the symbol at the top of the Stack is a terminal).  

**void printStack()**  
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
This function prints out the contents of the global stack in the format ["E","E","E"]. It does this by creating a copy stack of the global stack and a vector of strings, iteratively pushing the top of the copy stack into the vector and popping the stack until the stack is empty, then iterating through the vector in reverse and printing the contents as we go in order to print out the stack contents in the correct order.  

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
This function is to be used in the situation that the symbol at the top of the stack is a non-terminal. This function takes in the symbol that is at the current input symbol and the symbol that is at the top of the Stack as parameters. It uses **rowNum(string top)** and **colunmNum(char input)** to fectch the corresponding rule(aka string) from the predictive parsing table(2d array) and put it into the fetched variable. If the fetched variable is empty, meaning that there is no rule, then the function prints out that the rule was not found as well as "Output: String is not accepted/ Invalid" and terminates the entire program. If the fetched variable is not empty and contains an epsilon(represted by the & symbol in this program), then the user is alerted that the stack has been popped and the new stack is printed out using **printStack()** after which the function ends/returns. If the fetched variable is not empty and does not contains an epsilon, then the inividual symbols in the rule are extracted from the fetched variable using istringstream and pushed into a vector. The vector is then iterated through in reverse order and the values are pushed into the stack in that order. The new stack is then printed out using **printStack()** after which the function ends/returns.

## Main  
```cpp
int main(void) {
    // Variables
    string userInput;
    char input;
    string top;

    // Get User Input
    cout << "Input: ";
    getline(cin, userInput);

    // Setting initial stack
    Stack.push("$");
    Stack.push("E");

    input = userInput[0];
    top = Stack.top();

    // Print out starting stack
    cout << "Stack: ";
    printStack();
    cout << "\n";
}
```
In our main function, the user is prompted to enter the input string they want to be parsed and that string is saved in the *userInput* variable. The empty global stack *Stack* gets the starting symbols $ and E pushed into it. The curent top of the stack and the current input symbol (the first character of the input string userInput) are extracted and put into the *top* and *input* variables respectfully. The current stack is printed out using **printStack()**.

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
