/**
    * Jacob Bananal
    *
    * Chapter 15 Programming Assignment
    *
    * April 3, 2018
    *
**/

#ifndef PROGRAMMINGPROJECT_H
#define PROGRAMMINGPROJECT_H

class ProgrammingProject: public GradedActivity
{
private:
    int useOfClasses; // use of classes
    int codeExecution; // code execution
    int properChoiceOfCode; // proper choice of code
    int correctPseudocode; // correct pseudocode
    int useOfComments; // use of comments
    int inputOutputProfessionalism; // input/output professionalism

public:
    //Initializes each variable to 0
    ProgrammingProject(): GradedActivity()
    {
        useOfClasses = 0;
        codeExecution = 0;
        properChoiceOfCode = 0;
        correctPseudocode = 0;
        useOfComments = 0;
        inputOutputProfessionalism = 0;
    }

    //overloaded constructor
    ProgrammingProject(int,int,int,int,int,int);

    //Mutators functions
    void setUseOfClasses(int);
    void setCodeExecution(int);
    void setProperChoiceOfCode(int);
    void setCorrectPseudocode(int);
    void setUseOfComments(int);
    void setInputOutputProfessionalism(int);

    //accessors functions
    int getUseOfClasses() const
    {
        return useOfClasses;
    }

    int getCodeExecution() const
    {
        return codeExecution;
    }

    int getProperChoiceOfCode() const
    {
        return properChoiceOfCode;
    }

    int getCorrectPseudoCode() const
    {
        return correctPseudocode;
    }

    int getUseOfComments() const
    {
        return useOfComments;
    }

    int getInputOutputProfessionalism() const
    {
        return inputOutputProfessionalism;
    }
};
#endif // PROGRAMMINGPROJECT_H
