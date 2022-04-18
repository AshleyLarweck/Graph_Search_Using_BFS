#include<stdio.h>
#include "Graph.h"

//Given the number of vertices of the graph, allocate the nxn adjacency matrix and initialize every edge to 0 (i.e. the edges aren't there initially).
//Return the address of the graph.
Graph newGraph(int n)
{
    Graph myGraph = (Graph)malloc(sizeof(GraphImp));
	//allocate 2d array
	myGraph->adjacencyM = (int**)malloc(n*sizeof(int*));	
	int i;
	for (i = 0; i < n; i++)
	{
		myGraph->adjacencyM[i] = (int*)malloc(n*sizeof(int));
		int j;
		for (j = 0; j< n; j++)
		{
			myGraph->adjacencyM[i][j] = 0;
		}
	}
}

//Free the adjacency matrix and then the graph itself.
void freeGraph(Graph g)
{
    int i;
    
    for(i = 0; i <= g->n; i++)
    {
        free(g->adjacencyM[i]);
        free(g->adjacencyM);
        free(g);
    }
}

//Add the edge e to the graph g.
void addEdge(Graph g, Edge e)
{
    g->adjacencyM[e.fromVertex][e.toVertex] = 1;
}

//Given graph g and vertex v, scan the adjacency matrix and return the first edge in g such that v is the "fromVertex" of the edge.
//Return -1 if there is no such edge.
Edge firstAdjacent(Graph g, Vertex v)
{
    Edge e;
    int i;
    e.fromVertex = v;
    
    for(i = v; i <= g->n; i++)
    {
        if(g->adjacencyM[v][i])
        {
            e.toVertex = i;
        }
        else
        {
            e.toVertex = -1;
        }
    }
    return e;
}

//Given graph g and vertex e, scan the adjacency matrix and return the next edge after e in g such that e.fromVertex is the "fromVertex" of the edge.
//Return -1 if there is no such edge.
Edge nextAdjacent(Graph g, Edge e)
{
    Edge tempEdge;
    tempEdge.fromVertex = e.fromVertex;
    int i;
    
    for(i = e.toVertex + 1; i <= g->n; i++)
    {
        if(g->adjacencyM[e.fromVertex][i])
        {
            tempEdge.toVertex = i;
        }
        else
        {
            tempEdge.toVertex = -1;
        }
    }
    
    if(tempEdge.toVertex == -1)
    {
        tempEdge.fromVertex = -1;
    }
    
    Edge nextEdge = tempEdge;
    
    return nextEdge;
}

//Print the sequence of vertices on a shortest path in g starting from start and ending at destination.  
//A shortest path should be computed using the Breadth First Search (BFS) algorithm that maintains the parents of each vertex in the shortest path tree as defined in class.  
//BFS can be implemented directly in this function, or you may create a new function for BFS.
void shortestPath(Graph g, Vertex start, Vertex destination)
{
    Queue q = newQueue();
    int visitedArr[g->n]; 
    int parentArr[g->n];
    Edge e;
    Vertex currentVertex, tempVertex;
	visitedArr[start] = TRUE;
	
	enqueue(q,start);
    
    while(dequeue(q, &currentVertex))
    {
        for(e = firstAdjacent(g, currentVertex); e.toVertex != -1; e = nextAdjacent(g, e))
        {
            tempVertex = e.toVertex;
            
            if(visitedArr[tempVertex] == FALSE)
			{
				enqueue(q,tempVertex);
				visitedArr[tempVertex] = TRUE;
				parentArr[tempVertex] = currentVertex;
			}	
        } 
    } 
    freeQueue(q);
}