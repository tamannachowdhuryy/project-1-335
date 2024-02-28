/*
CSCI 335 Spring 2024
Assignment 1 - Book
Name: Tamanna Chowdhury
Book.cpp: Implementations of all the book items needed to move all the objects from one location to another 
*/

#include "Book.hpp"

   /*
        * Default constructor.
        * Default-initializes all private members.
        * Default title: "". 
        * Default author: "". 
        * Default ISBN value: 0LL. 
        * Default keywords: [].
        * Default keywords: "".
   */
    Book::Book() : title_(""), author_(""), ISBN_(0LL), price_(0.0f), icon_(nullptr), keywords_(), blurb_("")
    {
        
    }

    /**
        * Destructor
            @post: Destroy the book object
    */
    Book::~Book()
    {
        delete[] icon_; // this will deallocated the memory for icon
    }

    /*
        * Copy Constructor  
        * @param: Get the rhs of everything in the private member    
    */
    Book::Book(const Book& rhs): title_(rhs.title_), author_(rhs.author_), ISBN_(rhs.ISBN_), price_(rhs.price_), keywords_(rhs.keywords_), blurb_(rhs.blurb_)
    {
        

        // Perform a deep copy of icon_
        if (rhs.icon_) {
            icon_ = new int[80];
            for (int i = 0; i < 80; ++i) {
                icon_[i] = rhs.icon_[i];
            }
        } else {
            icon_ = nullptr;
        }
       
    }

    /*
        * Copy Assignment 
            @param: const Book on the rhs
            @return: return pointer 
    */
    Book& Book::operator=(const Book& rhs)
    {
        if(this != &rhs){
            author_ = rhs.author_;
            blurb_ = rhs.blurb_;
            title_ = rhs.title_; 
            ISBN_ = rhs.ISBN_; 
            keywords_ = rhs.keywords_; 
            price_ = rhs.price_;
            

            // Perform a deep copy of icon_
            if (rhs.icon_) {
                icon_ = new int[80];
                for (int i = 0; i < 80; ++i) {
                    icon_[i] = rhs.icon_[i];
                }
            } else {
                icon_ = nullptr;
            }
        }
        return *this;
    }

    /*
        * Move Constructor 
            @param rhs: A rvalue reference to the source Book object being moved.

    */
    Book::Book(Book&& rhs) : title_(std::move(rhs.title_)), author_(std::move(rhs.author_)), ISBN_(std::move(rhs.ISBN_)), price_(std::move(rhs.price_)), icon_(std::move(rhs.icon_)), keywords_(std::move(rhs.keywords_)), blurb_(std::move(rhs.blurb_))
    {
        rhs.icon_ = nullptr;   
    }

    /*
        * Move Assignment:
            @param rhs: A rvalue reference to the source Book object being moved.
            @return A reference to the current Book object after the move assignment.     
    */
    Book& Book::operator=(Book&& rhs)
    {
    if (this != &rhs) {
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = std::move(rhs.ISBN_);
        price_ = std::move(rhs.price_);
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);

        
    }

    return *this;
    }

    /**
        @return    : a string of the Book title
    **/
    const std::string& Book::getTitle() const
    {
        return title_;
    }

    /**
        @param      : a reference to a title
        @post       : sets the private member variable to the value of the parameter.
    **/
    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    /**
        @return    : a string of the Book author
    **/
    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    /**
        @param      : a reference to a author
        @post       : sets the private member variable to the value of the parameter.
    **/
    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    /**
        @return    : a int of the Book ISBN
    **/
    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    /**
        @param      : a reference to a ISBN
        @post       : sets the private member variable to the value of the parameter.
    **/
    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }

    /**
        @return    : a int of the Book Icon
    **/
    const int* Book::getIcon() const
    {
        return icon_;
    }

    /**
        @param      : a reference to a Icon
        @post       : delete the icon and create a if statement to collect all the 80 intergers that is in the text file 
    **/
    void Book::setIcon(int* icon) {
        if (icon_) {
            delete[] icon_;
        }

        if (icon) {
            icon_ = new int[80];
            for (int i = 0; i < 80; ++i) {
                icon_[i] = icon[i];
            }
        } else {
            icon_ = nullptr;
        }
    }

    /**
        @return    : a int of the Book price
    **/
    float Book::getPrice() const
    {
        return price_;
    }

    /**
        @param      : a reference to a price
        @post       : sets the private member variable to the value of the parameter.
    **/
    void Book::setPrice(float price)
    {
        price_ = price;
    }

    /**
        @return    : a int of the Book keyboards
    **/
    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    /**
        @param      : a reference to a keyboard
        @post       : sets the private member variable to the value of the parameter.
    **/
    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    /**
        @return    : a int of the Book blurb
    **/
    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    /**
        @param      : a reference to a blurb
        @post       : sets the private member variable to the value of the parameter.
    **/
    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ = blurb;
    }

    /**
        * @post: Print the Book in the following format:
        * Title: [Title]
        * Author: [Name]
        * ISBN: [Numbers]
        * Icon: [Numbers]
        * Price: [Cost]
        * Keywords: []
        * Blurb: [Words related on the book]
        * Note: For [ImageData]: If there is no image data, print "No image data" instead
    */
    void Book::print() const
    {
    std::cout << "Title: " << getTitle() << std::endl;
    std::cout << "Author: " << getAuthor() << std::endl;
    std::cout << "ISBN: " << getISBN() << std::endl;

    std::cout << "Icon: ";
    
     if (const int* icon = getIcon()) {
        for (int i = 0; i < 80; i++) {
            std::cout << icon_[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "null" << std::endl;
    }

    // Print price with exactly 2 digits after the decimal point
    std::cout << "Price: $" << std::fixed << std::setprecision(2) << getPrice() << std::endl;

    // Print keywords using getter method
    std::cout << "Keywords: ";
    for (const auto& keyword : getKeywords()) {
        std::cout << keyword << " ";
    }
    std::cout << std::endl;

    // Print blurb using getter method
    std::cout << "Blurb: " << getBlurb() << std::endl;
    }
