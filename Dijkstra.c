void Dijkstra(struct Graph *G,int s)
{
	struct PriorityQueue *PQ = CreatePriorityQueue();
	int v,w;
	EnQueue(PQ,s);
	for(int i=0;i<G->V;i++)
	{
		Distance[i] = -1;
	}
	Distance[s] = 0;
	while(!EmptyQueue(PQ))
	{
		v = DeleteMin(PQ);
		for(
