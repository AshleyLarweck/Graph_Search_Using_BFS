#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Graph.h"

int main()
{
    FILE *fileIn;
    char buffer[100];
    int numVertices, numPaths; 
    int numEdges, spStart, spDestination;
    int i = 0, j = 0;
    Edge myEdge;
    char spString[15];

    fileIn = fopen("p4Input.txt", "r");
    if(fileIn == NULL)
      {
        printf("Unable to open file.\n");
        return 1;
      }

    fgets(buffer, 50, fileIn);
    scanf(buffer, "%d\n", &numVertices);

    fgets(buffer, 50, fileIn);
    scanf(buffer, "%d\n", &numEdges);

    Graph myGraph = newGraph(numVertices);
    myEdge.fromVertex = 0;
    myEdge.toVertex = 1;
    int initialEdge;
    int finalEdge;
    

    while(fgets(buffer, 100, fileIn) != NULL)
    {
        sscanf(buffer, "%d %d\n", &initialEdge, &finalEdge);

        myEdge.fromVertex = initialEdge;
        myEdge.toVertex = finalEdge;
        addEdge(myGraph, myEdge);
         
        i++;
    }
    
    Stack stack = newStack(numVertices);

    fgets(buffer, 100, fileIn);
    sscanf(buffer, "%d\n", &numPaths);
    //printf("%d ", numPaths);

    while(fgets(buffer, 100, fileIn) != NULL && j < numVertices)
    {
      sscanf(buffer, "%15s %d %d", spString, &spStart, &spDestination);

    //printf("%d ", spStart);
    //printf("%d ", spDestination);

    j++;
    }
    
    fclose(fileIn);
    freeGraph(myGraph);
    return 0;
}