struct Node{
  char label;
  struct Node* next;//adjlist
  struct Node* neighbors;//
  int weight;
};
struct graph{
  int nb_vct;
  struct Node* begin;
  int nb_edge;
};
struct print{//for print that we can return 2 values // may use it in floyd warshall
  char* str;
  int len;
  int dist;//for floyd
  int* chemin;//for floyd //array with node index
};
struct floyd{//D AND P FLOYD warshall
  int** D;
  int** P;
};
struct graph* new_graph();
int is_empty(struct graph* G);//1 True(empty) ,0 False
int add_node(struct graph* G,char lbl);//1 added 0 not added
int add_edge(struct graph* G,char lbl_src , char lbl_dest,int wg);//1 added 0 not added
int has_node(struct graph* G,char lbl);//1 there is node 0 no
int has_edge(struct graph* G,char lbl_src , char lbl_dest);//1 there is edge 0 no
void del_edge(struct graph* G,char lbl_src , char lbl_dest);
void del_node(struct graph* G,char lbl);
struct print* print_graph(struct graph* G);//for print that we can return 2 values
/*****************************************************/
int graph_order(struct graph* G);
int vct_order_exit(struct graph* G,char lbl);//sortant
int vct_order_entre(struct graph* G,char lbl);//entrant
int is_simple(struct graph* G);//pas de double laison et boucle
int is_complet(struct graph* G);//chaque 2 sommet sont reliee nombre d aret = n(n-1)/2(non orinte) n*(n-1) oriente
/******************************************************/
int** matrix_square(int or,int w);//matrice adj (carre) // w is initial values of the matrix
int** adjency_matrix(struct graph* G);
int** weighted_adjency_matrix(struct graph* G);//for floyd warshall
int** matrix(int or,int vct);//incidence not square
int** incidence_matrix(struct graph* G);
char* topology_ordre(struct graph* G);//ykhdemch
char label_node_i(struct graph* G,int i);//return label for node number i
int is_cyclic(struct graph* G);//topology_ordre=NULL 1 means cyclic 0 no//moch mjarrab
//rang dune sommet f tri topologie
/********************************************************/
struct floyd* floydwarshall(struct graph* G);//oriented no negatif cycle!!!!
struct print* floydwarshall_result(struct graph* G,char lbl1 ,char lbl2 );
int is_connex(struct graph* G);//no INF IN floyd warshall D//fortement  il exsite une chemin entre deux noeud;//1 means connex 0 no//moch mjarrab
//distance
//int diametre
//Trasitive closure
//mazel fazet l distance
//bellfort
//djikestra
//coloriage
//pofondeur
//largeur
