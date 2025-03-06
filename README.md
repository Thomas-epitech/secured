# {EPITECH} Secured Project

A C library implementing a custom hash table data structure for securing and efficiently storing information.

## Overview

This project provides a robust implementation of a hash table in C, including a custom hash function and methods for inserting, deleting, searching, and displaying elements. The library is designed to efficiently handle data storage and retrieval while maintaining security through hashing.

## Features

- **Custom Hash Function**: Implementation of an original hash function that efficiently distributes data
- **Hash Table Operations**: Complete set of operations for manipulating the hash table
  - Create and destroy hash tables
  - Insert key-value pairs
  - Delete entries by key
  - Search for values by key 
  - Display the complete hash table contents
- **Collision Handling**: Implementation of separate chaining to resolve hash collisions

## Technical Details

- **Language**: C
- **Compiled Output**: Static library (libhashtable.a)
- **Compilation**: Via Makefile, including re, clean, and fclean rules
- **Authorized Functions**: write, malloc, free
- **Error Handling**: Error messages are written to the error output with exit code 84 for errors

## API Reference

### Hash Function

```c
int hash(char *key, int len);
```
- **Description**: Hashes a string key to produce an integer hash value
- **Parameters**:
  - `key`: The string to be hashed
  - `len`: The size of the hash table
- **Returns**: An integer hash value

### Hash Table Creation and Destruction

```c
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
```
- **Description**: Creates a new hash table
- **Parameters**:
  - `hash`: Pointer to the hash function to be used
  - `len`: Size of the hash table
- **Returns**: Pointer to the newly created hash table

```c
void delete_hashtable(hashtable_t *ht);
```
- **Description**: Deletes a hash table and frees all associated memory
- **Parameters**:
  - `ht`: Pointer to the hash table to be deleted

### Hash Table Operations

```c
int ht_insert(hashtable_t *ht, char *key, char *value);
```
- **Description**: Inserts a key-value pair into the hash table
- **Parameters**:
  - `ht`: Pointer to the hash table
  - `key`: The key for the entry
  - `value`: The value to be stored
- **Returns**: Status code (0 for success, non-zero for error)
- **Note**: If the key already exists, the value is updated

```c
int ht_delete(hashtable_t *ht, char *key);
```
- **Description**: Deletes an entry from the hash table by key
- **Parameters**:
  - `ht`: Pointer to the hash table
  - `key`: The key of the entry to delete
- **Returns**: Status code (0 for success, non-zero for error)

```c
char *ht_search(hashtable_t *ht, char *key);
```
- **Description**: Searches for a value in the hash table by key
- **Parameters**:
  - `ht`: Pointer to the hash table
  - `key`: The key to search for
- **Returns**: The value if found, NULL otherwise

```c
void ht_dump(hashtable_t *ht);
```
- **Description**: Displays the complete contents of the hash table
- **Parameters**:
  - `ht`: Pointer to the hash table to display

## Implementation Details

### Hash Table Structure

The hash table is implemented using separate chaining for collision resolution, where each bucket contains a linked list of elements that hash to the same index.

```c
typedef struct hashtable_s {
    // Implementation details to be defined
} hashtable_t;
```

### Collision Handling

When multiple keys hash to the same index, they are stored in a linked list at that index (separate chaining). This allows the hash table to handle an unlimited number of elements, regardless of the initial table size.

## Usage Example

```c
#include "hashtable.h"
#include <stdio.h>

int main(void)
{
    // Create a new hash table with size 4
    hashtable_t *ht = new_hashtable(&hash, 4);
    
    // Insert elements
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    
    // Display the hash table
    ht_dump(ht);
    
    // Search for an element
    printf("Looking for \"Kratos\": \"%s\"\n", ht_search(ht, "Kratos"));
    
    // Delete an element
    ht_delete(ht, "Vision");
    
    // Display the hash table again
    ht_dump(ht);
    
    // Clean up
    delete_hashtable(ht);
    
    return 0;
}
```
