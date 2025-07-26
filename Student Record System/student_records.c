#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    char roll_no[20];
    char name[50];
    float marks;
};

void add_student() {
    struct Student s;
    FILE *fp=fopen("student_data.txt","a");

    if(fp==NULL) {
        printf("Error Opening file.\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%s",s.roll_no);
    printf("Enter Name: ");
    getchar();  //clear newline
    fgets(s.name, sizeof(s.name),stdin); 
    s.name[strcspn(s.name, "\n")]=0;  //remove newline
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%s,%s,%.2f\n", s.roll_no, s.name, s.marks);
    fclose(fp);
    printf("Student Added Successfully!\n");

}
void view_students() {
    struct Student s;
    FILE *fp= fopen("student_data.txt","r");

    if(fp==NULL) {
        printf("No student data found.\n");
        return;
    }
    printf("\n----- STUDENT RECORDS -----\n");
    printf("Roll No\t\t Name\t\t Marks\n");
    printf("----------------------------------------\n");
    while (fscanf(fp, "%[^,],%[^,],%f\n",s.roll_no,s.name, &s.marks)==3) {
        printf("%s\t%s\t%.2f\n", s.roll_no, s.name, s.marks);
    }
    fclose(fp);

}
void search_student() {
    char target_roll[20];
    int found=0;
    struct Student s;
    FILE *fp= fopen("student_data.txt", "r");

    if(fp==NULL) {
        printf("No Student data found.\n");
        return;
    }
    printf("Enter Roll Number to search: ");
    scanf("%s", target_roll);

    while(fscanf(fp,"%[^,],%[^,],%f\n", s.roll_no,s.name, &s.marks)==3) {
        if(strcmp(s.roll_no, target_roll)==0) {
            printf("\nStudent Found:\n");
            printf("Roll No: %s\nName: %s\nMarks: %.2f\n", s.roll_no,s.name, s.marks);
            found=1;
            break;

        }
    }
    if (!found) {
        printf("Student with Roll Number %s not found.\n", target_roll);
    }
    fclose(fp);
}

void show_menu() {
    printf("\n------ STUDENT RECORD SYSTEM ------\n");
    printf("1. Add Student\n");
    printf("2. View All Students\n");
    printf("3. Search Student by Roll Number\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    while(1) {
        show_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_student(); break;
            case 2: view_students(); break;
            case 3: search_student(); break;
            case 4: 
                printf("Exiting...\n");
                return 0;
            default:    
                printf("Invalid Choice! Please try again.\n");
        }
    }
    return 0;
}
