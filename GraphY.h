struct Node{
  int label;
  struct Node* next;//adjlist
  struct Node* neighbors;//
};
struct adjlist{
    struct Node* begin;
};
struct graph{
  int nb_vct;
  struct adjlist* array;
};
struct graph* new_graph();
int is_empty(struct graph* G);
void add_node(struct graph* G,int lbl);
void add_edge(struct graph* G,int lbl_src , int lbl_dest);
int has_edge(struct graph* G,int lbl_src , int lbl_dest);
void del_edge(struct graph* G,int lbl_src , int lbl_dest);
void del_node(struct graph* G,int lbl);
