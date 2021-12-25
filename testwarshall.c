#include <stdio.h>
#include <stdlib.h>
#include "GraphY.h"
#include <stdbool.h>
//graph oriente, label ordered inc;
int main(int argc, char const *argv[]) {
  struct graph* g1=malloc(sizeof(struct graph));
  g1=new_graph();
add_node(g1,'A');
add_node(g1,'B');
add_node(g1,'C');
add_node(g1,'D');
//add_node(g1,'E');
add_edge(g1,'A','B',4);
add_edge(g1,'B','C',1);
add_edge(g1,'B','D',4);
add_edge(g1,'C','A',-2);
add_edge(g1,'C','D',1);
add_edge(g1,'D','B',3);
struct floyd* f=floydwarshall(g1);
int i = 0,j=0;
for (i = 0; i < graph_order(g1); i++) {
  for (j = 0; j < graph_order(g1); j++) {
    printf("%d\t",*(*(f->D+i)+j) );
  }
  printf("\n" );
}
printf("\n" );printf("\n" );
for (i = 0; i < graph_order(g1); i++) {
  for (j = 0; j < graph_order(g1); j++) {
    printf("%d\t",*(*(f->P+i)+j) );
  }
  printf("\n" );
}
struct print* p = floydwarshall_result(g1,'A','D');
printf("\n" );printf("\n" );
printf("%d\n",p->dist );
//chemin
for (i = 0; i < p->len; i++) {
  printf("%c\t",label_node_i(g1,*(p->chemin+i)));
}
printf("\nconnex = %d",is_connex(g1));
printf("\ncyclic = %d",is_cyclic(g1));
  return 0;
}

