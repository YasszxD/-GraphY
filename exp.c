#include <stdio.h>
#include <stdlib.h>
#include "GraphY.h"
#include <stdbool.h>
//graph oriente, label ordered inc;
int main(int argc, char const *argv[]) {
  struct graph* g1=malloc(sizeof(struct graph));
  g1=new_graph();
//  printf("%i\n",is_empty(g1));
add_node(g1,'A');
add_node(g1,'B');
add_node(g1,'C');
add_node(g1,'D');
add_node(g1,'E');
int i=0,j=0;
//add_edge(g1,'A','B');
add_edge(g1,'A','D');
add_edge(g1,'A','B');
add_edge(g1,'B','D');
add_edge(g1,'C','A');
add_edge(g1,'D','E');
char* lol = topology_ordre(g1);
//printf("%p\n",lol );
if (lol!=NULL){
for (j = 0; j < graph_order(g1); j++) {
  printf("%c\t",*(lol+j));
}}


  return 0;
}
