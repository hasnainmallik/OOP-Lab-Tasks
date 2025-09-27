#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
using namespace std;

void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}


// Exception Classes
class CampusException : public exception {
private:
    string message;
public:
    CampusException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class AuthenticationException : public CampusException {
public:
    AuthenticationException(const string& msg = "Authentication failed") 
        : CampusException("🔐 " + msg) {}
};

class AuthorizationException : public CampusException {
public:
    AuthorizationException(const string& msg = "Access denied") 
        : CampusException("🚫 " + msg) {}
};

class DataException : public CampusException {
public:
    DataException(const string& msg = "Data operation failed") 
        : CampusException("💾 " + msg) {}
};

class ValidationException : public CampusException {
public:
    ValidationException(const string& msg = "Validation error") 
        : CampusException("❌ " + msg) {}
};




// Color codes for beautiful terminal output
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BOLD = "\033[1m";
const string BRIGHT_RED = "\033[91m";
const string BRIGHT_GREEN = "\033[92m";
const string BRIGHT_YELLOW = "\033[93m";
const string BRIGHT_BLUE = "\033[94m";
const string BRIGHT_MAGENTA = "\033[95m";
const string BRIGHT_CYAN = "\033[96m";
const string BRIGHT_WHITE = "\033[97m";

// ASCII Art Banner Functions
void printMainBanner() {
   cout << BRIGHT_CYAN << BOLD << "\n";
cout << "███████╗███╗   ███╗ █████╗ ██████╗ ████████╗     ██████╗ █████╗ ███╗   ███╗██████╗ ██╗   ██╗███████╗\n";
cout << "██╔════╝████╗ ████║██╔══██╗██╔══██╗╚══██╔══╝    ██╔════╝██╔══██╗████╗ ████║██╔══██╗██║   ██║██╔════╝\n";
cout << "███████╗██╔████╔██║███████║██████╔╝   ██║       ██║     ███████║██╔████╔██║██████╔╝██║   ██║███████╗\n";
cout << "╚════██║██║╚██╔╝██║██╔══██║██╔══██╗   ██║       ██║     ██╔══██║██║╚██╔╝██║██╔═══╝ ██║   ██║╚════██║\n";
cout << "███████║██║ ╚═╝ ██║██║  ██║██║  ██║   ██║       ╚██████╗██║  ██║██║ ╚═╝ ██║██║     ╚██████╔╝███████║\n";
cout << "╚══════╝╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝        ╚═════╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝      ╚═════╝ ╚══════╝\n";
cout << "\n";

    cout << "███╗   ███╗ █████╗ ███╗   ██╗ █████╗  ██████╗ ███████╗███╗   ███╗███████╗███╗   ██╗████████╗\n";
    cout << "████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔════╝ ██╔════╝████╗ ████║██╔════╝████╗  ██║╚══██╔══╝\n";
    cout << "██╔████╔██║███████║██╔██╗ ██║███████║██║  ███╗█████╗  ██╔████╔██║█████╗  ██╔██╗ ██║   ██║   \n";
    cout << "██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██╔══╝  ██║╚██╔╝██║██╔══╝  ██║╚██╗██║   ██║   \n";
    cout << "██║ ╚═╝ ██║██║  ██║██║ ╚████║██║  ██║╚██████╔╝███████╗██║ ╚═╝ ██║███████╗██║ ╚████║   ██║   \n";
    cout << "╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝   \n";
    cout << "\n";
    cout << "███████╗██╗   ██╗███████╗████████╗███████╗███╗   ███╗\n";
    cout << "██╔════╝╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔════╝████╗ ████║\n";
    cout << "███████╗ ╚████╔╝ ███████╗   ██║   █████╗  ██╔████╔██║\n";
    cout << "╚════██║  ╚██╔╝  ╚════██║   ██║   ██╔══╝  ██║╚██╔╝██║\n";
    cout << "███████║   ██║   ███████║   ██║   ███████╗██║ ╚═╝ ██║\n";
    cout << "╚══════╝   ╚═╝   ╚══════╝   ╚═╝   ╚══════╝╚═╝     ╚═╝\n";
    cout << RESET << "\n";
    cout << BRIGHT_YELLOW << "                    🎓 Welcome to Smart Campus Management System 🎓" << RESET << "\n";
    cout << BRIGHT_GREEN << "                         Making Education Management Smarter!" << RESET << "\n\n";
}

void printStudentBanner() {
    cout << BRIGHT_BLUE << BOLD << "\n";
    cout << "███████╗████████╗██╗   ██╗██████╗ ███████╗███╗   ██╗████████╗\n";
    cout << "██╔════╝╚══██╔══╝██║   ██║██╔══██╗██╔════╝████╗  ██║╚══██╔══╝\n";
    cout << "███████╗   ██║   ██║   ██║██║  ██║█████╗  ██╔██╗ ██║   ██║   \n";
    cout << "╚════██║   ██║   ██║   ██║██║  ██║██╔══╝  ██║╚██╗██║   ██║   \n";
    cout << "███████║   ██║   ╚██████╔╝██████╔╝███████╗██║ ╚████║   ██║   \n";
    cout << "╚══════╝   ╚═╝    ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝   ╚═╝   \n";
    cout << "\n";
    cout << "██████╗  ██████╗ ██████╗ ████████╗ █████╗ ██╗     \n";
    cout << "██╔══██╗██╔═══██╗██╔══██╗╚══██╔══╝██╔══██╗██║     \n";
    cout << "██████╔╝██║   ██║██████╔╝   ██║   ███████║██║     \n";
    cout << "██╔═══╝ ██║   ██║██╔══██╗   ██║   ██╔══██║██║     \n";
    cout << "██║     ╚██████╔╝██║  ██║   ██║   ██║  ██║███████╗\n";
    cout << "╚═╝      ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝\n";
    cout << RESET << "\n";
    cout << BRIGHT_YELLOW << "                    📚 Student Dashboard 📚" << RESET << "\n\n";
}

void printFacultyBanner() {
    cout << BRIGHT_GREEN << BOLD << "\n";
    cout << "███████╗ █████╗  ██████╗██╗   ██╗██╗  ████████╗██╗   ██╗\n";
    cout << "██╔════╝██╔══██╗██╔════╝██║   ██║██║  ╚══██╔══╝╚██╗ ██╔╝\n";
    cout << "█████╗  ███████║██║     ██║   ██║██║     ██║    ╚████╔╝ \n";
    cout << "██╔══╝  ██╔══██║██║     ██║   ██║██║     ██║     ╚██╔╝  \n";
    cout << "██║     ██║  ██║╚██████╗╚██████╔╝███████╗██║      ██║   \n";
    cout << "╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝      ╚═╝   \n";
    cout << "\n";
    cout << "██████╗  ██████╗ ██████╗ ████████╗ █████╗ ██╗     \n";
    cout << "██╔══██╗██╔═══██╗██╔══██╗╚══██╔══╝██╔══██╗██║     \n";
    cout << "██████╔╝██║   ██║██████╔╝   ██║   ███████║██║     \n";
    cout << "██╔═══╝ ██║   ██║██╔══██╗   ██║   ██╔══██║██║     \n";
    cout << "██║     ╚██████╔╝██║  ██║   ██║   ██║  ██║███████╗\n";
    cout << "╚═╝      ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝\n";
    cout << RESET << "\n";
    cout << BRIGHT_YELLOW << "                    🏫 Faculty Dashboard 🏫" << RESET << "\n\n";
}

void printAdminBanner() {
    cout << BRIGHT_MAGENTA << BOLD << "\n";
    cout << " █████╗ ██████╗ ███╗   ███╗██╗███╗   ██╗\n";
    cout << "██╔══██╗██╔══██╗████╗ ████║██║████╗  ██║\n";
    cout << "███████║██║  ██║██╔████╔██║██║██╔██╗ ██║\n";
    cout << "██╔══██║██║  ██║██║╚██╔╝██║██║██║╚██╗██║\n";
    cout << "██║  ██║██████╔╝██║ ╚═╝ ██║██║██║ ╚████║\n";
    cout << "╚═╝  ╚═╝╚═════╝ ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝\n";
    cout << "\n";
    cout << "██████╗  ██████╗ ██████╗ ████████╗ █████╗ ██╗     \n";
    cout << "██╔══██╗██╔═══██╗██╔══██╗╚══██╔══╝██╔══██╗██║     \n";
    cout << "██████╔╝██║   ██║██████╔╝   ██║   ███████║██║     \n";
    cout << "██╔═══╝ ██║   ██║██╔══██╗   ██║   ██╔══██║██║     \n";
    cout << "██║     ╚██████╔╝██║  ██║   ██║   ██║  ██║███████╗\n";
    cout << "╚═╝      ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝\n";
    cout << RESET << "\n";
    cout << BRIGHT_YELLOW << "                    ⚙️  Admin Control Panel ⚙️" << RESET << "\n\n";
}

void printLoginBanner() {
    cout << BRIGHT_CYAN << BOLD << "\n";
    cout << "██╗      ██████╗  ██████╗ ██╗███╗   ██╗\n";
    cout << "██║     ██╔═══██╗██╔════╝ ██║████╗  ██║\n";
    cout << "██║     ██║   ██║██║  ███╗██║██╔██╗ ██║\n";
    cout << "██║     ██║   ██║██║   ██║██║██║╚██╗██║\n";
    cout << "███████╗╚██████╔╝╚██████╔╝██║██║ ╚████║\n";
    cout << "╚══════╝ ╚═════╝  ╚═════╝ ╚═╝╚═╝  ╚═══╝\n";
    cout << RESET << "\n";
    cout << BRIGHT_YELLOW << "           🔐 Please Enter Your Credentials 🔐" << RESET << "\n\n";
}

void printSeparator() {
    cout << BRIGHT_CYAN << "════════════════════════════════════════════════════════════════════════════════\n" << RESET;
}

void printMenuSeparator() {
    cout << BRIGHT_BLUE << "────────────────────────────────────────────────────────────────────────────────\n" << RESET;
}

// Base User class
class User {
protected:
    string username;
    string password;
    string fullName;
    string email;
    string phone;
    string userType;

public:
    User() {}
    User(string u, string p, string fn, string e, string ph, string ut) 
        : username(u), password(p), fullName(fn), email(e), phone(ph), userType(ut) {}

    virtual ~User() {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getFullName() const { return fullName; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
    string getUserType() const { return userType; }



    friend ostream& operator<<(ostream& os, const User& user);
friend bool validateUserCredentials(const User& user);

    void setPassword(string p) { password = p; }
    void setEmail(string e) { email = e; }
    void setPhone(string ph) { phone = ph; }

    virtual void displayInfo() const {
        cout << BRIGHT_CYAN << "👤 USER PROFILE" << RESET << "\n";
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "Username: " << BRIGHT_WHITE << username << RESET << endl;
        cout << BRIGHT_YELLOW << "Name: " << BRIGHT_WHITE << fullName << RESET << endl;
        cout << BRIGHT_YELLOW << "Email: " << BRIGHT_WHITE << email << RESET << endl;
        cout << BRIGHT_YELLOW << "Phone: " << BRIGHT_WHITE << phone << RESET << endl;
        cout << BRIGHT_YELLOW << "Type: " << BRIGHT_GREEN << userType << RESET << endl;
        printMenuSeparator();
    }

    virtual string serialize() const {
        return username + "|" + password + "|" + fullName + "|" + email + "|" + phone + "|" + userType;
    }
};

ostream& operator<<(ostream& os, const User& user) {
    os << BRIGHT_CYAN << "USER PROFILE" << RESET << "\n";
    os << "Username: " << user.username << "\n";
    os << "Name: " << user.fullName << "\n";
    os << "Email: " << user.email << "\n";
    os << "Type: " << user.userType << "\n";
    return os;
}
bool validateUserCredentials(const User& user) {
    // Email validation
    size_t at_pos = user.email.find('@');
    size_t dot_pos = user.email.find('.', at_pos);
    
    if (at_pos == string::npos || dot_pos == string::npos) {
        throw ValidationException("Invalid email format for user: " + user.username);
    }
    
    // Password strength check
    if (user.password.length() < 6) {
        throw ValidationException("Password too weak (min 6 characters) for user: " + user.username);
    }
    
    // Username validation (alphanumeric only)
    for (char c : user.username) {
        if (!isalnum(c) && c != '_') {
            throw ValidationException("Username can only contain letters, numbers, and underscores");
        }
    }
    
    return true;
}

// Student class
class Student : public User {
private:
    string studentId;
    string department;
    int semester;
    double gpa;

public:
    Student() : User(), semester(1), gpa(0.0) {}
    Student(string u, string p, string fn, string e, string ph, string sid, string dept, int sem = 1) 
        : User(u, p, fn, e, ph, "STUDENT"), studentId(sid), department(dept), semester(sem), gpa(0.0) {}

    string getStudentId() const { return studentId; }
    string getDepartment() const { return department; }
    int getSemester() const { return semester; }
    double getGPA() const { return gpa; }

    void setSemester(int s) { semester = s; }
    void setGPA(double g) { gpa = g; }

    void displayInfo() const override {
        cout << BRIGHT_BLUE << "📚 STUDENT PROFILE" << RESET << "\n";
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "Username: " << BRIGHT_WHITE << username << RESET << endl;
        cout << BRIGHT_YELLOW << "Name: " << BRIGHT_WHITE << fullName << RESET << endl;
        cout << BRIGHT_YELLOW << "Email: " << BRIGHT_WHITE << email << RESET << endl;
        cout << BRIGHT_YELLOW << "Phone: " << BRIGHT_WHITE << phone << RESET << endl;
        cout << BRIGHT_YELLOW << "Student ID: " << BRIGHT_CYAN << studentId << RESET << endl;
        cout << BRIGHT_YELLOW << "Department: " << BRIGHT_GREEN << department << RESET << endl;
        cout << BRIGHT_YELLOW << "Semester: " << BRIGHT_MAGENTA << semester << RESET << endl;
        cout << BRIGHT_YELLOW << "GPA: " << BRIGHT_GREEN << fixed << setprecision(2) << gpa << RESET << endl;
        printMenuSeparator();
    }

   std::string serialize() const override {
        return User::serialize() + "|" + studentId + "|" + department + "|" + to_string(semester) + "|" + to_string(gpa);
    }

};

// Faculty class
class Faculty : public User {
private:
    string facultyId;
    string department;
    string designation;
    double salary;

public:
    Faculty() : User(), salary(0.0) {}
    Faculty(string u, string p, string fn, string e, string ph, string fid, string dept, string desig, double sal = 0.0) 
        : User(u, p, fn, e, ph, "FACULTY"), facultyId(fid), department(dept), designation(desig), salary(sal) {}

    string getFacultyId() const { return facultyId; }
    string getDepartment() const { return department; }
    string getDesignation() const { return designation; }
    double getSalary() const { return salary; }

    void setSalary(double s) { salary = s; }

    void displayInfo() const override {
        cout << BRIGHT_GREEN << "🏫 FACULTY PROFILE" << RESET << "\n";
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "Username: " << BRIGHT_WHITE << username << RESET << endl;
        cout << BRIGHT_YELLOW << "Name: " << BRIGHT_WHITE << fullName << RESET << endl;
        cout << BRIGHT_YELLOW << "Email: " << BRIGHT_WHITE << email << RESET << endl;
        cout << BRIGHT_YELLOW << "Phone: " << BRIGHT_WHITE << phone << RESET << endl;
        cout << BRIGHT_YELLOW << "Faculty ID: " << BRIGHT_CYAN << facultyId << RESET << endl;
        cout << BRIGHT_YELLOW << "Department: " << BRIGHT_GREEN << department << RESET << endl;
        cout << BRIGHT_YELLOW << "Designation: " << BRIGHT_MAGENTA << designation << RESET << endl;
        cout << BRIGHT_YELLOW << "Salary: " << BRIGHT_GREEN << "$" << fixed << setprecision(2) << salary << RESET << endl;
        printMenuSeparator();
    }

   string serialize() const override {
        return User::serialize() + "|" + facultyId + "|" + department + "|" + designation + "|" + to_string(salary);
    }
};

// Admin class
class Admin : public User {
private:
    string adminId;
    string accessLevel;

public:
    Admin() : User() {}
    Admin(string u, string p, string fn, string e, string ph, string aid, string access) 
        : User(u, p, fn, e, ph, "ADMIN"), adminId(aid), accessLevel(access) {}

    string getAdminId() const { return adminId; }
    string getAccessLevel() const { return accessLevel; }

    void displayInfo() const override {
        cout << BRIGHT_MAGENTA << "⚙️  ADMIN PROFILE" << RESET << "\n";
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "Username: " << BRIGHT_WHITE << username << RESET << endl;
        cout << BRIGHT_YELLOW << "Name: " << BRIGHT_WHITE << fullName << RESET << endl;
        cout << BRIGHT_YELLOW << "Email: " << BRIGHT_WHITE << email << RESET << endl;
        cout << BRIGHT_YELLOW << "Phone: " << BRIGHT_WHITE << phone << RESET << endl;
        cout << BRIGHT_YELLOW << "Admin ID: " << BRIGHT_CYAN << adminId << RESET << endl;
        cout << BRIGHT_YELLOW << "Access Level: " << BRIGHT_RED << accessLevel << RESET << endl;
        printMenuSeparator();
    }

    string serialize() const override {
        return User::serialize() + "|" + adminId + "|" + accessLevel;
    }
};

// Course class
class Course {
public:
    string courseId;
    string courseName;
    string department;
    int credits;
    int maxCapacity;
    int currentEnrollment;
    string instructor;
    string schedule;
    double fee;

public:
    Course() : credits(0), maxCapacity(0), currentEnrollment(0), fee(0.0) {}
    Course(string id, string name, string dept, int cred, int cap, string inst, string sched, double f) 
        : courseId(id), courseName(name), department(dept), credits(cred), maxCapacity(cap), 
          currentEnrollment(0), instructor(inst), schedule(sched), fee(f) {}

    string getCourseId() const { return courseId; }
    string getCourseName() const { return courseName; }
    string getDepartment() const { return department; }
    int getCredits() const { return credits; }
    int getMaxCapacity() const { return maxCapacity; }
    int getCurrentEnrollment() const { return currentEnrollment; }
    string getInstructor() const { return instructor; }
    string getSchedule() const { return schedule; }
    double getFee() const { return fee; }

    friend ostream& operator<<(ostream& os, const Course& course);
friend double calculateTotalRevenue(const vector<Course>& courses);

    bool enrollStudent() {
        if (currentEnrollment < maxCapacity) {
            currentEnrollment++;
            return true;
        }
        return false;
    }

    bool dropStudent() {
        if (currentEnrollment > 0) {
            currentEnrollment--;
            return true;
        }
        return false;
    }

    void displayInfo() const {
        cout << BRIGHT_CYAN << "📚 COURSE INFORMATION" << RESET << "\n";
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "Course ID: " << BRIGHT_WHITE << courseId << RESET << endl;
        cout << BRIGHT_YELLOW << "Course Name: " << BRIGHT_GREEN << courseName << RESET << endl;
        cout << BRIGHT_YELLOW << "Department: " << BRIGHT_BLUE << department << RESET << endl;
        cout << BRIGHT_YELLOW << "Credits: " << BRIGHT_MAGENTA << credits << RESET << endl;
        cout << BRIGHT_YELLOW << "Capacity: " << BRIGHT_CYAN << currentEnrollment << "/" << maxCapacity << RESET << endl;
        cout << BRIGHT_YELLOW << "Instructor: " << BRIGHT_GREEN << instructor << RESET << endl;
        cout << BRIGHT_YELLOW << "Schedule: " << BRIGHT_BLUE << schedule << RESET << endl;
        cout << BRIGHT_YELLOW << "Fee: " << BRIGHT_GREEN << "$" << fixed << setprecision(2) << fee << RESET << endl;
        printMenuSeparator();
    }

     string serialize() const {
        return courseId + "|" + courseName + "|" + department + "|" + to_string(credits) + "|" + 
               to_string(maxCapacity) + "|" + to_string(currentEnrollment) + "|" + instructor + "|" + 
               schedule + "|" + to_string(fee);
    }
};

ostream& operator<<(ostream& os, const Course& course) {
    os << BRIGHT_CYAN << "COURSE INFORMATION" << RESET << "\n";
    os << "Course ID: " << course.courseId << "\n";
    os << "Course Name: " << course.courseName << "\n";
    os << "Department: " << course.department << "\n";
    os << "Enrollment: " << course.currentEnrollment << "/" << course.maxCapacity << "\n";
    return os;
}

double calculateTotalRevenue(const vector<Course>& courses) {
    double total = 0.0;
    for (const auto& course : courses) {
        total += course.fee * course.currentEnrollment;
    }
    return total;
}

// Enrollment class
class Enrollment {
private:
    string studentId;
    string courseId;
    string enrollmentDate;
    string status;

public:
    Enrollment() {}
    Enrollment(string sid, string cid, string date, string stat) 
        : studentId(sid), courseId(cid), enrollmentDate(date), status(stat) {}

    string getStudentId() const { return studentId; }
    string getCourseId() const { return courseId; }
    string getEnrollmentDate() const { return enrollmentDate; }
    string getStatus() const { return status; }

    void setStatus(string s) { status = s; }

    string serialize() const {
        return studentId + "|" + courseId + "|" + enrollmentDate + "|" + status;
    }
};

// Bill class
class Bill {
private:
    string studentId;
    string description;
    double amount;
    string status;
    string dueDate;

public:
    Bill() : amount(0.0) {}
    Bill(string sid, string desc, double amt, string stat, string due) 
        : studentId(sid), description(desc), amount(amt), status(stat), dueDate(due) {}

    string getStudentId() const { return studentId; }
    string getDescription() const { return description; }
    double getAmount() const { return amount; }
    string getStatus() const { return status; }
    string getDueDate() const { return dueDate; }

    void setStatus(string s) { status = s; }

    void displayInfo() const {
        cout << BRIGHT_YELLOW << "💰 BILL INFORMATION" << RESET << "\n";
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "Student ID: " << BRIGHT_WHITE << studentId << RESET << endl;
        cout << BRIGHT_YELLOW << "Description: " << BRIGHT_CYAN << description << RESET << endl;
        cout << BRIGHT_YELLOW << "Amount: " << BRIGHT_GREEN << "$" << fixed << setprecision(2) << amount << RESET << endl;
        cout << BRIGHT_YELLOW << "Status: " << (status == "PENDING" ? BRIGHT_RED : BRIGHT_GREEN) << status << RESET << endl;
        cout << BRIGHT_YELLOW << "Due Date: " << BRIGHT_BLUE << dueDate << RESET << endl;
        printMenuSeparator();
    }

  string serialize() const {
        return studentId + "|" + description + "|" + to_string(amount) + "|" + status + "|" + dueDate;
    }
};

// Attendance class
class Attendance {
private:
    string studentId;
    string courseId;
    string date;
    string status;

public:
    Attendance() {}
    Attendance(string sid, string cid, string d, string stat) 
        : studentId(sid), courseId(cid), date(d), status(stat) {}

    string getStudentId() const { return studentId; }
    string getCourseId() const { return courseId; }
    string getDate() const { return date; }
    string getStatus() const { return status; }

    string serialize() const {
        return studentId + "|" + courseId + "|" + date + "|" + status;
    }
};

// ID Card class
class IDCard {
private:
    string cardId;
    string studentId;
    string studentName;
    string department;
    string email;
    string phone;
    string issueDate;
    string expiryDate;
    string status;
    string photoPath;

public:
    IDCard() {}
    IDCard(string cid, string sid, string name, string dept, string em, string ph, 
           string issue, string expiry, string stat = "ACTIVE") 
        : cardId(cid), studentId(sid), studentName(name), department(dept), 
          email(em), phone(ph), issueDate(issue), expiryDate(expiry), 
          status(stat), photoPath("default_photo.jpg") {}

    string getCardId() const { return cardId; }
    string getStudentId() const { return studentId; }
    string getStudentName() const { return studentName; }
    string getDepartment() const { return department; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
    string getIssueDate() const { return issueDate; }
    string getExpiryDate() const { return expiryDate; }
    string getStatus() const { return status; }

    void setStatus(string s) { status = s; }

    void displayCard() const {
        system("cls");
        

        cout << BRIGHT_WHITE << "╔══════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║" << BRIGHT_CYAN << "                        SMART CAMPUS UNIVERSITY                              " << BRIGHT_WHITE << "║\n";
        cout << "║" << BRIGHT_YELLOW << "                            STUDENT ID CARD                                  " << BRIGHT_WHITE << "║\n";
        cout << "╠══════════════════════════════════════════════════════════════════════════════╣\n";
        cout << "║                                                                              ║\n";
        cout << "║  " << BRIGHT_CYAN << "┌─────────────┐" << BRIGHT_WHITE << "  " << BRIGHT_YELLOW << "Name: " << BRIGHT_GREEN << left << setw(35) << studentName << BRIGHT_WHITE << " ║\n";
        cout << "║  " << BRIGHT_CYAN << "│             │" << BRIGHT_WHITE << "  " << BRIGHT_YELLOW << "ID: " << BRIGHT_GREEN << left << setw(37) << studentId << BRIGHT_WHITE << " ║\n";
        cout << "║  " << BRIGHT_CYAN << "│   STUDENT   │" << BRIGHT_WHITE << "  " << BRIGHT_YELLOW << "Department: " << BRIGHT_GREEN << left << setw(30) << department << BRIGHT_WHITE << " ║\n";
        cout << "║  " << BRIGHT_CYAN << "│    PHOTO    │" << BRIGHT_WHITE << "  " << BRIGHT_YELLOW << "Email: " << BRIGHT_GREEN << left << setw(34) << email << BRIGHT_WHITE << " ║\n";
        cout << "║  " << BRIGHT_CYAN << "│             │" << BRIGHT_WHITE << "  " << BRIGHT_YELLOW << "Phone: " << BRIGHT_GREEN << left << setw(34) << phone << BRIGHT_WHITE << " ║\n";
        cout << "║  " << BRIGHT_CYAN << "│             │" << BRIGHT_WHITE << "                                             ║\n";
        cout << "║  " << BRIGHT_CYAN << "└─────────────┘" << BRIGHT_WHITE << "  " << BRIGHT_YELLOW << "Card ID: " << BRIGHT_MAGENTA << left << setw(32) << cardId << BRIGHT_WHITE << " ║\n";
        cout << "║                            " << BRIGHT_YELLOW << "Issue Date: " << BRIGHT_BLUE << left << setw(29) << issueDate << BRIGHT_WHITE << " ║\n";
        cout << "║  " << BRIGHT_RED << "▀▀▀▀▀▀▀▀▀▀▀▀▀" << BRIGHT_WHITE << "  " << BRIGHT_YELLOW << "Expiry Date: " << BRIGHT_RED << left << setw(28) << expiryDate << BRIGHT_WHITE << " ║\n";
        cout << "║  " << BRIGHT_RED << "AUTHORIZED ID " << BRIGHT_WHITE << "  " << BRIGHT_YELLOW << "Status: " << (status == "ACTIVE" ? BRIGHT_GREEN : BRIGHT_RED) << left << setw(33) << status << BRIGHT_WHITE << " ║\n";
        cout << "║  " << BRIGHT_RED << "▄▄▄▄▄▄▄▄▄▄▄▄▄" << BRIGHT_WHITE << "                                             ║\n";
        cout << "║                                                                              ║\n";
        cout << "║  " << BRIGHT_BLUE << "🏫 This card is property of Smart Campus University               " << BRIGHT_WHITE << "   ║\n";
        cout << "║  " << BRIGHT_BLUE << "📞 Contact: +1-800-CAMPUS | 🌐 www.smartcampus.edu              " << BRIGHT_WHITE << "   ║\n";
        cout << "║                                                                              ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════════════╝\n";
        cout << RESET;
    }

    void displayInfo() const {
        cout << BRIGHT_CYAN << "🆔 ID CARD INFORMATION" << RESET << "\n";
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "Card ID: " << BRIGHT_WHITE << cardId << RESET << endl;
        cout << BRIGHT_YELLOW << "Student ID: " << BRIGHT_CYAN << studentId << RESET << endl;
        cout << BRIGHT_YELLOW << "Name: " << BRIGHT_GREEN << studentName << RESET << endl;
        cout << BRIGHT_YELLOW << "Department: " << BRIGHT_BLUE << department << RESET << endl;
        cout << BRIGHT_YELLOW << "Email: " << BRIGHT_WHITE << email << RESET << endl;
        cout << BRIGHT_YELLOW << "Phone: " << BRIGHT_WHITE << phone << RESET << endl;
        cout << BRIGHT_YELLOW << "Issue Date: " << BRIGHT_BLUE << issueDate << RESET << endl;
        cout << BRIGHT_YELLOW << "Expiry Date: " << BRIGHT_RED << expiryDate << RESET << endl;
        cout << BRIGHT_YELLOW << "Status: " << (status == "ACTIVE" ? BRIGHT_GREEN : BRIGHT_RED) << status << RESET << endl;
        printMenuSeparator();
    }

    string serialize() const {
        return cardId + "|" + studentId + "|" + studentName + "|" + department + "|" + 
               email + "|" + phone + "|" + issueDate + "|" + expiryDate + "|" + status;
    }
};

// FileIO class for handling file operations
class FileIO {
public:
    static vector<string> readFile(const string& filename) {
        vector<string> lines;
        ifstream file(filename.c_str());
        string line;

        if (file.is_open()) {
            while (getline(file, line)) {
                if (!line.empty()) {
                    lines.push_back(line);
                }
            }
            file.close();
        }
        return lines;
    }

    static void writeFile(const string& filename, const vector<string>& lines) {
        ofstream file(filename.c_str());
        if (file.is_open()) {
            for (size_t i = 0; i < lines.size(); ++i) {
                file << lines[i] << endl;
            }
            file.close();
        }
    }

    static void appendToFile(const string& filename, const string& line) {
        ofstream file(filename.c_str(), ios::app);
        if (file.is_open()) {
            file << line << endl;
            file.close();
        }
    }

    static vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        stringstream ss(str);
        string token;

        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static string getCurrentDateTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        string dateTime(dt);
        if (!dateTime.empty()) dateTime.erase(dateTime.size() - 1); // Remove newline
        return dateTime;
    }
};

// Main Campus Management System
class CampusManagementSystem {
private:
    vector<User*> users;
    vector<Course> courses;
    vector<Enrollment> enrollments;
    vector<Bill> bills;
    vector<Attendance> attendanceRecords;
    vector<IDCard> idCards;
    User* currentUser;

public:
    CampusManagementSystem() : currentUser(NULL) {
        loadData();
    }

    ~CampusManagementSystem() {
        saveData();
        for (User* user : users) {
            delete user;
        }
    }

    void loadData() {
        // Create default courses
        courses.push_back(Course("CS101", "Introduction to Programming", "Computer Science", 3, 30, "Dr. Wilson", "Mon/Wed 9:00-10:30", 1200.0));
        courses.push_back(Course("CS201", "Data Structures", "Computer Science", 4, 25, "Dr. Smith", "Tue/Thu 10:00-11:30", 1500.0));
        courses.push_back(Course("CS301", "Database Management Systems", "Computer Science", 3, 20, "Dr. Johnson", "Mon/Wed 2:00-3:30", 1300.0));
        courses.push_back(Course("MATH101", "Calculus I", "Mathematics", 4, 40, "Prof. Brown", "Daily 8:00-9:00", 1000.0));
        courses.push_back(Course("PHY101", "Physics I", "Physics", 3, 35, "Dr. Davis", "Tue/Thu 1:00-2:30", 1100.0));

        // Load additional courses from file
        vector<string> courseLines = FileIO::readFile("courses.dat");
        for (size_t i = 0; i < courseLines.size(); ++i) {
            vector<string> parts = FileIO::split(courseLines[i], '|');
            if (parts.size() >= 9) {
                Course course(parts[0], parts[1], parts[2], atoi(parts[3].c_str()), 
                             atoi(parts[4].c_str()), parts[6], parts[7], atof(parts[8].c_str()));
                course.currentEnrollment = atoi(parts[5].c_str());
                courses.push_back(course);
            }
        }

        // Load ID cards
        vector<string> idCardLines = FileIO::readFile("idcards.dat");
        for (size_t i = 0; i < idCardLines.size(); ++i) {
            vector<string> parts = FileIO::split(idCardLines[i], '|');
            if (parts.size() >= 9) {
                IDCard idCard(parts[0], parts[1], parts[2], parts[3], parts[4], 
                             parts[5], parts[6], parts[7], parts[8]);
                idCards.push_back(idCard);
            }
        }

        // Load enrollments
        vector<string> enrollmentLines = FileIO::readFile("enrollments.dat");
        for (size_t i = 0; i < enrollmentLines.size(); ++i) {
            vector<string> parts = FileIO::split(enrollmentLines[i], '|');
            if (parts.size() >= 4) {
                Enrollment enrollment(parts[0], parts[1], parts[2], parts[3]);
                enrollments.push_back(enrollment);
            }
        }

        // Load bills
        vector<string> billLines = FileIO::readFile("bills.dat");
        for (size_t i = 0; i < billLines.size(); ++i) {
            vector<string> parts = FileIO::split(billLines[i], '|');
            if (parts.size() >= 5) {
                Bill bill(parts[0], parts[1], atof(parts[2].c_str()), parts[3], parts[4]);
                bills.push_back(bill);
            }
        }

        // Create some sample bills for john_doe
        bills.push_back(Bill("STU001", "Course Fee - Introduction to Programming", 1200.0, "PENDING", "2024-02-15"));
        bills.push_back(Bill("STU001", "Library Fee", 50.0, "PENDING", "2024-02-10"));
        bills.push_back(Bill("STU001", "Lab Fee", 200.0, "PAID", "2024-01-20"));

        // Create default admin user
        users.push_back(new Admin("admin", "admin123", "System Administrator", 
                                 "admin@campus.edu", "000-000-0000", "ADMIN001", "FULL"));

        // Create default student user
        users.push_back(new Student("john_doe", "password123", "John Doe", 
                                   "john@campus.edu", "123-456-7890", "STU001", "Computer Science", 1));

        // Create default faculty user
        users.push_back(new Faculty("dr_wilson", "teacher123", "Dr. Wilson", 
                                   "wilson@campus.edu", "555-123-4567", "FAC001", "Computer Science", "Professor", 75000.0));
    }

    void saveData() {
        // Save courses
        vector<string> courseLines;
        for (size_t i = 0; i < courses.size(); ++i) {
            courseLines.push_back(courses[i].serialize());
        }
        FileIO::writeFile("courses.dat", courseLines);

        // Save enrollments
        vector<string> enrollmentLines;
        for (size_t i = 0; i < enrollments.size(); ++i) {
            enrollmentLines.push_back(enrollments[i].serialize());
        }
        FileIO::writeFile("enrollments.dat", enrollmentLines);

        // Save bills
        vector<string> billLines;
        for (size_t i = 0; i < bills.size(); ++i) {
            billLines.push_back(bills[i].serialize());
        }
        FileIO::writeFile("bills.dat", billLines);

        // Save users
        vector<string> userLines;
        for (size_t i = 0; i < users.size(); ++i) {
            userLines.push_back(users[i]->serialize());
        }
        FileIO::writeFile("users.dat", userLines);

        // Save ID cards
        vector<string> idCardLines;
        for (size_t i = 0; i < idCards.size(); ++i) {
    idCardLines.push_back(idCards[i].serialize());
}

        FileIO::writeFile("idcards.dat", idCardLines);
    }

  
    bool login(const string& username, const string& password) {
    try {
        if (username.empty() || password.empty()) {
            throw ValidationException("Username and password cannot be empty");
        }
        
        for (size_t i = 0; i < users.size(); ++i) {
            User* user = users[i];
            if (user->getUsername() == username && user->getPassword() == password) {
                currentUser = user;
                return true;
            }
        }
        throw AuthenticationException("Invalid username or password");
    }
    catch (const exception& e) {
        cerr << BRIGHT_RED << "Login Error: " << e.what() << RESET << endl;
        return false;
    }
}


    void logout() {
        currentUser = NULL;
          system("cls");
    }

    void displayMainMenu() {
          system("cls");
        
        
        printMainBanner();
        printSeparator();
        cout << BRIGHT_WHITE << BOLD << "                              🚀 MAIN MENU 🚀\n" << RESET;
        printSeparator();
        cout << BRIGHT_GREEN << "   [1] " << BRIGHT_BLUE << "📚 Student Portal" << RESET << "       " 
             << BRIGHT_GREEN << "[2] " << BRIGHT_GREEN << "🏫 Faculty Portal" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [3] " << BRIGHT_MAGENTA << "⚙️  Admin Portal" << RESET << "        " 
             << BRIGHT_GREEN << "[4] " << BRIGHT_CYAN << "📋 View All Courses" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [5] " << BRIGHT_RED << "🚪 Exit" << RESET << "\n\n";
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "   Enter your choice: " << BRIGHT_WHITE;
    }

    void displayStudentMenu() {
          system("cls");
   
        printStudentBanner();
        printSeparator();
        cout << BRIGHT_WHITE << BOLD << "                           🎯 STUDENT DASHBOARD 🎯\n" << RESET;
        printSeparator();
        cout << BRIGHT_GREEN << "   [1] " << BRIGHT_CYAN << "👤 View Profile" << RESET << "         " 
             << BRIGHT_GREEN << "[2] " << BRIGHT_BLUE << "📝 Enroll in Course" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [3] " << BRIGHT_MAGENTA << "📚 View Enrollments" << RESET << "     " 
             << BRIGHT_GREEN << "[4] " << BRIGHT_YELLOW << "💰 View Bills" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [5] " << BRIGHT_GREEN << "💳 Pay Bill" << RESET << "             " 
             << BRIGHT_GREEN << "[6] " << BRIGHT_CYAN << "📊 View Attendance" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [7] " << BRIGHT_MAGENTA << "🆔 Generate ID Card" << RESET << "     " 
             << BRIGHT_GREEN << "[8] " << BRIGHT_BLUE << "🎫 View ID Card" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [9] " << BRIGHT_RED << "🚪 Logout" << RESET << "\n\n";
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "   Enter your choice: " << BRIGHT_WHITE;
    }

    void displayFacultyMenu() {
          system("cls");
        printFacultyBanner();
        printSeparator();
        cout << BRIGHT_WHITE << BOLD << "                          🎯 FACULTY DASHBOARD 🎯\n" << RESET;
        printSeparator();
        cout << BRIGHT_GREEN << "   [1] " << BRIGHT_CYAN << "👤 View Profile" << RESET << "         " 
             << BRIGHT_GREEN << "[2] " << BRIGHT_BLUE << "📚 View Teaching Courses" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [3] " << BRIGHT_MAGENTA << "✅ Mark Attendance" << RESET << "      " 
             << BRIGHT_GREEN << "[4] " << BRIGHT_YELLOW << "👥 View Student List" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [5] " << BRIGHT_RED << "🚪 Logout" << RESET << "\n\n";
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "   Enter your choice: " << BRIGHT_WHITE;
    }

    void displayAdminMenu() {
          system("cls");
        printAdminBanner();
        printSeparator();
        cout << BRIGHT_WHITE << BOLD << "                          🎯 ADMIN CONTROL PANEL 🎯\n" << RESET;
        printSeparator();
        cout << BRIGHT_GREEN << "   [1] " << BRIGHT_CYAN << "➕ Add New Course" << RESET << "       " 
             << BRIGHT_GREEN << "[2] " << BRIGHT_BLUE << "👤 Add New User" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [3] " << BRIGHT_MAGENTA << "👥 View All Users" << RESET << "       " 
             << BRIGHT_GREEN << "[4] " << BRIGHT_YELLOW << "📚 View All Courses" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [5] " << BRIGHT_CYAN << "📊 Generate Reports" << RESET << "     " 
             << BRIGHT_GREEN << "[6] " << BRIGHT_BLUE << "🆔 Manage ID Cards" << RESET << "\n";
             cout << BRIGHT_GREEN << "   [7] " << BRIGHT_GREEN << "💾 Save Data" << RESET << "           ";
        cout << BRIGHT_GREEN << "   [8] " << BRIGHT_RED << "🚪 Logout" << RESET << "\n\n";
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "   Enter your choice: " << BRIGHT_WHITE;
    }

    void enrollStudentInCourse() {
    try {
        if (!currentUser || currentUser->getUserType() != "STUDENT") {
            throw AuthorizationException("Only students can enroll in courses");
        }

        cout << "\nAvailable Courses:" << endl;
        for (size_t i = 0; i < courses.size(); i++) {
            cout << (i + 1) << ". ";
            courses[i].displayInfo();
            cout << "------------------------" << endl;
        }

        int choice;
        cout << "Enter course number to enroll: ";
        cin >> choice;

        if (choice > 0 && choice <= courses.size()) {
            string studentId = static_cast<Student*>(currentUser)->getStudentId();
            string courseId = courses[choice - 1].getCourseId();

            // Check if already enrolled
            for (size_t i = 0; i < enrollments.size(); ++i) {
                if (enrollments[i].getStudentId() == studentId && 
                    enrollments[i].getCourseId() == courseId) {
                    throw ValidationException("Already enrolled in this course");
                }
            }

            // Try to enroll - this method returns true if successful
            if (courses[choice - 1].enrollStudent()) {
                Enrollment newEnrollment(studentId, courseId, FileIO::getCurrentDateTime(), "ACTIVE");
                enrollments.push_back(newEnrollment);

                // Create bill for course fee
                Bill courseBill(studentId, "Course Fee - " + courses[choice - 1].getCourseName(), 
                               courses[choice - 1].getFee(), "PENDING", FileIO::getCurrentDateTime());
                bills.push_back(courseBill);

                cout << BRIGHT_GREEN << "✅ Successfully enrolled in " << BRIGHT_CYAN 
                     << courses[choice - 1].getCourseName() << BRIGHT_GREEN << "! ✅" << RESET << endl;

                saveData(); 
            } else {
                throw DataException("Course is full");
            }
        } else {
            throw ValidationException("Invalid course selection");
        }
    } catch (const exception& e) {
        cerr << BRIGHT_RED << "Enrollment Error: " << e.what() << RESET << endl;
    }
    
    cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
}

    void viewStudentEnrollments() {
        
    
        if (!currentUser || currentUser->getUserType() != "STUDENT") {
            cout << "Access denied!" << endl;
            return;
        }

        string studentId = static_cast<Student*>(currentUser)->getStudentId();
        cout << "\nYour Enrollments:" << endl;

        for (size_t i = 0; i < enrollments.size(); ++i) {
            const Enrollment& enrollment = enrollments[i];
            if (enrollment.getStudentId() == studentId) {
                for (size_t j = 0; j < courses.size(); ++j) {
                    const Course& course = courses[j];
                    if (course.getCourseId() == enrollment.getCourseId()) {
                        cout << "Course: " << course.getCourseName() << endl;
                        cout << "Status: " << enrollment.getStatus() << endl;
                        cout << "Enrolled: " << enrollment.getEnrollmentDate() << endl;
                        cout << "------------------------" << endl;
                        break;
                    }
                }
            }
        }
        // Add at the end:
    cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
      system("cls");
    }

    void viewStudentBills() {
        
     system("cls");
        if (!currentUser || currentUser->getUserType() != "STUDENT") {
            cout << "Access denied!" << endl;
            return;
        }

        string studentId = static_cast<Student*>(currentUser)->getStudentId();
        cout << "\nYour Bills:" << endl;

        for (size_t i = 0; i < bills.size(); ++i) {
            const Bill& bill = bills[i];
            if (bill.getStudentId() == studentId) {
                bill.displayInfo();
                cout << "------------------------" << endl;
            }
        }
        // Add at the end:
    cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
      system("cls");
    }

    void payBill() {
        
        if (!currentUser || currentUser->getUserType() != "STUDENT") {
            cout << "Access denied!" << endl;
            return;
        }

        string studentId = static_cast<Student*>(currentUser)->getStudentId();
        cout << "\nPending Bills:" << endl;

        vector<int> pendingBills;
        for (size_t i = 0; i < bills.size(); i++) {
            if (bills[i].getStudentId() == studentId && bills[i].getStatus() == "PENDING") {
                cout << (pendingBills.size() + 1) << ". ";
                bills[i].displayInfo();
                cout << "------------------------" << endl;
                pendingBills.push_back(i);
            }
        }

        if (pendingBills.empty()) {
            cout << "No pending bills!" << endl;
            return;
        }

        int choice;
        cout << "Enter bill number to pay: ";
        cin >> choice;

        if (choice > 0 && choice <= pendingBills.size()) {
            bills[pendingBills[choice - 1]].setStatus("PAID");
            cout << "Payment successful!" << endl;

            saveData(); 
        } else {
            cout << "Invalid choice!" << endl;
        }
        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
    }

    void addNewCourse() {
         
        if (!currentUser || currentUser->getUserType() != "ADMIN") {
            cout << "Access denied!" << endl;
            return;
        }

        string courseId, courseName, department, instructor, schedule;
        int credits, capacity;
        double fee;

        cout << "\nEnter Course Details:" << endl;
        cout << "Course ID: ";
        cin >> courseId;
        cin.ignore();
        cout << "Course Name: ";
        getline(cin, courseName);
        cout << "Department: ";
        getline(cin, department);
        cout << "Credits: ";
        cin >> credits;
        cout << "Max Capacity: ";
        cin >> capacity;
        cin.ignore();
        cout << "Instructor: ";
        getline(cin, instructor);
        cout << "Schedule: ";
        getline(cin, schedule);
        cout << "Fee: ";
        cin >> fee;

        Course newCourse(courseId, courseName, department, credits, capacity, instructor, schedule, fee);
        courses.push_back(newCourse);
        cout << "Course added successfully!" << endl;

        saveData(); 
        
    }

    void addNewUser() {
         
        if (!currentUser || currentUser->getUserType() != "ADMIN") {
            cout << "Access denied!" << endl;
            return;
        }

        string username, password, fullName, email, phone;
        int userType;

        cout << "\nEnter User Details:" << endl;
        cout << "Username: ";
        cin >> username;
        cin.ignore();
        cout << "Password: ";
        getline(cin, password);
        cout << "Full Name: ";
        getline(cin, fullName);
        cout << "Email: ";
        getline(cin, email);
        cout << "Phone: ";
        getline(cin, phone);
        cout << "User Type (1-Student, 2-Faculty, 3-Admin): ";
        cin >> userType;
        cin.ignore();

        if (userType == 1) {
            int semester;
            double gpa;
            string studentId, department;
            cout << "Student ID: ";
            getline(cin, studentId);
            cout << "Department: ";
            getline(cin, department);
            cout << "Enter Semester: ";
           cin >> semester;
            cout << "Enter GPA: ";
             cin >> gpa;
            Student* newStudent = new Student(username, password, fullName, email, phone, 
                                        studentId, department, semester);
        newStudent->setGPA(gpa);
        users.push_back(newStudent);
       

        } else if (userType == 2) {
            string facultyId, department, designation;
            double salary;
            cout << "Faculty ID: ";
            getline(cin, facultyId);
            cout << "Department: ";
            getline(cin, department);
            cout << "Designation: ";
            getline(cin, designation);
            cout << "Salary: ";
            cin >> salary;
            users.push_back(new Faculty(username, password, fullName, email, phone, facultyId, department, designation, salary));
        } else if (userType == 3) {
            string adminId, accessLevel;
            cout << "Admin ID: ";
            getline(cin, adminId);
            cout << "Access Level: ";
            getline(cin, accessLevel);
            users.push_back(new Admin(username, password, fullName, email, phone, adminId, accessLevel));
        }
 cout << BRIGHT_GREEN << "✅ User added successfully!" << RESET << endl;
 saveData(); 
 
    }

    void viewAllUsers() {
        
    
        if (!currentUser || currentUser->getUserType() != "ADMIN") {
            cout << "Access denied!" << endl;
            return;
        }

        cout << "\nAll Users:" << endl;
        for (size_t i = 0; i < users.size(); ++i) {
            const User* user = users[i];
            user->displayInfo();
            cout << "------------------------" << endl;
        }
    }

    void viewAllCourses() {
        
     system("cls");
        cout << BRIGHT_CYAN << "\n📚 ALL AVAILABLE COURSES 📚\n" << RESET << endl;
        printSeparator();
        if (courses.empty()) {
            cout << BRIGHT_RED << "❌ No courses available! ❌" << RESET << endl;
            return;
        }

        for (size_t i = 0; i < courses.size(); i++) {
            cout << BRIGHT_GREEN << "Course #" << (i + 1) << RESET << endl;
            courses[i].displayInfo();
            cout << "------------------------" << endl;
        }
    }

    void viewTeachingCourses() {
        
    
        if (!currentUser || currentUser->getUserType() != "FACULTY") {
            cout << "Access denied!" << endl;
            return;
        }

        Faculty* faculty = static_cast<Faculty*>(currentUser);
        cout << BRIGHT_GREEN << "\n🏫 YOUR TEACHING COURSES 🏫\n" << RESET << endl;
        printSeparator();

        bool found = false;
        for (size_t i = 0; i < courses.size(); ++i) {
            const Course& course = courses[i];
            if (course.getInstructor() == faculty->getFullName()) {
                course.displayInfo();
                cout << "------------------------" << endl;
                found = true;
            }
        }

        if (!found) {
            cout << BRIGHT_YELLOW << "⚠️  No courses assigned to you yet. ⚠️" << RESET << endl;
        }
        
    }

    void markAttendance() {
        
        if (!currentUser || currentUser->getUserType() != "FACULTY") {
            cout << "Access denied!" << endl;
            return;
        }

        Faculty* faculty = static_cast<Faculty*>(currentUser);
        cout << BRIGHT_BLUE << "\n✅ MARK ATTENDANCE ✅\n" << RESET << endl;
        printSeparator();

        // Show courses taught by this faculty
        vector<string> teachingCourses;
        for (size_t i = 0; i < courses.size(); ++i) {
            const Course& course = courses[i];
            if (course.getInstructor() == faculty->getFullName()) {
                teachingCourses.push_back(course.getCourseId());
                cout << teachingCourses.size() << ". " << course.getCourseName() 
                     << " (" << course.getCourseId() << ")" << endl;
            }
        }

        if (teachingCourses.empty()) {
            cout << BRIGHT_RED << "❌ No courses assigned to you! ❌" << RESET << endl;
            return;
        }

        int courseChoice;
        cout << "\nSelect course to mark attendance: ";
        cin >> courseChoice;

        if (courseChoice > 0 && courseChoice <= teachingCourses.size()) {
            string selectedCourse = teachingCourses[courseChoice - 1];

            // Show enrolled students
            cout << "\nEnrolled Students:" << endl;
            vector<string> enrolledStudents;

            for (size_t i = 0; i < enrollments.size(); ++i) {
                const Enrollment& enrollment = enrollments[i];
                if (enrollment.getCourseId() == selectedCourse && enrollment.getStatus() == "ACTIVE") {
                    for (size_t j = 0; j < users.size(); ++j) {
                        const User* user = users[j];
                        if (user->getUserType() == "STUDENT") {
                            const Student* student = static_cast<const Student*>(user);
                            if (student->getStudentId() == enrollment.getStudentId()) {
                                enrolledStudents.push_back(enrollment.getStudentId());
                                cout << enrolledStudents.size() << ". " 
                                     << student->getFullName() << " (" 
                                     << student->getStudentId() << ")" << endl;
                                break;
                            }
                        }
                    }
                }
            }

            if (enrolledStudents.empty()) {
                cout << BRIGHT_YELLOW << "⚠️  No students enrolled in this course. ⚠️" << RESET << endl;
                return;
            }

            cout << "\nMarking attendance for today: " << FileIO::getCurrentDateTime() << endl;

            for (size_t i = 0; i < enrolledStudents.size(); ++i) {
                const string& studentId = enrolledStudents[i];
                char status;
                cout << "Student " << studentId << " - Present? (y/n): ";
                cin >> status;

                string attendanceStatus = (status == 'y' || status == 'Y') ? "PRESENT" : "ABSENT";

                Attendance newAttendance(studentId, selectedCourse, FileIO::getCurrentDateTime(), attendanceStatus);
                attendanceRecords.push_back(newAttendance);
            }

            cout << BRIGHT_GREEN << "✅ Attendance marked successfully! ✅" << RESET << endl;
        } else {
            cout << "Invalid choice!" << endl;
        }
        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
    }

    void viewStudentList() {
  
        if (!currentUser || currentUser->getUserType() != "FACULTY") {
            cout << "Access denied!" << endl;
            return;
        }

        Faculty* faculty = static_cast<Faculty*>(currentUser);
        cout << BRIGHT_CYAN << "\n👥 STUDENT LIST 👥\n" << RESET << endl;
        printSeparator();

        // Show students in courses taught by this faculty
        for (size_t courseIdx = 0; courseIdx < courses.size(); ++courseIdx) {
            const Course& course = courses[courseIdx];
            if (course.getInstructor() == faculty->getFullName()) {
                cout << BRIGHT_GREEN << "Course: " << course.getCourseName() 
                     << " (" << course.getCourseId() << ")" << RESET << endl;
                cout << "Enrolled Students:" << endl;

                bool hasStudents = false;
                for (size_t enrollmentIdx = 0; enrollmentIdx < enrollments.size(); ++enrollmentIdx) {
                    const Enrollment& enrollment = enrollments[enrollmentIdx];
                    if (enrollment.getCourseId() == course.getCourseId() && enrollment.getStatus() == "ACTIVE") {
                        for (size_t userIdx = 0; userIdx < users.size(); ++userIdx) {
                            const User* user = users[userIdx];
                            if (user->getUserType() == "STUDENT") {
                                const Student* student = static_cast<const Student*>(user);
                                if (student->getStudentId() == enrollment.getStudentId()) {
                                    cout << "- " << student->getFullName() 
                                         << " (" << student->getStudentId() 
                                         << ", " << student->getEmail() << ")" << endl;
                                    hasStudents = true;
                                    break;
                                }
                            }
                        }
                    }
                }

                if (!hasStudents) {
                    cout << BRIGHT_YELLOW << "  No students enrolled yet." << RESET << endl;
                }
                cout << "------------------------" << endl;
            }
        }
         cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
            cin.get();
    }

    void viewStudentAttendance() {
        
      if (!currentUser || currentUser->getUserType() != "STUDENT") {
            cout << "Access denied!" << endl;
            return;
        }

        Student* student = static_cast<Student*>(currentUser);
        cout << BRIGHT_CYAN << "\n📊 YOUR ATTENDANCE RECORD 📊\n" << RESET << endl;
        printSeparator();

        cout << "Student: " << student->getFullName() << " (" << student->getStudentId() << ")" << endl;
        cout << "------------------------" << endl;

        bool hasRecords = false;
        for (size_t i = 0; i < attendanceRecords.size(); ++i) {
            const Attendance& record = attendanceRecords[i];
            if (record.getStudentId() == student->getStudentId()) {
                // Find course name
                string courseName = "Unknown Course";
                for (size_t j = 0; j < courses.size(); ++j) {
                    const Course& course = courses[j];
                    if (course.getCourseId() == record.getCourseId()) {
                        courseName = course.getCourseName();
                        break;
                    }
                }

                cout << "Course: " << BRIGHT_BLUE << courseName << RESET 
                     << " (" << record.getCourseId() << ")" << endl;
                cout << "Date: " << BRIGHT_YELLOW << record.getDate() << RESET << endl;
                cout << "Status: " << (record.getStatus() == "PRESENT" ? BRIGHT_GREEN : BRIGHT_RED) 
                     << record.getStatus() << RESET << endl;
                cout << "------------------------" << endl;
                hasRecords = true;
            }
        }

        if (!hasRecords) {
            cout << BRIGHT_YELLOW << "⚠️  No attendance records found. ⚠️" << RESET << endl;
        }
    }

    void generateReports() {
         system("cls");
        if (!currentUser || currentUser->getUserType() != "ADMIN") {
            cout << "Access denied!" << endl;
            return;
        }

        cout << BRIGHT_CYAN << BOLD << "\n📊 REPORT GENERATION CENTER 📊\n" << RESET << endl;
        printSeparator();

        cout << BRIGHT_GREEN << "   [1] " << BRIGHT_BLUE << "📈 Enrollment Report" << RESET << "       " 
             << BRIGHT_GREEN << "[2] " << BRIGHT_MAGENTA << "💰 Financial Report" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [3] " << BRIGHT_YELLOW << "📊 Attendance Report" << RESET << "      " 
             << BRIGHT_GREEN << "[4] " << BRIGHT_CYAN << "🏫 Course Statistics" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [5] " << BRIGHT_WHITE << "👥 User Statistics" << RESET << "       " 
             << BRIGHT_GREEN << "[6] " << BRIGHT_GREEN << "📋 Complete System Report" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [7] " << BRIGHT_RED << "🔙 Back to Admin Panel" << RESET << "\n\n";
        printMenuSeparator();

        int choice;
        cout << BRIGHT_YELLOW << "   Select Report Type: " << BRIGHT_WHITE;
        cin >> choice;

        switch (choice) {
            case 1:
                generateEnrollmentReport();
                break;
            case 2:
                generateFinancialReport();
                break;
            case 3:
                generateAttendanceReport();
                break;
            case 4:
                generateCourseStatistics();
                break;
            case 5:
                generateUserStatistics();
                break;
            case 6:
                generateCompleteReport();
                break;
            case 7:
                return;
            default:
                cout << BRIGHT_RED << "❌ Invalid choice!" << RESET << endl;
        }
    }

    void generateEnrollmentReport() {
     
        cout << BRIGHT_BLUE << "\n📈 ENROLLMENT REPORT 📈\n" << RESET << endl;
        printSeparator();

        map<string, int> courseEnrollments;
        map<string, int> departmentEnrollments;

        for (size_t i = 0; i < enrollments.size(); ++i) {
            const Enrollment& enrollment = enrollments[i];
            if (enrollment.getStatus() == "ACTIVE") {
                // Count by course
                for (size_t j = 0; j < courses.size(); ++j) {
                    const Course& course = courses[j];
                    if (course.getCourseId() == enrollment.getCourseId()) {
                        courseEnrollments[course.getCourseName()]++;
                        departmentEnrollments[course.getDepartment()]++;
                        break;
                    }
                }
            }
        }

        cout << BRIGHT_CYAN << "📚 COURSE-WISE ENROLLMENTS:" << RESET << endl;
        printMenuSeparator();
        for (std::map<string, int>::const_iterator it = courseEnrollments.begin(); it != courseEnrollments.end(); ++it) {
            cout << BRIGHT_YELLOW << "• " << it->first << ": " 
                 << BRIGHT_GREEN << it->second << " students" << RESET << endl;
        }

        cout << "\n" << BRIGHT_CYAN << "🏢 DEPARTMENT-WISE ENROLLMENTS:" << RESET << endl;
        printMenuSeparator();
        for (std::map<string, int>::const_iterator it = departmentEnrollments.begin(); it != departmentEnrollments.end(); ++it) {
            cout << BRIGHT_YELLOW << "• " << it->first << ": " 
                 << BRIGHT_GREEN << it->second << " enrollments" << RESET << endl;
        }

        cout << "\n" << BRIGHT_GREEN << "✅ Total Active Enrollments: " 
             << BRIGHT_WHITE << enrollments.size() << RESET << endl;
    }

    void generateFinancialReport() {
      
        cout << BRIGHT_MAGENTA << "\n💰 FINANCIAL REPORT 💰\n" << RESET << endl;
        printSeparator();

        double totalRevenue = 0.0;
        double pendingAmount = 0.0;
        int paidBills = 0;
        int pendingBills = 0;

        for (size_t i = 0; i < bills.size(); ++i) {
            const Bill& bill = bills[i];
            if (bill.getStatus() == "PAID") {
                totalRevenue += bill.getAmount();
                paidBills++;
            } else if (bill.getStatus() == "PENDING") {
                pendingAmount += bill.getAmount();
                pendingBills++;
            }
        }

        cout << BRIGHT_CYAN << "💵 REVENUE SUMMARY:" << RESET << endl;
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "Total Revenue Collected: " 
             << BRIGHT_GREEN << "$" << fixed << setprecision(2) << totalRevenue << RESET << endl;
        cout << BRIGHT_YELLOW << "Pending Amount: " 
             << BRIGHT_RED << "$" << fixed << setprecision(2) << pendingAmount << RESET << endl;
        cout << BRIGHT_YELLOW << "Total Potential Revenue: " 
             << BRIGHT_BLUE << "$" << fixed << setprecision(2) << (totalRevenue + pendingAmount) << RESET << endl;

        cout << "\n" << BRIGHT_CYAN << "📊 BILLING STATISTICS:" << RESET << endl;
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "Paid Bills: " << BRIGHT_GREEN << paidBills << RESET << endl;
        cout << BRIGHT_YELLOW << "Pending Bills: " << BRIGHT_RED << pendingBills << RESET << endl;
        cout << BRIGHT_YELLOW << "Total Bills: " << BRIGHT_WHITE << (paidBills + pendingBills) << RESET << endl;

        if (paidBills + pendingBills > 0) {
            double collectionRate = (double)paidBills / (paidBills + pendingBills) * 100;
            cout << BRIGHT_YELLOW << "Collection Rate: " 
                 << (collectionRate >= 70 ? BRIGHT_GREEN : BRIGHT_YELLOW) 
                 << fixed << setprecision(1) << collectionRate << "%" << RESET << endl;
        }
    }

    void generateAttendanceReport() {
      
        cout << BRIGHT_YELLOW << "\n📊 ATTENDANCE REPORT 📊\n" << RESET << endl;
        printSeparator();

        map<string, pair<int, int> > courseAttendance; // courseName -> (present, total)
        map<string, pair<int, int> > studentAttendance; // studentId -> (present, total)

        for (size_t recordIdx = 0; recordIdx < attendanceRecords.size(); ++recordIdx) {
            const Attendance& record = attendanceRecords[recordIdx];
            // Find course name
            string courseName = "Unknown Course";
            for (size_t courseIdx = 0; courseIdx < courses.size(); ++courseIdx) {
                const Course& course = courses[courseIdx];
                if (course.getCourseId() == record.getCourseId()) {
                    courseName = course.getCourseName();
                    break;
                }
            }

            // Update course attendance
            courseAttendance[courseName].second++; // total
            if (record.getStatus() == "PRESENT") {
                courseAttendance[courseName].first++; // present
            }

            // Update student attendance
            studentAttendance[record.getStudentId()].second++; // total
            if (record.getStatus() == "PRESENT") {
                studentAttendance[record.getStudentId()].first++; // present
            }
        }

        cout << BRIGHT_CYAN << "🏫 COURSE-WISE ATTENDANCE:" << RESET << endl;
        printMenuSeparator();
        for (std::map<string, std::pair<int, int> >::const_iterator it = courseAttendance.begin(); it != courseAttendance.end(); ++it) {
            double percentage = it->second.second > 0 ? 
                (double)it->second.first / it->second.second * 100 : 0;
            cout << BRIGHT_YELLOW << "• " << it->first << ": " 
                 << BRIGHT_WHITE << it->second.first << "/" << it->second.second 
                 << " (" << (percentage >= 75 ? BRIGHT_GREEN : BRIGHT_RED) 
                 << fixed << setprecision(1) << percentage << "%" << BRIGHT_WHITE << ")" << RESET << endl;
        }

        cout << "\n" << BRIGHT_CYAN << "👥 STUDENT ATTENDANCE SUMMARY:" << RESET << endl;
        printMenuSeparator();
        for (std::map<string, std::pair<int, int> >::const_iterator it = studentAttendance.begin(); it != studentAttendance.end(); ++it) {
            double percentage = it->second.second > 0 ? 
                (double)it->second.first / it->second.second * 100 : 0;

            // Find student name
            string studentName = it->first;
            for (size_t u = 0; u < users.size(); ++u) {
                const User* user = users[u];
                if (user->getUserType() == "STUDENT") {
                    const Student* student = static_cast<const Student*>(user);
                    if (student->getStudentId() == it->first) {
                        studentName = student->getFullName() + " (" + it->first + ")";
                        break;
                    }
                }
            }

            cout << BRIGHT_YELLOW << "• " << studentName << ": " 
                 << BRIGHT_WHITE << it->second.first << "/" << it->second.second 
                 << " (" << (percentage >= 75 ? BRIGHT_GREEN : BRIGHT_RED) 
                 << fixed << setprecision(1) << percentage << "%" << BRIGHT_WHITE << ")" << RESET << endl;
        }

        cout << "\n" << BRIGHT_GREEN << "📈 Total Attendance Records: " 
             << BRIGHT_WHITE << attendanceRecords.size() << RESET << endl;
    }

    void generateCourseStatistics() {
        
        cout << BRIGHT_CYAN << "\n🏫 COURSE STATISTICS 🏫\n" << RESET << endl;
        printSeparator();

        cout << BRIGHT_YELLOW << "📚 COURSE OVERVIEW:" << RESET << endl;
        printMenuSeparator();

        int totalCapacity = 0;
        int totalEnrolled = 0;
        double totalRevenue = 0.0;

        for (size_t i = 0; i < courses.size(); ++i) {
            const Course& course = courses[i];
            totalCapacity += course.getMaxCapacity();
            totalEnrolled += course.getCurrentEnrollment();
            totalRevenue += course.getFee() * course.getCurrentEnrollment();

            double utilizationRate = course.getMaxCapacity() > 0 ? 
                (double)course.getCurrentEnrollment() / course.getMaxCapacity() * 100 : 0;

            cout << BRIGHT_CYAN << "• " << course.getCourseName() << RESET << endl;
            cout << "  Course ID: " << BRIGHT_WHITE << course.getCourseId() << RESET << endl;
            cout << "  Department: " << BRIGHT_GREEN << course.getDepartment() << RESET << endl;
            cout << "  Enrollment: " << BRIGHT_YELLOW << course.getCurrentEnrollment() 
                 << "/" << course.getMaxCapacity() << RESET;
            cout << " (" << (utilizationRate >= 70 ? BRIGHT_GREEN : BRIGHT_YELLOW) 
                 << fixed << setprecision(1) << utilizationRate << "%" << BRIGHT_WHITE << ")" << RESET << endl;
            cout << "  Revenue: " << BRIGHT_GREEN << "$" 
                 << fixed << setprecision(2) << (course.getFee() * course.getCurrentEnrollment()) << RESET << endl;
            cout << "  Instructor: " << BRIGHT_BLUE << course.getInstructor() << RESET << endl;
            cout << "  Schedule: " << BRIGHT_MAGENTA << course.getSchedule() << RESET << endl;
            printMenuSeparator();
        }

        double overallUtilization = totalCapacity > 0 ? 
            (double)totalEnrolled / totalCapacity * 100 : 0;

        cout << BRIGHT_GREEN << "📊 OVERALL STATISTICS:" << RESET << endl;
        cout << BRIGHT_YELLOW << "Total Courses: " << BRIGHT_WHITE << courses.size() << RESET << endl;
        cout << BRIGHT_YELLOW << "Total Capacity: " << BRIGHT_WHITE << totalCapacity << RESET << endl;
        cout << BRIGHT_YELLOW << "Total Enrolled: " << BRIGHT_WHITE << totalEnrolled << RESET << endl;
        cout << BRIGHT_YELLOW << "Utilization Rate: " 
             << (overallUtilization >= 70 ? BRIGHT_GREEN : BRIGHT_YELLOW) 
             << fixed << setprecision(1) << overallUtilization << "%" << RESET << endl;
        cout << BRIGHT_YELLOW << "Course Revenue: " << BRIGHT_GREEN << "$" 
             << fixed << setprecision(2) << totalRevenue << RESET << endl;
    }

    void generateUserStatistics() {
        
        cout << BRIGHT_WHITE << "\n👥 USER STATISTICS 👥\n" << RESET << endl;
        printSeparator();

        int studentCount = 0;
        int facultyCount = 0;
        int adminCount = 0;

        map<string, int> departmentStudents;
        map<string, int> departmentFaculty;

        for (size_t i = 0; i < users.size(); ++i) {
            const User* user = users[i];
            if (user->getUserType() == "STUDENT") {
                studentCount++;
                const Student* student = static_cast<const Student*>(user);
                departmentStudents[student->getDepartment()]++;
            } else if (user->getUserType() == "FACULTY") {
                facultyCount++;
                const Faculty* faculty = static_cast<const Faculty*>(user);
                departmentFaculty[faculty->getDepartment()]++;
            } else if (user->getUserType() == "ADMIN") {
                adminCount++;
            }
        }

        cout << BRIGHT_CYAN << "👤 USER TYPE DISTRIBUTION:" << RESET << endl;
        printMenuSeparator();
        cout << BRIGHT_YELLOW << "Students: " << BRIGHT_GREEN << studentCount << RESET << endl;
        cout << BRIGHT_YELLOW << "Faculty: " << BRIGHT_BLUE << facultyCount << RESET << endl;
        cout << BRIGHT_YELLOW << "Admins: " << BRIGHT_MAGENTA << adminCount << RESET << endl;
        cout << BRIGHT_YELLOW << "Total Users: " << BRIGHT_WHITE << (studentCount + facultyCount + adminCount) << RESET << endl;

        cout << "\n" << BRIGHT_CYAN << "🏢 DEPARTMENT-WISE STUDENTS:" << RESET << endl;
        printMenuSeparator();
        for (std::map<string, int>::const_iterator it = departmentStudents.begin(); it != departmentStudents.end(); ++it) {
            cout << BRIGHT_YELLOW << "• " << it->first << ": " 
                 << BRIGHT_GREEN << it->second << " students" << RESET << endl;
        }

        cout << "\n" << BRIGHT_CYAN << "🏫 DEPARTMENT-WISE FACULTY:" << RESET << endl;
        printMenuSeparator();
        for (std::map<string, int>::const_iterator it = departmentFaculty.begin(); it != departmentFaculty.end(); ++it) {
            cout << BRIGHT_YELLOW << "• " << it->first << ": " 
                 << BRIGHT_BLUE << it->second << " faculty" << RESET << endl;
        }
    }

    void generateCompleteReport() {
        
        cout << BRIGHT_WHITE << BOLD << "\n🔍 COMPLETE SYSTEM REPORT 🔍\n" << RESET << endl;
        printSeparator();

        cout << BRIGHT_GREEN << "Generating comprehensive system report...\n" << RESET << endl;

        generateUserStatistics();
        cout << "\n"; printSeparator(); cout << "\n";

        generateCourseStatistics();
        cout << "\n"; printSeparator(); cout << "\n";

        generateEnrollmentReport();
        cout << "\n"; printSeparator(); cout << "\n";

        generateFinancialReport();
        cout << "\n"; printSeparator(); cout << "\n";

        generateAttendanceReport();

        cout << "\n" << BRIGHT_GREEN << BOLD << "✅ Complete System Report Generated Successfully! ✅" << RESET << endl;
    }

    void generateIDCard() {
        
        if (!currentUser || currentUser->getUserType() != "STUDENT") {
            cout << BRIGHT_RED << "❌ Access denied! Only students can generate ID cards. ❌" << RESET << endl;
            return;
        }

        Student* student = static_cast<Student*>(currentUser);
        string studentId = student->getStudentId();

        // Check if ID card already exists
        for (size_t i = 0; i < idCards.size(); ++i) {
            const IDCard& card = idCards[i];
            if (card.getStudentId() == studentId && card.getStatus() == "ACTIVE") {
                cout << BRIGHT_YELLOW << "⚠️  You already have an active ID card! ⚠️" << RESET << endl;
                cout << BRIGHT_BLUE << "Would you like to view your existing card? (y/n): " << BRIGHT_WHITE;
                char choice;
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    viewIDCard();
                }
                return;
            }
        }

        cout << BRIGHT_GREEN << "\n🆔 GENERATING NEW ID CARD 🆔\n" << RESET << endl;
        printSeparator();

        // Generate card ID with year and random number for better uniqueness
        time_t now = time(0);
        struct tm* timeinfo = localtime(&now);
        int year = timeinfo->tm_year + 1900;
        int randomNum = rand() % 9000 + 1000; // 4-digit random number
        stringstream ss;
        ss << "SC" << year << studentId.substr(3) << randomNum;
        string cardId = ss.str();
        
        // Calculate expiry date (4 years from now)
        time_t expiry = now + (4 * 365 * 24 * 60 * 60); // 4 years
        char expiryStr[20];
        strftime(expiryStr, sizeof(expiryStr), "%Y-%m-%d", localtime(&expiry));

        IDCard newCard(cardId, studentId, student->getFullName(), student->getDepartment(),
                      student->getEmail(), student->getPhone(), FileIO::getCurrentDateTime(), 
                      string(expiryStr), "ACTIVE");

        idCards.push_back(newCard);

        cout << BRIGHT_GREEN << "✅ ID Card generated successfully! ✅\n" << RESET << endl;
        saveData(); 
        cout << BRIGHT_CYAN << "🎉 Here's your new ID card preview: 🎉\n" << RESET << endl;
        
        newCard.displayCard();

        cout << "\n" << BRIGHT_YELLOW << "📋 Card Details:" << RESET << endl;
        newCard.displayInfo();

        cout << "\n" << BRIGHT_BLUE << "💡 Your ID card has been saved and is now active!" << RESET << endl;
        cout << BRIGHT_BLUE << "💡 You can view it anytime from the student menu." << RESET << endl;
     
    }

    void viewIDCard() {
         
          system("cls");
  
        if (!currentUser || currentUser->getUserType() != "STUDENT") {
            cout << BRIGHT_RED << "❌ Access denied! Only students can view ID cards. ❌" << RESET << endl;
            return;
        }

        Student* student = static_cast<Student*>(currentUser);
        string studentId = student->getStudentId();

        cout << BRIGHT_BLUE << "\n🆔 YOUR ID CARD 🆔\n" << RESET << endl;
        printSeparator();

        bool cardFound = false;
        for (size_t i = 0; i < idCards.size(); ++i) {
            const IDCard& card = idCards[i];
            if (card.getStudentId() == studentId) {
                if (card.getStatus() == "ACTIVE") {
                    card.displayCard();
                    cout << "\n";
                    card.displayInfo();
                    cardFound = true;
                } else {
                    cout << BRIGHT_RED << "⚠️  Your ID card is " << card.getStatus() << " ⚠️" << RESET << endl;
                    cout << BRIGHT_YELLOW << "Please contact the administration for assistance." << RESET << endl;
                    cardFound = true;
                }
                break;
            }
        }

        if (!cardFound) {
            cout << BRIGHT_YELLOW << "⚠️  No ID card found! ⚠️" << RESET << endl;
            cout << BRIGHT_BLUE << "Would you like to generate a new ID card? (y/n): " << BRIGHT_WHITE;
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                generateIDCard();
            }
        }
    }

    void manageIDCards() {
        
        if (!currentUser || currentUser->getUserType() != "ADMIN") {
            cout << BRIGHT_RED << "❌ Access denied! Admin privileges required. ❌" << RESET << endl;
            return;
        }

        cout << BRIGHT_MAGENTA << "\n🆔 ID CARD MANAGEMENT 🆔\n" << RESET << endl;
        printSeparator();

        cout << BRIGHT_GREEN << "   [1] " << BRIGHT_BLUE << "📋 View All ID Cards" << RESET << "       " 
             << BRIGHT_GREEN << "[2] " << BRIGHT_YELLOW << "🔍 Search ID Card" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [3] " << BRIGHT_RED << "🚫 Deactivate Card" << RESET << "        " 
             << BRIGHT_GREEN << "[4] " << BRIGHT_GREEN << "✅ Activate Card" << RESET << "\n";
        cout << BRIGHT_GREEN << "   [5] " << BRIGHT_CYAN << "🔙 Back to Admin Panel" << RESET << "\n\n";
        printMenuSeparator();

        int choice;
        cout << BRIGHT_YELLOW << "   Select option: " << BRIGHT_WHITE;
        cin >> choice;

        switch (choice) {
            case 1:
                viewAllIDCards();
                break;
            case 2:
                searchIDCard();
                break;
            case 3:
                changeCardStatus("INACTIVE");
                break;
            case 4:
                changeCardStatus("ACTIVE");
                break;
            case 5:
                return;
            default:
                cout << BRIGHT_RED << "❌ Invalid choice!" << RESET << endl;
        }
    }

    void viewAllIDCards() {
          system("cls");
    
        cout << BRIGHT_CYAN << "\n📋 ALL ID CARDS 📋\n" << RESET << endl;
        printSeparator();

        if (idCards.empty()) {
            cout << BRIGHT_YELLOW << "⚠️  No ID cards found in the system. ⚠️" << RESET << endl;
            return;
        }

        for (size_t i = 0; i < idCards.size(); i++) {
            cout << BRIGHT_GREEN << "Card #" << (i + 1) << RESET << endl;
            idCards[i].displayInfo();
            cout << "------------------------" << endl;
        }
    }

    void searchIDCard() {
         
        string searchId;
        cout << BRIGHT_YELLOW << "Enter Student ID or Card ID to search: " << BRIGHT_WHITE;
        cin >> searchId;

        bool found = false;
        for (size_t i = 0; i < idCards.size(); ++i) {
            const IDCard& card = idCards[i];
            if (card.getStudentId() == searchId || card.getCardId() == searchId) {
                cout << BRIGHT_GREEN << "\n✅ ID Card Found! ✅\n" << RESET << endl;
                card.displayCard();
                cout << "\n";
                card.displayInfo();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << BRIGHT_RED << "❌ No ID card found with the given ID! ❌" << RESET << endl;
        }
    }

    void changeCardStatus(const string& newStatus) {
         
        string searchId;
        cout << BRIGHT_YELLOW << "Enter Student ID or Card ID: " << BRIGHT_WHITE;
        cin >> searchId;

        bool found = false;
        for (size_t i = 0; i < idCards.size(); ++i) {
            IDCard& card = idCards[i];
            if (card.getStudentId() == searchId || card.getCardId() == searchId) {
                string oldStatus = card.getStatus();
                card.setStatus(newStatus);
                cout << BRIGHT_GREEN << "✅ Card status changed from " << BRIGHT_BLUE << oldStatus 
                     << BRIGHT_GREEN << " to " << BRIGHT_BLUE << newStatus << BRIGHT_GREEN << "! ✅" << RESET << endl;
                found = true;

                saveData(); 
                break;
            }
        }

        if (!found) {
            cout << BRIGHT_RED << "❌ No ID card found with the given ID! ❌" << RESET << endl;
        }
    }

    void run() {
        int choice;
        string username, password;

       
        printMainBanner();
        cout << BRIGHT_GREEN << "🌟 Welcome to Smart Campus Management System! 🌟" << RESET << endl << endl;

        while (true) {
            if (!currentUser) {
                
               
                printLoginBanner();
                printSeparator();
                cout << BRIGHT_YELLOW << "   Username: " << BRIGHT_WHITE;
                cin >> username;
                cout << BRIGHT_YELLOW << "   Password: " << BRIGHT_WHITE;
                cin >> password;
                cout << RESET;

                
                if (login(username, password)) {
                    system("cls"); 
                  cout << "\n" << BRIGHT_GREEN << "✅ Login successful! Welcome " << BRIGHT_CYAN 
                   << currentUser->getFullName() << BRIGHT_GREEN << "! ✅" << RESET << endl;
                   Sleep(1500);
                     system("cls");  
                   


          }              else {
                    
                    cout << "\n" << BRIGHT_RED << "❌ Invalid credentials! Please try again. ❌" << RESET << endl;
                  Sleep(1500); 
                   
                printMainBanner(); 
                    continue;
     }
            }

            if (currentUser->getUserType() == "STUDENT") {
                
                
                displayStudentMenu();
                cin >> choice;
                 cin.ignore();

                switch (choice) {
                    case 1:
                        currentUser->displayInfo();
                         cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                         cin.get();
                        break;
                    case 2:
                        enrollStudentInCourse();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                        cin.get();
                        break;
                    case 3:
                        viewStudentEnrollments();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                        cin.get();
                        break;
                    case 4:
                        viewStudentBills();
                        break;
                    case 5:
                        payBill();
                        break;
                    case 6:
                        viewStudentAttendance();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                        cin.get();
                        break;
                    case 7:
                        generateIDCard();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                        cin.get();
                        break;
                    case 8:
                        viewIDCard();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                        cin.get();
                        break;
                    case 9:
                        logout();
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                         cin.get();
                }
            } else if (currentUser->getUserType() == "FACULTY") {
                
               
                displayFacultyMenu();
                cin >> choice;
                cin.ignore();

                switch (choice) {
                    case 1:
                  
                        currentUser->displayInfo();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                         cin.get();
                        break;
                    case 2:
                    
                        viewTeachingCourses();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                         cin.get();
                        
                       
                        break;
                    case 3:
                        markAttendance();
                        
                        break;
                    case 4:
                        viewStudentList();
                       
                        break;
                    case 5:
                        logout();
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
            cin.get();
                }
            } else if (currentUser->getUserType() == "ADMIN") {
                
                
                displayAdminMenu();
                cin >> choice;
                cin.ignore(); 

                switch (choice) {
                    case 1:
                        addNewCourse();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                        cin.get();
                        break;
                    case 2:
                        addNewUser();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                        cin.get();
                        break;
                    case 3:
                        viewAllUsers();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                        cin.get();
                        break;
                    case 4:
                        viewAllCourses();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                        cin.get();
                        break;
                    case 5:
                        generateReports();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                        cin.get();
                        break;
                    case 6:
                        manageIDCards();
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
                        cin.get();
                        break;
                    case 7:
                          saveData();
                          cout << BRIGHT_GREEN << "✅ Data saved successfully! ✅" << RESET << endl;
                          cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
            cin.get();
                          
                             break;
                     case 8:  
                              logout();
                              break;
                    default:
                        cout << "Invalid choice!" << endl;
                        cout << BRIGHT_YELLOW << "\nPress Enter to continue..." << RESET;
            cin.get();
                        
                }
            }

            if (!currentUser) {
                
    
                cout << "\nDo you want to exit? (y/n): ";
                char exitChoice;
                cin >> exitChoice;
                if (exitChoice == 'y' || exitChoice == 'Y') {
                    break;
                }
            }
        }

        cout << "\n" << BRIGHT_CYAN << BOLD;
        cout << "████████╗██╗  ██╗ █████╗ ███╗   ██╗██╗  ██╗    ██╗   ██╗ ██████╗ ██╗   ██╗██╗\n";
        cout << "╚══██╔══╝██║  ██║██╔══██╗████╗  ██║██║ ██╔╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║██║\n";
        cout << "   ██║   ███████║███████║██╔██╗ ██║█████╔╝      ╚████╔╝ ██║   ██║██║   ██║██║\n";
        cout << "   ██║   ██╔══██║██╔══██║██║╚██╗██║██╔═██╗       ╚██╔╝  ██║   ██║██║   ██║╚═╝\n";
        cout << "   ██║   ██║  ██║██║  ██║██║ ╚████║██║  ██╗       ██║   ╚██████╔╝╚██████╔╝██╗\n";
        cout << "   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝       ╚═╝    ╚═════╝  ╚═════╝ ╚═╝\n";
        cout << RESET << "\n";
        cout << BRIGHT_GREEN << "🌟 Thank you for using Smart Campus Management System! 🌟" << RESET << endl;
        cout << BRIGHT_YELLOW << "         Have a great day and keep learning! 📚✨" << RESET << endl;
    }
};

int main() {
    enableANSI();
    SetConsoleOutputCP(65001);
    CampusManagementSystem cms;
    cms.run();
    return 0;
} 