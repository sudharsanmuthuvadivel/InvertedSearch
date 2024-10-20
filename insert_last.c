#include "inverted_search.h"

/*Function to insert Word node at last of the word linked list*/
int insert_at_last(Wlist **head, data_t *data)
{
    //create a node 
    Wlist *new = malloc(sizeof(Wlist));
    if(!new)
        return FAILURE;
    //update the fields
    new->file_count = 1;
    strcpy(new->word , data);
    new->Tlink = NULL;
    new->w_link = NULL;

    //call fun() to create Ltable node
    update_link_table(&new);

    //check Wlist is empty or not
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    //list is not empty

    Wlist *temp = *head;
    //traverse through Wlist

    while(temp->w_link)
    {
        temp = temp->w_link;
    }

    temp->w_link = new;
    return SUCCESS;

}

/*Function to create Link table*/
int update_link_table(Wlist **head)
{
    //create a node
    Ltable *new = malloc(sizeof(Ltable));
    if(!new)
        return FAILURE;

    new->word_count = 1;
    strcpy(new->file_name, fname);
    new->table_link = NULL;

    (*head)->Tlink = new;

    return SUCCESS;
}