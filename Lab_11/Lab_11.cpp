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



int Lab_11() {

    Student s1("Юрій", 19, "КПІ\n");
    s1.printAll();

    Student s2("Марія", 20, "КНУ імені Шевченка\n");
    s2.printAll();

    Student s3("Ігор", 18, "КНУ імені Шевченка\n");
    s3.printAll();

    cout << "--- Зміна імені ---\n";

    Student s4("Юрій", 19, "КПІ");
    s4.printAll();
    cout << "Змінюємо ім'я на 'Олександр'\n";
    s4.changeName("Олександр");
    s4.printAll();
    cout << "\n";

    Student s5("Марія", 20, "КНУ імені Шевченка");
    s5.printAll();
    cout << "Змінюємо ім'я на 'Вераніка'\n";
    s5.changeName("Вераніка");
    s5.printAll();
    cout << "\n";

    Student s6("Ігор", 18, "КНУ імені Шевченка");
    s6.printAll();
    cout << "Змінюємо ім'я на 'Нікіта'\n";
    s6.changeName("Нікіта");
    s6.printAll();


    return 0;
}