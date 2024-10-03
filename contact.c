#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
    int i=addressBook->contactCount;
    for(int j=0;j<i;j++)
    {
        printf("name->%s\n",addressBook->contacts[j].name);
        printf("phone->%s\n",addressBook->contacts[j].phone);
        printf("email->%s\n",addressBook->contacts[j].email);

    }
    
}

/*void initialize(AddressBook *addressBook) 
{
    
}*/

void createContact(AddressBook *addressBook) 
{
    int i=addressBook->contactCount;
   printf("enter name:");
   scanf("%s",addressBook->contacts[i].name);
   printf("enter phone number");
   scanf("%s",addressBook->contacts[i].phone);
   printf("enter email");
   scanf("%s",addressBook->contacts[i].email);
    addressBook->contactCount=addressBook->contactCount+1;
   printf("%d",addressBook->contactCount);
     
}

void searchContact(AddressBook *addressBook) 
{
    printf("enter the name to find in contact");
    char str[50];
    scanf("%s",str);
    int i=addressBook->contactCount;
    for(int j=0;j<i;j++)
    {
        if(strcmp(addressBook[j].contacts->name,str)==0)
        {
        printf("name->%s\n",addressBook->contacts[j].name);
        printf("phone->%s\n",addressBook->contacts[j].phone);
        printf("email->%s\n",addressBook->contacts[j].email); 
        return;
        }
    }
  printf("entry not found");
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
