#include "contact.h"

int main()
{
    int operation;
   AddressBook addressBook;
   addressBook.contactCount=0;
   printf("\n\n\n\033[1m<<<<<<<<<<<<<<<<<<<<<<<<<ADDRESS BOOK >>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n\n\n\n\n"); 
   //add_t(&addressBook);
   initialize(&addressBook);
   while(1)
   {
    printf("\e[0;36m--------------------------DISPLAY MENU ---------------------------\n\e[0m"); 
    printf("\e[0;33mEnter operation\nPress 1 to create contact\nPress 2 to edit contacts\nPress 3 to search in contacts\nPress 4 to perfom delete operation\nPress 5 to view all contacts\n\e[0m""\033[0;31mExit press 6\033[0m\n");
    printf("\n\e[0;36m--------------------------------------------------------------------\nEnter : \e[0m");
      //sleep(2);
   
     scanf("%d",&operation);
     switch(operation)
     {
        case 1:createContact(&addressBook);
                break;
        case 2:  editContact(&addressBook);break;
        case 3:  searchContact(&addressBook);break;
        case 4:  deleteContact(&addressBook);break;
        case 5 : listContacts(&addressBook);break;
        case 6 : add_t(&addressBook);
                 return 0;
        default : return 0;

     }
   }
   return 0;
}

