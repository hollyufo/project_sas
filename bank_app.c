#include<stdio.h>
struct costumer
{
 char ID[20];
 char name[30];
 int accountnum;
 float balance;
}user;
// function to insert records to the file
void insert(){
  FILE *fp;
  fp = fopen("Record", "a");
  printf("Enter Id number : ");
  scanf("%s", &user.ID);
  printf("Enter the Name : ");
  scanf("%s", &user.name);
  printf("Enter account number : ");
  scanf("%d", &user.accountnum)
  printf("Enter the balance : ");
  scanf("%f", &user.balance);
  fwrite(user, sizeof(user), 1, fp);
  fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void disp()
{
    FILE *fp1;
    fp1 = fopen("Record", "r");
    printf("\nid Number\tName\tbalance\tbalance\n\n");
    while (fread(&stud, sizeof(stud), 1, fp1))
    printf("  %s\t\t%s\t%d\t%.2f\n", student.id, user.name, user.accountnum, user.balance);
    fclose(fp1);
}
// function to search 
void search(){
    FILE *fp2;
    int r, s, t;
    printf("\nEnter the id you want to search : ");
    scanf("%s", &r);
    t = tid(r);
    if (t == 0){
        printf("the id %s is not available in the records.\n", r);
    }
    else {
        fp2 = fopen("Record", "r");
        while (fread(&user, sizeof(user), 1, fp2))
        {
            s = user.ID;
            if (s == r){
                printf("\nid  = %s", user.ID);
                printf("\nName    = %s", user.name);
                printf("\nbalnace    = %.2f\n", user.balance);
                printf("\naccount number = %d\n" user.accountnum);
            }
        }
        fclose(fp2);
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
        search();
   break;
  case 4:
        deletefile();
   break;
  case 5:
        update();
   break;
  case 6:
        emp = empty();
        if (emp == 0)
        printf("\n The file is EMPTY\n");
   else
        sort();
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
