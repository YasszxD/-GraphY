#include <stdio.h>
#include <stdlib.h>
#include "GraphY.h"
#include <stdbool.h>
//graph oriente, label ordered inc;
int main(int argc, char const *argv[]) {
  struct graph* g1=malloc(sizeof(struct graph));
  g1=new_graph(3);
//  printf("%i\n",is_empty(g1));
  add_node(g1,0);
  add_node(g1,1);
  add_edge(g1,1, 0);
  add_edge(g1,0, 1);
  printf("%i\n",is_complet(g1));
  return 0;
}
