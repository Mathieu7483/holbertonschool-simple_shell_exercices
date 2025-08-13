#include "split.h"
/*
*linked_list_path
*
*/

list_t *linked_list_path(void)
{
    char *path;
    char *path_copy;
    char *token;
    list_t *head = NULL;
    list_t *current = NULL;

    path = getenv("PATH");

    if (path == NULL)
    {
        fprintf(stderr, "Erreur: la variable PATH n'a pas été trouvée.\n");
        return (NULL);
    }

    path_copy = strdup(path);
    if (path_copy == NULL)
    {
        perror("strdup");
        return (NULL);
    }

    token = strtok(path_copy, ":");

    while (token != NULL)
    {
        list_t *new_node = malloc(sizeof(list_t));
        if (new_node == NULL)
        {
            perror("malloc");
            free(path_copy);
            return (NULL);
        }
        new_node->dir = strdup(token);
        if (new_node->dir == NULL)
        {
            perror("strdup");
            free(new_node);
            free(path_copy);
            return (NULL);
        }
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }

        token = strtok(NULL, ":");
    }

    free(path_copy);
    return (head);
}

/**
*free_list - free all the memory 
*@head: pointer to the first node of the list
*/
void free_list(list_t *head)
{
    list_t *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->dir);
        free(temp);
    }
}

/**
 *main - main function to test
 */
int main(void)
{
    list_t *path_list;
    list_t *current;

    printf("Construction de la liste des répertoires du PATH...\n");
    path_list = linked_list_path();

    if (path_list != NULL)
    {
        printf("Liste des répertoires (parcourue depuis la liste chaînée) :\n");
        printf("----------------------------------------------------------\n");
        current = path_list;
        while (current != NULL)
        {
            printf("%s\n", current->dir);
            current = current->next;
        }
        printf("----------------------------------------------------------\n");

        printf("Libération de la mémoire de la liste.\n");
        free_list(path_list);
    }
    else
    {
        printf("Échec de la construction de la liste.\n");
    }

    return (0);
}
