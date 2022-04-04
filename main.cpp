#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>

#include "movies.h"
using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  ofstream of;
  of.open("outputFile.csv");
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }
  movieBST b1;
  vector<string> movieList;
  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file

  // Read each file and store the name and rating
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    // Use std::string movieName and double movieRating
    // to construct your Movie objects
    // cout << movieName << " has rating " << movieRating << ": " <<  endl;
    b1.insertMovie(movieName, movieRating);
    if(!flag){
      of << b1.getNodesInserted() << ", " << b1.getNodesVisited() << endl;
      movieList.push_back(movieName);
    }
  }
  of.close();
  movieFile.close();
  if(!flag){
    for(int i = 0; i < atoi(argv[3]); i++){
      clock_t t = clock();
      for(int j = 0; j < movieList.size(); j++){
        b1.search(b1.getRoot(), movieList[j]);
      }
      t = clock() - t;
  cout << (t*1000000/CLOCKS_PER_SEC) << " microseconds" << endl;
    }
  
  }
  if(flag){
    b1.printPreOrder();
  }
  b1.vectorInsert(b1.getRoot(), argv[3]);
  b1.searchVector();

  
// do stuff
  

  return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}

