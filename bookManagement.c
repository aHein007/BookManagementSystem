#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DATASIZE 100

int addBook();
int addfileData(int id, char bookTitle[50], char authorName[50],char price[5]);
int displayAllBook();
int searchBooks();
int deleteBook();
int editBook();

//Global variable

int db_count =0;

struct booksInfo
{
   int bookId;
   char bookTitle[50];
   char authorName[50];
   char bookPrice[5];
};

struct booksInfo db[DATASIZE];

int main(){
    int choiceNumber = 0;
   

    printf("####Welcome to Our Book Management System####\n");
    printf("1. Add Book\n");
    printf("2. Edit Book\n");
    printf("3. Delete Book\n");
    printf("4. Search Book\n");
    printf("5. Display All Books\n");
    printf("6. Exits\n");

    printf("Enter your Choice:");
    scanf("%d",&choiceNumber);

    switch(choiceNumber){
        case 1:
           
            addBook();
            break;

        case 2:
            editBook();
            break;

        case 3:
            deleteBook();
            break;
        
        case 4:
            searchBooks();
            break;

        case 5:
            displayAllBook();
            break;

        case 6:
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
            char bookPrice[5];

            printf("Enter your Book id:");
            scanf("%d",&bookId);

            printf("Please enter your Book Name:");
            scanf(" %[^\n]",bookTitle);

            printf("Please enter authorName:");
            scanf(" %[^\n]",authorName);

            printf("Please enter Book Price:");
            scanf(" %[^\n]",bookPrice);

            addfileData(bookId,bookTitle,authorName,bookPrice);

}

// add Books
int addfileData(int id, char bookTitle[50], char authorName[50],char price[5]){
    int sameId = 0;

    //you need to read the file before file create!!
     FILE *fptr1 = fopen("bookTitle.txt","r");
      
   
       if(fptr1 != NULL){
       int file_id=0;
       char file_bookTitle[50];
       char file_authorName[50];
       char file_bookPrice[20];
       
         //id check
        while(fscanf(fptr1,"%d %s %s %s",&file_id,file_bookTitle,file_authorName,file_bookPrice) != EOF){ // be careful &id scanf is obtain & when declare is int
            if(file_id == id){//main logic
                sameId =1;
                printf("Your have same id Please try another!");
                fclose(fptr1);
                break;
            }
        }
        
       }
        //put data to bookTitle.txt
       if(sameId == 0){
        int book_id =0;
        char book_title[50];
        char book_authorName[50];
        char book_price[20];
        int book_count=0;
       
            FILE *fptr = fopen("bookTitle.txt","a");
            //put book in file
            fprintf(fptr,"%d %s %s %sKs\n",id,bookTitle,authorName,price);
            //main point is fclose
            printf("Your book was added successfully!\n");
            fclose(fptr);

            //show book list
            FILE *fptr1 = fopen("bookTitle.txt","r");
            while(fscanf(fptr1,"%d %s %s %s",&book_id,book_title,book_authorName,book_price) != EOF){
            db[book_count].bookId = book_id;
            strcpy(db[book_count].bookTitle,book_title);
            strcpy(db[book_count].authorName,book_authorName);
            strcpy(db[book_count].bookPrice,book_price);
            book_count++;
        }

            printf("####Add Book List####\n");

           int i =0;
            while(i < book_count){
                printf("BookId:%d  BookTitle:%s  BookAuthorName:%s BookPrice:%s\n",db[i].bookId,db[i].bookTitle,db[i].authorName,db[i].bookPrice);
                i++;
            }
            fclose(fptr1);
            }

       
    fclose(fptr1);

   
}

//searchBooks

int searchBooks(){

    char user_search[50];
    int id = 0;
    char title[50];
    char name[50];
    char price[20];
    int bookFound =0;

    printf("Enter Search Book:");
    scanf(" %[^\n]",user_search);

    FILE *fptr = fopen("bookTitle.txt","r");

    if(fptr != NULL){
        while(fscanf(fptr,"%d %s %s %s",&id,title,name,price) != EOF){
            db[db_count].bookId = id;
            strcpy(db[db_count].bookTitle,title);
            strcpy(db[db_count].authorName,name);
            strcpy(db[db_count].bookPrice,strcat(price,"Ks"));
            db_count++;
        }

        int i =0;
        while(i < db_count){
            if(strcmp(db[i].bookTitle,user_search) == 0){// 0 is true , 1 is false
                  printf("BookId:%d  BookTitle:%s  BookAuthorName:%s BookPrice:%s\n",db[i].bookId , db[i].bookTitle , db[i].authorName,db[i].bookPrice);
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
    char price[20];

    if(fptr == NULL){
        printf("Your txt file has error!");
    }else{
         printf("####Book List####\n");
      while(fscanf(fptr,"%d %s %s %s",&id ,title ,author,price) != EOF){// read the data with fscanf
         printf("Book Id:%d  BookTitle:%s  AuthorName:%s BookPrice:%s\n",id,title,author,price);
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
    char price[20];

    printf("Enter your book id to Delete:");
    scanf("%d",&search_id);


    if(fptr != NULL){
        while(fscanf(fptr,"%d %s %s %s",&id,title,author,price) != EOF){
            db[db_count].bookId = id;
            strcpy(db[db_count].bookTitle,title);
            strcpy(db[db_count].authorName,author);
            strcpy(db[db_count].bookPrice,price);
            db_count++;
        }
    }else{
        printf("your txt file have error!");
    }

    FILE *fptr1 = fopen("bookTitle.txt","w");

    while(i < db_count){
       if(db[i].bookId != search_id){
            fprintf(fptr1,"%d %s %s %d\n",db[i].bookId,db[i].bookTitle,db[i].authorName,db[i].bookPrice);
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


int  editBook(){
    // FILE *fptr = fopen("bookTitle.txt","r");
    printf("this is edit book");
    // while(fscanf(fptr,"%s %s"))
}








//  cout<<"####Welcome to Our Book Management System####\n";
//     cout<<"1. Add Book\n";
//     cout<<"2. Delete Book\n";
//     cout<<"3. Search Book\n";
//     cout<<"4. Display All Books \n";
//     cout<<"5. Exits\n";

//     cout<<"Enter your choice:";