

//member 1
#include <iostream>
#include<string>
#include<fstream>

using namespace std;

class capacityExceeded {
public:
	string what() {
		return "Capacity Exceeded";
	})
};
class overDue {
private:
	doube fine;
public:
	overDue(double f) {
		fine = f;
	}
	string what() {
		return "Over Due. Fine: ";
	}
	double getFine() {
		return fine;
	}

};

class Person {
private:
	string name;
	string CNIC;
	string contact;
	int age;
public:
	Person(string n, string c, string con, int a) :
		name(n), CNIC(c), contact(cont), age(a) {
	}
		
	virtual ~Person(){}
	virtual void displayInfo()=0
	string getName() {
		return name;
	}
	string getCNIC() {
		return CNIC;
	}
	string getContact() {
		return contact;
	}
	int getAge() {
		return age;
	}
};

class Student :public Person {
private:
	int rollNo;
	int semester;
	double GPA;
	string enrolledCourses[6];
	int courseCount;
	public
		Student(string n, string c, string con, int a, int r, int s, double g)
		:Person(n, c, cont, a), rollNo(r), semester(s), GPA(g), courseCount(0) {
	}
	void displayInfo(){
		cout << "Student: " << name << " | Roll Np: " << rollNo << " | GPA: " << GPA << " |Semester: " << semester << endl;
	}
	void calculateGrade() {
		if (GPA >= 3.5) {
			cout << "Grade: A" << endl;
		}
		else if (GPA >= 3.0) {
			cout << "Grade: B" << endl;
		}
		else if (GPA >= 2.0) {
			cout << "Grade: C" << endl;
		}
		else {
			cout << "Grade: F" << endl;
		}
		int getRollNo() {
			return rollNo;
		}
		double getGPA() {
			return GPA;
		}
		void setGPA(double g) {
			GPA = g;
		}
		void addCourse(string course) {
			if (courseCount < 6) {
				enrolledCourses[courseCount++] = course;
			}

		}
	};
	class Faculty :public Person {
	private:
		int employeeID;
		string department;
		string designation;
	public:
		Faculty(string n, string c, string con, int a, int eID, string dept, string desig)
			:Person(n, c, cont, a), employeeID(eID), department(dept), designation(desig) {
		}
		void displayInfo() {
			cout << "Faculty: " << name << " | Employee ID: " << employeeID << " | Department: " << department << " | Designation: " << designation << endl;
		}
		int getEmployeeID() {
			return employeeID;
		}
		string getDepartment() {
			return department;
		}
		string getDesignation() {
			return designation;
		}
	};
	class GraduateStudent :public Student {
	private:
		string researchTopic;
		string supervisor;
	public:
		GraduateStudent(string n, string c, string con, int a, int r, int s, double g, string topic, string sup)
			:Student(n, c, cont, a, r, s, g), researchTopic(topic), supervisor(sup) {
		}
		void displayInfo() {
			cout << "Graduate Student: " << name << " | Roll No: " << getRollNo() << " | GPA: " << getGPA() << " | Semester: " << semester << " | Research Topic: " << researchTopic << " | Supervisor: " << supervisor << endl;
		}
		string getResearchTopic() {
			return researchTopic;
		}
		string getSupervisor() {
			return supervisor;
		}
	};

	//member 2


