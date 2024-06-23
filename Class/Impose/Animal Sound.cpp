//dynamic_cast
#include <bits/stdc++.h>
using namespace std;
class Animal{
    public:
    virtual void speak(){
        cout << "Animal speak";
    }
};
class Dog:public Animal{
    public:
    void speak(){
        cout << "Dog Berks\n";
    }
};
class Cat:public Animal{
    public:
    void speak(){
        cout << "meow\n";
    }
};
int main(){
    Animal *ptr = new Dog();
    Animal *itr = new Cat();
    Dog *dogptr = dynamic_cast<Dog*>(ptr);
    if(dogptr)
        dogptr->speak();
    else
        cout << "Failed to cast\n";
    Cat *catptr = dynamic_cast <Cat*>(itr);
    if(catptr)
        catptr->speak();
    else
        cout << "Failed to cast\n";
    delete ptr;
    delete itr;
}
