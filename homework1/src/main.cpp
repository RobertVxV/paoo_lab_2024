#include <dog.hpp>
#include <iostream>

using namespace std;

int main()
{
     cout << endl;

     Dog *d1 = new Dog("Max", 2014, true);
     Dog *d2 = new Dog(*d1); // copy constructor
     cout << "d1: " << d1->to_string();
     cout << "d2: " << d2->to_string();
     Dog *d3 = new Dog(std::move(*d1)); // move constructor

     d2->setName("Maximus");
     d2->setIsHealthy(true);
     cout << "d1: " << d1->to_string();
     cout << "d2: " << d2->to_string();
     cout << "d3: " << d3->to_string() << endl;
     d1->setName("Rex");
     d1->setIsHealthy(false);
     cout << endl
          << "d1: " << d1->to_string();
     cout << "d2: " << d2->to_string();
     cout << "d3: " << d3->to_string() << endl;
     delete d1;
     delete d2;
     delete d3;
     return 0;
}
