/*
CSCI 335 Spring 2024
Assignment 1 - Book
Name: Tamanna Chowdhury
Book.cpp: Implementations of all the book items needed to move all the objects from one location to another 
*/
#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".

void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  // DO NOT ALTER ABOVE HERE

  /*
  implement the books that are moving
  iterate -> source vector
  for each book in source 
    check if any of the keywords match the given keyword 
      if matched
        move the book source to dest using the std::move and increment the book that was being moved
  */
  // first looks through the iterator 
  auto it = source.begin();
  while (it != source.end()) {
    const std::vector<std::string>& keywords = it->getKeywords(); // Access private member 
    
    // Manual loop to find keyword
    bool found = false;
    for (const auto& kw : keywords) {
        if (kw == keyword) {
            found = true;
        }
    }
    // if keyword is found then it will move if not it will go to the next item
    if (found) {
        dest.push_back(std::move(*it));
        it = source.erase(it);
        ++books_moved;
    } else {
        ++it;
    }
  }

 
  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}