// firstOOPProgram.cpp

#include <iostream>
using namespace std;

// Abstract base class
class AbstractEmployee {
public:
    virtual void askForPromotion() = 0; // Pure virtual function
};

// Base class: Employee
class Employee : public AbstractEmployee {
private:
    string name;
    string company;
    int age;

public:
    // Constructors
    Employee() {
        name = "Unknown";
        company = "None";
        age = 0;
    }

    Employee(string empName, string empCompany, int empAge) {
        name = empName;
        company = empCompany;
        setAge(empAge);
    }

    // Setter and Getter for name
    void setName(string empName) { name = empName; }
    string getName() const { return name; }

    // Setter and Getter for company
    void setCompany(string empCompany) { company = empCompany; }
    string getCompany() const { return company; }

    // Setter and Getter for age
    void setAge(int empAge) {
        if (empAge >= 18) {
            age = empAge;
        } else {
            cout << "Age must be 18 or older. Setting to 18." << endl;
            age = 18;
        }
    }
    int getAge() const { return age; }

    // Implementation of abstract method
    void askForPromotion() override {
        if (age > 30)
            cout << name << " got promoted!" << endl;
        else
            cout << name << " is not eligible for promotion yet." << endl;
    }
};

// Subclass: Developer
class Developer : public Employee {
private:
    string favoriteProgrammingLanguage;

public:
    // Constructor
    Developer(string name, string company, int age, string favLang)
        : Employee(name, company, age) {
        favoriteProgrammingLanguage = favLang;
    }

    // Setter and Getter for favoriteProgrammingLanguage
    void setFavoriteProgrammingLanguage(string lang) {
        favoriteProgrammingLanguage = lang;
    }

    string getFavoriteProgrammingLanguage() const {
        return favoriteProgrammingLanguage;
    }

    // Developer-specific method
    void fixBug() {
        cout << getName() << " fixes bugs using C++" << endl;
    }
};

int main() {
    // Create Developer object
    Developer dev("Charlie", "OpenAI", 28, "C++");

    // Use class methods
    dev.askForPromotion();  // From Employee
    dev.fixBug();           // From Developer

    return 0;
}
