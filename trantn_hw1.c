/*
    Tri Tran
    cs 532 hw1

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    FILE *sset = fopen("students_dataset.csv", "r");;


    char row[100],*ptr;
    int total = 0, n,i,j;


    /*input the csv file*/
    typedef struct
    {char f_name[100]; char l_name[100];   char major[100];    char degree[100];   float gpa;  int creh;   char ta[100];  char advisor[100];}dataset;

    dataset std[100];

    while(fgets(row, 100, sset)!= NULL)
    {
        ptr = strtok(row,",");
        strcpy(std[total].f_name, ptr);

        ptr = strtok(NULL,",");
        strcpy(std[total].l_name, ptr);

        ptr = strtok(NULL,",");
        strcpy(std[total].major, ptr);

        ptr = strtok(NULL,",");
        strcpy(std[total].degree, ptr);

        ptr = strtok(NULL,",");
        std[total].gpa = atof(ptr);

        ptr = strtok(NULL,",");
        std[total].creh = atoi(ptr);

        ptr = strtok(NULL,",");
        strcpy(std[total].ta, ptr);

        ptr = strtok(NULL,",");
        strcpy(std[total].advisor, ptr);

        total++;
    }



    /*question 1: how many different degree?*/
    int denum=0,countd=0;
{/*Question 1: display degree*/

printf("1. Number of degrees: ");
    for (i=1;i<total;i++){
        j=0;
        for (j=0;j<i;j++)
        {
            if (strcmp(std[i].degree,std[j].degree)==0)
            {
                break;
            }
        }
        if (i==j) {
                denum++;
                printf("%s ",std[i].degree);

        }
    }
}


    { /*Question 2: top 3 gpa*/

    float max1=0,max2=0,max3=0;

    /*in here, compare max with each element of gpa to see if it greater.
    if it is, push the greatest to second and second max become third max*/
    for(i=1;i<total;i++){
        if (std[i].gpa>max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = std[i].gpa;
        }
        else if (std[i].gpa>max2 && std[i].gpa!=max1 )
                {
                    max3 = max2;
                    max2 = std[i].gpa;}
                else if (std[i].gpa>max3 && std[i].gpa!=max2 && std[i].gpa!=max1)
                    {max3 = std[i].gpa;}
    }
    printf("\n\n2. Top 3 GPA: %f, %f, %f\n",max1,max2,max3);
    printf("  People who have highest GPA=%f\n",max1);
    for (i=1;i<total;i++){
        if (std[i].gpa==max1) printf("    %s %s\n",std[i].f_name,std[i].l_name);
    }
    printf("  People who have 2nd highest GPA=%f\n",max2);
    for (i=1;i<total;i++){
        if (std[i].gpa==max2) printf("    %s %s\n",std[i].f_name,std[i].l_name);
    }
    printf("  People who have 3rd highest GPA=%f\n",max3);
    for (i=1;i<total;i++){
        if (std[i].gpa==max3) printf("    %s %s\n",std[i].f_name,std[i].l_name);
    }

    }


    {/*question 3 and 4*/

    float sumcre =0;
    float sumCS=0;
    int countCS =0;
    for (i=1;i<total;i++)
    {
        sumcre = sumcre + std[i].creh;
        if (strcmp(std[i].major,"Computer Science") == 0)
        {
            sumCS = sumCS + std[i].gpa;
            countCS++;
        }
    }
    float ave = sumcre/(total-1);
    printf("\n3. Average credit hours of the college: %f\n",ave);
    float avecs = sumCS/countCS;
    printf("\n4. Average GPA of the Computer Science department: %f\n",avecs);

    }

{/*question 5: department and advisor */

printf("5. The list of departments along with the total number of advisors");

char arr[100][50];
denum=0;
int count = 0;
    for (i=1;i<total;i++){
        j=0; count=0;
        for (j=0;j<i;j++)
        {
            if (strcmp(std[i].major,std[j].major)==0)
            {
                break;
            }
        }
        if (i==j) {
            denum++;
            /**/
            for (int p = 0; p<total;p++)
                if(strcmp(std[p].advisor,std[i].advisor)==0) count++;
            printf("\n  Department %s has %d advisors.",std[i].major,count);

        }
    }

}


return 0;

}
