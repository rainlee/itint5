// ��������
// ά��һ�����Ϊ0�Ķ���ļ��ϣ�
// ÿ�δӸü�����ȡ��(û�������ȡ���������ȡ��Ҳ�У�ʹ�ö���/ջҲ�У���ͬ)һ�����㣬���ö�����뱣������List�С�
// ������ѭ�������ɸö������������бߣ���ͼ���Ƴ������ߣ�ͬʱ��ȡ�ñߵ�����һ�����㣬����ö��������ڼ�ȥ������֮��Ϊ0����ôҲ���������ŵ����Ϊ0�ļ����С�
// Ȼ������Ӽ�����ȡ��һ�����㡭������
// ������Ϊ��֮�󣬼��ͼ���Ƿ񻹴����καߣ�������ڵĻ���˵��ͼ�����ٴ���һ����·�������ڵĻ��򷵻ؽ��List����List�е�˳����Ƕ�ͼ������������Ľ����

typedef int JobID;

/*
 * deps[id]��ʾ����id������������
 * ������ںϷ�������������У�����true�����򷵻�false
 * �Ϸ����������������ڲ���result�У��Ѿ�����ռ䣬����Ҫpush_back��
 */
bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n,
                                  vector<JobID> &result) {
    map<JobID, vector<JobID> > mgraph;  // ���� - ��
    vector<int> edges(n+1, 0);   // ����δ����ı��������
    queue<JobID> q;              // ���Ϊ0�ļ���
    
    for (map<JobID, vector<JobID> >::const_iterator it = deps.begin(); it != deps.end(); ++it)
    {
        JobID id = it->first;
        const vector<JobID> &jobs = it->second;
        
        const int n = jobs.size();
        edges[id] = n;     // ���
        
        for (int i = 0; i < n; ++i)
            mgraph[jobs[i]].push_back(id);  // �����
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
        
        vector<JobID> &jobs = mgraph[id];   // �Ƴ���
        for (int i = 0; i < jobs.size(); ++i)
        {
            --edges[jobs[i]];
            if (0 == edges[jobs[i]])  // ���Ϊ0 ���
                q.push(jobs[i]);
        }
    }
    return cnt == n;
}