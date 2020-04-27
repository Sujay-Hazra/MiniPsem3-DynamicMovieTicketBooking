#include<stdio.h>
#include<conio.h>
#include<string.h>
#define clrscr() system("cls")
#include<stdlib.h>
int no_seat,no_row,totseat,price,booked_seats=0;
char movieinfo[50];
struct node
{
 char name[50];
 int seat[50],nos,cost;
 struct node *link;
}*first=NULL;
void calculation();
void initialization();
void booking();
void book();
void cancel();
void add();
int main(){
 int choice;
 clrscr();
 printf("_ _ _ _ _ WELCOME _ _ _ _ _\n");
 while(1)
 {
   printf("\nChoose your option:-\n\n1.Initialize Booking\n\n2.Start Booking\n\n3.Finish & Calculate\n\n4.Quit Program\n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n");
   scanf("%d",&choice);
   if(choice==1)
   initialization();
   else if(choice==4)
   exit(0);
   else if(no_seat!=0 && no_row!=0)
   {
   if(choice==2)
   booking();
   else if(choice==3)
   calculation();
   else
   printf("Enter Valid Choice\n");
   getch();
   }
   else
  {
   //clrscr();
   printf("\nInitialize the movie info properly first!!");
   getch();
   main();
  }
 }
}
void initialization()
{
 int y=1;
 //clrscr();
 while(y)
 {
 printf("Enter Movie Info\n (press tab once done)\n");
 scanf("%[^\t]s",movieinfo);
 printf("Enter No. of Seats in each row \n");
 scanf("%d",&no_seat);
 printf("Enter No. of Rows\n");
 scanf("%d",&no_row);
 printf("Enter Price of each Ticket\n");
 scanf("%d",&price);
 printf("save info?\n0.Yes\n1.No\n");
 scanf("%d",&y);
 clrscr();
 if(y!=0)
  {
   printf("Continue or Go back to main menu?\n1.Continue\n2.Go Back\n");
   scanf("%d",&y);
  }
 if(y==2)
  {
  no_seat=0;
  main();
  }
 }
 printf("Movie Info saved\n");
 getch();
 main();
}
void booking()
{
 int y;
 clrscr();
 printf("_-_-_-_ Movie Info _-_-_-_\n\n %s\n\nPrice Per Ticket:%d\n",movieinfo,price);
 b: printf("\nChoose Option\n\n1.Book\n\n2.Cancel Booking\n\n3.Exit\n\n_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
 scanf("%d",&y);
 if(y==1)
 {
   if(booked_seats==(no_seat*no_row))
   {
    clrscr();
    printf("\n-_-_-_* HOUSE FULL *_-_-_-\nFurther Booking Not Possible!!\n");
    getch();
    booking();
   }
   else
   book();
 }
 else if(y==2)
  cancel();
 else if(y==3)
  main();
 else
  {
  printf("\nEnter Valid Option\n");
  goto b;
  }
getch();
}
void book()
{
 int i,j,h,match=0,choice,z=1,k=1;
 struct node* temp=first;
 clrscr();
 printf("\n\tSeating Arrangement\n");
 printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
 for(i=0;i<no_row;i++)
  {
   for(j=0;j<no_seat;j++)
   {
    printf("%d\t",k);
    k++;
   }
   printf("\n");
  }
 k=1;
printf("\nCurrent seating arrangement\n");
 printf("-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-\n");
for(i=0;i<no_row;i++)
 {
   for(j=0;j<no_seat;j++)
    {
     while(temp!=NULL)
     {
       for(h=0;h<temp->nos;h++)
       {
	if(temp->seat[h]==k)
	{
	 printf("0\t");
	 k++;
	 match=1;
	 goto m;
	}
       }
     temp=temp->link;
    }
   m: temp=first;
    if(match==0)
    {
     printf("%d\t",k);
     k++;
    }
    match=0;
   }
   printf("\n");
  }
  while(z)
 {
  printf("\n-_-_-_-_* Choose Option *_-_-_-_-\n1.Proceed\n2.Exit\n");
  scanf("%d",&choice);
  if(choice==1)
   {
   add();
   booking();
   }
  else if(choice==2)
   booking();
  else
   printf("\nEnter valid option!!\n");
 }
}
void add()
{  struct node *temp,*temp2=first;
   int *a,i,j;
   a=(int *)calloc((no_row*no_seat),2);
   temp=(struct node*)malloc(sizeof(struct node));
   printf("\nEnter Full Name:\n");
   scanf("%s",temp->name);
   ll: printf("Enter No. of Seats:\n");
   scanf("%d",&temp->nos);
   if(temp->nos > (no_row*no_seat)-booked_seats)
   {
     printf("No of seats exceeds capacity please enter again!!\nSeats Available: %d\n",(no_row*no_seat)-booked_seats);
     goto ll;
     }
   if(temp->nos==0)
    { printf("NUMBER CANT BE ZERO!!\n");
      goto ll;
     }
   printf("Enter seat nos:\n");
   for(i=0;i<temp->nos;i++)
   {
     C: scanf("%d",&temp->seat[i]);
     *(a+i)=temp->seat[i];
     if(temp->seat[i]>(no_row*no_seat))
       {
	printf("Seat non existant\nEnter Again\n");
	goto C;
       }
     for(j=0;j<i;j++)
     { if(*(a+j)==temp->seat[i])
	{
	 printf("Seat just booked, Enter different seat\n");
	 goto C;
	 }
	}
     if(temp->seat[i]==0)
      {
       printf("NUMBER CANT BE ZERO\n Re Enter!!\n");
       goto C;
      }
     while(temp2!=NULL)
     { for(j=0;j<temp2->nos;j++)
	  {
	    if(temp->seat[i]==temp2->seat[j])
	    {
	     printf("Seat Already Booked, Please Enter Different Seat!!\n");
	     goto C;
	    }
	   }
	  temp2=temp2->link;
     }
     temp2=first;
     booked_seats++;
   }
   temp->cost=price*temp->nos;
   clrscr();
   printf("Booking Succesful!!\nPay %d at the counter\nSEATS BOOKED:\n",temp->cost);
   for(i=0;i<temp->nos;i++)
    {
     printf("%d\n",temp->seat[i]);
     }
   temp->link=first;
   first=temp;
   getch();
  }
 void calculation()
 {
  struct node*temp=first;
  clrscr();
  totseat=no_seat*no_row;
  printf("-_-_-_-_-_-_-_* CALCULATION *_-_-_-_-_-_-_-");
  if(totseat==booked_seats)
  printf("\nCongrats!!!\n H\tO\tU\tS\tE\nF\tU\tL\tL\n");
  printf("\nTotal Seat available :  %d\n",totseat);
  printf("\nNumber of seats booked :  %d\n",booked_seats);
  printf("\nTotal Revenue for this movie :  %d\n",price*booked_seats);
  printf("\nPercentage of booked seats :  %d%",(booked_seats*100)/totseat);
  printf("\n-_-_-_-_* Record of Customers *_-_-_-_-\n\tNAME\t\tNo. of Tickets\t\tCost\n");
  while(temp!=NULL)
  {
   printf("\n\t%s\t\t %d\t\t %d\n",temp->name,(temp->cost)/price,temp->cost);
   temp=temp->link;
  }
  printf("\n\nBACK\n");
  getch();
  main();
 }
  void cancel()
 {
   struct node *temp=first;
   char Name[50];
   int y=1,cancel_amount=0,i,j,nus,*seats,flag=0;
   seats=(int *)calloc(nus,totseat);
   clrscr();
   if(booked_seats==0)
    {
     printf("No Seats Booked Yet");
     getch();
     booking();
     }
   printf("-_-_-_-_* CANCELLATION *_-_-_-_-\nEnter any number to Continue\nPress 0 to go Back\n");
   scanf("%d",&y);
   while(y)
   {
   printf("\nEnter your Name (under which the ticket was previously booked)\n");
   scanf("%s",Name);
   while(temp!=NULL)
   {
    if(strcmp(Name,temp->name)==0)
    {
    printf("* Name Found *, Displaying Booked Tickets:\n");
     for(i=0;i<temp->nos;i++)
     {
      printf("%d\n",temp->seat[i]);
     }
     flag++;
     break;
     }
     temp=temp->link;
    }
   if(flag==0)
   {
    printf("\nName not found please Re enter!!\n");
    getch();
    cancel();
   }
   printf("\nEnter the no. of tickets to be Cancelled\n");
   u: scanf("%d",&nus);
   if(nus>temp->nos)
    {
     printf("\nNo. of ticket to be cancelled cant be greater than tickets booked\n");
     printf("\nEnter again\n");
     goto u;
    }
   if(nus==0)
   {
     printf("\nNUMBER CANT BE ZERO!!\n Re Enter!!\n");
     cancel();
    }
   j=0;
   flag=0;
   printf("Enter Seat Numbers to Cancel\n");
   for(i=0;i<nus;i++)
   {
     mg: scanf("%d",seats);

     if(*seats==0)
     {
      printf("NO CAN'T BE ZERO!! RE ENTER!! \n");
      goto mg;
     }

     while(j<temp->nos)
     {
     if(*seats==temp->seat[j])
       {
       flag++;
       break;
       }
      j++;
     }
     if(flag!=0)
     {
      temp->seat[j]=0;
      booked_seats--;
      cancel_amount++;
      printf("Ticket succesfully cancelled\n");
      j=0;
      seats++;
     }
     if(flag==0)
     {
      printf("seat no. not found please re enter\n");
      j=0;
      goto mg;
     }
     flag=0;
    }
    temp->cost=(temp->cost)-(cancel_amount*price);
    clrscr();
    printf("Tickets are Cancelled\n Collect Rs%d\nPress Enter to go Back",cancel_amount*price);
    getch();
    y=0;
   }
   booking();
      }

