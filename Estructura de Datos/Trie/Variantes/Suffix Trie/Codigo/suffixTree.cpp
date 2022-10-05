// Include header file
#include <iostream>
#include <string>
#include <vector>
// C++ program for
// Suffix tree implementation
using namespace std;
class TreeNode
{
    public: string sub;
    vector < int > child; 
    TreeNode()
    {
        this->sub = "";
    }
};
class SuffixTree
{
    public: 
    vector < TreeNode *> nodes;
    SuffixTree(string data)
    {
    
        this->nodes.push_back(new TreeNode());
        // Construct tree
        this->buildTree(data);
    }
    void addSuffix(string suf)
    {
        // Declare some useful auxiliary variables
        int n = 0;
        int i = 0;
        int x2 = 0;
        int n2 = 0;
        int n3 = 0;
        int j = 0;
        TreeNode *temp = NULL;
        bool process = true;
        string sub2 = "";
        while (i < suf.length())
        {
            char b = suf[i];

          
            while (process)
            {

                if (x2 == this->nodes[n]->child.size())
                {
                    n2 = this->nodes.size();
                    temp = new TreeNode();
                    temp->sub = suf.substr(i);
                    

                    this->nodes.push_back(temp);
                    this->nodes[n]->child.push_back(n2);
                    return;
                }
                n2 = this->nodes[n]->child.at(x2);
                if (this->nodes.at(n2)->sub[0] == b)
                {
                    process = false;
                }
                else
                {
                    x2++;
                }
            }
            sub2 = this->nodes.at(n2)->sub;
            process = true;
            while (j < sub2.length() && (i + j) < 
                   suf.length() && process == true)
            {
                if (suf[i + j] != sub2[j])
                {
                    n3 = n2;
                    n2 = this->nodes.size();
                    temp = new TreeNode();
                    temp->sub = sub2.substr(0, j);
                    temp->child.push_back(n3);
                    this->nodes.push_back(temp);
                    this->nodes.at(n3)->sub = sub2.substr(j);
                    this->nodes.at(n)->child.at(x2) = n2;
                    process = false;
                }
                else
                {
                    j++;
                }
            }
            i += j;
            n = n2;
            // Reset value
            x2 = 0;
            n2 = 0;
            n3 = 0;
            j = 0;
            temp = NULL;
            process = true;
            sub2 = "";

        }
    }
    void buildTree(string str)
    {
        for (int i = 0; i < str.length(); ++i)
        {
            this->addSuffix(str.substr(i));
        }
    }
    void printData(int n, string prefix)
    {
        vector < int > children = this->nodes[n]->child;;
        if (children.empty())
        {
            cout << "⤑ " << this->nodes.at(n)->sub << endl;
            return;
        }
        cout << "┐ " << this->nodes.at(n)->sub << endl;
        for (int i = 0; i < children.size() - 1; i++)
        {
            int c = children.at(i);
            cout << prefix << "├─";
            this->printData(c, prefix  +  "│ ");
        }
        cout << prefix << "└─";
        this->printData(children.at(
          children.size() - 1
        ), prefix  +  "  ");
    }
    void visualize()
    {
        if (this->nodes.empty())
        {
            cout << "\nEmpty Tree";
            return;
        }
        this->printData(0, "");
    }
};
int main()

    SuffixTree *tree1 = new SuffixTree("abbcba");
    tree1->visualize();
    return 0;
}
