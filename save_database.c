#include "inverted_search.h"

/*Function to save the database*/
void save_database(Wlist *head[])
{
    char file_name[F_NAME_SIZE];
    printf("Enter the file name : ");
    scanf("%s", file_name);

    char *str = strstr(file_name, ".");
    if (!str)
        strcat(file_name, ".txt");

    FILE *fptr = fopen(file_name, "w");
    if(!fptr){
        printf(RED"ERROR: File Not Opened. So Not Possible To Save Database\n"RESET);
        return;
    }

    fseek(fptr, 0, SEEK_SET);
    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            write_database_file(head[i], fptr);
        }
    }
    printf(BLUE"INFO : Database Successfully Stored\n"RESET);
    fclose(fptr);
}

/*Function to write the data into another one file */
void write_database_file(Wlist *head, FILE *databasefile)
{
    
    int index = head->word[0] % 97;
    if (index > 25)
        index = 26;

    fprintf(databasefile, "[#%d]:\n", index);
    fprintf(databasefile, "Word is [%s]: ", head->word);
    fprintf(databasefile, "File count is %d File/s: ", head->file_count);

    Ltable *Thead = head->Tlink;
    while (Thead)
    {
        fprintf(databasefile, "File Name is %s: ", Thead->file_name);
        fprintf(databasefile, "Word count is %d. ", Thead->word_count);
        Thead = Thead->table_link;
    }
    fprintf(databasefile, "\n");
}