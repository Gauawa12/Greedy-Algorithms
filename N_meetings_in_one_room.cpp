
void maxMeetings(int s[], int e[], int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
    map<pair<int,int>,int>m;
    for(int i=0;i<n;i++)
    {
        pq.push(make_pair(e[i],s[i]));
        m[make_pair(e[i],s[i])]=i+1;
    }
    int count;
    vector<pair<int,int>>v;
    while(!pq.empty())
    {   count=0;
        auto t=pq.top();
        pq.pop();
        
        int a=t.first;
        int b=t.second;
        if(!pq.empty())
        {
            auto x=pq.top();
            int c=x.first;
            int d=x.second;
            if(d<a)
            {
                pq.pop();
                pq.push(make_pair(a,b));
            }
            else
            {
                v.push_back(make_pair(a,b));
            }
        }
        else
        {
            v.push_back(make_pair(a,b));
        }
    }
    
    for(auto x:v)
    {
        cout<<m[make_pair(x.first,x.second)]<<" ";
    }
}

