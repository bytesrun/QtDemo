#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "I'd like to treat teacher";
}

void Student::treat(QString strName)
{
    qDebug() << "I'd like to treat teacher: " << strName;
}
