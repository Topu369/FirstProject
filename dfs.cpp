#include <iostream>
using namespace std;
void DFS(int graph[9][9], int totalNodes, int startNode)
{
    int stack[9];
    int top = -1;
    bool visited[9] = {false};

    stack[++top] = startNode;

    cout << "DFS Traversal: ";

    while (top != -1)
    {
        int currentNode = stack[top--];

        if (!visited[currentNode])
        {
            cout << currentNode << " ";
            visited[currentNode] = true;

            for (int i = totalNodes - 1; i >= 0; i--)
            {
                if (graph[currentNode][i] == 1 && !visited[i])
                {
                    stack[++top] = i;
                }
            }
        }
    }

    cout << endl;
}
int main()
{
    const int totalNodes = 9;

    int graph[9][9] =
    {
        // 0  1  2  3  4  5  6  7  8
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
        {1, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
        {0, 0, 0, 0, 1, 0, 0, 1, 0}, // 2
        {0, 1, 0, 0, 0, 0, 0, 0, 0}, // 3
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
        {1, 0, 1, 0, 0, 0, 0, 0, 0}, // 5
        {0, 0, 0, 1, 0, 1, 0, 0, 1}, // 6
        {0, 0, 0, 0, 0, 1, 1, 0, 1}, // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0}  // 8
    };

    int startNode = 2;
    DFS(graph, totalNodes, startNode);

    return 0;
}
