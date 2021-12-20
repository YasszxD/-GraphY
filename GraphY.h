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
  int is_oriented;
  int nb_edge;
};
struct graph* new_graph();
int is_empty(struct graph* G);
void add_node(struct graph* G,int lbl);
void add_edge(struct graph* G,int lbl_src , int lbl_dest);
int has_edge(struct graph* G,int lbl_src , int lbl_dest);
void del_edge(struct graph* G,int lbl_src , int lbl_dest);
void del_node(struct graph* G,int lbl);
/*****************************************************/
int graph_order(struct graph* G);
int vct_order(struct graph* G,int lbl);//sortant
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
int** topologie_ordre(struct graph* G);
//rang dune sommet f tri topologie
