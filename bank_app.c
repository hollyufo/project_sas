#include<stdio.h>
#include <stdlib.h>

struct coustumer{
    char id[50];
    char name[50];
    int accountn;
    float balance;
}users;
//function to insert info to the file 
void insert()
{
  FILE *fp;
  fp = fopen("Record", "a");
  printf("Enter CIN number:");
  scanf("%s", &users.id[50]);
  printf("Enter the Name : ");
  scanf("%s", &users.name[20]);
  printf("Enter the account number : ");
  scanf("%d", &users.accountn);
  printf("Enter the balance : ");
  scanf("%f", &users.balance);
  fwrite(&users, sizeof(users), 1, fp);
  fclose(fp);
}
//function to display accounts
void disp()
{
    FILE *fp1;
    fp1 = fopen("Record", "r");
    printf("\nid Number\tName\taccount Number\tbalance\n\n");
    while (fread(&users, sizeof(users), 1, fp1))
    printf("  %s\t\t%s\t%d\t%.2f\n", users.id, users.name, users.accountn, users.balance);
    fclose(fp1);
}
//function to search the record
void search()
{
 FILE *fp2;
 int r, s, t;
 printf("\nEnter the Roll no you want to search  :");
 scanf("%d", &r);
 t = cincheck(r);
 if (avl == 0)
  printf("ID %d is not available in the file\n",r);
 else
 {
  fp2 = fopen("Record", "r");
  while (fread(&users, sizeof(users), 1, fp2))
  {
   s = user.id;
   if (s == r)
   {
    printf("\nRoll no : %s", users.id);
    printf("\nName    : %s", users.name);
    printf("\nAccount number : %d ", users.accountn)
    printf("\nBlanace    = %.2f\n", stud.balance);
   }
  }
  fclose(fp2);
 }
}
//function to update ..
void update()
{
 int t;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter Id to update the account :");
 scanf("%d", &r);
 t = cincheck(r);
 if (avl == 0)
 {
  printf("Roll number %s is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&users, sizeof(users), 1, fpo))
  {
   s = stud.rollno;
   if (s != r)
    fwrite(&users, sizeof(users), 1, fpt);
   else
   {
    printf("\n\t1. Update id number %d", r);
    printf("\n\t2. Update the balance %d", r);
    printf("\n\t3. Update both Name and id %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter id:");
     scanf("%s", &users.id);
     break;
    case 2:
     printf("Enter balance to a : ");
     scanf("%f", &users.balance);
     break;
    case 3:
     printf("Enter Name: ");
     scanf("%s", &users.name);
     printf("Enter id: ");
     scanf("%s", &users.id);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&users, sizeof(users), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&users, sizeof(users), 1, fpt))
  {
   fwrite(&users, sizeof(users), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}


// MAIN PROGRAM
void main()
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
    emp = empty();
    if (emp == 0)
        printf("\nThe file is EMPTY\n");
   else
        disp();
   break;
  case 3:
   printf("\nThe file is EMPTY\n");
   break;
  case 4:
   printf("\nThe file is EMPTY\n");
   break;
  case 5:
   printf("\nThe file is EMPTY\n");
   break;
  case 6:
    printf("\nThe file is EMPTY\n");
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
