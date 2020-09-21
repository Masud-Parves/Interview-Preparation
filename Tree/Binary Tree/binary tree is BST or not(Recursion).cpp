#include<bits/stdc++.h>

using namespace std;

/*

        Bismillahir Rahmanir Rahim
        Problem :
        Problem Link :
        Topics :
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/

#define ff first
#define ss second
#define mp make_pair
#define SZ(a)           (int)a.size()
#define all(a)  a.begin(), a.end()
#define allr(a)  a.rbegin(), a.rend()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define TEST_CASE(t) for(int zz=1 ; zz<=t ; zz++)
#define PRINT_CASE printf("Case %d: ",zz)
#define endl            "\n"
#define Debug(x)            cout<<#x " = "<<(x)<<endl
#define NOT_VISITED 0
#define IS_VISITED 1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N  (1<<pos);}
//int Reset(int N,int pos){return N= N & ~(1<<pos);}
//bool Check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)3e5+5;


typedef long long ll;
const ll inf = 5e18+100;
typedef unsigned long long ull;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef vector<int> vi;

struct node{
	int data;
	struct node *left, *right;
	node(int val){
		data = val;
		left = right = NULL;
	}
};

node* INSERT(node *root, int value){
	if(root == NULL){
		return new node(value);
	}

	if(value <= root->data) {
		root->left = INSERT(root->left, value);
	} else {
		root->right = INSERT(root->right, value);
	}

	return root;
}


bool isBST(node* root, int minkey, int maxkey){
	if(root == NULL) {
		return true;
	}

	if(root->data<minkey || root->data>maxkey){
		return false;
	}

	return isBST(root->left, minkey, root->data) && isBST(root->right, root->data, maxkey);
}

int main()
{
    CIN

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ///cout << "Fi Amanillah" << endl;

    int nodes;
    cin >> nodes;

    struct node* root = NULL;
    for(int i=0 ; i<nodes ; i++){
    	int key;
    	cin >> key;
    	root = INSERT(root, key);
    }

    swap(root->left, root->right); /// to test not BST case

    if(isBST(root, INT_MIN, INT_MAX)){
    	cout << "The Tree is BST" << endl;
    } else {
    	cout << "The Tree is not BST" << endl;
    }

    return 0;
}