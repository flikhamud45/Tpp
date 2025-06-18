#pragma once


typedef struct _node_t
{
    struct _node_t* next;
    struct _node_t* prev;
    void* value;
} node_t;

class LinkedList
{
public:

    LinkedList();

    ~LinkedList();

    void push(node_t* n);

    node_t* push(void* value);

    void pop(node_t* n);

    node_t* getStart() const;

    node_t* getEnd() const;

    void clear();

  private:
    node_t* m_start;
  node_t* m_end;


};