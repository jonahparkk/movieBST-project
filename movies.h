
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;


class movieBST {
 private:

    struct Node {
	const string movieName;
    const double rating;
     int depth;
    

	Node *left, *right, * parent;
	// useful constructor:
    Node(string v = "", double w= 0.0, int x=0) : movieName(v), rating(w), depth(x),left(0), right(0), parent(0) { }
    bool operator== (const Node& temp);
    };

    // just one instance variable (pointer to root node):
    Node *root;

    
    
    void clear(Node *n); // for destructor
    bool insertMovie(string movieName, double rating, int depth, Node *n); // note overloading names for simplicity
    void printPreOrder(Node *n) const;
    
    vector<Node> moviePairs;
    int nodesVisited;
    int nodesInserted;

 public:
    movieBST();                   // constructor
    ~movieBST();                  // destructor
    bool insertMovie(string movieName, double rating);
    void printPreOrder() const; // prints tree data pre-order to cout
    Node* getRoot();
    void vectorInsert(Node* t, string prefix);
    double search(Node* t,string name);
    int getNodesVisited();
    int getNodesInserted();
    void searchVector();
    bool isEmpty();
    
};