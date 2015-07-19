#include<stdio.h>
#include<time.h>
#include <string.h>
#define MAX 20000

struct BFSProgram
{
    int Id;
    char CityName[50];
    float Population;
    float Elevation; 
};

struct BFSProgram Nodes[MAX];
int G[MAX][MAX], visited[MAX], size=MAX, queue[MAX],front=-1,rear=-1;
FILE * fileWriter;

int delete(); 
void add(int item); 
void solveForBFS(int Node); 
void printFinalOutput(int Node);

int main()
{
    fileWriter = fopen("output_BFS_C.txt", "w+");
    clock_t begin, end;
    int startingNode = 1; // by default the startingNode is 1
    printf("Enter Vertex Size : \n");
    scanf("%d",&size);
    printf("\n");
    int i = 0;
    for(i=0;i<size;i++)
    {
        visited[i] = 0;
    	queue[i] = 0;
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
    	file = fopen ("1000/matrix-100.txt", "r");
    }
    else if (size == 3000)
    {
    	file = fopen ("3000/matrix-100.txt", "r");
    }
	else if (size == 4000)
    {
    	file = fopen ("4000/matrix-100.txt", "r");
    }
	else if (size == 10000)
    {
    	file = fopen ("10000/matrix-100.txt", "r");
    }
	else if (size == 20000)
    {
    	file = fopen ("20000/matrix-100.txt", "r");
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
	startingNode = startingNode - 1;
    solveForBFS(startingNode);

    fclose(fileWriter);
    end = clock();
    double time_spend = (double)(end-begin);
    printf("\nTotal Execution Time : %lf \n",time_spend);
    return 0;
}


void solveForBFS(int Node) 
{ 
    int p,i; 
	add(Node); 
    visited[Node] = 1; 
	p=delete();
		if(p!=-1) 
		{
			printFinalOutput(p+1);
		}
	
	while(p!=-1) 
	{ 
		for(i=0;i<size;i++) 
		{
			if((G[p][i]!=0)&&(visited[i]==0)) 
			{ 
				add(i); 
				visited[i]=1; 
			} 
		}
		p=delete(); 
		if(p!=-1) 
		{
			printFinalOutput(p+1);
		}
	}
	for(i=0;i<size;i++) {
		if(visited[i]==0) 
		{
			solveForBFS(i);	
		} 
	}
}

void add(int item) 
{ 
    if(rear==size-1) 
        printf("No Space in Queue");
    else 
    { 
        if(rear==-1) 
        { 
            queue[++rear]=item; 
            front++; 
        } 
        else 
            queue[++rear]=item; 
    } 
} 

int delete() 
{ 
    int i;
    if((front>rear)||(front==-1)) 
        return(-1); 
    else 
    { 
        i=queue[front++];
        return(i);
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
