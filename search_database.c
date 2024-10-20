#include "inverted_search.h"

/*Function to search the data in database*/
void search(Wlist *head, char *word)
{
    if (head == NULL)
    {
        printf(RED"ERROR: List Is Empty, Search Not Possible\n"RESET);
        return;
    }

    // traverse the list
    while (head)
    {
        // compare each node word with the search word
        if (!strcmp(head->word, word))
        {
            printf(BLUE"\nINFO : Word: '%s' Is Present In %d File/s \n"RESET, word, head->file_count);
            printf(GREEN"=========================================\n");
            printf("%-25s %-10s\n", "File Name", "Word Count/s");
            printf("=========================================\n"RESET);

            Ltable *Thead = head->Tlink;
            while (Thead)
            {
                printf(GREEN"%-25s %d time/s \n"RESET, Thead->file_name, Thead->word_count);
                Thead = Thead->table_link;
            }
            printf(GREEN"=========================================\n"RESET);
            return;
        }
        head = head->w_link;
    }

    printf(RED"INFO : Word: '%s' Not Found In Database\n"RESET, word);
}