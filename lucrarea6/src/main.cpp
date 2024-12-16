#include <iostream>
#include <memory>
#include <cstring>
#include <mutex>

class Lock {
public:
    explicit Lock(std::shared_ptr<std::mutex> pm)
        : mutexPtr(std::move(pm)) {
        mutexPtr->lock();
        std::cout << "Mutex locked.\n";
    }

    ~Lock() {
        mutexPtr->unlock();
        std::cout << "Mutex unlocked.\n";
    }

private:
    std::shared_ptr<std::mutex> mutexPtr;
};

class ResourceManager {
private:
    std::unique_ptr<char[]> resource;
    size_t size;
    std::shared_ptr<std::mutex> resourceMutex;

public:
    ResourceManager(const char* data)
        : resourceMutex(std::make_shared<std::mutex>()) {
        size = std::strlen(data) + 1;
        resource = std::make_unique<char[]>(size);
        std::strcpy(resource.get(), data);
        std::cout << "Resource allocated: " << resource.get() << "\n";
    }

    // Destructor: default cleanup handled by unique_ptr
    ~ResourceManager() {
        std::cout << "Resource deallocated.\n";
    }

    ResourceManager(const ResourceManager& other)
        : resourceMutex(other.resourceMutex) {
        Lock lock(resourceMutex);
        size = other.size;
        resource = std::make_unique<char[]>(size);
        std::strcpy(resource.get(), other.resource.get());
        std::cout << "Resource copied: " << resource.get() << "\n";
    }

    ResourceManager& operator=(const ResourceManager& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }

        Lock lockThis(resourceMutex);
        Lock lockOther(other.resourceMutex);

        size = other.size;
        resource = std::make_unique<char[]>(size);
        std::strcpy(resource.get(), other.resource.get());
        std::cout << "Resource assigned: " << resource.get() << "\n";

        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept
        : resourceMutex(std::move(other.resourceMutex)) {
        
        Lock lock(resourceMutex);
        
        resource = std::move(other.resource);
        size = other.size;
        other.size = 0;
        std::cout << "Resource moved.\n";
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this == &other) {
            return *this; // Handle self-assignment
        }

        Lock lockThis(resourceMutex);
        Lock lockOther(other.resourceMutex);

        resource = std::move(other.resource);
        size = other.size;
        other.size = 0;
        std::cout << "Resource move-assigned.\n";

        return *this;
    }

    const char* getResource() const {
        Lock lock(resourceMutex);
        return resource.get();
    }
};

int main() {
    ResourceManager rm1("Hello, World!");

    // Copying resource
    ResourceManager rm2 = rm1;

    // Assigning resource
    ResourceManager rm3("Temporary Resource");
    rm3 = rm1;

    // Moving resource
    ResourceManager rm4 = std::move(rm3);

    std::cout << "rm1 resource: " << rm1.getResource() << "\n";
    std::cout << "rm2 resource: " << rm2.getResource() << "\n";
    std::cout << "rm4 resource: " << rm4.getResource() << "\n";

    return 0;
}
