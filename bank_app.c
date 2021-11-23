#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char cincheck();
struct student
{
 int id;
 int accountn;
 char lastname[30];
 char firstname[30];
 float balance;
}user;
//    finction to add records
void insert()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the cin        :");
 scanf("%d", &user.id);
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
//    function to display the records
void disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nid  \taccountn \tlast name \t first name \t balance\n\n");
 while (fread(&user, sizeof(user), 1, fp1))
 printf("%d\t\t%i\t\t%s\t\t%s\t\t%.2f\n", user.id, user.accountn, user.lastname, user.firstname, user.balance);
 fclose(fp1);
}
//    function o check if the cin is there //
int avlrollno(int rno)
{
 FILE *fp;
 int c = 0;
 fp = fopen("Record", "r");
 while (!feof(fp))
 {
  fread(&user, sizeof(user), 1, fp);

  if (rno == user.id)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//    function to search the record
void search()
{
 FILE *fp2;
 int r, s, avl;
 printf("\nEnter the cin you want to search  :");
 scanf("%d", &r);
 avl = avlrollno(r);
 if (avl == 0)
  printf("cin %d is not available in the file\n",r);
 else
 {
  fp2 = fopen("Record", "r");
  while (fread(&user, sizeof(user), 1, fp2))
  {
   s = user.id;
   if (s == r)
   {
    printf("\ncin              = %d", user.id);
    printf("\nfirst Name       = %s", user.firstname);
    printf("\nlast Name        = %s", user.lastname);
    printf("\nacount number    = %d", user.accountn);
    printf("\nbalance          = %.2f\n", user.balance);
   }
  }
  fclose(fp2);
 }
}
//    Ffunction to deleted the record
void deletefile()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the cin you want to delete :");
 scanf("%d", &r);
 if (avlrollno(r) == 0)
  printf("Roll no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&user, sizeof(user), 1, fpo))
  {
   s = user.id;
   if (s != r)
    fwrite(&user, sizeof(user), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&user, sizeof(user), 1, fpt))
   fwrite(&user, sizeof(user), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
 }

}
//    function to updated the records
void update()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter cin number to update:");
 scanf("%d", &r);
 avl = avlrollno(r);
 if (avl == 0)
 {
  printf("the cin %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&user, sizeof(user), 1, fpo))
  {
   s = user.id;
   if (s != r)
    fwrite(&user, sizeof(user), 1, fpt);
   else
   {
    printf("\n\t1. Update cin Number %d", r);
    printf("\n\t2. Update the first and last name %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter new cin:");
     scanf("%d", &user.id);
     break;
    case 2:
     printf("Enter new first name : ");
     scanf("%s", user.firstname);
     printf("Enter new last name  : ");
     scanf("%s", user.lastname);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&user, sizeof(user), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&user, sizeof(user), 1, fpt))
  {
   fwrite(&user, sizeof(user), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}
//    function for operation diop and w
void operation()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter cin number to update:");
 scanf("%d", &r);
 avl = avlrollno(r);
 if (avl == 0)
 {
  printf("the cin %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&user, sizeof(user), 1, fpo))
  {
   s = user.id;
   if (s != r)
    fwrite(&user, sizeof(user), 1, fpt);
   else
   {
     float t;
    printf("\n\t1.DIPOSIT ");
    printf("\n\t2. WITHDRWAL");
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter amoout you wanna deposit :");
     scanf("%f", &t);
     user.balance = user.balance + t;
     break;
    case 2:
     printf("Enter the amount you wanna widthdrwal : ");
     scanf("%f", &t);
     user.balance = user.balance - t;
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&user, sizeof(user), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&user, sizeof(user), 1, fpt))
  {
   fwrite(&user, sizeof(user), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}

//function to chek if the file is empty
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
/* Function to sort the record */
void sort()
{
 int a[20], count = 0, i, j, t, c;
 FILE *fpo;
 fpo = fopen("Record", "r");
 while (fread(&user, sizeof(user), 1, fpo))
 {
  a[count] = user.id;
  count++;
 }
 c = count;
 for (i = 0; i<count - 1; i++)
 {
  for (j = i + 1; j<count; j++)
  {
   if (a[i]>a[j])
   {
    t = a[i];
    a[i] = a[j];
    a[j] = t;
   }
  }
 }
 printf("cin\t\tfirst Name\t\tlast name\t\tbalance\t\taccount number\t\t\n\n");
 count = c;
 for (i = 0; i<count; i++)
 {
  rewind(fpo);
  while (fread(&user, sizeof(user), 1, fpo))
  {
   if (a[i] == user.id)
    printf("\n%d\t\t %s \t\t %s \t\t %.2f \t\t%d",user.id, user.firstname, user.lastname , user.balance , user.accountn);
  }

 }
}
// MAIN PROGRAM
int main()
{
 int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. UPDATE\n\t6. OPERATION \n\t8. SORT");
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
       deletefile();
   break;
  case 5:
        update();
   break;
  case 6: 
      operation(); 
   break;
  case 7:
   exit(1);
   break;
  case 8:
    sort();
    break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);
}