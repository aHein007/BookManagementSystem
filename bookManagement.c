#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DATASIZE 100

int addBook();
int addfileData(int id, char bookTitle[50], char authorName[50]);
int displayAllBook();
int searchBooks();
int deleteBook();

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
            deleteBook();
            break;
        
        case 3:
            searchBooks();
            break;

        case 4:
            displayAllBook();
            break;

        case 5:
            printf("#####Good Bye#####");
            exit(1);
            break;

        default:
            printf("Please enter between 1~5!");
            exit(1);
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

// add Books
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

//searchBooks

int searchBooks(){

    char user_search[50];
    int id = 0;
    char title[50];
    char name[50];
    int bookFound =0;

    printf("Enter Search Book:");
    scanf(" %[^\n]",user_search);

    FILE *fptr = fopen("bookTitle.txt","r");

    if(fptr != NULL){
        while(fscanf(fptr,"%d %s %s",&id,title,name) != EOF){
            db[db_count].bookId = id;
            strcpy(db[db_count].bookTitle,title);
            strcpy(db[db_count].authorName,name);
            db_count++;
        }

        int i =0;
        while(i < db_count){
            if(strcmp(db[i].bookTitle,user_search) == 0){// 0 is true , 1 is false
                  printf("BookId:%d  BookTitle:%s  BookAuthorName:%s\n",db[i].bookId , db[i].bookTitle , db[i].authorName);
                bookFound =1;
                
            }
            i++;
        }

      if(bookFound == 0)
          printf("Your Book is not found!");
      

    }else{
        printf("Your txt have been error!");
    }


    fclose(fptr);

}

//display all Books
int displayAllBook(){
    FILE *fptr = fopen("bookTitle.txt","r");
    int id = 0;
    char title[50];
    char author[50];

    if(fptr == NULL){
        printf("Your txt file has error!");
    }else{
         printf("####Book List####\n");
      while(fscanf(fptr,"%d %s %s",&id ,title ,author) != EOF){// read the data with fscanf
         printf("Book Id:%d  BookTitle:%s  AuthorName:%s\n",id,title,author);
      }
       
    }

    fclose(fptr);
}


int deleteBook(){
    FILE *fptr = fopen("bookTitle.txt","r");
    int id =0;
    char title[50];
    char author[50];
    int db_count = 0;
    int search_id =0;
    int i = 0;
    int bookFound = 1;

    printf("Enter your book id to Delete:");
    scanf("%d",&search_id);


    if(fptr != NULL){
        while(fscanf(fptr,"%d %s %s",&id,title,author) != EOF){
            db[db_count].bookId = id;
            strcpy(db[db_count].bookTitle,title);
            strcpy(db[db_count].authorName,author);
            db_count++;
        }
    }else{
        printf("your txt file have error!");
    }

    FILE *fptr1 = fopen("bookTitle.txt","w");

    while(i < db_count){
       if(db[i].bookId != search_id){
            fprintf(fptr1,"%d %s %s\n",db[i].bookId,db[i].bookTitle,db[i].authorName);
            bookFound =0;
        }

    i++;
    }

    if(bookFound == 1)
        printf("Your Delete id not found!");
    else
         printf("Your books have been Deleted!\n");

    fclose(fptr);

}









//  cout<<"####Welcome to Our Book Management System####\n";
//     cout<<"1. Add Book\n";
//     cout<<"2. Delete Book\n";
//     cout<<"3. Search Book\n";
//     cout<<"4. Display All Books \n";
//     cout<<"5. Exits\n";

//     cout<<"Enter your choice:";