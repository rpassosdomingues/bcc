// Here I created a project to calculate the wage of a teacher.

#include <stdio.h>

int main(void){

  float hour_value, number_of_classes, gross_salary, inss_rate, wage;

  printf("\n Enter the value of the hourly rate: ");
  scanf(" %f", &hour_value);

  printf("\n Enter the number of classes per month: ");
  scanf(" %f", &number_of_classes);

  inss_rate = 0.10;

  gross_salary = number_of_classes * hour_value;
  wage = gross_salary - inss_rate * gross_salary;

  printf("\n\t The net salary of the teacher is: R$ %.2f \n\n", wage);

  return 0;
}
