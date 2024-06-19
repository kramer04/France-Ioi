#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
struct Edge
{
  int node, length;
};
struct Event
{
  int time, node;
  bool operator>(const Event &other) const
  {
    if (time == other.time) return node > other.node;
    return time > other.time;
  }
};
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, A, K;
  std::cin >> N >> A >> K;
  std::vector<std::vector<Edge>> adj(N + 1);
  for (int i = 0; i < A; ++i)
  {
    int u, v, l;
    std::cin >> u >> v >> l;
    adj [u].push_back({v, l});
    adj [v].push_back({u, l});
  }
  std::vector<int> dist(N + 1, INT_MAX);
  dist [K] = 0;
  std::priority_queue<Event, std::vector<Event>, std::greater<Event>> pq;
  pq.push({0, K});
  while (!pq.empty())
  {
    Event current = pq.top();
    pq.pop();
    int time = current.time;
    int node = current.node;
    if (time > dist [node]) continue;
    for (const Edge &edge : adj [node])
    {
      int next_node = edge.node;
      int new_time = time + edge.length;
      if (new_time < dist [next_node])
      {
        dist [next_node] = new_time;
        pq.push({new_time, next_node});
      }
    }
  }
  std::vector<Event> result;
  for (int i = 1; i <= N; ++i)
  {
    if (dist [i] < INT_MAX)
    {
      result.push_back({dist [i], i});
    }
  }
  std::sort(result.begin(), result.end(), [](const Event &a, const Event &b) {
    if (a.time == b.time) return a.node < b.node;
    return a.time < b.time;
  });
  for (const Event &event : result)
  {
    std::cout << event.time << " " << event.node << "\n";
  }
  return 0;
}
