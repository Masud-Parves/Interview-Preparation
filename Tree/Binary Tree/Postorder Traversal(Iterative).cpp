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
	node (int val){
		data = val;
		left = right = NULL;
	}
};

void Postorder_Traversal(struct node *root){
	stack < struct node* > s1, s2;

	s1.push(root);

	while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        auto poped_node = s1.top();
        s1.pop();
        s2.push(poped_node);

        // Push left and right children
        // of removed item to s1
        if (poped_node->left)
            s1.push(poped_node->left);
        if (poped_node->right)
            s1.push(poped_node->right);
    }

	while(!s2.empty()){
        auto t = s2.top();
		cout << t->data << " ";
		s2.pop();
	}
}

void solve(){
	
	/// Input Tree
	struct node *root = new node(10);
	root->left = new node(8);
	root->right = new node(2);
	root->left->left =new  node(3);
	root->left->right = new node(5);
	root->right->left = new node(6);

	cout << "Inorder Traversal : " << endl;
	Postorder_Traversal(root);
	cout << "\n";

    return;
}

int main()
{
    CIN
    //cout << "Fi Amanillah" << endl;

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
