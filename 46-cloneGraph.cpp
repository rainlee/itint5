// ��1��DFS + map
// �ȸ��Ƶ㣬���Ʊ�
// ��һ�����Ѿ���map�д��ڣ����Ȼ��ͱ߶��Ѿ����ƣ�ֱ�ӷ���
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

// ��2��BFS + map
// ���ʱ���Ƶ㣬����ʱ���Ʊ�
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