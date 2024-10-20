#include "inverted_search.h"

/*Function to display the database*/
void display_database(Wlist *head[])
{
    printf(GREEN"\n=======================================================================\n");
    printf("%-10s %-15s %-15s %-15s %-10s\n", "[Index]", "[Word]", "File Count", "File Name", "Word Count");
    printf("=======================================================================\n"RESET);

    for (int i = 0; i < 27; i++) // Iterate through indices 0 to 26
    {
        if (head[i] != NULL)
        {
            // Print the word count for the current index
            if (print_word_count(head[i]) != SUCCESS)
            {
                printf(RED"ERROR: Failed To Display The Database\n"RESET);
            }
        }
    }
    printf(GREEN"=======================================================================\n"RESET);
}

/*Function to display  the details in database */
int print_word_count(Wlist *head)
{
    // Calculate the index based on the first character of the word
    while (head != NULL)
    {
        // Calculate index based on the first character
        int index = (tolower(head->word[0]) >= 'a' && tolower(head->word[0]) <= 'z') ? 
                     (tolower(head->word[0]) - 'a') : 26; // Use 26 for non-alphabetic characters

        // Print the details
        printf(GREEN"[%d]\t   %-15s %-1d File/s\t "RESET, index, head->word, head->file_count);

        Ltable *Thead = head->Tlink;
        while (Thead)
        {
            printf(GREEN"%11s %10d"RESET, Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
            if (Thead)
                printf("\n%41s", " "); // Align the output for multiple files
        }
        printf("\n");
        head = head->w_link; // Move to the next word in the list
    }
    return SUCCESS;
}
