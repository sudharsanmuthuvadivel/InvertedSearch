#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>


/* Define macros for colours */
#define  RED  	 "\033[1;31m"
#define  GREEN	 "\033[1;32m"
#define  BLUE 	 "\033[1;34m"
#define  YELLOW	 "\033[1;33m"
//#define  PURPLE	 "\033[1;35m"
#define  CYAN	 "\033[1;36m"
#define  WHITE	 "\033[1;37m"
#define  BLACK	 "\033[1;30m"
#define  RESET	 "\033[0m"


/*define macros*/
#define SUCCESS 0
#define FAILURE -1
#define FILE_EMPTY -2
#define FILE_NOT_AVAILABLE -3
#define REPEATATION -4
#define F_NAME_SIZE 15
#define WORD_SIZE 50

extern char *fname;
typedef char data_t;

typedef char data_t;
/*Structure for file list */
typedef struct node
{
	char file_name[F_NAME_SIZE];
	struct node *link;
} Flist;

/*Structure for link table*/
typedef struct linkTable_node
{
	int word_count;
	char file_name[FILENAME_MAX];
	struct linkTable_node *table_link;
}Ltable;

/*Structure for Word list*/
typedef struct Word_node
{
	int file_count;
	char word[WORD_SIZE];
	Ltable *Tlink;
	struct Word_node *w_link;
}Wlist;




/* Function prototypes */
void file_validation_n_file_list(Flist **f_head, char **argv);
int is_File_Empty(char *filename);

/*Function Prototypes To create Database */
int to_create_list_of_file(Flist **f_head, char *filename);
void create_database(Flist *f_head, Wlist *head[]);
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename);
int insert_at_last(Wlist **head, data_t *data);
int update_link_table(Wlist **head);
int update_word_count(Wlist **head, char *filename);

/*Function Protypes To Display Database*/
void display_database(Wlist *head[]);
int print_word_count(Wlist *head);

/*Function Prototype To Update Database*/
void update_database(Wlist *head[], Flist **f_head);
int file_validation(char *file_name, Flist **f_head);


void search(Wlist *head, char *word);

void save_database(Wlist *head[]);
void write_database_file(Wlist *head, FILE *databasefile);
#endif