#include <stdio.h>

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
            printf("this is add Book");
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

//  cout<<"####Welcome to Our Book Management System####\n";
//     cout<<"1. Add Book\n";
//     cout<<"2. Delete Book\n";
//     cout<<"3. Search Book\n";
//     cout<<"4. Display All Books \n";
//     cout<<"5. Exits\n";

//     cout<<"Enter your choice:";