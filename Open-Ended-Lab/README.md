# OOP_Project_Second_Semester
A comprehensive C++ application for managing university operations including student/faculty administration, course enrollment, attendance tracking, billing, and ID card generation with role-based access control.


# 🎓 Smart Campus Management System

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![OOP](https://img.shields.io/badge/Pure-OOP-success.svg)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)


A comprehensive **Object-Oriented C++ console application** demonstrating pure OOP principles with advanced exception handling, file management, and operator overloading.

## 🌟 Features

### 👥 Multi-Role Access System
- **Student Portal**: Course enrollment, GPA tracking, bill payment, ID card generation
- **Faculty Dashboard**: Student management, course coordination, attendance tracking  
- **Admin Control Panel**: Full system oversight, user management, analytics

### 📚 Academic Management
- Course catalog with real-time enrollment tracking
- Semester-based academic planning
- Credit system management
- Instructor assignment and scheduling

### 💰 Financial Module
- Automated billing and fee management
- Payment status tracking
- Revenue analytics
- Due date notifications

## 🏗️ Pure Object-Oriented Architecture

### 🔑 OOP Principles Demonstrated

#### 1. **Encapsulation**
```cpp
class User {
private:
    string username;        // Data hiding
    string password;
    
public:
    // Controlled access through methods
    string getUsername() const { return username; }
    void setPassword(string p) { password = p; }
};
```

#### 2. **Inheritance Hierarchy**
```
User (Base Class)
├── Student
├── Faculty  
└── Admin
```

#### 3. **Polymorphism**
```cpp
virtual void displayInfo() const;    // Virtual function
virtual string serialize() const;    // Method overriding
```

#### 4. **Abstraction**
```cpp
class Course {
public:
    bool enrollStudent();    // Simple interface
    bool dropStudent();      // Hidden complexity
private:
    int currentEnrollment;   // Implementation details
};
```

### 🎯 Advanced OOP Features

#### **Friend Functions**
```cpp
class User {
private:
    string username, password;
    
public:
    friend ostream& operator<<(ostream& os, const User& user);
    friend bool validateUserCredentials(const User& user);
};

// Friend function accessing private members
ostream& operator<<(ostream& os, const User& user) {
    os << "Username: " << user.username;  // Direct access to private data
    return os;
}
```

#### **Operator Overloading**
```cpp
class Course {
public:
    friend ostream& operator<<(ostream& os, const Course& course);
    friend double calculateTotalRevenue(const vector<Course>& courses);
};

// Stream insertion operator
ostream& operator<<(ostream& os, const Course& course) {
    os << course.courseName << " (" << course.currentEnrollment << "/" 
       << course.maxCapacity << ")";
    return os;
}
```

## ⚠️ Exception Handling System

### **Custom Exception Hierarchy**
```cpp
// Base exception class
class CampusException : public exception {
private:
    string message;
public:
    CampusException(const string& msg) : message("❌ " + msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

// Specialized exceptions
class AuthenticationException : public CampusException {
public:
    AuthenticationException(const string& msg = "Authentication failed") 
        : CampusException("🔐 " + msg) {}
};

class DataException : public CampusException {
public:
    DataException(const string& msg = "File operation failed") 
        : CampusException("💾 " + msg) {}
};
```

### **Validation with Friend Functions**
```cpp
bool validateUserCredentials(const User& user) {
    // Friend function accessing private members
    if (user.password.length() < 6) {
        throw ValidationException("Password too weak for user: " + user.username);
    }
    
    size_t at_pos = user.email.find('@');
    if (at_pos == string::npos) {
        throw ValidationException("Invalid email for user: " + user.username);
    }
    return true;
}
```

## 💾 File Handling Implementation

### **Object Serialization**
```cpp
class User {
public:
    virtual string serialize() const {
        return username + "|" + password + "|" + fullName + "|" + email;
    }
};

class Student : public User {
public:
    string serialize() const override {
        return User::serialize() + "|" + studentId + "|" + department;
    }
};
```

### **File Operations with Exception Handling**
```cpp
void saveUsersToFile(const vector<User*>& users, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw DataException("Cannot open file: " + filename);
    }
    
    try {
        for (const auto& user : users) {
            file << user->serialize() << endl;
        }
    }
    catch (...) {
        throw DataException("Error writing to file: " + filename);
    }
}
```

## 🚀 Quick Start

### Prerequisites
- Windows OS with C++17 compiler
- Visual Studio or MinGW

### Compilation & Execution
```bash
g++ -o campus_system main.cpp -std=c++17
./campus_system
```

## 📊 Class Structure

### **Core Classes**
```cpp
User (Base)
├── Student (studentId, department, GPA)
├── Faculty (facultyId, department, salary)  
└── Admin (adminId, accessLevel)

Supporting Classes:
Course, Enrollment, Bill, Attendance, IDCard
```

### **Friend Functions Implementation**
```cpp
// User class friends
friend ostream& operator<<(ostream& os, const User& user);
friend bool validateUserCredentials(const User& user);

// Course class friends  
friend ostream& operator<<(ostream& os, const Course& course);
friend double calculateTotalRevenue(const vector<Course>& courses);
```

## 👥 Contributors

 **FEEZA KULSOOM** 

 **HASNAIN MALIK**

 **ABDULREHMAN**

## 💡 Code Examples

### **Operator Overloading in Action**
```cpp
Course cs101("CS101", "OOP Programming", 3, 30);
cout << cs101;  // Uses overloaded << operator

// Output: CS101 - OOP Programming (0/30 students)
```

### **Friend Function Usage**
```cpp
User student("john_doe", "password123", "John Doe");
cout << student;  // Friend function accessing private data

// Friend validation function
try {
    validateUserCredentials(student);
} 
catch (const ValidationException& e) {
    cout << e.what();  // ❌ Validation error messages
}
```

### **Polymorphic File Saving**
```cpp
vector<User*> users;
users.push_back(new Student(...));
users.push_back(new Faculty(...));

// Each object knows how to serialize itself
for (auto user : users) {
    file << user->serialize() << endl;  // Polymorphic call
}
```

## 🎯 OOP Features Demonstrated

### **1. Inheritance & Polymorphism**
- Virtual functions for runtime polymorphism
- Method overriding in derived classes
- Abstract base class design

### **2. Encapsulation & Friend Functions**  
- Private data members with controlled access
- Friend functions for specific privileged operations
- Maintained encapsulation while allowing necessary access

### **3. Operator Overloading**
- Stream insertion operators (<<)
- Natural syntax for object output
- Enhanced code readability

### **4. Exception Handling**
- Custom exception hierarchy
- Resource management (RAII)
- Graceful error recovery

## 📈 Project Metrics

- **10+ Well-designed classes** following OOP principles
- **4-Level inheritance hierarchy**
- **6+ Friend functions** for specific operations
- **Comprehensive operator overloading**
- **Robust exception handling system**

## 🔧 Technical Implementation

### **File Management**
- Object serialization/deserialization
- Exception-safe file operations
- Data persistence with validation

### **Memory Management**
- RAII principles
- Proper object lifecycle
- Resource cleanup

## 🎓 Educational Value

This project demonstrates:
- **Pure OOP implementation** without external dependencies
- **Friend functions** and their appropriate use cases
- **Operator overloading** for intuitive interfaces
- **Exception handling** in object-oriented design
- **File I/O** with object serialization

---

<div align="center">

**🎓 Exemplary Object-Oriented Programming Project**

*Demonstrating C++ OOP principles in a real-world application* ✨

</div>

---

### ✅ OOP Checklist
- [x] **Encapsulation** with access modifiers
- [x] **Inheritance** hierarchy design
- [x] **Polymorphism** through virtual functions  
- [x] **Abstraction** with simple interfaces
- [x] **Friend functions** for specific access
- [x] **Operator overloading** for intuitive use
- [x] **Exception handling** hierarchy
- [x] **File I/O** with object serialization

**A complete OOP implementation showcasing advanced C++ features.** 🏗️✨
