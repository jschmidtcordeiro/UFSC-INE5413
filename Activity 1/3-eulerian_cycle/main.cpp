#include "System.h"

#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>

/*
[Ciclo Euleriano] (2,0pts) Crie um programa que recebe um grafo como argumento. Ao final, o programa deverá
determinar se há ou não um ciclo euleriano e exibí-lo na tela de acordo com o exemplo abaixo. A primeira linha
deverá conter o número 0 caso o grafo não contenha o ciclo euleriano. Caso contenha, deverá ser impresso 1 na
primeira linha e em seguida, a sequência de vértices que corresponde ao ciclo deverá ser impressa.
 * */



std::vector<bool> bfs(Graph *graph) {
  // os nós são numerados a partir de 1, logo usamos um elemento 
  // sentinela para simplificar o código
  std::vector<bool> visited(graph->getNodes().size() + 1, false);
  visited[0] = true;

  std::queue<Node*> queue;

  queue.push(graph->getNodes()[0]);
  while (!queue.empty()) {
    auto node = queue.front();
    queue.pop();

    visited[node->getValue()] = true;
    for (auto edge : node->getNeighbors()) {
      auto neighboor = edge->getDestination();
      if (visited[neighboor->getValue()]) continue;

      queue.push(neighboor);
    }
  }

  return visited;
}

bool is_eulerian(Graph *graph) {
  // Se houver algum nó com grau ímpar, o grafo não é  euleriano
  for (auto& node : graph->getNodes())
    if (node->getNeighbors().size() % 2 != 0)
      return false;

  auto visited = bfs(graph);

  // O grafo só é euleriano se ele for conectado (i.e: se bfs consegue visitar todos os vértices)
  return std::all_of(visited.begin(), visited.end(), [](const bool& b){
      return b;
  });
}


std::pair<bool, std::vector<Node*>> find_euler_circuit(Graph *graph) {
  if (!is_eulerian(graph)) return {false, {}};


  std::set<std::pair<int, int>> edges_visited;
  std::vector<int> num_of_neighboors_visited(graph->numberOfNodes()+1, 0);
  
  std::vector<Node*> path;
  std::stack<Node*> trail;

  trail.push(graph->getNodes()[0]);

  while (!trail.empty()) {
    auto node = trail.top();
    int node_value = node->getValue();
    auto node_neighboors = node->getNeighbors();

    if (num_of_neighboors_visited[node_value] == node_neighboors.size()) {
      path.push_back(node);
      trail.pop();
      continue;
    }

    // Acha a primeira aresta ainda não visitada que está conectada ao `node` atual
    auto neighboor = std::find_if(node_neighboors.begin(), node_neighboors.end(), [&edges_visited](Edge* edge) {
        int source = edge->getSource()->getValue();
        int destination = edge->getDestination()->getValue();
        return !edges_visited.count({source, destination});
    });

    int source = (*neighboor)->getSource()->getValue();
    int destination = (*neighboor)->getDestination()->getValue();

    num_of_neighboors_visited[source]++;
    num_of_neighboors_visited[destination]++;

    edges_visited.insert({source, destination});
    edges_visited.insert({destination, source});

    trail.push((*neighboor)->getDestination());
  }

  std::reverse(path.begin(), path.end());
  return {true, path};
}

int main(int argc, char **argv) {
  std::string filepath = "input";
  if (argc > 1)
    filepath = argv[1];

  System sys(filepath);
  sys.run();
  Graph* graph = sys.getGraph();

  auto[found, eulerian_circuit] = find_euler_circuit(graph);

  if (!found) {
    std::cout << "0\n";
  } else {
    std::cout << "1\n";

    for (int i = 0; i < eulerian_circuit.size(); ++i) {
      std::cout << eulerian_circuit[i]->getValue();
      if (i == eulerian_circuit.size() - 1) std::cout << '\n';
      else std::cout << ',';
    }
      
  }
}
