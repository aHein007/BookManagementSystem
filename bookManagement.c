#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DATASIZE 100

int addBook();
int addfileData(int id, char bookTitle[50], char authorName[50]);
int displayAllBook();

//Global variable

int db_count =0;

struct booksInfo
{
   int bookId;
   char bookTitle[50];
   char authorName[50];
};

struct booksInfo db[DATASIZE];




int main(){
    int choiceNumber = 0;
   

    printf("####Welcome to Our Book Management System####\n");
    printf("1. Add Book\n");
    printf("2. Delete Book\n");
    printf("3. Search Book\n");
    printf("4. Display All Books\n");
    printf("5. Exits\n");

    printf("Enter your Choice:");
    scanf("%d",&choiceNumber);

    switch(choiceNumber){
        case 1:
           
            addBook();
            break;

        case 2:
            printf("Delete Book");
            break;
        
        case 3:
            printf("Search Book");
            break;

        case 4:
            displayAllBook();
            break;

        case 5:
            printf("this is exits");
            break;

        default:
            printf("Please enter between 1~5!");
            break;
    }

    return 0;
}


int addBook(){

            int bookId;
            char bookTitle[50];
            char authorName[50];

            printf("Enter your Book id:");
            scanf("%d",&bookId);

            printf("Please enter your Book Name:");
            scanf(" %[^\n]",bookTitle);

            printf("Please enter authorName:");
            scanf(" %[^\n]",authorName);

            addfileData(bookId,bookTitle,authorName);

            printf("Your book was added successfully!");
}


int addfileData(int id, char bookTitle[50], char authorName[50]){
    FILE *fptr = fopen("bookTitle.txt","a");

    if(fptr == NULL){
        printf("Your txt file has error!");
    }else{
        //put book in file.
        fprintf(fptr,"%d %s %s\n", id, bookTitle, authorName);

        // put boo in db structure array.
        db[db_count].bookId =id;
        strcpy(db[db_count].bookTitle,bookTitle);
        strcpy(db[db_count].authorName,authorName);
        db_count++;
    }


 fclose(fptr);

   
}



int displayAllBook(){
    FILE *fptr = fopen("bookTitle.txt","r");
    int id = 0;
    char title[50];
    char author[50];

    if(fptr == NULL){
        printf("Your txt file has error!");
    }else{
         printf("####Book List####\n");
      while(fscanf(fptr,"%d %s %s",&id,title,author) != EOF){// read the data with fscanf
         printf("Book Id:%d BookTitle:%s AuthorName:%s\n",id,title,author);
      }
       
    }

    fclose(fptr);
}



//  cout<<"####Welcome to Our Book Management System####\n";
//     cout<<"1. Add Book\n";
//     cout<<"2. Delete Book\n";
//     cout<<"3. Search Book\n";
//     cout<<"4. Display All Books \n";
//     cout<<"5. Exits\n";

//     cout<<"Enter your choice:";