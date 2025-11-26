#include <iostream>
#include <string>
using namespace std;


class Student {
protected:
    string name;
    int age;
    string university;

public:

    Student() : name(""), age(0), university("") {}


    Student(string n, int a, string u) : name(n), age(a), university(u) {}


    Student(const Student& s) {
        name = s.name;
        age = s.age;
        university = s.university;
    }


    ~Student() {

    }


    void setUniversity(string u) {
        university = u;
    }

    void changeName(string newName) {
        name = newName;
    }

    void inputAge() {
        cout << "Введіть вік: ";
        cin >> age;
    }

    void printAge() const {
        cout << "Вік: " << age << endl;
    }

    void printAll() const {
        cout << "Ім'я: " << name << endl;
        cout << "Вік: " << age << endl;
        cout << "ВНЗ: " << university << endl;
    }
};


class StudentWithGrades : public Student {

    int grades[10];
    int gradeCount;

public:

    StudentWithGrades() : Student() {
        gradeCount = 0;
    }


    StudentWithGrades(string n, int a, string u, int* arr, int cnt)
        : Student(n, a, u)
    {
        gradeCount = cnt;
        for (int i = 0; i < cnt; i++)
            grades[i] = arr[i];
    }


    StudentWithGrades(const StudentWithGrades& st) : Student(st) {
        gradeCount = st.gradeCount;
        for (int i = 0; i < gradeCount; i++)
            grades[i] = st.grades[i];
    }





    void addGrade(int g) {
        if (gradeCount < 10)
            grades[gradeCount++] = g;
        else
            cout << "Масив оцінок переповнений!" << endl;
    }


    void printGrades() const {
        cout << "Оцінки: ";
        for (int i = 0; i < gradeCount; i++)
            cout << grades[i] << " ";
        cout << endl;
    }


    void printAll() const {
        Student::printAll();
        printGrades();
    }
};


int Lab_11() {

    Student s1("Юрій", 19, "КПІ");
    s1.printAll();

    cout << "\n--- Студент з оцінками ---\n";

    int arr[5] = { 90, 85, 75, 100, 80 };

    StudentWithGrades s2("Марія", 20, "КНУ імені Шевченка", arr, 5);
    s2.printAll();

    cout << "\nДодаємо оцінку 95:\n";
    s2.addGrade(95);
    s2.printGrades();

    return 0;
}