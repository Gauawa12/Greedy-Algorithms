double fractionalKnapsack(int W, Item arr[], int n)
{
    priority_queue<pair<double,pair<int,int>>>pq;

    for(int i=0;i<n;i++)
    {
    	double a=(double)(arr[i].value)/(arr[i].weight);//very Important conversion
    	int q=arr[i].value;
    	
    	int w=arr[i].weight;
    
    	pq.push(make_pair(a,make_pair(q,w)));
    
    }

    double totval=0;
   
    while(W>0 && !pq.empty())
    {
    	auto t=pq.top();
    	pq.pop();
    	double conv=t.first;
    	//cout<<"conv "<<conv;
    	int x=t.second.first;
    	int y=t.second.second;
    	if(y>=W)
    	{       double d=conv*(double)W;
    			totval=totval+d;
    	
    		W=0;
    	}
    	else
    	{
    		totval=totval+(double)(conv*(double)y);
    	
    		W=W-y;
    	}


    }

    
    return totval;

}
