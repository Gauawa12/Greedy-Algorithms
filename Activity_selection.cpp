int activitySelection(int s[], int e[], int n){
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   for(int i=0;i<n;i++)
   {
       pq.push(make_pair(e[i],s[i]));
   }
   int count=0;
   while(!pq.empty())
   {
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
               count++;
           }
       }
       else
       {
           count++;
       }
   }
   return count;
}

// s&e denote starting and ending times
