#include "inverted_search.h"

/*Function to Validate the given file and add to file linked list*/
void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1, empty;
    while (argv[i] != NULL)
    {
        empty = is_File_Empty(argv[i]);
        if (empty == FILE_NOT_AVAILABLE)
        {
            printf(RED"ERROR: File : %s Is Not Available\n", argv[i]);
            printf("So, There Is No Possible To Adding This File Into File Linked List\n" RESET);
            i++;
            continue;
        }
        else if (empty == FILE_EMPTY)
        {
            printf(RED"ERROR: File : %s Is Empty\n", argv[i]);
            printf("So, There Is No Possible To Adding This File Into File Linked List\n"RESET);
            i++;
            continue;
        }
        else
        {
            int ret_val = to_create_list_of_file(f_head, argv[i]);
            if (ret_val == SUCCESS)
                printf(BLUE"INFO: %s Is Successfully Inserted Into File Linked List\n"RESET, argv[i]);
            else if (ret_val == REPEATATION)
                printf(RED"ERROR: File Name : %s Is Repeated. So Not Possible To Add Into File Linked List\n"RESET, argv[i]);
            else
                printf(RED"Failure\n"RESET);

            i++;
            continue;
        }
    }
}

/*Function to check file is empty or not*/
int is_File_Empty(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        if (errno == ENOENT)
        {
            return FILE_NOT_AVAILABLE;
        }
    }

    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }
}

/*Function To Add File into File Linked List*/
int to_create_list_of_file(Flist **f_head, char *name)
{
    Flist *new = malloc(sizeof(Flist));
    if(!new)
        return FAILURE;

    strcpy(new->file_name, name);
    new->link = NULL;

    if(!*f_head)
    {
        *f_head = new;
        return SUCCESS;
    }
    
    Flist *temp = *f_head;
    while(temp)
    {
        if(!strcmp(temp->file_name, name))
        {
            free(new);
            return REPEATATION;
        }

        if(!temp->link)
        {
            temp->link = new;
            return SUCCESS;
        }
        temp = temp->link;
    }
}
