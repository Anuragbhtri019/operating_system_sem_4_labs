 #include <stdio.h>
int main()
{
	int incomingStream[] = { 3, 1, 4, 1, 6, 5, 1, 3};
	int pageFaults = 0;
	int frames = 3;
	int m, n, s, pages;
	pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
	printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");
	int temp[frames];
	for(m = 0; m < frames; m++)
	{
    	temp[m] = -1;
	}
   for(m = 0; m < pages; m++)
	{
    	s = 0;
    	for(n = 0; n < frames; n++)
    	{
        	if(incomingStream[m] == temp[n])
        	{
            	s++;
            	pageFaults--;
            	break;
        	}
    	}
    	pageFaults++;
   	if((pageFaults <= frames) && (s == 0))
    	{
        	temp[pageFaults - 1] = incomingStream[m];
    	}
    	else if(s == 0)
    	{
        	temp[(pageFaults - 1) % frames] = incomingStream[m];
    	}
    	printf("%d\t\t", incomingStream[m]);
    	for(n = 0; n < frames; n++)
    	{
        	if(temp[n] != -1)
            	printf("%d\t", temp[n]);
        	else
            	printf("-\t");
    	}
    	printf("\n");
	}
	printf("\nTotal Page Faults:\t%d\n", pageFaults);
	return 0;
}
