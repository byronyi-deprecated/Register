#ifndef TASK_H
#define TASK_H

struct InsertTask
{
    virtual void doTask() = 0;
};

struct InsertStudentTask : public InsertTask
{
    void doTask();
};

struct InsertCourseTask : public InsertTask
{
    void doTask();
};

struct InsertRegTask : public InsertTask
{
    void insert();
};

struct DeleteTask
{
    virtual void remove() = 0;

};

#endif // TASK_H
