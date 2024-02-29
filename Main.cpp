/*
CSCI 335 Spring 2024
Assignment 1 - Book
Name: Tamanna Chowdhury
Book.cpp: Implementations of all the book items needed to move all the objects from one location to another 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include "Book.hpp"
#include "MoveAll.hpp"

int main(){
  
  std::vector<Book> catalog, cart;

  // open file
  std::string filename = "1000bookInputFile.txt";
  std::ifstream fin(filename);

  // define expected format
  std::regex title("(Title: )(.*)");
  std::regex author("(Author: )(.*)");
  std::regex ISBN("(ISBN: )(.*)");
  std::regex icon("(Icon: )(.*)");
  std::regex price("(Price: \\$)(.*)");
  std::regex keywords("(Keywords: )(.*)");
  std::regex blurb("(Blurb: )(.*)");

  // declare helper variables for reading from file
  std::string line;
  std::smatch match;
  Book temp;

  // reads all 7 fields in each iteration and copies the value of each field into Book "temp"
  // pushes "temp" onto the back of "catalog" at the end of the iteration
  while (getline(fin,line)){

    // Title
    if (!std::regex_search(line, match, title)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setTitle(match[2]);

    // Author
    getline(fin,line);
    if (!std::regex_search(line, match, author)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setAuthor(match[2]);

    // ISBN
    getline(fin,line);
    if (!std::regex_search(line, match, ISBN)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setISBN(std::stoll(match[2]));

    // Icon
    getline(fin,line);
    if (!std::regex_search(line, match, icon)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    std::stringstream numstring(match[2]);
    int next_number;
    int* numarray = new int[80];
    for (int i=0 ; i<80; ++i){
      if (!(numstring >> next_number))
        std::cout << "Error reading file format" << std::endl;
      numarray[i] = next_number;
    }
    temp.setIcon(numarray);
    numarray = nullptr;




    // Price
    getline(fin,line);
    if (!std::regex_search(line, match, price)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setPrice(std::stof(match[2]));

    // Keywords
    getline(fin,line);
    if (!std::regex_search(line, match, keywords)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    std::stringstream keyword_string(match[2]);
    std::vector<std::string> keywords;
    while (keyword_string){
      std::string keyword;
      if (!getline(keyword_string >> std::ws, keyword, ',' )) break;
      keywords.push_back(keyword);
    }
    temp.setKeywords(keywords);

    // Blurb
    getline(fin,line);
    if (!std::regex_search(line, match, blurb)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setBlurb(match[2]);

    getline(fin,line);  // skip line between entries
    catalog.push_back(temp);

  }

  // write your test cases here

 // Test: Print all books in the catalog
  // for (const auto& temp : catalog) {
  //   temp.print();
  //   std::cout << "----------------------------------\n";
  // }

  //Test Case 1: keyword "Paranormal Romance" 
  std::cout << "Test Case 1:\n";
  moveAll("Paranormal Romance", catalog, cart);
  std::cout << "----------------------------------\n";

  // Test Case 2: keyword "Fandom" 
  std::cout << "Test Case 2:\n";
  moveAll("Fandom", catalog, cart);
  std::cout << "----------------------------------\n";
  
  //Test Case 3: keyword "Social Science" 
  std::cout << "Test Case 3:\n";
  moveAll("Mauritius", catalog, cart);
  // for (const auto& book : cart) {
  //   book.print();  // prints all the books the keyword has 
  // } 
  std::cout << "----------------------------------\n";

  // Test Case 4: keyword "Literary Fiction" 
  std::cout << "Test Case 4:\n";
  moveAll("Literary Fiction", catalog, cart);
  std::cout << "----------------------------------\n";

  // Test Case 5: keyword "Graphic Novels Manga" 
  std::cout << "Test Case 5:\n";
  moveAll("Graphic Novels Manga", catalog, cart);
  std::cout << "----------------------------------\n";

  return 0;
}