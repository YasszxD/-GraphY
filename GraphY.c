#include <stdio.h>
#include <stdlib.h>
#include "GraphY.h"
//graph oriente non pondere
/******************************edit graph**************************/
//create  new graph
struct graph* new_graph(){
  struct graph* G = malloc(sizeof(struct graph));
  G->nb_vct=0;
  G->nb_edge=0;
  G->begin=NULL;
  return G;
}
int is_empty(struct graph* G){if( G->begin == NULL) return 1; else return 0;}
int has_node(struct graph* G,char lbl){
  struct Node* parcour = malloc(sizeof(struct Node));
  parcour = G->begin;
  int i = 0;
  while (parcour!=NULL) {
    if (lbl==parcour->label)  return i;
    parcour=parcour->next;
    i++;
  }
  return -1;
}
int add_node(struct graph* G,char lbl){
  //search same name with other Node
  if(has_node(G,lbl)!=-1) return 0;
  G->nb_vct+=1;
  struct Node* parcour = malloc(sizeof(struct Node));
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->next=NULL;
  new_node->label=lbl;
  new_node->neighbors=NULL;

  if (is_empty(G)) {
    G->begin=new_node;
  }

  else{// sort new nodes

    if(lbl<G->begin->label){//if new node > first node
        parcour=G->begin;
        G->begin=new_node;
        new_node->next=parcour;
    }
    else{
    //sort the rest
    parcour = G->begin;
    while (parcour->next!=NULL && lbl>parcour->next->label) {
      parcour=parcour->next;
    }
    if(parcour->next==NULL)//new node is the last node
      parcour->next=new_node;
    else{
      new_node->next=parcour->next;
      parcour->next=new_node;
    }
  }
  }
  return 1;
}

int add_edge(struct graph* G,char lbl_src , char lbl_dest){

  if(has_node(G,lbl_src)==-1 || has_node(G,lbl_dest)==-1) return 0;
  struct Node* src = malloc(sizeof(struct Node));
  src = G->begin;
  while (src->next!=NULL && src->label!=lbl_src) {//search the src node
    src=src->next;
  }
  while (src->neighbors != NULL && lbl_dest>src->neighbors->label ) {//sort lbl_dest in src neighbors
    src=src->neighbors;
  }
  struct Node* new_neighbor = malloc(sizeof(struct Node));
  new_neighbor->label=lbl_dest;
  new_neighbor->next=NULL;
  new_neighbor->neighbors=NULL;
  if(src->neighbors == NULL){//last node or first;
  src->neighbors = new_neighbor;
  }
  else{//sort the new node in neighbors
    new_neighbor->neighbors=src->neighbors;
    src->neighbors=new_neighbor;
  }
  G->nb_edge++;
  return 1;
}

int has_edge(struct graph* G,char lbl_src , char lbl_dest){
  if(has_node(G,lbl_src) ==-1 || has_node(G,lbl_dest)==-1) return 0;
  struct Node* src = malloc(sizeof(struct Node));
  src = G->begin;
  while (src->next!=NULL && src->label!=lbl_src) {//search src
    src=src->next;
  }
  while (src->neighbors != NULL ) {
    src=src->neighbors;
    if(src->label==lbl_dest)//serach dest;
      return 1;
  }
  return 0;
}
void del_edge(struct graph* G,char lbl_src , char lbl_dest){
  if(has_node(G,lbl_src)==-1||has_node(G,lbl_dest)==-1) return;//dst or src not in graph
  struct Node* src = malloc(sizeof(struct Node));
  src = G->begin;
  while (src->next!=NULL && src->label!=lbl_src) {//search src
    src=src->next;
  }
  while (src->neighbors->neighbors!=NULL && //search  the node before which we want to delete
         src->neighbors->label!=lbl_dest) {
    src=src->neighbors;
  }
  if(src->neighbors->label==lbl_dest)//if the node we want to delete is the last
    src->neighbors=src->neighbors->neighbors;
}
void del_node(struct graph* G,char lbl){
  if(has_node(G,lbl)==-1) return;
  //delete the node edges then the node
  G->nb_vct-=1;
  struct Node* parcour = malloc(sizeof(struct Node));
  parcour = G->begin;
  if(parcour->label=lbl){
    while(parcour->neighbors != NULL){//delete edges
      del_edge(G,lbl,parcour->neighbors->label);
    }
    G->begin=parcour->next;//delete node
  }
  else{
    while(parcour->next!=NULL && parcour->next->label!=lbl){ //search the lbl;
      parcour=parcour->next;
    }
    while(parcour->neighbors != NULL){//delete edges
      del_edge(G,lbl,parcour->neighbors->label);
    }
    parcour->next=parcour->next->next;//delete nodes
  }
}
/****************************************************************************/
struct print* print_graph(struct graph* G){
  struct print* ptr = malloc(1*sizeof(struct print));
  ptr->str = malloc(100*sizeof(char));
  char* a=ptr->str;
  ptr->len=0;
  struct Node* courant = G->begin;
  struct Node* parcour;
  while (courant!=NULL){
    parcour=courant->neighbors;
    while(parcour!=NULL){
      *a=courant->label;
				a++;
				*a=' ';
				a++;
				*a='i';
				a++;
				*a='s';
				a++;
				*a=' ';
				a++;
				*a='c';
				a++;
				*a='o';
				a++;
				*a='n';
				a++;
				*a='n';
				a++;
				*a='e';
				a++;
				*a='c';
				a++;
				*a='t';
				a++;
				*a='e';
				a++;
				*a='d';
				a++;
				*a=' ';
				a++;
				*a='t';
				a++;
				*a='o';
				*a++;
				*a=' ';
				a++;
				*a=parcour->label;
				a++;
				*a='\n';
				a++;
        ptr->len+=20;
      parcour=parcour->neighbors;
    }
    courant=courant->next;
  }
  return ptr;
}
/****************************************************************************/
int graph_order(struct graph* G){return G->nb_vct;}

int vct_order_exit(struct graph* G,char lbl){
  struct Node* courant = G->begin;
  while(courant!=NULL&&courant->label!=lbl){//search lbl
    courant=courant->next;
  }
  int count = 0;
  if(courant->label==lbl){
    while (courant->neighbors!=NULL) {
      count++;
      courant=courant->neighbors;
    }
  }
  return count;
}
int vct_order_entre(struct graph* G,char lbl){
    int count = 0 ;
    struct Node* courant = G->begin;
    struct Node* parcour;
    while(courant!=NULL){
      parcour = courant->neighbors;
      while (parcour!=NULL) {
        if(parcour->label==lbl)
          count++;
        parcour=parcour->neighbors;
      }
      courant=courant->next;
    }
    return count;
}

int is_cyclic(struct graph* G){
  /*tritopologie*/
}

int is_simple(struct graph* G){ // node is not link with herself or has 2 link with same node
  struct Node* courant = G->begin;
  struct Node* parcour;
  struct Node* doubleliason;
  while(courant!=NULL){
    parcour = courant->neighbors;
    doubleliason = courant;
    while (parcour!=NULL) {
      if(courant->label==parcour->label || doubleliason->label==parcour->label ){
        return 0;
      }
      parcour=parcour->neighbors;
      doubleliason=doubleliason->neighbors;
    }
    courant=courant->next;
  }
  return 1;
}

int is_complet(struct graph* G){
  if(G->nb_edge==graph_order(G)*(graph_order(G)-1))
    return 1;
  return 0;
}
/***************************************************************************/
//matrice d adjacence
int** matrix_square(int or){
  //int or =k;
  int** mat = malloc(or*sizeof(int*));
  int** x =mat;
  for(x;x<mat+or;x++){
    *x = malloc(or * sizeof(int));
  }
  //init
  int** i = mat;
  int* j;
  for (i;i<mat+or;i++){
    for(j=*i;j<*i+or;j++){
      *j=0;
    }
  }
  return mat;
}

int** adjency_matrix(struct graph* G){
  int or = graph_order(G);
  int** adj_mat=matrix_square(or);
  struct Node* courant = G->begin;
  struct Node* parcour;
  int i=0;
  while(courant!=NULL){
    parcour = courant->neighbors;
    while (parcour!=NULL) {
      //adj_mat[parcour->label][courant->label]-=1;
      adj_mat[i][has_node(G,parcour->label)]+=1;
      parcour=parcour->neighbors;
    }
    courant=courant->next;
    i++;
  }
  return adj_mat;
}
int** matrix(int or,int vct){
  //int or =k;
  int** mat = malloc(or*sizeof(int*));
  int** x =mat;
  for(x;x<mat+or;x++){
    *x = malloc(vct * sizeof(int));
  }
  //init
  int** i = mat;
  int* j;
  for (i;i<mat+or;i++){
    for(j=*i;j<*i+vct;j++){
      *j=0;
    }
  }
  return mat;
}
int** incidence_matrix(struct graph* G){
  int** inc_mat=matrix(graph_order(G),G->nb_vct);
  struct Node* courant = G->begin;
  struct Node* parcour;
  int vct_num=0,i=0;
  while(courant!=NULL){
    parcour = courant->neighbors;
    while (parcour!=NULL) {
      inc_mat[i][vct_num]-=1;
      inc_mat[has_node(G,parcour->label)][vct_num]+=1;
      parcour=parcour->neighbors;
      vct_num+=1;
    }
    i++;
    courant=courant->next;
  }
  return inc_mat;
}
char label_node_i(struct graph* G,int i){
  struct Node* courant = G->begin;
  while(i){
    i--;
    courant=courant->next;
  }
  return courant->label;
}

char* topology_ordre(struct graph* G){
  int or = graph_order(G);
  char* ret = malloc(or*sizeof(char));//max length
  int* deleted= malloc(or*sizeof(int));
  int* parc = deleted;
  for(parc;parc<deleted+or;parc++) {*parc=0;}
  char* parc_char = ret;
  int** adj_mat =adjency_matrix(G);
  int k,z,i = 0,j=-1;
  int flag = 1;//1 mean all are zeros ,0 no
  int flag_changed=0;
  int* check_cycle=NULL;
  while(check_cycle!=*(adj_mat+i)){
    if(deleted[i]==1)
      goto pass;
    for(k=0;k<or;k++){
      if(*(*(adj_mat+k)+i)!=0){
        flag=0;
        break;
      }
    }
    if(flag==1){
      check_cycle=*(adj_mat+i);
      deleted[i]=1;
      *parc_char=label_node_i(G,i);
      parc_char++;
      for(k=0;k<or;k++){
        *(*(adj_mat+i)+k)=0;
      }
    }
    flag=1;
    pass :if(check_cycle==NULL) check_cycle=*(adj_mat+i);
         i++;
         if(i==or) i = 0;

  }
  for (k = 0; k < or; k++) {
    for (i = 0; i < or; i++) {
      if(*(*(adj_mat+k)+i)==1){
        ret=NULL;//return NULL if graph is is_cyclic
        break;
      }
    }
  }
return ret;
}
