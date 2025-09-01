#include<stdio.h>
#include<math.h>

void add (double a , double b){
	printf("the sum of two numbers is %.2lf",a+b);
}

void subtract (double a , double b){
	printf("the difference of two numbers is %.2lf",a-b);
}

void multiply (double a , double b){
	printf("the product of two numbers is %.2lf",a*b);
}

void divide (double a , double b){
	if(b==0){
		printf("you are dividing numerator by zero which is infinite");
	}
	else{ 
	printf("the division of two numbers is %.2lf",a/b);
    }
}

void square(double c)
{
	printf("the square of the number is %.2lf",c*c);
}

void squareroot(double c){
	if(c<0){
		printf("you have entered a negative number");
	}
	else{
	printf("the squareroot of the number is %.2lf",sqrt(c));
    }
}

void exponent(double a, double b){
	printf("the exponent of the number is %.2lf",pow(a,b));
}

void nth_root(double a, double b)
{
	printf("the nth root of the number is %.2lf",pow(a,1/b));
}

void showhistory(char string[]){
	FILE* ptr = NULL;
	ptr = fopen("calculationhistory.txt","a");
	fprintf(ptr,"%s\n",string);
	fclose(ptr);
}

int main()
{
	double a,b;
	int choice,i=0;
	double c;
	char option,string[100];
	
	do{
		system("cls");
		printf("======================================MADE IN INDIA CALCULATOR======================================\n");
	printf("press 1 to add the numbers\n");
	printf("press 2 to subtract the numbers\n");
	printf("press 3 to multiply the numbers\n");
	printf("press 4 to divide the numbers\n");
	printf("press 5 to square the numbers\n");
	printf("press 6 to find root of the numbers\n");
	printf("press 7 to find exponent of the number\n");
	printf("press 8 to find nth root of the number\n");
	printf("press 9 to view the calculation history\n");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			printf("enter two numbers");
			scanf("%lf%lf",&a,&b);
			add(a,b);
			i++;
			sprintf(string,"calculation %d : %lf + %lf = %.2lf",i,a,b,a+b);
			showhistory(string);
			break;
			
		case 2:
			printf("enter two numbers");
			scanf("%lf%lf",&a,&b);
			subtract(a,b);
			i++;
			sprintf(string,"calculation %d : %.3lf - %.3lf = %.2lf",i,a,b,a-b);
			showhistory(string);
			break;
		
		case 3:
			printf("enter two numbers");
			scanf("%lf%lf",&a,&b);
			multiply(a,b);
			i++;
			sprintf(string,"calculation %d : %.3lf * %.3lf = %.2lf",i,a,b,a*b);
			showhistory(string);
			break;
		
		case 4:
			printf("enter two numbers");
			scanf("%lf%lf",&a,&b);
			divide(a,b);
			i++;
			sprintf(string,"calculation %d : %.3lf / %.3lf = %.2lf",i,a,b,a/b);
			showhistory(string);
			break;
			
		case 5:
			printf("enter a number");
			scanf("%lf",&c);
			square(c);
			i++;
			sprintf(string,"calculation %d : %.3lf square is = %.2lf",i,c,c*c);
			showhistory(string);
			break;
			
		case 6:
			printf("enter a number");
			scanf("%lf",&c);
			squareroot(c);
			i++;
			sprintf(string,"calculation %d : %.3lf squareroot is = %.2lf",i,c,sqrt(c));
			showhistory(string);
			break;	
			
		case 7:
			printf("enter a number and its exponent");
			scanf("%lf%lf",&a,&b);
			exponent(a,b);
			i++;
			sprintf(string,"calculation %d : %.3lf to the power %.3lf is = %.2lf",i,a,b,pow(a,b));
			showhistory(string);
			break;	
		
		case 8:
			printf("enter a number and its nth root");
			scanf("%lf%lf",&a,&b);
			nth_root(a,b);
			i++;
			sprintf(string,"calculation %d : %.3lf to the nth root %.3lf is = %.2lf",i,a,b,pow(a,1/b));
			showhistory(string);
			break;	
				
		case 9:
			if(i==0){
				printf("you have not performed any calculation\n");
			}
			else{
				char line[100];
				FILE*ptr=fopen("calculationhistory.txt","r");
				printf("your calculation history is given below:\n");
				if(ptr==NULL){
					printf("no calculation found");
				}
				else{
				while(fgets(line,sizeof(line),ptr)!=NULL){
				printf("%s",line);	
				}
				}
				fclose(ptr);
			}
		    break;
		default :
			printf("you have entered a invalid number");
	}
	printf("\n do you want to use this calculator again? \n print y for yes and n for no:");
	scanf(" %c",&option); //we can also use getchar before scanf so that we clean the newline character instead of giving a space before %c. 
	printf("\n");
	
	if(option=='n' || option=='N' || option!='y' || option!='Y')
	{
		printf("THANKS for using the calculator");
	}
	
}while( option=='y' || option=='Y');
	
	return 0;
}
