// 拓扑排序
// 维护一个入度为0的顶点的集合：
// 每次从该集合中取出(没有特殊的取出规则，随机取出也行，使用队列/栈也行，下同)一个顶点，将该顶点放入保存结果的List中。
// 紧接着循环遍历由该顶点引出的所有边，从图中移除这条边，同时获取该边的另外一个顶点，如果该顶点的入度在减去本条边之后为0，那么也将这个顶点放到入度为0的集合中。
// 然后继续从集合中取出一个顶点…………
// 当集合为空之后，检查图中是否还存在任何边，如果存在的话，说明图中至少存在一条环路。不存在的话则返回结果List，此List中的顺序就是对图进行拓扑排序的结果。

typedef int JobID;

/*
 * deps[id]表示任务id所依赖的任务
 * 如果存在合法的任务完成序列，返回true，否则返回false
 * 合法的任务序列请存放在参数result中（已经分配空间，不需要push_back）
 */
bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n,
                                  vector<JobID> &result) {
    map<JobID, vector<JobID> > mgraph;  // 顶点 - 边
    vector<int> edges(n+1, 0);   // 顶点未处理的边数，入度
    queue<JobID> q;              // 入度为0的集合
    
    for (map<JobID, vector<JobID> >::const_iterator it = deps.begin(); it != deps.end(); ++it)
    {
        JobID id = it->first;
        const vector<JobID> &jobs = it->second;
        
        const int n = jobs.size();
        edges[id] = n;     // 入度
        
        for (int i = 0; i < n; ++i)
            mgraph[jobs[i]].push_back(id);  // 有向边
    }
    
    for (int i = 1; i <= n; ++i)
        if (0 == edges[i])
            q.push(i);
        
    int cnt = 0;
    while (!q.empty())
    {
        JobID id = q.front();
        q.pop();
        
        //result.push_back(id);
        //++cnt;
        result[cnt++] = id;
        
        if (mgraph.find(id) == mgraph.end())
            continue;
        
        vector<JobID> &jobs = mgraph[id];   // 移除边
        for (int i = 0; i < jobs.size(); ++i)
        {
            --edges[jobs[i]];
            if (0 == edges[jobs[i]])  // 入度为0 入队
                q.push(jobs[i]);
        }
    }
    return cnt == n;
}