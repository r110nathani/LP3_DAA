#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int frequency;
    char c;
    Node * left;
    Node * right;

    Node()
    {
        frequency = -1;
        c = '~';
        left = right = NULL;
    }

    Node(int x)
    {
        frequency = x;
        c = '~';
        left = right = NULL;
    }

    Node(int x , char f)
    {
        frequency = x;
        c = f;
        left = right = NULL;
    }

    friend class Compress;
    friend class pqComp;
};

class pqComp
{
    public:
    bool operator()(Node const * a , Node const * b)
    {
        return a->frequency > b->frequency;
    }
};

class Compress
{
    unordered_map<char,int> frequency_map;
    unordered_map<char,string> huffcodes;
    string input = "";
    public:

    Node * ans_root;
    Compress()
    {
        ans_root = NULL;
        cout<<"Enter input"<<endl;
        getline(cin,input);
        countFrequency();
        create_tree();
    }

    void countFrequency()
    {
        for(auto it : input)
        {
            if(it != ' ')
            {
                frequency_map[it]++;
            }
        }
    }

    void create_tree()
    {
        priority_queue<Node*,vector<Node*>,pqComp>pq;
        for(auto it : frequency_map)
        {
            Node * node = new Node(it.second , it.first);
            pq.push(node);
        }

        while(pq.size()>=2)
        {
            Node * tmp1 = pq.top();
            pq.pop();
            Node * tmp2 = pq.top();
            pq.pop();
            Node * parentNode = new Node(tmp1->frequency + tmp2->frequency);
           
            parentNode->left = tmp1;
            parentNode->right = tmp2;
            
            pq.push(parentNode);
        }

        ans_root = pq.top();
    }

    void assignCodes(Node *root, string temp) {
        if (!root) return;

        if (root->left == NULL && root->right == NULL) {
            huffcodes[root->c] = temp;
            return;
        }

        assignCodes(root->left, temp + "0");
        assignCodes(root->right, temp + "1");
    }

    void printHuffTable(){
        cout<<"Hello"<<endl;
        for(auto it:huffcodes){
            
            cout<<it.first<<" "<<it.second<<" "<<endl;
        }
    }
};

int main()
{
    Compress c;
    Node * tmp = c.ans_root;
    string temp = "";
    c.assignCodes(tmp,temp);
    c.printHuffTable();
}

