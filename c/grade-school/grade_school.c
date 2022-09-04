#include "grade_school.h"

void init_roster(roster_t* roster)
{
    roster->count = 0;
    memset(roster, 0, MAX_NAME_LENGTH);
}

bool add_student(roster_t* roster, const char* student_name, uint8_t desired_grade)
{
    if (check_duplicated_name(*roster, student_name))
    {
        return false;
    }

    strcpy(roster->students[roster->count].name, student_name);
    roster->students[roster->count].grade = desired_grade;
    roster->count++;

    sort_by_grade(roster);
    sort_by_name(roster);

    return true;
}

bool check_duplicated_name(roster_t roster, const char* name)
{
    for (size_t i = 0; i < roster.count; i++)
    {
        if (strcmp(roster.students[i].name, name) == 0)
        {
            return true;
        }
    }
    return false;
}

void sort_by_grade(roster_t* roster)
{
    student_t holder;

    for (size_t i = 0; i < roster->count; i++)
    {
        for (size_t j = i + 1; j < roster->count; j++)
        {
            if (roster->students[i].grade > roster->students[j].grade)
            {
                holder = roster->students[i];
                roster->students[i] = roster->students[j];
                roster->students[j] = holder;

                i = 0;
            }
        }
    }
}

void sort_by_name(roster_t* roster)
{
    student_t holder;
    size_t char_index = 0;
    bool change = false;

    for (size_t i = 0; i < roster->count; i++)
    {
        for (size_t j = i + 1; j < roster->count; j++)
        {
            if (roster->students[i].grade != roster->students[j].grade)
            {
                continue;
            }

            char_index = 0;

            while (true)
            {
                if ((roster->students[i].name[char_index] == '\0') || (roster->students[j].name[char_index] == '\0'))
                {
                    break;
                }

                if (toupper(roster->students[i].name[char_index]) > toupper(roster->students[j].name[char_index]))
                {
                    holder = roster->students[j];
                    roster->students[j] = roster->students[i];
                    roster->students[i] = holder;
                    i = 0;
                    change = true;
                    break;
                }
                else if (toupper(roster->students[i].name[char_index]) < toupper(roster->students[j].name[char_index]))
                {
                    break;
                }
                
                char_index++;

            }
            
            if (change)
            {
                break;
            }
        }

    }
}

roster_t get_grade(roster_t* roster, uint8_t desired_grade)
{
    roster_t desired_students;
    init_roster(&desired_students);

    for (size_t i = 0; i < roster->count; i++)
    {
        if (roster->students[i].grade == desired_grade)
        {
            add_student(&desired_students, roster->students[i].name, desired_grade);
        }
    }

    return desired_students;
}