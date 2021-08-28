#include "list.h"

char* s_gets(char* string, int sz);
void showmovie(Item item);
void main(void) {
    Item temp;
    List movies;
    initialiazeList(&movies);
    if (ListIsFull()) {
        fprintf(stderr, "Not enough memory, programm shutting down!\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter Movie title or empty string to exit:");
    while (s_gets(temp.title, MAX_SIZE) != NULL && temp.title[0] != '\0') {
        puts("Enter movie's reting:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n') continue;
        if (AddItem(temp, &movies) == false) {
            fprintf(stderr, "Not enough memory, programm shutting down!\n");
            exit(EXIT_FAILURE);
        }
        puts("Enter next movie, or empty string to exit:");
    }
    if (ListIsEmpty(&movies)) {
        printf("List is empty, data was not entered\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Your entered %d movies!\n", ListItemCount(&movies));
        puts("Your movies list:");
        Traverse(&movies, showmovie);
    }
    EmptyList(&movies);
    puts("Programm is over!");
}

char* s_gets(char* string, int sz) {
    char* ret_val;
    char* find;
    ret_val = fgets(string, sz, stdin);
    if (ret_val) {
        find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n') continue;
    }
    return ret_val;
}
void showmovie(Item item) { printf("Movie title: %s, movie rating: %d\n", item.title, item.rating); }