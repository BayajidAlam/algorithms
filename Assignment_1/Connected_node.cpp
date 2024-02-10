#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // input node and edge
  int n, e;
  cin >> n >> e;

  // initialize an adjacency list
  vector<int> mat[n];

  while (e--)
  {
    // input a, b
    int a, b;
    cin >> a >> b;
    // connection
    mat[a].push_back(b);
    mat[b].push_back(a); // ignore this if the graph is directed
  }

  // input the number of queries
  int tt;
  cin >> tt;

  while (tt--)
  {
    // input the query node
    int x_node;
    cin >> x_node;

    // check if the query node has any connected nodes
    if (mat[x_node].empty())
    {
      cout << "-1" << endl;
    }
    else
    {
      // sort the connected nodes in descending order
      sort(mat[x_node].begin(), mat[x_node].end(), greater<int>());

      // print the result
      for (int connectedNode : mat[x_node])
      {
        cout << connectedNode << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
