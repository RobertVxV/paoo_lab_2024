#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <ctime>
#include <iostream>

class Dog
{
private:
    std::string name;
    int birth_year;
    bool isHealthy;

public:
    // Constructor
    Dog(const std::string &name, int birth_year, bool isHealthy)
    {
        this->name = name;
        this->birth_year = birth_year;
        this->isHealthy = isHealthy;
        std::cout<<"Created dog using constructor: " << this->to_string();
    }

    // Destructor
    ~Dog() {
        std::cout<<"Removed dog using destructor: " << this->to_string();
    }

    // Getters
    const std::string getName() const { return name; }
    int getAge() const
    {
        time_t t = time(NULL);
        struct tm *now = localtime(&t);
        int current_year = now->tm_year + 1900;
        return current_year - birth_year;
    }
    bool getIsHealthy() const { return isHealthy; }

    // Setters
    void setIsHealthy(bool isHealthy) { this->isHealthy = isHealthy; }

    // Actions
    void bark()
    {
        std::cout << this->name << ", age " << this->getAge() << " said: hamham" << std::endl;
    }
    // to_string method
    std::string to_string()
    {
        std::string health_status = isHealthy ? "healthy" : "not healthy";
        return "Dog[name: " + name + ", age: " + std::to_string(getAge()) + ", health status: " + health_status + "]\n";
    }
};

#endif // DOG_HPP
