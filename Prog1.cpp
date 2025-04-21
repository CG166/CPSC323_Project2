#include <iostream>
#include <string>
#include <stack>
#include <string>
#include <sstream>


using namespace std;
//Global Variables
stack<string> Stack;
string ppTable[5][8] = {
    {"T E'", "", "", "", "", "T E'", "", ""},
    {"", "T + E'", "T - E'", "", "", "", "&", "&"},
    {"F T'", "", "", "", "", "F T'", "", ""},
    {"", "&", "&", "F * T'", "F / T'", "", "&", "&"},
    {"a", "", "", "", "", "( E )", "", ""},
};


//Functions
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

void printStack() {
    stack<string> stackCopy(Stack);
    while (!stackCopy.empty()) {
        cout << stackCopy.top() << "\n";
        stackCopy.pop();
    }
}

void parse(char input, string top) {
    //Variables
    string fetched; //Whatever is retrieved from parsing table
    string symbol;
    int row = rowNum(top);
    int column = colunmNum(input);

    //Pop the top of the stack
    Stack.pop();

    //Debug
    cout << "Row: " << row << "\n";
    cout << "Colunm: " << column << "\n";

    //Fetch result from parsing table
    fetched = ppTable[row][column];
    if (fetched.empty()) {
        cout << "Output: String is not accepted/ In valid.";
    } else if(fetched == "&") {
        return;
    }else { 
        istringstream stream(fetched);
        cout << "From table: " << fetched << "\n";
    
        //Push new symbols to stack
        while (stream >> symbol) {
            Stack.push(symbol);
        }
        
        //Print new stack
        cout << "New Stack: ";
        printStack();
    }

}

int main(void) {
    //Variables
    string userInput;
    char input;
    string top;

    //Get User Input
    cout << "Input: ";
    getline(cin, userInput);

    //Setting initial stack
    Stack.push("$");
    Stack.push("T");

    input = userInput[0];
    top = Stack.top();


    //Parsing until $
    while(input != '$' && top != "$") {
        input = userInput[0];
        top = Stack.top();

        //Printing out top of stack and current input symbol
        cout << "Stack: " << top << "\n";
        cout << "Input: " << input << "\n";

        if(isTerminal(top) == true){ //Check if stack top is a terminal
            if(string(1,input) == top) { //Check if stack top and current input match
                //Pop Stack
                Stack.pop();
                //Move input forward
                userInput.erase(0,1);
            } else { //If stack top and current input don't match, reject the string
                cout << "Output: String is not accepted/ In valid."; //Print out rejection message
                break; //Break out of while loop
            }
        } else { //If stack top is a non-terminal
            parse(input, top);
        }

        cout << "\n";


    }
    

    return 0;
}
