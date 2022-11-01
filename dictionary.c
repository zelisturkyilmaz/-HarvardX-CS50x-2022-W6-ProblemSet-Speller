// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];

unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int word_length = strlen(word);
    char lowercase[word_length + 1];

    for (int i = 0; i < word_length; i++)
    {
        lowercase[i] = tolower(word[i]);
    }

    lowercase[word_length] = '\0';

    node *cursor = table[hash(lowercase)];

    if (word_length == 1)
    {
        return true;
    }
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        // point cursor to the nect node
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
    FILE *dictionary_file = fopen(dictionary, "r");
    while (fscanf(dictionary_file, "%s", word) != EOF)
    {
        node *word_node = malloc(sizeof(node));

        if (word_node == NULL)
        {
            // unload (free) the memory
            unload();
            // return false
            return false;
        }
        else
        {
            // copying word into the word node
            strcpy(word_node->word, word);
            /// n is the hash word the word
            int n = hash(word_node->word);

            /// Point the word node to the first element of the already existing bucket in the hash_table.
            word_node->next = table[n];

            /// Point the hash table to the new node which was made.
            table[n] = word_node;
            word_count++;
        }
    }
    fclose(dictionary_file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {

        node *cursor = table[i];


        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

        free(cursor);
    }
    return true;
}
