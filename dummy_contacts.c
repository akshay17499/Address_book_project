#include "contact.h"
// Dummy contact data
static Contact dummyContacts[] = {
    {"John Doe", "1234567890", "john@example.com"},
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Frank Miller", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}
};
int n=sizeof(dummyContacts)/sizeof(Contact);
void initialize(AddressBook *addressBook) 
{
    FILE *fp=NULL;
    fp=fopen("contacts.txt","a+");
    if(fp==NULL)
    {
        printf("ERROR!!!!");
        return ;
    }
    fseek(fp,0,SEEK_SET);
   
    char ch[50];
    //fgets(ch,50,fp);
    //printf("%s",ch);
    FILE *fp1=NULL;
    //fseek(fp1,0,SEEK_END);
    int i =0;
    // printf("fp1(l0cation)->%d\n",ftell(fp1));
    while(fgetc(fp)!=EOF)
    {   
        //printf("1");
        char ch;
        int k=0;
        fseek(fp,-1,SEEK_CUR);
        while((ch=fgetc(fp))!=',')
        {
        addressBook->contacts[i].name[k]=ch;
        k++;
        }
        addressBook->contacts[i].name[k]='\0';
        k=0;
       while((ch=fgetc(fp))!=',')
       {
        addressBook->contacts[i].phone[k]=ch;
        k++;
       }
        addressBook->contacts[i].phone[k]='\0';
        k=0;
       while((ch=fgetc(fp))!='\n')
       {
        addressBook->contacts[i].email[k]=ch;
         k++;
       }
        addressBook->contacts[i].email[k]='\0';
       // printf("%s%s%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
      addressBook->contactCount=addressBook->contactCount+1;
        
    i++;
    }
    return;
    
}


