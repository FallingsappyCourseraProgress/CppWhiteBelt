#include <iostream>
using namespace std;

struct Specialization
{
    explicit Specialization(string newValue)
    {
        value = newValue;
    }

    string value;
};

struct Course
{
    explicit Course(string newValue)
    {
        value = newValue;
    }

    string value;
};

struct Week
{
    explicit Week(string newValue)
    {
        value = newValue;
    }

    string value;
};

struct LectureTitle {
    LectureTitle(Specialization specialization, Course course, Week week)
    {
        this->specialization = specialization.value;
        this->course = course.value;
        this->week = week.value;
    }

    string specialization;
    string course;
    string week;
};

int main()
{
    // Можно
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );

    // Нельзя
    //LectureTitle title("C++", "White belt", "4th");

    //LectureTitle title(string("C++"), string("White belt"), string("4th"));

    //LectureTitle title = { "C++", "White belt", "4th" };

    //LectureTitle title = { {"C++"}, {"White belt"}, {"4th"} };

    //LectureTitle title(
    //    Course("White belt"),
    //    Specialization("C++"),
    //    Week("4th")
    //);

    //LectureTitle title(
    //    Specialization("C++"),
    //    Week("4th"),
    //    Course("White belt")
    //)

    return 0;
}
