vector<int> v,m;

MinStack::MinStack() {
    v.clear();
    m.clear();
}

void MinStack::push(int x) {
    v.push_back(x);
    if(m.size()==0)
        m.push_back(x);
    else
        {
            m.push_back(min(x,m[m.size()-1]));
        }
        
}

void MinStack::pop() {
    if(v.size())
    {
    v.pop_back();
    m.pop_back();
    }
}

int MinStack::top() {
    if(v.size()==0)
        return -1;
    else
        return v[v.size()-1];
}

int MinStack::getMin() {
    if(m.size()==0)
        return -1;
    else
        return m[m.size()-1];
}

