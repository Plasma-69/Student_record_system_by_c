#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void addstudent();
void studentrecord();
void searchstudent();
void delete();

struct student{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[12];
    char adde[20];
    float per;
}

;void main(){
    int choice;
    while(choice != 5){
        printf("\t\t\t===STUDENT RECORDS MANAGEMENT SYSTEM===\n");
        printf("\t\t\t 1. Add Student Record\n");
        printf("\t\t\t 2. Student Record\n");
        printf("\t\t\t 3. Search Students\n");
        printf("\t\t\t 4.Delete Record\n");
        printf("\t\t\t 5. EXIT\n");
        printf("\t\t\t ______________________________________\n");
        printf("\t\t\t   \n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            system("cls");
            addstudent();
            system("cls");
            break;

            case 2:
            system("cls");
            studentrecord();
            printf("\t\t\tPress any key to Exit\n");
            getch();
            system("cls");
            break;

            case 3:
            system("cls");
            searchstudent();
            printf("\t\t\tPress any key to Exit\n");
            getch();
            system("cls");
            break;

            case 4:
            system("cls");
            delete();
            printf("\t\t\tPress any key to Exit\n");
            getch();
            system("cls");
            break;

            default:
            system("cls");
            getch();

            printf("\t\t\tEnter a Valid Number\n");
            printf("\t\t\tPress any key to continue..........\n");
            getch();
            system("cls");
            break;

            case 5:
            system("cls");
            printf("\n\t\t\t Thank you, for using our system -- plasma69\n");
            getch();
            system("cls");
            break;


        }

    }
}

void addstudent(){
    char another;
    FILE *fp;
    struct student info;
    do{
        system("cls");
        printf("\t\t\t===Add Student Info===\n");
        fp = fopen("student_info.txt","a");
        printf("\n\t\tEnter First Name :   ");
        scanf("%s", &info.first_name);
        printf("\n\t\tEnter Last Name :   ");
        scanf("%s", &info.last_name);
        printf("\n\t\tEnter Roll Number :   ");
        scanf("%d", &info.roll_no);
        printf("\n\t\tEnter Class :   ");
        scanf("%s", &info.Class);
        printf("\n\t\tEnter Address :   ");
        scanf("%s", &info.adde);
        printf("\n\t\tEnter Percentage :   ");
        scanf("%f", &info.per);

        printf("\n\t\t\t_______________________\n");
        if(fp == NULL){
            fprintf(stderr,"\t\t\tFile Not Found");
        }
        else{
            printf("\t\t\tStudent Info Added Successfully\n");
        }

        fwrite(&info,sizeof(struct student),1,fp);
        fclose(fp);
        printf("\t\t\tDo You Want To Add More Students (y/n) :   ");
        scanf("%s", &another);

        
    }while(another == 'y' || another == 'Y');
    
}

void studentrecord(){
    FILE *fp;
    struct student info;
    fp = fopen("student_info.txt","r");
    printf("\t\t\t===Student Records===\n");
    if(fp==NULL){
        fprintf(stderr,"\t\t\tFile Not Found");

    }else{
            printf("\t\t\tRecords\n");
            printf("\t\t\t_______________\n\n");

        }
    while(fread(&info,sizeof(struct student),1,fp)){
        printf("\n\t\tStudent Name : %s %s ",info.first_name,info.last_name);
        printf("\n\t\tRoll Number :  %d",info.roll_no);
        printf("\n\t\tClass : %s",info.Class);
        printf("\n\t\tAddress :  %s",info.adde);
        printf("\n\t\tPercentage : %d",info.per);
        printf("\n\t\t____________________________\n");

    }    
    fclose(fp);
    getch();
}

void searchstudent(){
    FILE *fp;
    struct student info;
    int roll_no,found = 0;
    fp = fopen("student_info.txt","r");
    printf("\t\t\t====Search Student===\n");
    printf("\t\t\tEnter Roll Number :   ");
    scanf("%d",&roll_no);
    while(fread(&info,sizeof(struct student),1,fp)){
        if(info.roll_no == roll_no){
            found = 1;
            printf("\n\t\tStudent Name : %s %s ",info.first_name,info.last_name);
            printf("\n\t\tRoll Number :  %d",info.roll_no);
            printf("\n\t\tClass : %s",info.Class);
            printf("\n\t\tAddress :  %s",info.adde);
            printf("\n\t\tPercentage : %d",info.per);
            printf("\n\t\t____________________________\n");
        }
    }
    if(!found){
        printf("\n\t\t\tStudent Not Found\n");
    }
}

void delete(){
    FILE *fp, *fp1;
    struct student info;
    int roll_no,found = 0;
    printf("\t\t\t===Delete Student Record===\n");
    fp = fopen("student_info","r");
    fp = fopen("temp.txt","w");
    printf("\t\t\tEnter roll numnber:  ");
    scanf("%d",&roll_no);
        if(fp ==NULL){
            fprintf(stderr,"\t\t\tFile Not Found");
    }
    while(fread(&info,sizeof(struct student),1,fp)){
        if(info.roll_no==roll_no){
            found = 1;
        }else{
            fwrite(&info,sizeof(struct student),1,fp1); 
        }
    }
    fclose(fp);
    fclose(fp1);

    if(found){
        remove("student_info");
        rename("temp.txt","student_info");
        printf("\n\t\t\tRecord Deleted Successfully\n");

    }
    if(!found){
        printf("\n\t\t\tStudent Not Found\n");
    }
    getch();
}