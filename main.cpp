#include <iostream>
#include "myStack.h"
#include "myQueue.h"
using namespace std;

bool isNumber(char token){
    if(token <=57 && token >= 48){
        return true;
    }else{
        return false;
    }
}

int power(char c){
    if (c == '+' || c == '-'){
        return 1;
    } else if (c == '*' || c == '/'){
        return 2;
    }else if (c == 'N' || c == 'X' || c == 'M' || c == 'F'){
        return 3;
    }else{
        return 0;
    }
}

bool isOperator(char c){
    return (c == 40 || c == 41 || c == 42 || c == 43 || c == 45 || c == 47);
}

char isFunction(char c){
    char d = 0;
    if(c == 'I'){
        cin >> d;
        return 'F';
    } else if(c == 'N'){
        return 'N';
    }else{
        cin >> d;
        if (d == 'I'){
            cin >> d;
            return 'M';
        }else{
            cin >> d;
            return 'X';
        }
    }
}

bool isLetter(char c){
    return (c == 78 || c == 73 || c == 70 || c == 65 || c == 77 || c == 88);
}

void postfixConversion (myStack& Stack, myQueue& Queue){
    char d = 0;
    char c = 0;
    int priority = 20;
    int functionLength = 1;
    while (c != 46) { // check if period
        cin >> c;
        if(isNumber(c)){
            while (isNumber(c)){
                Queue.enqueue(c);
                cout << Queue.back(); //saving numbers into a queue
                cin >> c;
            }
            Queue.enqueue(' ');
            cout << " ";
        }
        if(isOperator(c)){
            if(c == '(') {
                Stack.push(c);
            } else if (c == ')') {
                while (Stack.top() != '(') {
                    if(Stack.top() == 'F'){
                        Queue.enqueue(Stack.top());
                        cout << "IF" << " ";
                    }else if(Stack.top() == ','){
                        functionLength++;
                    }else{
                        Queue.enqueue(Stack.top());
                        cout << Stack.top() << " ";
                    }
                    Stack.pop();
                }
                Stack.pop();
                if(Stack.top() == 'X'){
                    Queue.enqueue(Stack.top());
                    Queue.enqueue(char(functionLength));
                    cout << "MAX" << functionLength << " ";
                    Stack.pop();
                }else if(Stack.top() == 'M'){
                    Queue.enqueue(Stack.top());
                    Queue.enqueue(char(functionLength));
                    cout << "MIN" << functionLength << " ";
                    Stack.pop();
                }
                else if(Stack.top() == 'F'){
                    Queue.enqueue(Stack.top());
                    cout << "IF" << " ";
                    Stack.pop();
                }else if(Stack.top() == 'N'){
                    Queue.enqueue(Stack.top());
                    cout << Stack.top() << " ";
                    Stack.pop();
                }
                functionLength = 1;
            }else{
                priority = power(c);
                while (priority <= power(Stack.top())) {
                    Queue.enqueue(Stack.top());
                    if(Stack.top() == 'F'){
                        cout << "IF" << " ";
                    }else{
                        cout << Stack.top() << " ";
                    }
                    Stack.pop();
                }
                Stack.push(c);
                functionLength = 1;
            }
        } else if(c == ' '){
            continue;
        }else if ( c == ','){
            while(Stack.top() == '/' || Stack.top() == '*' || Stack.top() == '-' || Stack.top() == '+' || Stack.top() == 'N' ){//|| Stack.top() == 'F'){
                Queue.enqueue(Stack.top());
                if(Stack.top() == 'F'){
                    cout << "IF" << " ";
                }else{
                    cout << Stack.top() << " ";
                }
                Stack.pop();
            }
            Stack.push(c);
        }
        else if(isLetter(c)){
            d = isFunction(c);
            Stack.push((d));
        }
    }
    while(!Stack.empty()){
        Queue.enqueue(Stack.top());
        if(Stack.top() != 'F'){
            cout << Stack.top() << " ";
        }else{
            cout << "IF" << " ";
        }
        Stack.pop();
    }
}

void calculate(myStack& ONP, myStack& Stack, myQueue& Queue){
    int ERROR = 0;
    int functionLength = 1;
    int number = 0;
    while(!Queue.empty()) {
        int a = 0, b = 0;
        switch (char(Queue.front())) {
            case '+':
                Queue.pop();
                cout << endl << '+' << ' ';
                ONP.print();
                a = (ONP.intTop());
                ONP.pop();
                b = (ONP.intTop());
                ONP.pop();
                ONP.intPush(b + a);
                break;
            case '-':
                Queue.pop();
                cout << endl << '-' << ' ';
                ONP.print();
                a = (ONP.intTop());
                ONP.pop();
                b = (ONP.intTop());
                ONP.pop();
                ONP.intPush(b - a);
                break;
            case '*':
                Queue.pop();
                cout  << endl << '*' << ' ';
                ONP.print();
                a = (ONP.intTop());
                ONP.pop();
                b = (ONP.intTop());
                ONP.pop();
                ONP.intPush(b * a);
                break;
            case '/':
                Queue.pop();
                cout << endl << '/' << ' ';
                a = (ONP.intTop());
                ONP.print();
                ONP.pop();
                b = (ONP.intTop());
                ONP.pop();
                if(a == 0){
                    cout << "ERROR" << endl;
                    while(!Stack.empty()){
                        Stack.pop();
                    }while(!ONP.empty()){
                        ONP.pop();
                    }while(!Queue.empty()){
                        Queue.pop();
                    }
                    ERROR = 1;
                    break;
                }else{
                    ONP.intPush(b / a);
                }
                break;
            case 'N':
                Queue.pop();
                cout << endl << 'N' << ' ';
                ONP.print();
                a = (ONP.intTop());
                ONP.pop();
                ONP.intPush(-a);
                break;
            case 'F':
                Queue.pop();
                cout << endl << "IF" << ' ';
                ONP.print();
                a = (ONP.intTop());
                ONP.pop();
                b = (ONP.intTop());
                ONP.pop();
                if(ONP.intTop() > 0){
                    ONP.pop();
                    ONP.intPush(b);
                }else{
                    ONP.pop();
                    ONP.intPush(a);
                }
                break;
            case 'X':
                Queue.pop();
                cout << endl << "MAX" << int(Queue.front()) << ' ';
                functionLength = int(Queue.front());
                Queue.pop();
                ONP.print();
                a = (ONP.intTop());
                ONP.pop();
                for (int j = 0; j < functionLength - 1; ++j) {
                    b = (ONP.intTop());
                    ONP.pop();
                    if(a<b){
                        a = b;
                    }
                }
                ONP.intPush(a);
                functionLength = 1;
                break;
            case 'M':
                Queue.pop();
                cout << endl << "MIN" << int(Queue.front()) << ' ';
                functionLength = int(Queue.front());
                Queue.pop();
                ONP.print();
                a = (ONP.intTop());
                ONP.pop();
                for (int j = 0; j < functionLength - 1; ++j) {
                    b = (ONP.intTop());
                    ONP.pop();
                    if(a>b){
                        a = b;
                    }
                }
                ONP.intPush(a);
                functionLength = 1;
                break;
            case ' ':
                Queue.pop();
                break;
            case ',':
                Queue.pop();
                break;
            default:
                while (isNumber(Queue.front())) {
                    number = number * 10 + (Queue.front() - 48); //making multiple digit numbers
                    Queue.pop();
                }
                ONP.intPush(number);
                number = 0;
                break;
        }
    }
    if(ERROR != 1){
        cout << int(ONP.intTop()) << endl << endl;
    } else{
        cout << endl;
    }
    ERROR = 0;
}

int main() {
    int n = 0;
    myStack Stack{};
    myStack ONP{};
    myQueue Queue{};
    cin >> n;
    for (int i = 0; i < n; ++i) {//number of different equation that will be calculated
        postfixConversion(Stack, Queue);
        calculate(ONP, Stack, Queue);
        while(!Stack.empty()){
            Stack.pop();
        }while(!ONP.empty()){
            ONP.pop();
        }while(!Queue.empty()){
            Queue.pop();
        }
    }
    return 0;
}

