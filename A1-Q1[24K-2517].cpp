#include <iostream>
#include <string>
using namespace std;

class Skill
{
public:
    int skillID;
    string skillName;
    string description;

    void showSkillDetails()
    {
        cout << "Skill ID: " << skillID << ", Name: " << skillName << ", Description: " << description << endl;
    }

    void updateSkillDescription(string newDescription)
    {
        description = newDescription;
    }
};

class Sport
{
public:
    int sportID;
    string name;
    string description;
    Skill requiredSkills[5];
    int skillCount = 0;

    void addSkill(Skill s)
    {
        if (skillCount < 5)
        {
            requiredSkills[skillCount++] = s;
        }
    }

    void removeSkill(int id)
    {
        for (int i = 0; i < skillCount; i++)
        {
            if (requiredSkills[i].skillID == id)
            {
                for (int j = i; j < skillCount - 1; j++)
                {
                    requiredSkills[j] = requiredSkills[j + 1];
                }
                skillCount--;
                break;
            }
        }
    }
};

class Mentor;

class Student
{
public:
    int studentID;
    string name;
    int age;
    Sport sportsInterests[3];
    int interestCount = 0;
    Mentor *mentorAssigned = nullptr;

    void registerForMentorship(Mentor *m);
    void viewMentorDetails();
    void updateSportsInterest(Sport s);
};

class Mentor
{
public:
    int mentorID;
    string name;
    Sport sportsExpertise[3];
    int maxLearners;
    Student *assignedLearners[5];
    int learnerCount = 0;

    void assignLearner(Student *s)
    {
        if (learnerCount < maxLearners)
        {
            assignedLearners[learnerCount++] = s;
            s->mentorAssigned = this;
        }
    }

    void removeLearner(Student *s)
    {
        for (int i = 0; i < learnerCount; i++)
        {
            if (assignedLearners[i] == s)
            {
                for (int j = i; j < learnerCount - 1; j++)
                {
                    assignedLearners[j] = assignedLearners[j + 1];
                }
                learnerCount--;
                s->mentorAssigned = nullptr;
                break;
            }
        }
    }

    void viewLearners()
    {
        for (int i = 0; i < learnerCount; i++)
        {
            cout << assignedLearners[i]->name << endl;
        }
    }
};

void Student::registerForMentorship(Mentor *m)
{
    if (m->learnerCount < m->maxLearners)
    {
        m->assignLearner(this);
    }
}

void Student::viewMentorDetails()
{
    if (mentorAssigned != nullptr)
    {
        cout << "Mentor ID: " << mentorAssigned->mentorID << " Name: " << mentorAssigned->name << endl;
    }
}

void Student::updateSportsInterest(Sport s)
{
    if (interestCount < 3)
    {
        sportsInterests[interestCount++] = s;
    }
}

int main()
{
    cout << "Hasan Waseem, ID : 24K2517" << endl;
    Mentor mentor1;
    mentor1.mentorID = 101;
    mentor1.name = "Ali";
    mentor1.maxLearners = 3;

    Student student1;
    student1.studentID = 201;
    student1.name = "Saad";
    student1.age = 20;

    Sport sport1;
    sport1.sportID = 301;
    sport1.name = "Tennis";
    sport1.description = "A fast-paced game";

    Skill skill1;
    skill1.skillID = 401;
    skill1.skillName = "Backhand Stroke";
    skill1.description = "A fundamental tennis skill";

    sport1.addSkill(skill1);
    student1.updateSportsInterest(sport1);
    student1.registerForMentorship(&mentor1);

    cout << "Student's mentor details:" << endl;
    student1.viewMentorDetails();

    cout << "Mentor's learners list:" << endl;
    mentor1.viewLearners();

    return 0;
}
