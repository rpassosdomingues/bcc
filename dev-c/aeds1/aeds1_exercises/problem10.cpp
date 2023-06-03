/*
Project 3. the evaluation system of the Theory of Languages subject follows the following
criteria:
 - Three tests will be applied in the semester.
 - The final grade will be the average of the exams given.
 - The student is considered approved if he/she obtains a grade equal to or superior to 60 points and has
attended at least 40 classes.
 - Make an algorithm that reads the data containing the enrollment, the grade of the three exams and the
number of classes attended by 100 students.
 . Calculate and print:
- The final grade of each student.
- The highest and lowest grade of the class.
- The average grade of the class.
- The total of failed students.
- The total of failed students by attendance.
*/

#include <iostream>

using namespace std;

int main(void) {

  int enrollment, gradeP1, gradeP2, gradeP3;

  int count = 0;
  int totalStudents = 100;
  int totalFailures = 0;
  int totalFailuresAttendance = 0;
  int numAttendances = 0, minAttendance = 40;

  float highestGrade = -1;
  float lowestGrade = 1000;
  float finalGrade, averageGrade;

  while(count < totalStudents){

    cout << "\n Enter the enrollment number: ";
    cin >> enrollment;
    
    cout << "\n Enter the grade for P1: ";
    cin >> gradeP1;

    cout << "\n Enter the grade for P2: ";
    cin >> gradeP2;

    cout << "\n Enter the grade for P3: ";
    cin >> gradeP3;

    cout << "\n Enter the number of Attendances: ";
    cin >> numAttendances;

    finalGrade = (gradeP1 + gradeP2 + gradeP3) / 3.0;

    if (finalGrade < 60) {
      totalFailures++;
    } else if (numAttendances < minAttendance) {
        totalFailuresAttendance++;
    } else if (finalGrade > highestGrade) {
        highestGrade = finalGrade;
    } else if (finalGrade < lowestGrade) {
        lowestGrade = finalGrade;
    }

    averageGrade += finalGrade;

    count++;
    }

    averageGrade /= totalStudents;

    cout << "\n\t ===================== Results ===================== \n" << endl;

    cout << "\n\t Final grades of each student. \n";
    cout << "\n\t Highest grade: " << highestGrade << endl;
    cout << "\t Lowest grade: " << lowestGrade << endl;
    cout << "\t Average grade: " << averageGrade << endl;
    cout << "\t Total number of failures: " << totalFailures << endl;
    cout << "\t Total number of failures due to attendance: " << totalFailuresAttendance << endl;
    
    cout << "\n\t ===================== ------- ===================== \n" << endl;
    
    return 0;
}
