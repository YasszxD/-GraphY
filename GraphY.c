#include <stdio.h>
#include <stdlib.h>
#include "GraphY.h"


struct graph* new_graph(int nb_vertices){
  struct graph* G = malloc(sizeof(struct graph));
  struct adjlist* arr = malloc(sizeof(struct adjlist));
  G->nb_vct=0;
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
//7keyet ltartib
