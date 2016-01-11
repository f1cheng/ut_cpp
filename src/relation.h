#ifndef __RELATION_H__
#define __RELATION_H__

/* association know ___> */
class CDPlayer
{
private:
    String model;
    CD cd;/* *cd */
public:
    void play(CD cd);
};

/* dependency use ----> */
class Car 
{
public:
    void getCarLoc(CarLoc carLoc)
    {
        carLoc.getLocication();
    }
};

/* composition  own */
class Computer
{
private:
    CPU cpu;
    MotherBoard motherboard;
    RAM ram;
public:
    Computer(int speed, char *model, ramSize);
};

/* Aggreration  has */
class Department
{
private:
    Teacher *teacher;
public:
    Department(Teacher *t = NULL)
        : teacher("Mr Zhang")
    {
    }
};

#endif
