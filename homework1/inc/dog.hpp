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
    }

    // Destructor
    ~Dog(){}

    // Getters
    const std::string getName() const { return name; }
    int getAge() const
    {
        time_t t = time(NULL); // get time now
        struct tm *now = localtime(&t);
        int current_year = now->tm_year + 1900; // You might want to replace this with a function to get the current year dynamically
        return current_year - birth_year;
    }
    bool getIsHealthy() const { return isHealthy; }

    // Setters
    void setIsHealthy(bool isHealthy) { this->isHealthy = isHealthy; }

    // Methods
    void bark()
    {
        std::cout << this->name << ", age " << this->getAge() << " said: hamham" << std::endl;
    }
};

#endif // DOG_HPP