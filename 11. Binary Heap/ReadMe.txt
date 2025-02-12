


    struct CustomComparator{
        bool operator()(vector<int> a,vector<int> b){
            return a[1]>b[1];
        }
    };
        priority_queue< vector<int>, vector<vector<int>>,
                        CustomComparator > qtraverse;


// for class objects
User(){}
User(int id){ userId = id}

user = User(userId); for user 
user = new User(userId); for user*

For Priority Queue
Time Complexity:
MinHeapify = log(N)
decreaseKey = log(N)
insertKey = log(N)
deleteKey = log(N) + log(N)
extractMin = log(N)

The `map` insertions have an average time complexity of **O(log m)** where `m` is the number of distinct elements.
For each element, we perform a lookup in the `map`, which is an `O(log n)` operation.

