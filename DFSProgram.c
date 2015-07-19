#include<stdio.h>
#include<time.h>
#include <string.h>
#define MAX 20000

struct DFSProgram
{
    int Id;
    char CityName[50];
    float Population;
    float Elevation; 
};

struct DFSProgram Nodes[MAX];
int G[MAX][MAX], visited[MAX], size=MAX; 
FILE * fileWriter;
void solveForDFS(int startingNode);
void printFinalOutput(int Node);

int main()
{
    fileWriter = fopen("output_DFS_C.txt", "w+");
    clock_t begin, end;
    int startingNode = 1; // by default the startingNode is 1
    printf("Enter Vertex Size : \n");
    scanf("%d",&size);
    printf("\n");
    int i = 0;
    for(i=0;i<size;i++)
    {
        visited[i] = 0;
    }
    i=0;
    int counterX = 0;
    int counterY = 0;
    FILE* file;
    if(size==100)
    {
    	file = fopen ("100/matrix-100.txt", "r");
    }
    else if (size == 1000)
    {
    	file = fopen ("1000/matrix-1000.txt", "r");
    }
    else if (size == 3000)
    {
    	file = fopen ("3000/matrix-3000.txt", "r");
    }
	else if (size == 4000)
    {
    	file = fopen ("4000/matrix-4000.txt", "r");
    }
	else if (size == 10000)
    {
    	file = fopen ("10000/matrix-10000.txt", "r");
    }
	else if (size == 20000)
    {
    	file = fopen ("20000/matrix-20000.txt", "r");
    }
    fscanf (file, "%d", &i);    
    while (!feof (file))
    {  
        G[counterX][counterY] = i;
        counterY++;
        if(counterY==size){
            counterX++;
            counterY=0;
        }
        fscanf (file, "%d", &i);      
    }
    fclose (file);

    // Store Node Data In Struct
    char raw_data[50];
    if(size==100)
    {
    	file = fopen ("100/nodecols-100.txt", "r");
    }
    else if (size == 1000)
    {
    	file = fopen ("1000/nodecols-1000.txt", "r");
    }
    else if (size == 3000)
    {
    	file = fopen ("3000/nodecols-3000.txt", "r");
    }
	else if (size == 4000)
    {
    	file = fopen ("4000/nodecols-4000.txt", "r");
    }
	else if (size == 10000)
    {
    	file = fopen ("10000/nodecols-10000.txt", "r");
    }
	else if (size == 20000)
    {
    	file = fopen ("20000/nodecols-20000.txt", "r");
    } 	
    counterX=0;
    fscanf(file, "%s %s %s %s", &raw_data,&raw_data,&raw_data,&raw_data);
    while (!feof (file))
    { 
        fscanf(file, "%d %s %f %f", &Nodes[counterX].Id, &Nodes[counterX].CityName, &Nodes[counterX].Population, &Nodes[counterX].Elevation);
 	counterX++;
    }
    fclose(file);
    begin = clock();

    fputs(" ", fileWriter);

    solveForDFS(startingNode-1);

   fclose(fileWriter);
    end = clock();
    double time_spend = (double)(end-begin);
    printf("\nTotal Execution Time : %lf \n",time_spend);
    return 0;
}
void solveForDFS(int Node) 
{
    printFinalOutput(Node+1);
    visited[Node] = 1;
    int k;
    for(k=0; k<size; k++)
    {
        if(G[Node][k] == 1 && visited[k] == 0)
        {
	  solveForDFS(k);
        }
    }
}

void printFinalOutput(int Node)
{
	char pop[20], elev[20], node[20];
    sprintf(node, "%d", Node);
    sprintf(pop, "%f", Nodes[Node-1].Population);
    sprintf(elev, "%f", Nodes[Node-1].Elevation);
    char to_File[100];
    strcat(to_File, node);
    strcat(to_File, " ");
    strcat(to_File, Nodes[Node-1].CityName);
    strcat(to_File, " ");
    strcat(to_File, pop);
    strcat(to_File, " ");
    strcat(to_File, elev);
    strcat(to_File, " \n");
    fputs(to_File, fileWriter);
    );
}
