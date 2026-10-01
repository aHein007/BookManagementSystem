#include "stdio.h"
#include "stdlib.h"

int addBook();
int fileData(int id, char bookTitle[20], char authorName[20]);

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
            printf("this is Search book");
            break;
        
        case 3:
            printf("this is display Book");
            break;

        case 4:
            printf("this is display All Book");
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

            int bookId =0;
            char bookTitle[50];
            char authorName[50];

            printf("Enter your Book id:");
            scanf("%d",&bookId);

            printf("Please enter your Book Name:");
            scanf(" %[^\n]",&bookTitle);

            printf("Please enter authorName:");
            scanf(" %[^\n]",&authorName);

            fileData(bookId,bookTitle,authorName);

            printf("Your book was added successfully!");
}


int fileData(int id, char bookTitle[50], char authorName[50]){
    FILE *fptr = fopen("bookTitle.txt","a");

    if(fptr == NULL){
        printf("Your txt file has error!");
    }else{
        fprintf(fptr,"%d %s %s\n",id,bookTitle,authorName);
       
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