#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#define DATASIZE 100

int addBook();
int addfileData(int id, char bookTitle[50], char authorName[50],int price);
int displayAllBook();
int searchBooks();
int deleteBook();
int editBook();
int compareTwoCharArray(char oneChar[50],char twoChar[50]);
int charCount(char count_string[50]);

//Global variable

int db_count =0;
int same_char =1;
struct booksInfo
{
   int bookId;
   char bookTitle[50];
   char authorName[50];
   int bookPrice;
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
            int bookPrice=0;

            printf("Enter your Book id:");
            scanf("%d",&bookId);

            printf("Please enter your Book Name:");
            scanf(" %[^\n]",bookTitle);

            printf("Please enter authorName:");
            scanf(" %[^\n]",authorName);

            printf("Please enter Book Price:");
            scanf("%d",&bookPrice);

            addfileData(bookId,bookTitle,authorName,bookPrice);

}

// add Books
int addfileData(int id, char bookTitle[50], char authorName[50],int price){
    int sameId = 0;

    //you need to read the file before file create!!
     FILE *fptr1 = fopen("bookTitle.txt","r");
      
   
       if(fptr1 != NULL){
       int file_id=0;
       char file_bookTitle[50];
       char file_authorName[50];
       int file_bookPrice;
       
         //id check
        while(fscanf(fptr1,"%d %s %s %d",&file_id,file_bookTitle,file_authorName,&file_bookPrice) != EOF){ // be careful &id scanf is obtain & when declare is int
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
        int book_price;
        int book_count=0;
       
            FILE *fptr = fopen("bookTitle.txt","a");
            //put book in file
            fprintf(fptr,"%d %s %s %d\n",id,bookTitle,authorName,price);
            //main point is fclose
            printf("Your book was added successfully!\n");
            fclose(fptr);

            //show book list
            FILE *fptr1 = fopen("bookTitle.txt","r");
            while(fscanf(fptr1,"%d %s %s %d",&book_id,book_title,book_authorName,&book_price) != EOF){
            db[book_count].bookId = book_id;
            strcpy(db[book_count].bookTitle,book_title);
            strcpy(db[book_count].authorName,book_authorName);
            db[book_count].bookPrice=book_price;
            book_count++;
        }

            printf("####Add Book List####\n");

           int i =0;
            while(i < book_count){
                printf("BookId:%d  BookTitle:%s  BookAuthorName:%s BookPrice:%dKs\n",db[i].bookId,db[i].bookTitle,db[i].authorName,db[i].bookPrice);
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
    int price;
    int bookFound =0;

    printf("Enter Search Book:");
    scanf(" %[^\n]",user_search);

    FILE *fptr = fopen("bookTitle.txt","r");

    if(fptr != NULL){
        
        while(fscanf(fptr,"%d %s %s %s",&id,title,name,price) != EOF){
            db[db_count].bookId = id;
            strcpy(db[db_count].bookTitle,title);
            strcpy(db[db_count].authorName,name);
            db[db_count].bookPrice=price;
            db_count++;
        }

        int i =0;

         while(i < db_count){
          int titleSearch= compareTwoCharArray(db[i].bookTitle,user_search);
            if(titleSearch == 0){// 0 is true , 1 is false // stricmp is not remind the upper/lower case --> so cool
                  printf("BookId:%d  BookTitle:%s  BookAuthorName:%s BookPrice:%dKs\n",db[i].bookId , db[i].bookTitle , db[i].authorName,db[i].bookPrice);
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

//char count and compare
int charCount(char count_string[50]){
    
    int str_count = 0;
    while(str_count < 50){
        if(count_string[str_count] == '\0'){
            break;
        }
        str_count++;
    }

    return str_count;
    
}

                        // oneChar is data base  // two char is user_search
int compareTwoCharArray(char oneChar[50],char twoChar[50]){
  int oneCharCount = charCount(oneChar);
  int twoCharCount = charCount(twoChar);

  if(oneCharCount >= twoCharCount){
    for(int i =0; i <= oneCharCount - twoCharCount; i++){
        int same =0;
        for(int j =0 ; j < twoCharCount ; j++){
            if(tolower(oneChar[i+j]) != tolower(twoChar[j])){
                same =1;
                break;
            }
        }
       if(same == 0)
        return 0;
       
    }
    return -1;
  }
}

 // my concept with in-sensitive search
    // if(oneCharCount >= twoCharCount){
    //     for(int i = 0; i < oneCharCount;i++){
    //         if(tolower(oneChar[i]) == tolower(twoChar[i])){
    //              same_char =0;
    //         }
    //     }
        
       
    //     return same_char;


    // }

//display all Books
int displayAllBook(){
    FILE *fptr = fopen("bookTitle.txt","r");
    int id = 0;
    char title[50];
    char author[50];
    int price;
    int user_sort=0;
    char sort_permission[1];

    if(fptr == NULL){
        printf("Your txt file has error!");
    }else{
         printf("####Book List####\n");
      while(fscanf(fptr,"%d %s %s %d",&id ,title ,author,&price) != EOF){// read the data with fscanf

        db[db_count].bookId = id;
        strcpy(db[db_count].bookTitle,title);
        strcpy(db[db_count].authorName,author);
        db[db_count].bookPrice=price;
        db_count++;

         printf("Book Id:%d  BookTitle:%s  AuthorName:%s BookPrice:%dKs\n",id,title,author,price);
      }

      printf("Do you want to Sort the Data(y/n):");
      scanf("%s",sort_permission);

      if(sort_permission[0] == 'y' || sort_permission[0] == 'Y' ){
        printf("1. id\n");
        printf("2. Price\n");
        printf("Choose the number:");
        scanf("%d",&user_sort);

        if(user_sort == 1){
            printf("####Id Sort####\n");
           for(int i = 0; i <= db_count-1;i++){
                for(int j =i+1; j< db_count ; j++){
                    if(db[i].bookId > db[j].bookId){
                         //-->db swap
                         struct booksInfo db_temp =db[i]; 
                         db[i] = db[j];
                         db[j] =db_temp;
                         //-->db swap
                    }
                }
             printf("Book Id:%d  BookTitle:%s  AuthorName:%s BookPrice:%dKs\n",db[i].bookId,db[i].bookTitle,db[i].authorName,db[i].bookPrice);
           }
        }else{
            printf("####Price Sort List####\n");
           for(int i =0 ; i <= db_count-1;i++){
                for(int j = i+1; j < db_count;j++){
                    if(db[i].bookPrice > db[j].bookPrice){
                        struct booksInfo temp =db[i];
                        db[i] =db[j];
                        db[j] = temp;
                    }
                }
                 printf("Book Id:%d  BookTitle:%s  AuthorName:%s BookPrice:%dKs\n",db[i].bookId,db[i].bookTitle,db[i].authorName,db[i].bookPrice);
           }
        }
      }else{
        exit(1);
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
    int price;

    printf("Enter your book id to Delete:");
    scanf("%d",&search_id);


    if(fptr != NULL){
        while(fscanf(fptr,"%d %s %s %d",&id,title,author,&price) != EOF){
            db[db_count].bookId = id;
            strcpy(db[db_count].bookTitle,title);
            strcpy(db[db_count].authorName,author);
            db[db_count].bookPrice=price;
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
    FILE *fptr = fopen("bookTitle.txt","r");
    FILE *fptr1 = fopen("editBookTitle.txt","w");

     int edit_id =0;
     char editTitle[50];
     char editName[50];
     int editPrice;
     int user_search=0;
     int db_counter =0;
     int editBookFound =0;

     printf("Please Enter Edit books id:");
     scanf("%d",&user_search);

   
    while(fscanf(fptr,"%d %s %s %d",&edit_id,editTitle,editName,&editPrice) != EOF){

     if(user_search == edit_id){
       
        printf("Book Id:%d  BookTitle:%s  AuthorName:%s BookPrice:%d\n",edit_id,editTitle,editName,editPrice);

        char editBookTitle[50];
        char editAuthorName[50];
        int editBookPrice;

        printf("###Edit Books Page###\n");

        printf("Enter New Book Title:");
        scanf(" %[^\n]",editBookTitle);
        printf("Enter New Author Name:");
        scanf(" %[^\n]",editAuthorName);
        printf("Enter New Book Price:");
        scanf("%d",&editBookPrice);

       
        fprintf(fptr1,"%d %s %s %d\n",edit_id,editBookTitle,editAuthorName,editBookPrice);
        printf("Book updated successfully!\n");
        editBookFound =1;
    }else{
         fprintf(fptr1,"%d %s %s %d\n",edit_id,editTitle,editName,editPrice);
    }

    

   
}

if(editBookFound == 0)
        printf("Book id not found in dataBase!");

fclose(fptr);
fclose(fptr1);


remove("bookTitle.txt");// delete original file// this is delete for old data!
rename("editBookTitle.txt","bookTitle.txt"); // forward is new file to rename original file 
}










//  cout<<"####Welcome to Our Book Management System####\n";
//     cout<<"1. Add Book\n";
//     cout<<"2. Delete Book\n";
//     cout<<"3. Search Book\n";
//     cout<<"4. Display All Books \n";
//     cout<<"5. Exits\n";

//     cout<<"Enter your choice:";