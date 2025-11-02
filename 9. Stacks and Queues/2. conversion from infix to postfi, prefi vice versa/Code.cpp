

#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
    if( c == '+' || c == '-' ) return 1;
    if( c == '*' || c == '/' ) return 2;
    if( c == '^' ) return 3;

    return 0;
}

bool isOperand(char c) {
    if( c >= '0' && c <= '9' ) return true;
    if( c >= 'a' && c <= 'z' ) return true;
    if( c >= 'A' && c <= 'Z' ) return true;

    return false;
}

// Function to convert infix expression to postfix expression
// TC - O(n) + O(n) for stack operations
// SC - O(n) + O(n) for stack and output string
string convertInfixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    for( char ch : infix ) {
        if( isOperand(ch))
            postfix += ch;
        else if( ch == '(')
            st.push(ch);
        else if( ch == ')') {
            while( !st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // pop the '('
        }
        else{
            // pop all operators from stack with higher or equal priority
            while( !st.empty() && priority(st.top()) >= priority(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    // pop all remaining operators in the stack
    while( !st.empty() ) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}


// Function to convert infix expression to prefix expression
// TC - n + n + n + n : O(n) for stack operations
// SC - O(n) + O(n) for stack and output string
string convertInfixToPrefix(string infix) {
    // Reverse the infix expression
    reverse(infix.begin(), infix.end());
    
    // Replace '(' with ')' and vice versa
    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    
    // Convert to postfix
    
    stack<char> st;
    string postfix = "";
    for( char ch : infix ) {
        if( isOperand(ch))
            postfix += ch;
        else if( ch == '(')
            st.push(ch);
        else if( ch == ')') {
            while( !st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // pop the '('
        }
        else{
            // pop all operators from stack with higher  priority

            // cout<<st.top()<<endl;
            while( !st.empty() && priority(st.top()) > priority(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    // pop all remaining operators in the stack
    while( !st.empty() ) {
        postfix += st.top();
        st.pop();
    }

    
    // Reverse the postfix expression to get prefix
    reverse(postfix.begin(), postfix.end());
    
    return postfix;
}

// Function to convert postfix expression to infix expression
// TC - O(n) + O(n) for stack operations
// SC - O(n) + O(n) for stack and output string
string convertPostfixToInfix(string postfix) {

    stack<string> st;
    for( char ch: postfix){
        if( isOperand(ch)){
            st.push(string(1, ch));
        }
        else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string exp = "(" + op2 + ch + op1 + ")";
            st.push(exp);
        }
    }
    return st.top();
}

string convertPrefixToInfix(string prefix) {
    stack<string> st;
    int len = prefix.size();
    for(int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];
        if( isOperand(ch)) {
            st.push(string(1, ch));
        }
        else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string exp = "(" + op1 + ch + op2 + ")";
            st.push(exp);
        }
    }
    return st.top();
}

string convertPostfixToPrefix(string postfix) {
    // Convert postfix to infix first
    string prefix = "";
    stack<string> st;
    for(char ch : postfix) {
        if(isOperand(ch)) {
            st.push(string(1, ch));
        } else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string exp = ch + op2 + op1;
            st.push(exp);
        }
    }
    return st.top();
}

string convertPrefixToPostfix(string prefix) {

    string postfix = "";
    stack<string> st;
    int len = prefix.size();
    for(int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];
        if(isOperand(ch)) {
            st.push(string(1, ch));
        } else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string exp =  op1 + op2 + ch;
            st.push(exp);
        }
    }
    return st.top();
}


int main(){
    string infix;
    cin>>infix;
    cout<< "Convert from Infix to Postfix and Prefix" << endl;
    cout << "convert "<<infix<<" to Postfix : "<<convertInfixToPostfix(infix) << endl;
    cin>>infix;
    cout << "convert "<<infix<<" to Prefix : "<<convertInfixToPrefix(infix) << endl;

    string postfix;
    cin>>postfix;
    cout << "\nConvert from Postfix to Infix" << endl;
    cout << "convert "<<postfix<<" to Infix : "<<convertPostfixToInfix(postfix) << endl;

    string prefix;
    cin>>prefix;
    cout << "\nConvert from Prefix to Infix" << endl;
    cout << "convert "<<prefix<<" to Infix : "<<convertPrefixToInfix(prefix) << endl;
    
    cin>>postfix;
    cout << "\nConvert from Postfix to Prefix" << endl;
    cout << "convert "<<postfix<<" to Prefix : "<<convertPostfixToPrefix(postfix) << endl;

    cin>>prefix;
    cout << "\nConvert from Prefix to Postfix" << endl;
    cout << "convert "<<prefix<<" to postfix : "<<convertPrefixToPostfix(prefix) << endl;

    return 0;
}