
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include "movies.h"

using namespace std;
movieBST::movieBST() : root(0) { 
    nodesVisited = 0;
    nodesInserted = 0;
}

// destructor deletes all nodes
movieBST::~movieBST() {
    clear(root);
}

// recursive helper for destructor
void movieBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

bool movieBST::insertMovie(string movieName, double rating){
    // handle special case of empty tree first
    nodesVisited = 0;
    if (!root) {
	    root = new Node(movieName, rating, 0);
	    return true;
    }
    // otherwise use recursive helper
    nodesVisited++;
    return insertMovie(movieName, rating, 1, root);
}

// recursive helper for insert (assumes n is never 0)
bool movieBST::insertMovie(string newMovieName, double newRating, int level, Node *n) {
    if (newMovieName == n->movieName){
        return false;
    }
    if (newMovieName < n->movieName) {
	    if (n->left){
            nodesVisited++;
	        return insertMovie(newMovieName, newRating, level + 1, n->left);
        }
	    else {
            nodesInserted++;
            n->left = new Node(newMovieName, newRating, level);
            n->left->parent = n;
            return true;
	    }
    }
    else {
	    if (n->right){
            nodesVisited++;
	        return insertMovie(newMovieName, newRating, level+1, n->right);
        }
	    else {
            nodesInserted++;
	        n->right = new Node(newMovieName,newRating, level);
	        n->right->parent = n;
	        return true;
	    }
    }
}

void movieBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void movieBST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->movieName << ", " << n->rating << ", " << n->depth << endl;
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}
movieBST::Node* movieBST::getRoot(){
    return root;
}

void movieBST::vectorInsert(movieBST::Node* t, string prefix){
    //int i = 0;
    if (t == nullptr){
        return;
    }
    string name = t->movieName;
    double rating1 = t->rating;

    if(name.substr(0,prefix.length())== prefix){
        moviePairs.push_back(*t);
    }
       vectorInsert(t->left, prefix);
       vectorInsert(t->right, prefix);
}
double movieBST::search(Node* t, string title){
    if(t == nullptr){
        return -1;
    }
    else if(title == t->movieName){
        return t->rating;
    }
    search(t->left, title);
    search(t->right, title);
}
int movieBST::getNodesVisited(){
    return nodesVisited;
}
int movieBST::getNodesInserted(){
    return nodesInserted;
}
void movieBST::searchVector() {
    int index = -1;
    double max = -1;
    for(int i = 0; i < moviePairs.size(); i++){
        if (moviePairs[i].rating > max){
            max = moviePairs[i].rating;
            index = i;
        }
    }
    if(max > -1){
        cout << "\nBest movie is "  << moviePairs[index].movieName << " with rating " << moviePairs[index].rating << endl;
        return;
    }
    cout << endl;


}
bool movieBST::isEmpty(){
    Node* t = root;
    if(root == nullptr){
        return true;
    }
    return false;
}
