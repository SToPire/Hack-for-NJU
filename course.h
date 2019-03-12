#ifndef COURSE_H
#define COURSE_H


class Course
{
public:
    Course();
public:
    void C_major();//选择专业，根据专业不同重载C_course

    void Go_abroad();
    void postgraduate();
    void Graduation_audit();

    void C_course();//基本操作，以上三个函数通过调用该函数选取相关内容
};

#endif // COURSE_H
