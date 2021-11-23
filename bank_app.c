#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char cincheck();
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
 printf("Enter the cin        :");
 scanf("%s", user.id);
 printf("Enter account number :  ");
 scanf("%i", &user.accountn);
 printf("Enter the first Name :");
 scanf("%s", user.firstname);
  printf("Enter the last Name :");
 scanf("%s", user.lastname);
 printf("Enter the balance    :");
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
 printf("%s\t %i       \t %s      \t%s   \t%f\n", user.id, user.accountn, user.lastname, user.firstname, user.balance);
 fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void search()
{
 FILE *fp2;
 char r[50], s[50], avl[50];
 printf("\nEnter the CIN you want to search  :");
 scanf("%s", r);
 avl[30] = cincheck(r);
 if (avl[30] == 0)
  printf("Roll No %s is not available in the file\n",r);
 else
 {
  fp2 = fopen("Record", "r");
  while (fread(&user, sizeof(user), 1, fp2))
  {
   s[30] = user.id;
   if (strcmp(s[30], r[30]) == 0)
   {
    printf("\nRoll no = %s", user.id);
    printf("\nName    = %s", user.firstname);
    printf("\nMark    = %.2f\n", user.balance);
   }
  }
  fclose(fp2);
 }
}
char cincheck(char rno[30])
{
 FILE *fp;
 char c = 0;
 fp = fopen("Record", "r");
 while (!feof(fp))
 {
  fread(&user, sizeof(user), 1, fp);

  if (strcmp(rno[30], user.id) == 0)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("Record", "r");
 while (fread(&user, sizeof(user), 1, fp))
  c = 1;
 fclose(fp);
 return c;
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
      search();
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