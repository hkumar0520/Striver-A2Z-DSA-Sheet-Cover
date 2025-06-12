

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 0; i<n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

// traverse from reverse
vector<int> nextGreaterElementReverse(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = n-1; i >= 0; i--){
        // also st.top() <= arr[i]
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = arr[st.top()];
        }
        // also st.push(arr[i])
        st.push(i);
    }
    return ans;
}


vector<int> nextGreaterElementCircular(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 0; i < 2 * n; i++){
        while(!st.empty() && arr[st.top()] < arr[i % n]){
            ans[st.top()] = arr[i % n];
            st.pop();
        }
        if(i < n) st.push(i);
    }
    return ans;
}


vector<int> nextGreaterElementCircularReverse(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 2*n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i % n]){
            st.pop();
        }
        if(i < n) {
            if(!st.empty()){
                ans[i] = arr[st.top()];
            }
        }
        st.push(i % n);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = arr[st.top()];
        }
        st.push(i);
    }
    return ans;
}   

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> ans = nextGreaterElement(arr);
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    ans = nextGreaterElementReverse(arr);
    cout << endl<<"Next Greater Element Reverse: "<<endl;
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    ans = nextGreaterElementCircular(arr);
    cout << endl<<"Next Greater Element Circular: ";
    cout << endl;
    for( int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    ans = nextGreaterElementCircularReverse(arr);
    cout << endl<<"Next Greater Element Circular Reverse: ";
    cout << endl;
    for( int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    vector<int> sarr = {4, 5, 2, 10, 8};
    ans = prevSmallerElement(sarr);
    cout << endl<<"Previous Smaller Element: "<<endl;
    for( int i = 0; i < sarr.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}