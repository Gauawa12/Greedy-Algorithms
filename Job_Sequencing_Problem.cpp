Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete
and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is
to find the maximum profit and the number of jobs done.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of an integer N in first
line denoting the number of jobs and the next line consist of Job id, Deadline and the Profit associated to that Job.

Output:
Output the number of jobs done and the maximum profit.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Deadline <= 100
1 <= Profit <= 500

Example:
Input:
2
4
1 4 20 2 1 10 3 1 40 4 1 30
5
1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

Output:
2 60
2 127

Explanation:
Testcase 1: 2 jobs can be done with maximum profit of 60.

/*
struct Job{
int id;
int dead;
int profit;
}
*/
    

Solution : 

struct mysort{
    bool operator()(pair<int,int>&a,pair<int,int>&b)
{
    return (a.first>b.first);
}
};


void printJobScheduling(Job arr[], int n) 
{ 
    vector<pair<int,int>>v;
    int mxdl=-1;
    for(int i=0;i<n;i++)
    {
        v.push_back(make_pair(arr[i].profit,arr[i].dead));
        if(arr[i].dead>mxdl)
        {
            mxdl=arr[i].dead;
        }
    }
    
    sort(v.begin(),v.end(),mysort());
    int dl=1;
    int c=0,totval=0;mxdl++;
    vector<bool>allot(mxdl,true);
    
    for(int j=0;j<v.size();j++)
    {
        int t=v[j].second;
       
        for(int i=t;i>0;i--)
        {
            if(allot[i])
            {   
                allot[i]=false;
                c++;
                totval+=v[j].first;
                break;
            }
        }
    }
    cout<<c<<" "<<totval<<endl;
} 

