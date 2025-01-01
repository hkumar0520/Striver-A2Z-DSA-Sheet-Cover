

sort vector using  manual comparator
https://www.geeksforgeeks.org/how-to-sort-vector-using-custom-comparator-in-cpp/



// empty vector 
vector<int>{}

// finding index of node (vector)
int index = find(connections.begin(),connections.end(), node) - connections.begin();

// deleting of element at position index
connections.erase(connections.begin()+index);

// char insert at ith posistion
ans = ans.substr(0,i) + chinsert + ans.substr(i);

// typecasting
char chinsert = (char)('a'+ind);

//
 vector<long> dist(n, LONG_MAX);


// CustomComparator
    struct CustomComparator{
        bool operator()(vector<int> a,vector<int> b){
            return a[1]>b[1];
        }
    };
        priority_queue< vector<int>, vector<vector<int>>,
                        CustomComparator > qtraverse;


instead of INT_MAX use LONG_MAX

