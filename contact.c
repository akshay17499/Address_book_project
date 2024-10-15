#include "contact.h"
void name_f(AddressBook *addressBook,int i)
{ 
  //int i=addressBook->contactCount;
    int flag=1;         //checking using flag value if flag value is 1 till the end of whileloop it considered as a successfull entry and breaks from the while loop
    printf("Contact n.o %d\n",i+1);
    while(flag)
    {
      printf("Enter name:");
      scanf(" %49[^\n]",addressBook->contacts[i].name);
      int len_1=strlen(addressBook->contacts[i].name);
      for(int j=0;j<len_1;j++)//loop for cheking correct entry
      {
        char c_char=addressBook->contacts[i].name[j];
        if(!(c_char>='a'&&c_char<='z' || c_char>='A'&&c_char<='z'||c_char==' ')) 
         {      
             printf("\033[0;31mEntered Name Invalid(Name can only have alphabets)\nTry Again\n\033[0m\n");
             flag=0;        
             break;
          }
      } 
      for(int j=0;j<i;j++)                    //loop to check duplicates
      {
        if(!strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name))
        {
          flag=0;
          printf("\033[0;31mName already exists\nTry Again\n\033[0m\n");
          break;
        }
      }
     if(flag==1)
       break;                //if everthing is correct exit the loop else stay in 
    flag=1;              // keep the loop to run continously if the requirements are not met
    }
}
void phone_num(AddressBook *addressBook,int i)
{
  //int i=addressBook->contactCount;
   printf("Enter phone number : ");
    int flag=1;    //checking using flag value if flag value is 1 till the end of whileloop it considered as a successfull entry and breaks from the while loop
    while(flag)
    {
      scanf("%s",addressBook->contacts[i].phone);
  
     int len= strlen(addressBook->contacts[i].phone); //finfing length of string phone no
     for(int j=0;j<len;j++)
     {
        if(!(addressBook->contacts[i].phone[j]>='0'&&addressBook->contacts[i].phone[j]<='9'&&len==10)) //checking the entered string is outside this range or not
              {  
                printf("\033[0;31mEnter valid phone number(length must be 10 && enter only numbers)\nTry Again\n\n\033[0m""\nEnter phone number :  ");       //if found true breaking the loop
                 break;                                                              
              }
              else if(len-1==j)
              { 
                
                   for(int j=0;j<i;j++)                    //loop to check duplicates
                    {
                       if(!strcmp(addressBook->contacts[i].phone,addressBook->contacts[j].phone))
                          {
                              flag=1;
                              printf("\033[0;31mPhone Number already exists\nTry Again\n\033[0m\n\nEnter phone number : ");
                               //printf("Name already exists Try Again\n");
                               break;
                          }
                          else if(j==i-1) //checking if the loop has run i-1 since the contact is goning to store @ ith contact
                          flag=0;        //for exiting thewhile loop
                    }

               
              }
     }
    
    }
}

void e_mail(AddressBook *addressBook,int i)
{
  //int i=addressBook->contactCount;
  printf("Enter email  : ");
  int flag=1;
   int flag1=1;
   char arr[50];
   int k=0;
   while((flag||flag1))
   {
    k=0;
   scanf("%s",addressBook->contacts[i].email);
   int len= strlen(addressBook->contacts[i].email);
  // printf("len->%d   arr->%s",len,arr);
   int count=0;
   int fag2=0;
   int dot=0;
   for(int j=0;j<len;j++)
   { 
    if(addressBook->contacts[i].email[j]>='0'&&addressBook->contacts[i].email[j]<='9'||addressBook->contacts[i].email[j]>='a'&&addressBook->contacts[i].email[j]<='z'||addressBook->contacts[i].email[j]>='A'&&addressBook->contacts[i].email[j]<='Z'||addressBook->contacts[i].email[j]=='@'||addressBook->contacts[i].email[j]=='.'||addressBook->contacts[i].email[j]=='_')
    {  
      if(addressBook->contacts[i].email[j]=='@')
      {
        if(j==0)
        {
         //printf("\033[0;31mTry to use format <name||digits>@<name||digits>.com\nTry Again\nEnter valid email id : \033[0m\n"); 
         break;
         count=0;
        }
             count++;
             fag2++;
             
      }
      if(fag2>0)
      fag2++;
      if(addressBook->contacts[i].email[j]=='.')
      dot++;
       if(j>len-5&&fag2>3&&j!=0)
       {
        //printf("j->%d\n",j);
        arr[k++]=addressBook->contacts[i].email[j];
            if(len-1==j)
              {
                 arr[k]='\0';
                 if(!(count==1))
                   {
                    printf("\033[0;31mTry to use format <name||digits>@<name||digits>.com\nTry Again\nEnter valid email id : \033[0m\n");
                   }     
                 else
                   flag=0;
               }
       }
    }
    else
    { 
      break;
    }
   } 
//printf("dot->%d\n",dot);
//printf("arr->%s\n",arr);
     if(strcmp(arr,".com")!=0||dot!=1)
      { k=0; printf("\033[0;31mTry to use format <name||digits>@<name||digits>.com\nTry Again\n\033[0m\n");printf("Enter valid email id : "); flag1=1; }
     else
     {
        for(int j=0;j<i;j++)                    //loop to check duplicates
        {
          if(!strcmp(addressBook->contacts[i].email,addressBook->contacts[j].email))
          {
            flag=1;
            printf("\033[0;31mEmail already exists Try Again \n\033[0m\n");
            printf("Enter New Email : ");

            break;
          }
          else if(j==i-1) //checking if the loop has run i-1 since the contact is goning to store @ ith contact
          flag=0;        //for exiting thewhile loop
        }
         flag1=0;

     }
     
  }

}

void find(AddressBook*addressBook,int n,int m)  //m=0(edit)   m=1(delete)
{

    char str[50];
    while(getchar()!='\n');
    scanf("%49[^\n]",str);
    int len1=strlen(str);
    int i=addressBook->contactCount;
    int t_count=0;
    int arr[50]={0};
    int j;
    int phone_flag=0;
    int temp=0;
    //int flag=1;
    printf("\033[0;36m---------------------------------------------------------------------\033[0m\n");
    printf("%-s%10s%30s%25s\n","N.O","NAME","PHONE NUMBER","EMAIL");
    printf("\033[0;36m---------------------------------------------------------------------\033[0m\n");
    for(int j=0;j<i;j++)
    {
      //phone_flag=0;
      int count=0;
      temp=0;
      int len=strlen(addressBook->contacts[j].name);
      for(int l=0;l<len;l++)
      { 
        if(n==1)
        {                
         if(addressBook->contacts[j].name[l]>='a')
          {
            if(str[count]<='Z'&&str[count]>='A')
            {
              str[count]=str[count]+32;
            }
          }
          else if(addressBook->contacts[j].name[l]<='Z'&&addressBook->contacts[j].name[l]>='A')
           {
              if(str[count]>='a'&&str[count]<='z')
               {
                  str[count]=str[count]-32;
                }
            }

            if(addressBook->contacts[j].name[l]==str[count])
            {
               if(count==0)
               temp=l;
               
               count++;
               if(count==len1)
                {
                  //flag=0;         
                  arr[++t_count]=j;
                  //printf("%d\n",t_count);
                  printf("%-5d%-25s%-25s%s\n\n",t_count,addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
                  break;
                }
            }
            else
            {
              if(count>0)
              l=temp;
               count=0;
            }
        }
        else if(n==2)
        {
          if(strstr(addressBook->contacts[j].phone,str)!=NULL)
           {    
                //phone_flag=0;
                arr[++t_count]=j;
                printf("%-5d%-25s%-25s%s\n\n",t_count,addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
           
            }
            //else
           // phone_flag=0;
           if(phone_flag==0)
           break;
        }
        else if(n==3)
        {
         if(addressBook->contacts[j].email[l]>='a')
          {
            if(str[count]<='Z'&&str[count]>='A')
            {
              str[count]=str[count]+32;
            }
          }
          else if(addressBook->contacts[j].email[l]<='Z'&&addressBook->contacts[j].email[l]>='A')
           {
              if(str[count]>='a'&&str[count]<='z')
               {
                  str[count]=str[count]-32;
                }
            }

            if(addressBook->contacts[j].email[l]==str[count])
            {
              if(count==0)
              temp=l;
               count++;
               if(count==len1)
                {
                  //flag=0;
                  ++t_count;         
                  arr[t_count]=j;
                  printf("%-5d%-25s%-25s%s\n\n",t_count,addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
                  break;
                }
            }
            else
            {
              if(count>0)
              l=temp;
               count=0;
            }
        }  
      }
    }
    int e_num=0;
    if(t_count==0)
        printf("No contacts found\n");
    else
     {
      int e_xi_t=1;
      while(e_xi_t)
      {
         e_num=1;
    
       if(m==0)
       {
        if(t_count>1)
         { printf("which contact u want to edit : "); 
          while(1)
          {
           scanf(" %d",&e_num);
           if(e_num>t_count)
           {  
             printf("Enter valid number : ");
           }
           else
             break;
          }
         }
            int operation;
            //printf("enum->%d arr[enum]->%d\n",e_num,arr[e_num]);
            int f_l_a_g=1;
         while(1)
         {  
          printf("\e[0;33mperform edit operation\npress 1 to edit name\npress 2 to edit phone number\npress 3 to edit email \n\e[0m" "\e[0;31mExit press 4 :  \e[0m");
            scanf("%d",&operation);
            switch(operation)
            {
                case 1 :  
                          name_f(addressBook,arr[e_num]);
                          break;
                case 2 : phone_num(addressBook,arr[e_num]);
                         break;
                case 3 : e_mail(addressBook,arr[e_num]); break;

                case 4: if(t_count==1)
                          return;
                          else
                          f_l_a_g=0;  
                default:return;        
            }
            if(f_l_a_g==0)
            break;
         }
         if(t_count>1)
         {
          printf("want to do more edit operation in searched name press 1 else press 0 : ");
          scanf("%d",&e_xi_t);

         }
         else 
         return;

       }
       else//delete
       {
         if(t_count>1)
           { 
             printf("which contact u want to delete : "); 
              while(1)
              {
                scanf(" %d",&e_num);
                if(e_num>t_count)
                {  
                  printf("\e[0;31mEnter valid number(entered value greater than given N.O)\e[0m : ");
                 }
                else
                {
                  e_xi_t=0;
                   break;
                } 
              }

           }
           else if(t_count==1)
           {
            e_num=1;
            break;
           }
           else
           {
            printf("No Contact Found !!");
            return;
           }
       }
      }
      //printf("arr[%d]->%d",e_num,arr[e_num]);
      if(m!=0)    //deleat m=1
      {
         printf("\e[0;31m REMOVING CONTACT \e[0m ");  
         printf("\n\e[0;36m--------------------------------------------------------------------\n6\e[0m");
         printf("%10s%30s%25s\n","NAME","PHONE NUMBER","EMAIL");
         printf("\n\e[0;36m---------------------------------------------------------------------\n\e[0m");
       for(int j=0;j<i;j++)
       {             
        if(arr[e_num]==j)
         {
                 
            printf("%-25s%-25s%s\n\n",addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);        
            for(int k=j;k<i-1;k++ )
            {
               addressBook->contacts[k]=addressBook->contacts[k+1];
            }
            addressBook->contactCount=addressBook->contactCount-1;
             return;
          }
        }
      }
    }  
}

void listContacts(AddressBook *addressBook) 
{
    int i=addressBook->contactCount;
     
   printf("\n\e[0;36m----------------------------------------------------------------------\n\e[0m");
   printf("%10s%30s%25s\n","NAME","PHONE NUMBER","EMAIL");
   printf("\n\e[0;36m-----------------------------------------------------------------------\n\e[0m");
    for(int j=0;j<i;j++)
    {
        printf("%3d. ",j+1);
        printf("%-25s%-25s%s\n\n",addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
       // printf("%+25s",addressBook->contacts[j].phone);
       // printf("%25s\n",addressBook->contacts[j].email);

    }
  printf("\n\e[0;36m-------------------------------------------------------------------------\n\e[0m");
}


void createContact(AddressBook *addressBook) 
{
   name_f(addressBook,addressBook->contactCount);
   phone_num(addressBook,addressBook->contactCount);
   e_mail(addressBook,addressBook->contactCount);
   addressBook->contactCount=addressBook->contactCount+1;
   //printf("%d",addressBook->contactCount);
}

void searchContact(AddressBook *addressBook) 
{
    printf("\e[0;33mTo search by name press 1\nTo search by phone number press 2\nTo search by email id press 3 \e[0m\n\e[0;31mTo EXIT press 4\e[0m\nEnter your choise : ");
    int option;
    char str[50];
    int i=addressBook->contactCount;
    int flag=1;
    scanf("%d",&option);
    switch(option)
    {
       case 1 :  printf("\nEnter name : ");
                  while(getchar()!='\n');
                 scanf("%49[^\n]",str);
                 printf("\n\e[0;36m-------------------------------------------------------------------\n\e[0m");
                 printf("%5s%30s%25s\n","NAME","PHONE NUMBER","EMAIL");
                 printf("\n\e[0;36m--------------------------------------------------------------------\n\e[0m");
                 int len=0;
                 int last = 0;
                 int len1=strlen(str);
                int flag=1;
                int temp;
                 for(int j=0;j<i;j++)
                {
                  int count=0;
                  len=strlen(addressBook->contacts[j].name);
                  for(int l=0;l<len;l++)
                  {
                        
                      if(addressBook->contacts[j].name[l]>='a')
                     {
                      if(str[count]<='Z'&&str[count]>='A')
                       {
                         str[count]=str[count]+32;
                        }
                     }
                     else if(addressBook->contacts[j].name[l]<='Z'&&addressBook->contacts[j].name[l]>='A')
                     {
                       if(str[count]>='a'&&str[count]<='z')
                       {
                          str[count]=str[count]-32;
                       }
                     }

                    if(addressBook->contacts[j].name[l]==str[count])
                    {
                      if(count==0)
                      temp=l;
                      // printf("temp->%d",temp);
                      count++;
                      if(count==len1)
                      {
                        flag=0;
                        printf("%-25s%-25s%s\n\n",addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
                        break;
                      }
                    }
                    else
                    {
                      if(count>0)
                      {
                        l=temp;
                      }
                      
                      count=0;
                    }

                  }
                }
                if(flag==1)
                printf("NO CONTACT FOUND!!!");
                printf("\n\e[0;36m--------------------------------------------------------------------\n\e[0m");
                return;
        case 2 :   printf("\nEnter phone number : ");
                 scanf("%s",str);
                len=strlen(str);
               printf("\n\e[0;36m---------------------------------------------------------------------\n\e[0m");
                printf("%5s%30s%25s\n","NAME","PHONE NUMBER","EMAIL");
                printf("\n\e[0;36m--------------------------------------------------------------------\n\e[0m");
                flag=1;
                 for(int j=0;j<i;j++)
                {
                  
                    if(NULL!=strstr(addressBook->contacts[j].phone,str))
                      {
                       
                         flag=0;
                        printf("%-25s%-25s%s\n\n",addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
                        
                      }
                  }   
              if(flag==1)
                  printf("Entry not found!!!\n"); 
                  printf("\n\e[0;36m------------------------------------------------------------------\n\e[0m");
                  return;  
        case 3 :  printf("\nEnter email1 : ");
                  while(getchar()!='\n');
                  char str[50];
                 scanf("%49[^\n]",str);
                 
                 flag=1;
                 printf("\n\e[0;36m-------------------------------------------------------------------\n\e[0m");
                 printf("%10s%30s%25s\n","NAME","PHONE NUMBER","EMAIL");
                 printf("\n\e[0;36m-------------------------------------------------------------------\n\e[0m");
                 len1=strlen(str);
                 for(int j=0;j<i;j++)
                {
                  int count=0;
                  len=strlen(addressBook->contacts[j].email);
                  for(int l=0;l<len;l++)
                  {
                        
                      if(addressBook->contacts[j].email[l]>='a')
                     {
                      if(str[count]<='Z'&& str[count]>='A')
                       {
                         str[count]=str[count]+32;
                        }
                     }
                     else if(addressBook->contacts[j].email[l]<='Z'&&addressBook->contacts[j].email[l]>='A')
                     {
                       if(str[count]>='a'&&str[count]<='z')
                       {
                          str[count]=str[count]-32;
                       }
                     }
                       //printf("%c ",str[count]);
                    if(addressBook->contacts[j].email[l]==str[count])
                    {//printf("3");
                      if(count==0)
                      temp=l;
                      count++;
                      if(count==len1)
                      {
                        flag=0;
                        printf("%-25s%-25s%s\n\n",addressBook->contacts[j].name,addressBook->contacts[j].phone,addressBook->contacts[j].email);
                        break;
                      }
                    }
                    else
                    {
                      if(count>0)
                      l=temp;
                      count=0;
                    }

                  }
                }
                if(flag==1)
                printf("NO CONTACT FOUND!!!");
                printf("\n\e[0;36m--------------------------------------------------------------------\n\e[0m");
                return;
                   
        default : printf("\e[0;31Wrong entry returning to main menu\n\e[0m");
        printf("\n\e[0;36m-------------------------------------------------------------------\n\e[0m");
        return;       
    }
    
    
}

void editContact(AddressBook *addressBook) 
{
    printf("\033[0;33mTo search by name press 1\nTo search by phone number press 2\nTo search by email press 3\n\033[0m""\033[0;31mEXIT press 4\033[0m\n""Enter your choise : ");
    int option;
    scanf("%d",&option);
    switch(option)
    {
      case 1 : printf("\e[0;36mEnter name : \e[0m");
              find(addressBook,1,0);break;
      case 2 : printf("\e[0;36mEnter phone number : \e[0m");
              find(addressBook,2,0);break;
      case 3 : printf("\e[0;36mEnter email  : \e[0m");
              find(addressBook,3,0);break;
      default:return;
    }
} 

void deleteContact(AddressBook *addressBook) 
{
  printf("\033[0;33mTo search by name press 1\nTo search by phone number press 2\nTo search by email press 3\n\033[0m" "\033[0;31mExit press 4\033[0m\n");
   int option;
  
   scanf("%d",&option);
   switch(option)
   {
    case 1 : printf("Enter name of contact u want to delete : ");
             find(addressBook,1,1);
             break;
             
  case 2 :  printf("Enter phone number of contact u want to delete : ");
            find(addressBook,2,1);
             break;
  case 3 :  printf("Enter email of contact u want to delete : ");
             find(addressBook,2,1);
             break;
    default : return;
   }
}


void add_t(AddressBook *addressBook)
{
   FILE *fptr=NULL;
   fptr=fopen("contacts.txt","w");
   if(fptr==NULL)
   {
    printf("\nFAILURE(not able to open file)\n");
   }
   for(int i=0;i<addressBook->contactCount;i++)
   {
    fprintf(fptr,"%s",addressBook->contacts[i].name);
    fprintf(fptr,"%c",',');
    fprintf(fptr,"%s",addressBook->contacts[i].phone);
     fprintf(fptr,"%c",',');
    fprintf(fptr,"%s\n",addressBook->contacts[i].email);
   }
   fclose(fptr);
}
