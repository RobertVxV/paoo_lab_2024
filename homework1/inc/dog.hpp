#ifndef DOG_HPP
#define DOG_HPP

#include <string>

class Dog
{
private:
    char *name = new char[20]; // max 20 characters
    int birth_year;
    bool isHealthy;

public:
    // Constructor
    Dog(const char *name, int birth_year, bool isHealthy);

    // Destructor
    ~Dog();

    // Copy Constructor
    Dog(const Dog &other);

    // Move Constructor
    Dog(Dog &&other) noexcept;

    // Getters
    char *getName() const;
    int getAge() const;
    bool getIsHealthy() const;

    // Setters
    void setName(const char *name) const;
    void setIsHealthy(const bool isHealthy);

    // Actions
    void bark() const;

    // to_string method
    std::string to_string() const;
};

#endif // DOG_HPP
