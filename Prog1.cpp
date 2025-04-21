#include <iostream>
#include <string>
#include <stack>
#include <string>
#include <sstream>
#include <vector>


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

void parse(char input, string top) {
    //Variables
    string fetched; //Whatever is retrieved from parsing table
    string symbol;
    int row = rowNum(top);
    int column = colunmNum(input);
    vector<string> arrayStack;

    //Pop the top of the stack
    Stack.pop();

    //Fetch result from parsing table
    fetched = ppTable[row][column];
    if (fetched.empty()) {
        cout << "Rule not found!\n";
        cout << "Output: String is not accepted/ Invalid.\n";
        exit(1);
    } else if(fetched == "&") {
        cout << "From table: epsilon\n";
        cout << "Stack popped!\n";
         //Print new stack
        cout << "New Stack: ";
        printStack();
        return;
    }else { 
        istringstream stream(fetched);
        cout << "From table: " << fetched << "\n";
    
        //Push new symbols to array
        while (stream >> symbol) {
            arrayStack.push_back(symbol);
        }

        //Push symbols of array into stack in reverse order
        for (int i = arrayStack.size() - 1; i >= 0; --i) {
            Stack.push(arrayStack[i]);
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
    Stack.push("E");

    input = userInput[0];
    top = Stack.top();

    //print out starting stack
    cout << "Stack: ";
    printStack();
    cout << "\n";


    //Parsing until $
    while(input != '$' && top != "$") {
        input = userInput[0];
        top = Stack.top();

        //Printing out top of stack and current input symbol
        cout << "Top of Stack: " << top << ", ";
        cout << "Current Input: " << input << "\n";

        if(isTerminal(top) == true){ //Check if stack top is a terminal
            if(string(1,input) == top) { //Check if stack top and current input match
                //Pop Stack
                Stack.pop();
                //Move input forward
                userInput.erase(0,1);
                //Print out
                cout << "Top of Stack and Current Input Symbol match!\n";
                cout << "Current input symbol moved forward.\n";
                //Print new stack
                cout << "Stack popped!\n";
                cout << "New Stack: ";
                printStack();

            } else { //If stack top and current input don't match, reject the string
                cout << "Output: String is not accepted/ In valid.\n"; //Print out rejection message
                exit(1);
            }
        } else { //If stack top is a non-terminal
            parse(input, top);
        }
        //Space
        cout << "\n";
    }
    cout << "Output: String is accepted/ valid.\n";
    
    return 0;
}
