#include<iostream>
#include <cstring>
#include <memory>
using namespace std;
class description{
    public:
    string color;
    int size;
    description(){}; //constructor no-arg
    description( const string &, int );
    
     void display(){
        cout<<color<<endl<<size<<endl;
    }
    ~description(){
        cout<<"destructor"<<endl;
    }
    string getColor(){
        return color;

    }
    int getSize(){
        return size;
    }
  
};
description::description( const string &c, int s): color(c), size(s){}


class Imbracaminte:private description{
    private:
     string marca;
     string type;
     description *d = new description;
    // stoc *s = new stoc;

    public:
    Imbracaminte(){};
    Imbracaminte( const string&,  const string&, description &);
    ~Imbracaminte();
    Imbracaminte& operator=( Imbracaminte&);
    Imbracaminte( Imbracaminte &new_imbr);
    void display2(){
        cout<<marca<<endl<<type<<endl;
        cout<<d->getColor()<<endl<<d->getSize()<<endl;
       
    }


};


Imbracaminte::Imbracaminte(const string &m,  const string  &t, description &d1)
: marca(m),type(t) {
    
    
    d->color = d1.color;
    d->size = d1.size;
    
}
Imbracaminte::  Imbracaminte( Imbracaminte& other)
       : description(other),marca(other.marca),type(other.type) //item 12
    {   
      
        std::cout << "copy" << std::endl;
    } 
Imbracaminte& Imbracaminte:: operator=( Imbracaminte& m){ //item 11
        cout<<"Assignment operator"<<endl;
        if(this!=&m)
            {   
                description *d1 = d;
                d=new description(*m.d);
                delete d1;
                marca = m.marca;
                type = m.type;
            }
      
        return *this;
    }
Imbracaminte::~Imbracaminte(){
    cout<<"destructor"<<endl;
    delete d;

}
Imbracaminte* factoryMethod() {
  return (new Imbracaminte);
} 
class Magazin{
    private:
    bool exists = false;
    int stoc = 12;

    public:
  Magazin(int stoc) {
    std::cout << "Magazin Constructor"<<std::endl;
     this->stoc = stoc;
  }
  Magazin (const Magazin &m){
    std::cout <<"Magazin copy constructor"<<std::endl;
    this->stoc = m.stoc;
    this->exists = m.exists;
  }
  ~Magazin(){
    std::cout<<"Magazin sters"<<std::endl;
  }
  int getStoc(){
    return this->stoc;
  }
   int getifExists(){
    return this->exists;
  }
   void setifExists(bool exists){
    this->exists = exists;
  }
  void ExistsInMagazin(){
    if(this->exists== false)
       std::cout<<"In magazin se gasesc 0 produse"<<std::endl;
        else
            std::cout<<"In magazin se gasesc " << this->stoc<<"produse" <<std::endl;
  }

};
void lock(Magazin &m){
    std::cout<<"In acest magazin  nu se regaseste produsul"<<std::endl;
    m.setifExists(true);
}

void unlock(Magazin &m){
    std::cout<<"In acest magazin se regasesc din nou " << m.getStoc() << "produse"<<std::endl;
    m.setifExists(false);
}

class Mall{
    private:
        Magazin &magazin;
    public:
    Mall(Magazin &m):magazin(m){
        lock(magazin);
    }
    ~Mall(){
        unlock(magazin);
    }
};

int main(){
  

    description d;
    d = description("red", 34);
  //  d.display();
 
    Imbracaminte i("adidas","jeans", d);
    i.display2();

    //item 13

      {
        std::auto_ptr<Imbracaminte>  i1(factoryMethod());
        std::auto_ptr<Imbracaminte>  i2(i1);
    }
     {
        std::shared_ptr<Imbracaminte> i1(factoryMethod()); //call factory function
        std::cout << "Imbracaminte 1 " << i1.use_count() << std::endl; //shared_ptr instances 
        std::shared_ptr<Imbracaminte> i2(i1);
        std::cout << "Imbracaminte 2 " << i1.use_count() << std::endl;
        std::shared_ptr<Imbracaminte> i3(i1);
        std::cout << "Imbracaminte 3 " << i3.use_count() << std::endl;
        //std::cout << "Imbracaminte 3 " << i3.use_count() << std::endl;
    }

     //ITEM 14
     Magazin m(20);
   Mall *mall = new Mall(m);
    m.ExistsInMagazin();
    delete mall;
    m.ExistsInMagazin();
    lock(m);
    m.ExistsInMagazin();
    unlock(m);
    m.ExistsInMagazin();

    return 0;

}