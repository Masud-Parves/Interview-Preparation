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

int inOrder[200], postOrder[200];

struct node {
	int data;
	struct node *left,*right;
	node(int val){
	    data = val;
        left = right = NULL;
	}
};

void PreOrderTree(node* root){
	if(root == NULL) return;

	cout << root->data << " ";
	PreOrderTree(root->left);
	PreOrderTree(root->right);
}

int searchIdx(int st, int en, int val){
	for(int i=st ; i<=en ; i++){
		if(inOrder[i]==val){
			return i;
		}
	}
	return -1;
}

node* buildTree(int st, int en, int* pIdx){
	if(st>en) return NULL;


	node* newOne = new node(postOrder[*pIdx]);
    (*pIdx)--;

	if(st==en) return newOne;

    int idx = searchIdx(st, en, newOne->data);

	newOne->right = buildTree(idx+1, en, pIdx);
	newOne->left = buildTree(st, idx-1, pIdx);
	return newOne;
}

void solve(){

    int n;
    cout << "Number of nodes : " << endl;
    cin >> n;
    cout << "In-Order Sequence : " << endl;
    for(int i=0 ; i<n; i++) {
        cin >> inOrder[i];
    }

    cout << "Post-Order Sequence : " << endl;
    for(int i=0 ; i<n ; i++){
        cin >> postOrder[i];
    }
	int last = n-1;
	node * root = buildTree(0, n-1, &(last));

	cout << "Pre-Order Nodes : " << endl;
	PreOrderTree(root);

    return;
}

int main()
{
    CIN

    ///cout << "Fi Amanillah" << endl;

    int t = 1;
    //cin >> t;
    while(t--){
        /// C++ program to construct tree using inorder and postorder traversals.
        /// Complexity : Time :O(n^2) because we need to fine inorder position of every root node. Space : O(n), recursion : O(logn) for stuck memory
        /// Input :
        /*  8
            4 8 2 5 1 6 3 7
            8 4 5 2 6 7 3 1
        */
        solve();
    }

    return 0;
}
