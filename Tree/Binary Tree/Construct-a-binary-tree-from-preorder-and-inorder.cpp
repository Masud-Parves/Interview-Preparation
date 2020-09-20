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
#define pb push_back
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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
int inOrder[200], preOrder[200];

struct node {
    int data;
    struct node *left, *right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};

void postOrderTree(node* root){
    if(root == NULL){
        return;
    }
    postOrderTree(root->left);
    postOrderTree(root->right);
    cout << root->data << " ";
}

int searchItem(int st, int en, int val){
    for(int i=st ; i<=en; i++){
        if(val == inOrder[i]){
            return i;
        }
    }
    return -1;
}



node* buildTree(int st, int en, int &pIdx){
    if(st>en) return NULL;

    node* newOne = new node(preOrder[pIdx++]);

    if(st==en) return newOne;

    int sIdx = searchItem(st, en, newOne->data);

    newOne->left = buildTree(st, sIdx-1, pIdx);
    newOne->right = buildTree(sIdx+1, en, pIdx);
    return newOne;
}

/*
    Input :
        8
        4 2 1 7 5 8 3 6
        1 2 4 3 5 7 8 6
    Output :
        4 2 7 8 5 6 3 1

    Time : O(n^2)
    It Can be reduced using map to search In-order Element's position.
*/

int main()
{
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cout << "Fi Amanillah" << endl;

    int n;
    cin >> n;

    /// take input inorder sequence;
    for(int i=0; i<n ; i++){
        cin >> inOrder[i];
    }

    /// take input preorder sequence;
    for(int i=0 ; i<n ; i++){
        cin >> preOrder[i];
    }
    int pIdx = 0;
    node *root = buildTree(0, n-1, pIdx);

    postOrderTree(root);

    return 0;
}
