#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Name: Trần Tiến Ngọc
    MSSV: 20205009
    Status: done
*/
typedef struct wordCount_s
{
    char content[20];
    int count;
} wordCount_t;

typedef struct node_s
{
    wordCount_t data;
    struct node_s *left;
    struct node_s *right;
} node_t;

char upperString(char s[])
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
    }
}

void showData(wordCount_t data)
{
    printf("Content: %s | Count: %d|", data.content, data.count);
    printf("\n");
}

node_t *makeNode(char word[])
{
    node_t *p = (node_t *)malloc(sizeof(node_t));
    strcpy(p->data.content, word);
    p->data.count = 1;
    p->left = NULL;
    p->right = NULL;
    return p;
}

node_t *insert(node_t *node, char word[])
{
    upperString(word);
    if (node == NULL)
        return makeNode(word);
    int c = strcmp(node->data.content, word);
    if (c == 0)
    {
        printf("word %s exists, count + 1\n", node->data.content);
        node->data.count++;
        return node;
    }
    else if (c < 0) //  thì add node vừa insert vào rightChild
    {
        node->right = insert(node->right, word);
        return node;
    }
    else // thì add node vừa insert vào leftChild
    {
        node->left = insert(node->left, word);
        return node;
    }
}

void freeTree(node_t *r)
{
    if (r == NULL)
        return;
    freeTree(r->left);
    freeTree(r->right);
    free(r);
}

void inOrder(node_t *r)
{
    if (r == NULL)
        return;
    inOrder(r->left);
    showData(r->data);
    inOrder(r->right);
}

void inOrderF(node_t *r, FILE *f)
{
    if (r == NULL)
        return;
    inOrderF(r->left, f);
    fprintf(f, "%s %d\n", r->data.content, r->data.count);
    inOrderF(r->right, f);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Command Line Argument Error\n");
        return 1;
    }
    node_t *root = NULL;
    FILE *fr = NULL;
    char arr[128];
    char *fileRead = argv[1];
    char *fileWrite = argv[2];
    fr = fopen(fileRead, "r");
    if (fr == NULL)
        printf("Load data -> file not found\n");
    // tach va import
    while (fgets(arr, 128, fr) != NULL)
    {
        printf("%s", arr);
        char res[100][20];
        int i;
        char *p;
        const char *delim = " .,-@\n\t!#$^&*(){}|;:?/"; // ki tu tach
        for (p = strtok(arr, delim); p != NULL; p = strtok(NULL, delim))
        {
            root = insert(root, p);
        }
    }

    FILE *fw = fopen(fileWrite, "w");
    if (fw == NULL)
        printf("Write data -> file not found\n");

    // inOrder(root);
    inOrderF(root, fw);
    freeTree(root);
    fclose(fw);
    fclose(fr);
    return 0;
}