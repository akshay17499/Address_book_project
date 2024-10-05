#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
    int i=addressBook->contactCount;
    for(int j=0;j<i;j++)
    {
        printf("---------------------------------\n");
        printf("name  -> %s\n",addressBook->contacts[j].name);
        printf("phone -> %s\n",addressBook->contacts[j].phone);
        printf("email -> %s\n",addressBook->contacts[j].email);

    }
     printf("---------------------------------\n");
}


void createContact(AddressBook *addressBook) 
{
    int i=addressBook->contactCount;
   printf("enter name:");
   scanf("%49[^\n]",addressBook->contacts[i].name);
   
   printf("enter phone number : ");
    int flag=1;
    while(flag)
    {
      scanf("%s",addressBook->contacts[i].phone);
  
     int len= strlen(addressBook->contacts[i].phone);
     for(int j=0;j<len;j++)
     {
        if(!(addressBook->contacts[i].phone[j]>='0'&&addressBook->contacts[i].phone[j]<='9'))
              {   
                 printf("enter valid phone number : ");
                 break;
              }
              else if(len-1==j){

               flag=0; 
              }
     }
    
    }
   printf("enter email");
   flag=1;
   int flag1=1;
   char arr[5];
   int k=0;
   while((flag||flag1))
   {
   scanf("%s",addressBook->contacts[i].email);
   int len= strlen(addressBook->contacts[i].email);
   int count=0;
    for(int j=0;j<len;j++)
    {
      if(addressBook->contacts[i].email[j]=='@')
      {
             count++;
             
      }
      
       if(j>len-5)
       {
        arr[k++]=addressBook->contacts[i].email[j];
    if(len-1==j)
      {
        arr[k]='\0';
        if(!(count==1))
          {
             printf("enter valid email id : "); 
          }     
          else
          flag=0;
      }
       }
    }
//printf("%s",arr);
if(strcmp(arr,".com")!=0)
{ k=0; printf("enter valid email id : ");  }
else
flag1=0;

}
addressBook->contactCount=addressBook->contactCount+1;
   //printf("%d",addressBook->contactCount);
}

void searchContact(AddressBook *addressBook) 
{
    printf("To search by name press 1\nTo search by phone number press 2\nTo search by email id press 3 \nEnter your choise : ");
    int option;
    char str[50];
    int i=addressBook->contactCount;
    scanf("%d",&option);
    switch(option)
    {
       case 1 :  printf("\nEnter name : ");
                 scanf("%s",str);
                
                 for(int j=0;j<i;j++)
                {
                    if(strcmp(addressBook->contacts[j].name,str)==0)
                      {
                        printf("name->%s\n",addressBook->contacts[j].name);
                        printf("phone->%s\n",addressBook->contacts[j].phone);
                        printf("email->%s\n",addressBook->contacts[j].email); 
                        return;
                      }
                 }
                  printf("entry not found"); break;
        case 2 :   printf("\nEnter phone number : ");
                 scanf("%s",str);
                
                 for(int j=0;j<i;j++)
                {
                    if(strcmp(addressBook->contacts[j].phone,str)==0)
                      {
                        printf("name->%s\n",addressBook->contacts[j].name);
                        printf("phone->%s\n",addressBook->contacts[j].phone);
                        printf("email->%s\n",addressBook->contacts[j].email); 
                        return;
                      }
                 }
                  printf("entry not found"); break;  
        case 3 :  printf("\nEnter email : ");
                 scanf("%s",str);
                
                 for(int j=0;j<i;j++)
                {
                    if(strcmp(addressBook->contacts[j].email,str)==0)
                      {
                        printf("name->%s\n",addressBook->contacts[j].name);
                        printf("phone->%s\n",addressBook->contacts[j].phone);
                        printf("email->%s\n",addressBook->contacts[j].email); 
                        return;
                      }
                 }
                  printf("entry not found"); break;   
        default : printf("wrong entry returning to main menu\n");       
    }
    
    
}

void editContact(AddressBook *addressBook) 
{
    printf("enter the contact name u want to edit");
    char name[50];
    scanf("%s",name);
    int i=addressBook->contactCount;
    for(int j=0;j<i;j++)
    {
        if(strcmp(addressBook->contacts[j].name,name)==0)
        {
            int operation;
            printf("perform edit operation\npress 1 to edit name\npress 2 to edit phone number\npress 3 to edit email : ");
         while(1)
         {  
            scanf("%d",&operation);
            switch(operation)
            {
                case 1 : printf("enter new name:");
                          scanf("%s",addressBook->contacts[j].name);
                          break;
                case 2 : printf("enter new phone number");
                         scanf("%s",addressBook->contacts[j].phone);
                         break;
                case 3 : printf("edit email");
                         scanf("%s",addressBook->contacts[j].email);
            }
            int n=0;
            printf("to countinue edit press 1 else 0");
            scanf("%d",&n);
            if(n==0)
            return;
         }

        }
    }
printf("no contacts found");
}

void deleteContact(AddressBook *addressBook) 
{
   printf("name of contact that u want to delete");
   char name[50];
   scanf("%s",name);
   int i=addressBook->contactCount;
   for(int j=0;j<i;j++)
   {
       printf("1");
    if(strcmp(addressBook->contacts[j].name,name)==0)
    {
        printf("removing ");
        
        printf("name->%s\n",addressBook->contacts[j].name);
        printf("phone->%s\n",addressBook->contacts[j].phone);
        printf("email->%s\n",addressBook->contacts[j].email); 
        for(int k=j;k<i-1;k++ )
        {
            addressBook->contacts[k]=addressBook->contacts[k+1];
        }
        addressBook->contactCount=addressBook->contactCount-1;
        return;
    }
   }
printf("no such contact found");
}
