#include "tests.h"
#include "movies.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){

    test_insert();
    test_search();

}

void test_insert(){
    START_TEST("test_insert");
    test_insert_empty();
    test_insert_left();
    test_insert_right();
    END_TEST("test_insert");
}
void test_search(){
    START_TEST("test_search");
    string testCase = "search_empty";
    movieBST b;
    assertEquals(b.search(b.getRoot(), "random name"), -1.0, testCase);
    END_TEST("test_search");
}

void test_insert_empty(){
    string testCase = "insert_empty";
    movieBST b;
    b.insertMovie("random name", 5.0);
    assertEquals(b.getRoot()->movieName, "random name", testCase);
}
void test_insert_left(){
    string testCase = "insert_left";
    movieBST b;
    b.insertMovie("random name", 5.0);
    b.insertMovie("a", 4.0);
    assertEquals(b.getRoot()->left->movieName, "a", testCase);
}
void test_insert_right(){
    string testCase = "insert_right";
    movieBST b;
    b.insertMovie("random name", 5.0);
    b.insertMovie("z", 4.0);
    assertEquals(b.getRoot()->right->movieName, "z", testCase);
}
