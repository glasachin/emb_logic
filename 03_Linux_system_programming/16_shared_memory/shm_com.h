/*
    This is the simple data structure to store the data on shared memory.
    The fields can be anything based on our requirement.
*/

#define TEXT_SZ 2048

struct shared_use_st
{
    int written_by_you;
    char some_text[TEXT_SZ];
};