#include <iostream>
#include <unordered_set>
#include <vector>
#include <numeric>

#include "Graph.h"


bool coloring_with_n_colors(int u, Graph& g, std::vector<int>& colors, int max_color) {
  if (u == g.getSize())
    return true;
  
  std::unordered_set<int> adj_colors;
  for (auto& v : g.adj[u])
    if (colors[v] != -1)
      adj_colors.insert(colors[v]);
  
  for (int c = 0; c < max_color; ++c) {
    if (adj_colors.count(c))
      continue;

    int old_c = colors[u];
    colors[u] = c;
    if (coloring_with_n_colors(u+1, g, colors, max_color))
      return true;
    colors[u] = old_c;
  }

  return false;
}

std::vector<int> get_minimum_color(Graph& g) {
  for (int i = 1; i <= g.getSize(); ++i) {
    std::vector<int> colors(g.getSize(), -1);

    if (coloring_with_n_colors(0, g, colors, i))
      return colors;
  }

  return {};
}


int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Uso: main <arquivo-de-input>\n";
    return 0;
  }

  std::string path(argv[1]);
  auto graph = Graph::read_graph(path);

  auto colors = get_minimum_color(graph);
  int min_col = std::reduce(colors.begin(), colors.end(), -1, [](const int& a, const int& b) {return std::max(a,b);}) + 1;

  std::cout << "Coloração mínima: " << min_col << '\n';
  std::cout << "Números cromáticos: ";

  for (auto& c : colors)
    std::cout << c+1 << ' ';
  std::cout << '\n';
}
