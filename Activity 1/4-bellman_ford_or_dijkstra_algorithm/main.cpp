#include "System.h"

#include <algorithm>
#include <exception>
#include <vector>
#include <utility>
#include <stack>
#include <queue>

/*
[Algoritmo de Bellman-Ford ou de Dijkstra] (2,0pts) Crie um programa que recebe um arquivo de grafo como
argumento e um vértice s. O programa deverá executar o algoritmo de Bellman-Ford ou de Dijkstra e informar o
caminho percorrido de s até todos os outros vértices do grafo e a distância necessária. A saída deverá ser impressa
na tela de acordo com o exemplo abaixo. Cada linha representa o caminho realizado de s para o vértice da respectiva
linha. Em cada linha, antes dos símbolo “:” deverá estar o vértice destino. À direita de “:”, encontra-se o caminho
percorrido de s até o vértice destino. Mais à direita encontram-se os símbolos “d=” seguidos da distância necessária
para percorrer o caminho.
 * */



std::vector<Node*> get_path(std::vector<Node*>& ancestors, Node *dest) {
  std::vector<Node*> path = {dest};
  int destination = dest->getValue();

  while (ancestors[destination]) {
    path.push_back(ancestors[destination]);
    destination = ancestors[destination]->getValue();
  }

  std::reverse(path.begin(), path.end());
  return path;
}

std::pair<std::vector<int>, std::vector<Node*>> dijkstra(Graph *graph, int src) {
  std::vector<bool> visited(graph->numberOfNodes()+1, false);
  visited[0] = true;

  std::vector<Node*> ancestors(graph->numberOfNodes()+1, nullptr);
  
  std::vector<int> distance(graph->numberOfNodes()+1, 1e9);
  distance[src] = 0;
  
  std::set<std::pair<int, int>> st;
  for (auto node : graph->getNodes())
    st.emplace(distance[node->getValue()], node->getValue());


  while (!st.empty()) {
    int u = st.begin()->second;
    auto u_ptr = graph->getNode(u);
    visited[u] = true;

    st.erase(st.begin());

    for (auto& edge : u_ptr->getEdges()) {
      auto v_ptr = edge->getDestination();
      int w = edge->getValue();
      int v = v_ptr->getValue();

      if (visited[v] || distance[v] < distance[u] + w) continue;

      auto old_value = st.extract({distance[v], v});
      old_value.value() = {distance[u] + w, v};
      st.insert(std::move(old_value));

      ancestors[v] = u_ptr;
      distance[v] = distance[u] + w;
    }

  }

  return {distance, ancestors};
}


int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Uso: main <índice de vértice de origem>\n";
    return -1;
  }
  
  int src;
  try {
    src = std::stoi(argv[1]);
  } catch (std::exception& e) {
    std::cout << "Erro! O índice deve ser um número\n";
    return -2;
  }


  System sys("input");
  sys.run();
  Graph* graph = sys.getGraph();

  if (src > graph->numberOfNodes()) {
    std::cout << "O índice deve ser um número menor que a quantidade de vértices no grafo\n";
    return -3;
  }

  auto[distance, ancestors] = dijkstra(graph, src);

  for (int i = 1; i < graph->numberOfNodes()+1; ++i) {
    auto path = get_path(ancestors, graph->getNode(i));
    std::cout << i << ": ";

    for (int j = 0; j < path.size(); ++j) {
      std::cout << path[j]->getValue();
      if (j == path.size() - 1) std::cout << ";";
      else std::cout << ",";
    }


    std::cout << " d=" << distance[i] << '\n';
  }

}
