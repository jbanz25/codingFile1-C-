/**
    * Jacob Bananal
    *
    * Chapter 15 Programming Assignment
    *
    * April 3, 2018
    *
**/

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H
using namespace std;

class GradedActivity
{
private:
    double score;
public:
    GradedActivity()
    {
        score=0.0; //initializes to 0.0
    }
    GradedActivity(double s)
    {
        score=s;
    }
    void setScore(double s)
    {
        score=s;
    }
    double getScore() const
    {
        return score; //returns the score
    }
    char getLetterGrade() const;
};
#endif // GRADEDACTIVITY_H
