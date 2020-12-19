#include<bits/stdc++.h>

using namespace std;

struct TreeNode
 {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 struct TreeNode* insert(struct TreeNode* root,int data)
 	{
 		if (root == NULL)
 		{
 			struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
 			root->val = data;
 			root->left = NULL;
 			root->right = NULL;
 			return root;
 		}

 		else if(data>root->val)
 			root->right = insert(root->right,data);
 		else if(data<root->val)
 			root->left = insert(root->left,data);

 		return root;


 	};


    bool symmetric(TreeNode* root1,TreeNode* root2)
    {
        if(!root1 || !root2)
        {
            return root1 == root2;
        }
        if(root1->val != root2->val)
        {
            return false;
        }
        
        return symmetric(root1->left,root2->right) && symmetric(root1->right,root2->left);
        
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
        {
            return true;
        }
        
        return symmetric(root->left,root->right);
    }
    


 bool isValidBST(TreeNode* root,TreeNode* l = NULL,TreeNode* r = NULL)
    {
        if(root == NULL)
            return true;
        if(l!=NULL && l->val >= root->val)
            return false;
        if(r!=NULL && r->val <= root->val)
            return false;

        return isValidBST(root->left,l,root) && isValidBST(root->right,root,r);

    }

TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(root == NULL || root->val == val)
        {
            return root;
        }
        
        if(val < root->val)
            return searchBST(root->left,val);
        else
            return searchBST(root->right,val);  
    }

vector<int> preorderTraversal1(TreeNode* root) 
    {
        std::vector<int> arr;
        std::stack<TreeNode*> node;

        while(1)
        {
            while(root!=NULL)
            {
                arr.push_back(root->val);
                node.push(root);
                root = root->left;
            }

            if(node.empty())
                break;
            root = node.top();
            node.pop();
            root = root->right;
        }
        
       return arr;
  	}

vector<int> preorderTraversal2(TreeNode* root)
    {
    	std::vector<int> arr;
        if(root == NULL)
            return arr;

        std::stack<TreeNode*> node;
        node.push(root);
            while(!node.empty())
            {
                TreeNode* current = node.top();
                arr.push_back(current->val);
                node.pop();

                if(current->right!=NULL)
                    node.push(current->right);

                if(current->left!=NULL)
                    node.push(current->left);
            }
        return arr;
    }


vector<int> inorderTraversal_1(TreeNode* root)
    {
        std::vector<int> arr;
        std::stack<TreeNode*> node;

        while(1)
        {
            while(root)
            {
                node.push(root);
                root = root->left;
            }
            if(node.empty())
                break;
            root = node.top();
            node.pop();
            arr.push_back(root->val);

            root = root->right;
        }

        return arr;
    }


vector<int> inorderTraversal_2(TreeNode* root)
    {
        std::vector<int> arr;
        std::stack<TreeNode*> node;

       TreeNode* current = root;
        while(!node.empty() || current!=NULL)
        {
            if(current!=NULL)
            {
                node.push(current);
                current = current->left;
            }
            else
            {
                current = node.top();
                node.pop();
                arr.push_back(current->val);

                current = current->right;
            }
        }

        return arr;
    }

vector<int> postorderTraversal_1(TreeNode* root)
    {
        std::vector<int> arr;
        std::stack<TreeNode*> Node;

        if(root == NULL)
            return arr;

        Node.push(root);
        TreeNode* prev = NULL;
        while(!Node.empty())
        {
            TreeNode* current = Node.top();

            if(!prev || prev->left == current || prev->right == current)
            {
                if(current->left)
                    Node.push(current->left);
                else if(current->right)
                    Node.push(current->right);
            }
            else if(current->left == prev)
            {
                if(current->right)
                    Node.push(current->right);
            }
            else
            {
                arr.push_back(current->val);
                Node.pop();
            }

            prev = current;
        }

        return arr;
    }


vector<vector<int>> levelOrder(TreeNode* root)
    {
        std::queue<TreeNode*> Q;
        std::vector<int> arr;
        std::vector<std::vector<int>> V;
        if(root == NULL)
            return V;

        Q.push(root);

        while(!Q.empty())
        {
            std::vector<int> arr;
            int size = Q.size();

            for(int  i = 0; i < size; i++)
            {
                TreeNode* temp;
                temp = Q.front();
                Q.pop();

                arr.push_back(temp->val);

                if(temp->left)
                    Q.push(temp->left);
                if(temp->right)
                    Q.push(temp->right);
            }

            if(arr.size())
                V.push_back(arr);
        }

        return V;

    }


 int maxDepth(TreeNode* root)
    {
        int lh,rh;

        if(root == NULL)
            return 0;

        lh = maxDepth(root->left);
        rh = maxDepth(root->right);

        return 1+max(lh,rh);
    }


 vector<double> averageOfLevels(TreeNode* root)
    {
        std::queue<TreeNode*> Q;
        std::vector<double> V;
        if(root == NULL)
            return V;

        Q.push(root);

        while(!Q.empty())
        {
            double sum = 0;
            double avg = 0;
            int size = Q.size();

            for(int  i = 0; i < size; i++)
            {
                TreeNode* temp;
                temp = Q.front();
                Q.pop();

                sum = sum + temp->val;

                if(temp->left)
                    Q.push(temp->left);
                if(temp->right)
                    Q.push(temp->right);
            }
                avg = (double) sum/size;
                V.push_back(avg);
        }

        return V;
    }


int main(int argc, char const *argv[])
{
	TreeNode* root = NULL;

	int in;
	while(1)
	{
		cout<<"ENTER THE NODE"<<endl;
		cin>>in;
		if(in==0)
			break;
		root = insert(root,in);
	}

	bool res = isValidBST(root);

	cout<<res<<endl;

	std::vector<int> v;
	v = preorderTraversal1(root);
	int i=0;
	while(i!=v.size())
	{
		cout<<v[i]<<" ";
		i++;
	}
	cout<<endl;

}
