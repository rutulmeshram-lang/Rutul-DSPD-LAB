//7.Consider the undirected graph G, consisting of n nodes laid out in a 3 -by- 3 grid: Start searching at node 1, and break ties for exploring the next node based on lower numerical order (i.e. add nodes to a queue low to high, add nodes to a stack high to low). (a) In what order are nodes marked as explored by BFS? (b) In what order are nodes marked as explored by DFS?
#include <stdio.h>
#define N 9
int adj[N+1][N+1];
int visited[N+1];
int queue[100], front = -1, rear = -1;
void enqueue(int val) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}
int isQueueEmpty() {
    return (front == -1 || front > rear);
}
int stack[100], top = -1;
void push(int val) {
    if (top < 99)
        stack[++top] = val;
}
int pop() {
    if (top == -1) return -1;
    return stack[top--];
}
int isStackEmpty() {
    return (top == -1);
}
void BFS(int start) {
    for (int i = 1; i <= N; i++)
        visited[i] = 0;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Order: ");
    while (!isQueueEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        for (int i = 1; i <= N; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}
void DFS(int start) {
    for (int i = 1; i <= N; i++)
        visited[i] = 0;
    push(start);
    printf("DFS Order: ");
    while (!isStackEmpty()) {
        int node = pop();
        if (!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);
            for (int i = N; i >= 1; i--) {
                if (adj[node][i] && !visited[i]) {
                    push(i);
                }
            }
        }
    }
    printf("\n");
}
void buildGraph() {
    for (int i = 1; i <= N; i++) {
        if (i % 3 != 0) { 
            adj[i][i+1] = 1;
            adj[i+1][i] = 1;
        }
        if (i + 3 <= N) { 
            adj[i][i+3] = 1;
            adj[i+3][i] = 1;
        }
    }
}
int main() {
    buildGraph();
    printf("Undirected Graph (3x3 Grid): Nodes 1 to 9\n");
    printf("Starting node: 1\n\n");
    BFS(1);
    DFS(1);
    return 0;
}
