#include <stdio.h>
#include <string.h>

struct Task
{
    int id;
    char name[100];
    int status;
};

struct Task t[100];
int count = 0;

void addTask()
{
    t[count].id = count + 1;

    printf("Enter task: ");
    scanf(" %[^\n]", t[count].name);

    t[count].status = 0;
    count++;

    printf("Task added successfully.\n");
}

void viewTasks()
{
    int i;

    if (count == 0)
    {
        printf("No tasks available.\n");
        return;
    }

    printf("\nID\tTask\t\tStatus\n");

    for (i = 0; i < count; i++)
    {
        printf("%d\t%s\t\t", t[i].id, t[i].name);

        if (t[i].status == 0)
            printf("Pending\n");
        else
            printf("Completed\n");
    }
}

void editTask()
{
    int id, i;

    printf("Enter task ID to edit: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (t[i].id == id)
        {
            printf("Enter new task: ");
            scanf(" %[^\n]", t[i].name);
            printf("Task updated successfully.\n");
            return;
        }
    }

    printf("Task not found.\n");
}

void deleteTask()
{
    int id, i, j;

    printf("Enter task ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (t[i].id == id)
        {
            for (j = i; j < count - 1; j++)
            {
                t[j] = t[j + 1];
                t[j].id = j + 1;
            }

            count--;
            printf("Task deleted successfully.\n");
            return;
        }
    }

    printf("Task not found.\n");
}

void completeTask()
{
    int id, i;

    printf("Enter task ID to mark as completed: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (t[i].id == id)
        {
            t[i].status = 1;
            printf("Task marked as completed.\n");
            return;
        }
    }

    printf("Task not found.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== TO-DO LIST MANAGEMENT =====\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Edit Task\n");
        printf("4. Delete Task\n");
        printf("5. Mark Task as Completed\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                editTask();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                completeTask();
                break;

            case 6:
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}