#include <dog.hpp>
#include <ctime>
#include <iostream>
#include <cstring>
#include <sstream> //for std::stringstream 
#include <string>  //for std::string

// Constructor
Dog::Dog(const char *name, int birth_year, bool isHealthy)
{
    strcpy(this->name, name);
    this->birth_year = birth_year;
    this->isHealthy = isHealthy;
    std::cout << "Created dog using constructor: " << this->to_string();
}

// Destructor
Dog::~Dog()
{
    delete[] this->name;
    std::cout << "Removed dog using destructor" << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog &other)
{
    strcpy(this->name, other.name); // deep copy
    this->birth_year = other.birth_year;
    this->isHealthy = other.isHealthy;
    std::cout << "Created dog using copy constructor: " << this->to_string();
}

// Move Constructor
Dog::Dog(Dog &&other) noexcept
{
    delete[] this->name;
    this->name = other.name; // transfer ownership
    this->birth_year = other.birth_year;
    this->isHealthy = other.isHealthy;
    other.name = nullptr; // null other.name
    std::cout << "Created dog using move constructor: " << this->to_string();
}

// Getters
char *Dog::getName() const { return name; }

int Dog::getAge() const
{
    time_t t = time(nullptr);
    struct tm *now = localtime(&t);
    int current_year = now->tm_year + 1900;
    return current_year - birth_year;
}

bool Dog::getIsHealthy() const { return isHealthy; }

// Setters
void Dog::setName(const char *name) const
{
    if(this->name != nullptr){
        strncpy(this->name, name, 19);
    }
}

void Dog::setIsHealthy(const bool isHealthy) { this->isHealthy = isHealthy; }

// Actions
void Dog::bark() const
{
    std::cout << this->name << ", age " << this->getAge() << " said: ham-ham" << std::endl;
}

// to_string method
std::string Dog::to_string() const
{
    //get address of calling object.
    const void * address = static_cast<const void*>(this);
    std::stringstream ss;
    ss << address;  
    std::string address_str = ss.str(); 

    const char *name_ptr = (name != nullptr) ? name : "nullptr";
    std::string name_str(name_ptr);
    std::string health_status = isHealthy ? "healthy" : "not healthy";
    return "Dog[name: " + name_str + ", age: " + std::to_string(getAge()) + ", health status: " + health_status + "] - address: {" + address_str +"}\n";
}
