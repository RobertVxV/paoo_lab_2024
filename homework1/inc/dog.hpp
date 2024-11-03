#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <ctime>
#include <iostream>
#include <cstring>

class Dog
{
private:
    char *name = new char[20]; // max 20 characters
    int birth_year;
    bool isHealthy;

public:
    // Constructor
    Dog(const char *name, int birth_year, bool isHealthy)
    {
        strcpy(this->name, name);
        this->birth_year = birth_year;
        this->isHealthy = isHealthy;
        std::cout << "Created dog using constructor: " << this->to_string();
    }

    // Destructor
    ~Dog()
    {
        delete[] this->name;
        std::cout << "Removed dog using destructor" << std::endl;
    }

    // Copy Constructor
    Dog(const Dog &other)
    {
        strcpy(this->name, other.name); // deep copy
        this->birth_year = other.birth_year;
        this->isHealthy = other.isHealthy;
        std::cout << "Created dog using copy constructor: " << this->to_string();
    }

    // Move Constructor
    Dog(Dog &&other) noexcept
    {
        delete[] this->name; // delete this->name
        this->name = other.name; // transfer ownership
        this->birth_year = other.birth_year;
        this->isHealthy = other.isHealthy;
        other.name = nullptr; // null other.name
        std::cout << "Created dog using move constructor: " << this->to_string();
    }

    // Getters
    char *getName() const { return name; }
    int getAge() const
    {
        time_t t = time(nullptr);
        struct tm *now = localtime(&t);
        int current_year = now->tm_year + 1900;
        return current_year - birth_year;
    }
    bool getIsHealthy() const { return isHealthy; }

    // Setters
    void setName(const char *name) const
    {
        if(this->name != nullptr){
            strncpy(this->name, name, 19);
        }
    }
    void setIsHealthy(const bool isHealthy) { this->isHealthy = isHealthy; }

    // Actions
    void bark() const
    {
        std::cout << this->name << ", age " << this->getAge() << " said: ham-ham" << std::endl;
    }
    // to_string method
    std::string to_string() const
    {
        const char *name_ptr = (name != nullptr) ? name : "nullptr";
        std::string name_str(name_ptr);
        std::string health_status = isHealthy ? "healthy" : "not healthy";
        return "Dog[name: " + name_str + ", age: " + std::to_string(getAge()) + ", health status: " + health_status + "]\n";
    }
};

#endif // DOG_HPP
