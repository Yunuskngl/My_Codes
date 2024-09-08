#include <stdio.h>

 void write_polynomial3(double a, double b, double c, double d){


    if (a != 0) {
            if(a == -1.0)
            {
                printf("-x^3");
            }
        else if(a == 1.0)
            {
            printf("x^3");
            }
        else if(a == (int)a)
            {
            printf("%dx^3",(int)a);
            }
        else
            {
            printf("%.1fx^3", a);
            }

        if (b > 0) 
        {
            printf("+");
        }
    }
    else{
       if (b > 0) 
       {
            printf("+");
        }

    }

    if (b != 0) {
        if(b == -1.0)
        {
            printf("-x^2");
        }

        else if(b == 1.0)
        {
            printf("x^2");
        }

        else if(b == (int) b)
        {
            printf("%dx^2",(int)b);
        }

        else
        {
            printf("%.1fx^2", b);
        }

        if (c > 0) {
            printf("+");
        }
    }
    else{
       if (c > 0) {
            printf("+");
        }

    }

    if (c != 0) {
        if(c == -1.0){
            printf("-x");
            }


        else if(c == 1.0){
            printf("x");
            }


        else if(c == (int)c){
            printf("%dx",(int)c);}


        else{
            printf("%.1fx", c);}


        if (d > 0) {            
            printf("+");
        }
    }


    else{
       if (d > 0) 
       {
            printf("+");
        }

    }

    if (d != 0){
        
        if(d ==(int)d)
        {
            printf("%lf",d);
        }

    else
    {
	   printf("%.1f",d);}
	}
    printf("\n");
}


void calculate_fibonacci_sequence(){
    int i,x,sum;
    char line[79] = "";
    char terms  = '\n';
    int first_term = 0 ; 
    int second_term = 1;
    printf("enter a number of term : ");
    scanf("%d",&x);
    scanf("%c",&terms);
    while (terms != '\n' || x < 0)
    {
            if(terms == 42) break;
            if(terms != '\n'){
                printf("enter a numeric terms number:");
                scanf("%d",&x);
                scanf("%c",&terms);
            }
            if (x < 0)
            {
                printf("enter a positive terms number:");
                scanf("%d",&x);
                scanf("%c",&terms);
            }
            
    }i=1;
    if(terms != 42) printf("\nfibonacci :\n\n %d\n ",second_term); 
    while (i<x)
    {if(terms == 42) break;
    
  
        
    
        sum=first_term+second_term;
        first_term=second_term;
        second_term=sum;
        ++i;
        printf("%d\n ",sum);
    }
}



void decide_perfect_harmonic_number(int number)
{
    char c  ; 
    char line[79] = "";
    char positiveanswer[] = "Yes",negativeanswer[] = "No";
    while(number > 0 && c != '\n' && number != '\n' )
    {
        
        if(number - (int)number == 0){
        int sum=0,i;
        double harmonicsum=0.0;
        printf("please enter a number :\n");
        scanf("%d",&number);
        scanf("%c",&c);
        
        printf("Natural divisors : ");
        
        for (i=1;i<=number;i++){
            if (number%i==0) {
                printf("%d ",i);
                }}
        for(i = 1 ; i < number ; i++)   
        {   
            if(number % i == 0)   
            sum = sum + i ;   
        }
        printf("\n");
        printf("Is Perfect Number?:\n");
        if(sum == number){
            for (i = 0; i < 3; ++i) {
                printf("%c", positiveanswer[i]);
               }}

        else{
            for (i = 0; i < 2; ++i) {
                printf("%c", negativeanswer[i]);
               }
        }
        printf("\n");
        for (i=1;i<=number;i++){
            if (number%i==0) {
                harmonicsum += 1/i;
            }}
        printf("Is Harmonic Divisor Number? : ");
        if(harmonicsum - (int)harmonicsum == 0 )
        {
            printf("%s",positiveanswer);

        }
        else
        {
            printf("%s",negativeanswer);

        }
        printf("\n");
        }
    }

void bmi_calculation()
{
    double weight, height ,BMI=0,BMI1=0; 
    printf("enter a your weight value : \n");
    scanf("%lf",&weight);
    printf("enter a your height value : \n");
    scanf("%lf",&height);
    
    BMI = weight/height;

    BMI1 = BMI/height;
    
    printf("Your category: ");
    
    if(BMI1 < 16.0) {printf("Severely Underweight\n");}

    else if(BMI1 >= 16.0 && BMI1 < 18.5){printf("Underweight\n");}

    else if(BMI1 >= 18.5 && BMI1 < 25){printf("Normal\n");}

    else if(BMI1 >= 25 && BMI1 < 30){printf("Owerweight\n");}

    else if(BMI1 >= 30){printf("Obese\n");}

    else {printf("unvalid value\n");
	}
}
int main() {
    int req;

    while (1) {
        printf("Please enter a number:\n1. write_polynomial3\n2. decide_perfect_harmonic_number\n3. bmi_calculation\n4. calculate_fibonacci_sequence\n5. exit\n");
        scanf("%d", &req);

        switch (req) {
            case 1:
                write_polynomial3(1.2, 2.3, 3.4, 4.5);
                break;

            case 2:
                decide_perfect_harmonic_number(8);
                break;

            case 3:
                bmi_calculation();
                break;

            case 4:
                calculate_fibonacci_sequence();
                break;

            case 5:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}
