#include <dog.hpp>
#include <iostream>

using namespace std;

int main()
{
    cout<<endl;
    Dog *d = new Dog("Max", 2014, true);
    delete d;
    cout<<endl;
}
