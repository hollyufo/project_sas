#include<stdio.h>
#include<stdlib.h>
struct student
{
 char id[30];
 int accountn;
 char lastname[30];
 char firstname[30];
 float balance;
}user;
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the Roll no   :");
 scanf("%s", user.id);
 printf("Enter account number :  ");
 scanf("%f", &user.balance);
 printf("Enter the Name      :");
 scanf("%s", user.firstname);
  printf("Enter the Name      :");
 scanf("%s", user.lastname);
 printf("Enter the balance      :");
 scanf("%f", &user.balance);
 fwrite(&user, sizeof(user), 1, fp);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nid  \taccountn \tfirst name \t last name \t balance\n\n");
 while (fread(&user, sizeof(user), 1, fp1))
 printf("%s\t %i    \t %s    \t%s     \t%.2f\n", user.id, user.accountn, user.lastname, user.firstname, user.balance);
 fclose(fp1);
}

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
       disp();
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
     printf("\nits not done still coding it\n");  
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