#pragma once

// alloc memory
void* new_alloc(size_t size);

// deleted an alocated memory
void delete_alloc(void* ptr);

// print all alloctions and their sized
void print_memory();
