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
void deletefile

