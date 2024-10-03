#include "contact.h"

int main()
{
    int operation;
   printf("enter operation");
   AddressBook addressBook;
   addressBook.contactCount=0;
   while(1)
   {
     scanf("%d",&operation);
     switch(operation)
     {
        case 1:createContact(&addressBook);
                break;
        case 2:  editContact(&addressBook);break;
        case 3:  searchContact(&addressBook);break;
        case 4:  deleteContact(&addressBook);break;
        case 5 : listContacts(&addressBook);

     }

   }
}

