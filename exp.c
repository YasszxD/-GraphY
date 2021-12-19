#include <stdio.h>
#include <stdlib.h>
#include "GraphY.h"
#include <stdbool.h>
//graph oriente, label ordered inc;
int main(int argc, char const *argv[]) {
  struct graph* g1=malloc(sizeof(struct graph));
  g1=new_graph(3);
  printf("%i\n",is_empty(g1));
  add_node(g1,0);
  add_node(g1,1);
  add_node(g1,2);
  add_edge(g1,1, 0);
  if(has_edge(g1,1,0))
    printf("lol\n");
  add_edge(g1,1, 2);
  del_node(g1,1);
  if(has_edge(g1,1,0))
    printf("lol\n");
  printf("%i\n",is_empty(g1));
  return 0;
}
