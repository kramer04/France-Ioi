#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
struct Edge
{
  int node, length;
};
struct State
{
  int node, distance;
  bool operator>(const State &other) const
  {
    return distance > other.distance;
  }
};
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, A, start, end;
  std::cin >> N >> A >> start >> end;
  std::vector<std::vector<Edge>> adj(N + 1);
  for (int i = 0; i < A; ++i)
  {
    int u, v, l;
    std::cin >> u >> v >> l;
    adj [u].push_back({v, l});
    adj [v].push_back({u, l});
  }
  std::vector<int> dist(N + 1, INT_MAX);
  std::vector<int> pred(N + 1, -1);
  dist [start] = 0;
  std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
  pq.push({start, 0});
  while (!pq.empty())
  {
    State current = pq.top();
    pq.pop();
    int node = current.node;
    int distance = current.distance;
    if (distance > dist [node]) continue;
    for (const Edge &edge : adj [node])
    {
      int next_node = edge.node;
      int new_distance = distance + edge.length;
      if (new_distance < dist [next_node])
      {
        dist [next_node] = new_distance;
        pred [next_node] = node;
        pq.push({next_node, new_distance});
      }
    }
  }
  std::vector<int> path;
  for (int at = end; at != -1; at = pred [at])
  {
    path.push_back(at);
  }
  std::reverse(path.begin(), path.end());
  std::cout << dist [end] << " " << path.size() << "\n";
  for (int node : path)
  {
    std::cout << node << " ";
  }
  std::cout << "\n";
  return 0;
}
