#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

char tasks[MAX_TASKS][MAX_LENGTH];
int task_count=0;
void load_tasks() {
    FILE *fp= fopen("tasks.txt","r");
    if (fp==NULL) {
        return;
    }
    while (fgets(tasks[task_count], MAX_LENGTH, fp)) {
        tasks[task_count][strcspn(tasks[task_count], "\n")]= 0;
        task_count++;
    }
    fclose(fp);
}

void save_tasks() {
    FILE *fp=fopen("tasks.txt", "w");
    for(int i=0; i< task_count;i++) {
        fprintf(fp, "%s\n",tasks[i]);
    }
    fclose(fp);
}

void add_task() {
    if(task_count >= MAX_TASKS) {
        printf("Task Limit reached!\n");
        return;  
    }
    printf("Enter Task: ");
    getchar();  
    fgets(tasks[task_count], MAX_LENGTH,stdin);
    tasks[task_count][strcspn(tasks[task_count],"\n")] = 0;
    task_count++;
    save_tasks();
    printf("Task added successfully!\n");
}

void view_tasks() {
    if(task_count == 0) {
        printf("No Tasks yet!\n"); return;
    }
    printf("\n---- TO DO LIST ----\n");
    for(int i= 0; i<task_count; i++) {
        printf("%d. %s\n", i+1, tasks[i]);
    }
}

void delete_task() {
    int num;
    view_tasks(); 
    if(task_count==0) return;
    printf("Enter task number to delete: ");
    scanf("%d", &num); 
    if(num<1 || num>task_count) {
        printf("Invalid task number!\n"); return;
    }
    for(int i=num-1; i< task_count-1; i++) {
        strcpy(tasks[i],tasks[i+1]);
    }
    task_count--;
    save_tasks();
    printf("Task deleted successfully!\n");
}
void show_menu() {
    printf("\n----- TO-DO LIST MENU -----\n");
    printf("1. Add task\n");
    printf("2. View tasks\n");
    printf("3. Delete task\n");
    printf("4. EXIT\n");
    printf("Enter your choice: ");
}
int main() {
    int choice;
    load_tasks(); 
    while (1) {
        show_menu(); 
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_task(); break;
            case 2: view_tasks(); break; 
            case 3: delete_task(); break; 
            case 4: 
                printf("Exiting... Have a productive day!\n");
                return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0; 
}
