#include <stdio.h>
#include <math.h>
//program to help manager manage budget
//user inputs the num. of workers
//and the number of workers
//workers mon. salary
float print_out(float* salary, int* num_of_emps); 
int rebudget(float* d, float *budget);
int main() {
int i=1;
float budget, total, salary; float *money_ptr=&salary; float *total_ptr=&total;
int employees;
printf("Enter monthly budget: $"); scanf("%f", &budget);
while(i) {

printf("Enter monthly worker salary: $"); scanf("%f", &salary);
printf("Enter total workers:"); scanf("%d", &employees);
total=print_out(money_ptr, &employees);
i=rebudget(total_ptr, &budget); }
}
float print_out(float* salary, int* num_of_emps){
	int  workers=0,managers=0,directors=0;
	float temp=0;
	float msalary=0, dsalary=0,total=0;
	// while not exceeding the number of elements
	//print the salary and add the numbers
	 	workers= *num_of_emps;
	 	managers=workers/2;
	 	if (workers<3){
	 		managers=1;
	 	}
	 	directors= managers/5;
	 	temp=managers-(directors*5);

	 	if((temp)>3.0){
			directors++;}

		dsalary=5*(*salary);
		msalary=dsalary/2;
		printf("Total workers: %.d ", workers);
		printf("  Monthly salary : $ %.2f\n", *salary );
		printf("Total managers: %.d ",managers);
		printf("  Monthly salary : $ %.2f \n", msalary );
		printf("Total directors: %d ",directors);
		printf("  Monthly salary : $ %.2f\n", dsalary);
		dsalary=dsalary*directors;
		msalary=managers*msalary;

		total=  msalary + dsalary +(workers *(*salary));

	 //now return the total
	return total;
}
int rebudget(float* d, float *budget){
	 float temp, difference;
	 int again;
	 char *choice;

	 if(*d> *budget){
	 	temp= *d - *budget;

	 	choice="OVER";}
	 else{
	 	temp= *budget - *d;
	 	
	 	choice="UNDER";
	 }
	 printf("This is %s your budget by $ %.2f.",choice, temp);
	// Now you ared 
	printf("Would you like to rebudget? 1 for yes 2 for no.\n");
	scanf("%d",&again);
	if(again==1){
		return temp;
	}
	else if(again==2){
		 printf("Shutting down ...\n");
		return 0;
	}
	else{
		printf("I am sorry that is not a valid entry.");
		printf(" Shutting down ...\n");
	}
}