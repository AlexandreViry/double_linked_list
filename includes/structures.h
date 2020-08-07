typedef struct {
    int val;
    node_t *previous;
    node_t *next;
}node_t;

typedef struct {
    size_t length;
    node_t *end;
    node_t *beg;
}list_t;
