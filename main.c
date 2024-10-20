#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");
    Wlist *head[27] = {NULL};

    char ch;
    int choice;

    // validate CLA
    if (argc <= 1)
    {
        printf(RED"Enter Valid No.Of Arguments\n" RESET);
        printf(YELLOW"INFO : Usage: ./Slist.exe file1.txt file2.txt.....\n" RESET);
        return 0;
    }
    // declare file head pointer
    Flist *f_head = NULL;

    // valdate the file
    file_validation_n_file_list(&f_head, argv);

    if (f_head == NULL)
    {
        printf(RED"ERROR : No Files Are Added To File Linked list\n");
        printf("So, Process Got Terminated\n" RESET);
        return 1;
    }

    do
    {
        
        printf(GREEN"\n===================== INVERTED SEARCH =======================\n");
        printf("1. CREATE DATABASE\n2. DISPLAY DATABASE\n3. UPDATE DATABASE\n4. SEARCH\n5. SAVE DATABASE\n6. Exit\n");
        printf("=============================================================\n"RESET);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_database(f_head, head);
            // printf("No Error!\n");
            break;
        case 2:
            display_database(head);
            break;
        case 3:
            update_database(head, &f_head);
            break;
        case 4:
            char word[WORD_SIZE];

            printf("Enter the word : ");
            scanf("%s", word);

            int index = tolower(word[0]) % 97;
            if (index > 25)
                index = 26;

            search(head[index], word);
            break;
        case 5:
            save_database(head);
            break;
        case 6:
            printf(YELLOW"Thank You For Using This Application!\n"RESET);
            exit(0);
        default:
            printf(RED"Please Enter Valid Choice!\n"RESET);
            break;
        }
        printf("Do You Want To Continue?\nPress 'Y'(yes) For Continue, Press 'N'(NO) For Exit From Project: ");
        getchar();
        scanf("%c", &ch);

    } while (ch == 'y' || ch == 'Y');

    if(ch != 'y' || ch != 'Y')
        printf(YELLOW"Thank You For Using This Application!\n"RESET);
    return 0;
}
