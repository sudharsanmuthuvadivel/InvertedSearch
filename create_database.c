#include "inverted_search.h"

char *fname;
/*Function to create database for word in the list*/
void create_database(Flist *f_head, Wlist *head[])
{
    // Traverse through file linked list
    while (f_head != NULL)
    {
        read_datafile(f_head, head, f_head->file_name);
        printf(BLUE"INFO: Database Created For File : %s \n"RESET, f_head->file_name);
        f_head = f_head->link;
    }
    
}

/*Function to read word data from file*/
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    fname = filename;                                    
    int flag;  // Declare flag inside the loop

    // Open the file in read mode
    FILE *fptr = fopen(filename, "r");
    if (!fptr)
        return 0;

    fseek(fptr, 0, SEEK_SET);
    char word[WORD_SIZE];

    /* Read the strings (words) from the data file */
    while (fscanf(fptr, "%s", word) != EOF)
    {
        flag = 1;  // Reset flag for each new word
        int index = tolower(word[0]) % 97;

        // Check if the word starts with special characters
        if (!(index >= 0 && index <= 25)) 
            index = 26;

        /* Check if the word already exists in the list */
        if (head[index] != NULL)
        {
            Wlist *temp = head[index];
            while (temp)  // Traverse through Word linked list
            {
                if (!strcmp(temp->word, word))  // If the word is found
                {
                    /* Update the word count or file count in the hash table */
                    if (update_word_count(&temp, filename) == SUCCESS)
                    {
                        flag = 0;  // Word is found, so no need to insert
                        break;
                    }
                }
                temp = temp->w_link;
            }
        }

        // If the word was not found, insert it at the end of the list
        if (flag)
        {
            insert_at_last(&head[index], word);
        }
    }

    fclose(fptr);  // Don't forget to close the file
    return NULL;   // Return type is Wlist* but not used, return NULL to avoid warnings
}

/*Function to Update word or file count  when word is repeated*/
int update_word_count(Wlist **head, char *filename)
{
    Ltable *temp = (*head)->Tlink;
    Ltable *prev = NULL;

    // Traverse through the Ltable linked list
    while (temp)
    {
        /* Check if the word is repeated in the same file */
        if (!strcmp(temp->file_name, filename)) 
        {
            temp->word_count++;  // Increment word count
            return SUCCESS;
        }
        prev = temp;
        temp = temp->table_link;  // Move to the next link node
    }

    // If the word is found but not in the same file, create a new node
    Ltable *new = malloc(sizeof(Ltable));
    if (!new)
        return FAILURE;
    
    new->word_count = 1;
    strcpy(new->file_name, filename);
    new->table_link = NULL;

    if (prev)
        prev->table_link = new;  // Insert new node at the end of Ltable list
    else
        (*head)->Tlink = new;  // If no files exist, this is the first file

    (*head)->file_count++;  // Increment file count for the word
    return SUCCESS;
}

