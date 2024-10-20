#include "inverted_search.h"

/*Function to update the database*/
void update_database(Wlist *head[], Flist **f_head)
{
    int result;
    char file_name[F_NAME_SIZE];
    printf("Enter The File Name To Update The Database : ");
    scanf("%s", file_name);
    /*Function call to validate the file*/
    result = file_validation(file_name, f_head);
    if (result != SUCCESS)
    {
        printf(RED"ERROR: Failed To Update Database\n"RESET);
        return;
    }

    while (*f_head)
    {
        if (!strcmp((*f_head)->file_name, file_name))
        {
            create_database(*f_head, head);//function call to create the database for new file
        }
        *f_head = (*f_head)->link;
    }
}

/*Functon to validate new file*/
int file_validation(char *file_name, Flist **f_head)
{
    int result = is_File_Empty(file_name); //Functioncaal to check if file has content or not
    if (result == FILE_NOT_AVAILABLE)
    {
        printf(RED"ERROR: File %s Is Not Avalailable\n", file_name);
        printf("So Not Possible To Adding This File Into File Linked List\n"RESET);
        return FAILURE;
    }
    else if (result == FILE_EMPTY)
    {
        printf(RED"ERROR: There Is No Content In This File %s\n", file_name);
        printf("So Not Possible To Add This File Into File Linked List\n"RESET);
        return FAILURE;
    }
    else
    {
        result = to_create_list_of_file(f_head, file_name);
        if (result == SUCCESS)
        {
            printf(BLUE"INFO: %s Is Successfully Inserted Into File Linked List\n"RESET, file_name);
            return SUCCESS;
        }
        else if (result == REPEATATION)
        {
            printf(RED"ERROR: File: %s Is Repeated, So Not Possible To Add That File Into File Linked List\n"RESET, file_name);
            return FAILURE;
        }
        else
        {
            printf(RED"ERROR: Memory Allocation Failed\n"RESET);
            return FAILURE;
        }
    }
}