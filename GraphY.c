#include <stdio.h>
#include <stdlib.h>
#include "GraphY.h"
//graph oriente non pondere
/******************************edit graph**************************/
struct graph* new_graph(int is_or){
  struct graph* G = malloc(sizeof(struct graph));
  struct adjlist* arr = malloc(sizeof(struct adjlist));
  G->nb_vct=0;
  G->nb_edge=0;
  G->is_oriented=is_or;
  G->array=arr;
  arr->begin=NULL;
  return G;
}

int is_empty(struct graph* G){if( G->array->begin == NULL) return 0; else return 1;}
void add_node(struct graph* G,int lbl){
  G->nb_vct+=1;
  struct Node* new_node = malloc(sizeof(struct Node));
  struct adjlist* arr = malloc(sizeof(struct adjlist));
  new_node->next=NULL;
  new_node->label=lbl;
  new_node->neighbors=NULL;
  if (!G->array->begin) {
    G->array->begin=new_node;
  }
  else{
    struct Node* parcour = malloc(sizeof(struct Node));
    parcour = G->array->begin;
    while (parcour->next!=NULL && lbl>parcour->next->label) {
      parcour=parcour->next;
    }
    if(parcour->next==NULL)
      parcour->next=new_node;
    else{
      new_node->next=parcour->next;
      parcour->next=new_node;
    }
  }
}

void add_edge(struct graph* G,int lbl_src , int lbl_dest){
  struct Node* src = malloc(sizeof(struct Node));
  src = G->array->begin;
  while (src->next!=NULL && src->label!=lbl_src) {
    src=src->next;
  }
  /*struct Node* dest = malloc(sizeof(struct Node));
  dest = G->array->begin;
  while (dest->next!=NULL && dest->label!=lbl_dest) {
    dest=dest->next;
  }*/
  while (src->neighbors != NULL ) {
    src=src->neighbors;
  }
  src->neighbors = malloc(sizeof(struct Node));
  src->neighbors->label=lbl_dest;
  src->neighbors->next=NULL;
  src->neighbors->neighbors=NULL;
  G->nb_edge++;
}

int has_edge(struct graph* G,int lbl_src , int lbl_dest){
  struct Node* src = malloc(sizeof(struct Node));
  src = G->array->begin;
  while (src->next!=NULL && src->label!=lbl_src) {
    src=src->next;
  }
  while (src->neighbors != NULL ) {
    src=src->neighbors;
    if(src->label==lbl_dest)
      return 1;
  }
  return 0;
}

void del_edge(struct graph* G,int lbl_src , int lbl_dest){
  struct Node* src = malloc(sizeof(struct Node));
  src = G->array->begin;
  while (src->next!=NULL && src->label!=lbl_src) {
    src=src->next;
  }
  while (src->neighbors->neighbors!=NULL &&
         src->neighbors->label!=lbl_dest) {
    src=src->neighbors;
  }
  if(src->neighbors->label==lbl_dest)
    src->neighbors=src->neighbors->neighbors;
}

void del_node(struct graph* G,int lbl){
  G->nb_vct-=1;
  while(G->array->begin->next!=NULL &&
        G->array->begin->next->label!=lbl){
    G->array->begin->next=G->array->begin->next->next;
  }
  struct Node* f = G->array->begin->next;
  if(G->array->begin->next->label==lbl){
    G->array->begin->next=G->array->begin->next->next;
    free(f);
  }
}
/****************************************************************************/
int graph_order(struct graph* G){return G->nb_vct;}
int vct_order(struct graph* G,int lbl){
  while(G->array->begin!=NULL&&G->array->begin->label!=lbl){
    G->array->begin=G->array->begin->next;
  }
  int count = 0;
  if(G->array->begin->label==lbl){
    while (G->array->begin!=NULL) {
      count++;
      G->array->begin=G->array->begin->neighbors;
    }
  }
  return count;
}
int is_cyclic(struct graph* G){
  /*tritopologie*/
}

int is_simple(struct graph* G){
  struct Node* courant = G->array->begin;
  while(courant!=NULL){
    struct Node* parcour = courant->neighbors;
    struct Node* doubleliason = courant;
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
/****************************************************************************/
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
  struct Node* courant = G->array->begin;
  struct Node* parcour;
  while(courant!=NULL){
    parcour = courant->neighbors;
    while (parcour!=NULL) {
      //adj_mat[parcour->label][courant->label]-=1;
      adj_mat[courant->label][parcour->label]+=1;
      parcour=parcour->neighbors;
    }
    courant=courant->next;
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
  struct Node* courant = G->array->begin;
  struct Node* parcour;
  int vct_num=0;
  while(courant!=NULL){
    parcour = courant->neighbors;
    while (parcour!=NULL) {
      inc_mat[courant->label][vct_num]-=1;
      inc_mat[parcour->label][vct_num]+=1;
      parcour=parcour->neighbors;
      vct_num+=1;
    }
    courant=courant->next;
  }
  return inc_mat;
}
