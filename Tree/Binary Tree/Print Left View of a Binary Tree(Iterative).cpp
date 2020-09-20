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
	struct node *left,*right;

	node(int val){
		data = val;
		left = right = NULL;
	}
};

void leftViewPrint(node* root){
	if(root == NULL){
		return;
	}

	queue< node* > Q;
	Q.push(root);

	while(!Q.empty()) {
		node* u = Q.front();
        int len = Q.size();
		for(int i=0 ; i<len ;i++){
            node* _front = Q.front();
            Q.pop();

            if(i==0){
                cout << _front->data << " ";
            }

            if(_front->left){
                Q.push(_front->left);
            }

            if(_front->right){
                Q.push(_front->right);
            }
		}

	}
    return;
}

int main()
{
    CIN
    ///cout << "Fi Amanillah" << endl;

    ///Iterative Method To Print Left View of a Binary Tree

    /// Input Tree
	struct node *root = new node(10);
	root->left = new node(12);
	root->right = new node(3);
    root->left->right = new  node(4);
	root->right->left = new node(5);
	root->right->left->right = new node(6);
	root->right->left->right->left = new node(18);
	root->right->left->right->right = new node(17);

	leftViewPrint(root);

    return 0;
}