// Problem: Implement Stack using Queue
// Link: https://leetcode.com/problems/implement-stack-using-queues/description/
// Difficulty: Easy
// Topic: Stacks and Queues

class MyStack
{
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int frontElem = q.front();
        q.pop();
        return frontElem;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */