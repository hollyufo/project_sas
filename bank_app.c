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
