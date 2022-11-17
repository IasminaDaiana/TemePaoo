
#include<iostream>
#include <cstring>
using namespace std;


class Library{

    private:
    std::string nameLibrary;
    public:
    Library(const std::string&);
    std::string getName(){
        return this->nameLibrary ; 
    }


};
Library::Library (const std::string& nameL ) : nameLibrary(nameL){}


class Book{
   private:
     std::string name;
    int numberOfPage;
     std::string Author;
    int numberOfExemplars;
     std::string descriptionOfBook;
    int sizeofText;
    Library library;
    
    public:
    Book(  const std::string& ,  int ,  const  std::string&, int , const std::string&, Library & );
    ~Book(){
        cout<<"destructor is called"<<endl;
    }
    Book(const Book&) ; //= delete;
    

    void display(){
        cout<<name<<endl<<numberOfPage<<endl<<numberOfExemplars<<endl<<Author<<endl<<descriptionOfBook<<endl<<library.getName()<<endl;
    }
   Book& operator=(const Book& t){
        cout<<"Assignment operator"<<endl;
        if(this!=&t)
            {
                name = t.name;
                numberOfPage = t.numberOfPage;
                Author = t.Author;
                numberOfExemplars = t.numberOfExemplars;
                descriptionOfBook = t.descriptionOfBook;
            }
      
        return *this;
    }
     
   

   
};
Book::  Book(const Book& other)
       : name(other.name), numberOfPage(other.numberOfPage), Author(other.Author),numberOfExemplars(other.numberOfExemplars),descriptionOfBook(other.descriptionOfBook),library(other.library)
    {
        std::cout << "copy" << std::endl;
    } 
 Book::Book( const std::string& BookName, int pages,   const std::string &AuthorName,  int exemplars,  const std::string& description , Library &l):
name(BookName),
numberOfPage(pages),
Author(AuthorName),
numberOfExemplars(exemplars),
descriptionOfBook(description),
library(l){
  
} // initialization in constructor


int main(){
    
    
    Library l1("Piata Victoriei");
    Library l2("Carturesti");
    Book b1("fata din padure",100, "Mihai Eminescu", 130,"It s a horror story about a girl", l1);

   b1.display();
   
   Book b2(b1); // copy
   b2.display();
    cout<<endl;

    Book b3("capra cu trei iezi", 320, "Ion creanga", 200, "Este o poveste...", l1);
    b3=b2; //asignment operator
    b3.display();

    cout<<endl;
 
   return 0;
    

}