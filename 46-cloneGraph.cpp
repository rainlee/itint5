// 法1：DFS + map
// 先复制点，后复制边
// 若一个点已经在map中存在，则必然点和边都已经复制，直接返回
GraphNode *dfs(GraphNode *node, unordered_map<GraphNode *, GraphNode *> &mvisited)
{
    if (!node) return NULL;
    
    if (mvisited.find(node) != mvisited.end())
        return mvisited[node];
    
    GraphNode *newnode = new GraphNode(node->data);
    mvisited[node] = newnode;
    for (int i = 0; i < node->neighbors.size(); ++i)
        newnode->neighbors.push_back(dfs(node->neighbors[i], mvisited));
    
    return newnode;
}

GraphNode *cloneGraph_1(GraphNode *node) {
    unordered_map<GraphNode *, GraphNode *> mvisited;
    return dfs(node, mvisited);
}

// 法2：BFS + map
// 入队时复制点，出队时复制边
GraphNode *bfs(GraphNode *node)
{
    if (!node) return NULL;
    
    unordered_map<GraphNode *, GraphNode *> mvisited;
    queue<GraphNode *> q;
    
    mvisited[node] = new GraphNode(node->data);
    q.push(node);
    while (!q.empty())
    {
        GraphNode *cur = q.front(); q.pop();
        GraphNode *newcur = mvisited[cur];
        if (!newcur->neighbors.empty())
            continue;
        
        GraphNode *ngh = NULL;
        for (int i = 0; i < cur->neighbors.size(); ++i)
        {
            if (mvisited.find(cur->neighbors[i]) != mvisited.end())
                ngh = mvisited[cur->neighbors[i]];
            else
            {
                ngh = new GraphNode(cur->neighbors[i]->data);
                mvisited[cur->neighbors[i]] = ngh;
            }
            newcur->neighbors.push_back(ngh);
            q.push(cur->neighbors[i]);
        }
    }
    return mvisited[node];
}

GraphNode *cloneGraph(GraphNode *node) {
    //return cloneGraph_1(node);
    return bfs(node);
}