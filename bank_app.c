#include<stdio.h>
#include <stdlib.h>

typedef struct coustumer{
    char id[50];
    char fname[50];
    char lname[50];
    int accountn;
    float balance;
}users;
//function to insert info to the file 
void insert()
{
    users foo;
    // open file in append mode
    FILE *fp;
    fp = fopen("accounts.txt", "a");
    // if file is not opened then exit
    if (fp == NULL)
    {
        printf("Error in opening file");
        exit(0);
    }
    // take user input
    printf("Enter first Name : ");    
    scanf("%s", foo.fname);
    printf("Enter last Name : ");    
    scanf("%s", foo.lname);
    printf("Enter CIN number:");
    scanf("%s", foo.id);
    printf("Enter the account number : ");
    scanf("%d", &foo.accountn);
    printf("Enter the balance : ");
    scanf("%f", &foo.balance);
    // write data to file
    fprintf(fp, "%s,%s,%s,%d,%f\n", foo.fname, foo.lname, foo.id, foo.accountn, foo.balance);
    // close file
    fclose(fp);
}
//function to display accounts


// MAIN PROGRAM
// MAIN PROGRAM
int main()
{
 int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. UPDATE\n\t6. SORT");
  printf("\n\t7. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   break;
  case 3:
   printf("\nits not done still coding it\n");
   break;
  case 4:
       printf("\nits not done still coding it\n");
   break;
  case 5:
   printf("\nits not done still coding it\n");
   break;
  case 6:

   break;
  case 7:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);
}