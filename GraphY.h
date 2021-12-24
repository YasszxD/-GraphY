struct Node{
  char label;
  struct Node* next;//adjlist
  struct Node* neighbors;//

};
struct graph{
  int nb_vct;
  struct Node* begin;
  int is_oriented;
  int nb_edge;
};

struct graph* new_graph();
int is_empty(struct graph* G);//1 True(empty) ,0 False
int add_node(struct graph* G,char lbl);//1 added 0 not added
int add_edge(struct graph* G,char lbl_src , char lbl_dest);//1 added 0 not added
int has_node(struct graph* G,char lbl);//1 there is node 0 no
int has_edge(struct graph* G,char lbl_src , char lbl_dest);//1 there is edge 0 no
void del_edge(struct graph* G,char lbl_src , char lbl_dest);
void del_node(struct graph* G,char lbl);
/*****************************************************/
int graph_order(struct graph* G);
int vct_order_exit(struct graph* G,char lbl);//sortant
int vct_order_entre(struct graph* G,char lbl);//entrant
//int is_cyclic(struct graph* G);
//distance diametre
int is_simple(struct graph* G);//pas de double laison et boucle
//int is_connex(struct graph* G);//fortement  il exsite une chemin entre deux noeud;
int is_complet(struct graph* G);//chaque 2 sommet sont reliee nombre d aret = n(n-1)/2(non orinte) n*(n-1) oriente
/******************************************************/
int** matrix_square(int or);//matrice adj (carre)
int** adjency_matrix(struct graph* G);
int** matrix(int or,int vct);//incidence not square
int** incidence_matrix(struct graph* G);
char* topology_ordre(struct graph* G);//ykhdemch
char label_node_i(struct graph* G,int i);//return label for node number i
//rang dune sommet f tri topologie
/********************************************************/
