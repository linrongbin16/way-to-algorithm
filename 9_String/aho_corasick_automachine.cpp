#include<iostream>
#include<string.h>
#include<malloc.h>
#include <queue>
#include <stdio.h>
#include <time.h>
using namespace std;


//#define UNFAIL 3
/* reallocation step for AC_NODE_t.outgoing array */
#define REALLOC_CHUNK_OUTGOING 2

struct ac_edge;

typedef struct node
{
    unsigned int 		id;         		/* Node ID : just for debugging purpose */
    unsigned short 		depth; 				/* depth: distance between this node and the root */

    struct node 		*parent;      		/*parent node, for compute failure function*/
    struct node 		*failure_node;    	/* The failure node of this node */

    short int 			final;         		/* 0: no ; 1: yes, it is a final node */
    int 				patternNo;     		/*Accept pattern index: just for debugging purpose */

    /* Outgoing Edges */
    struct ac_edge		*outgoing_edge;		/* Array of outgoing character edges */
    unsigned short 		outgoing_num;  		/* Number of outgoing character edges */
    unsigned short 		outgoing_max;  		/* Max capacity of allocated memory for outgoing character edges */
} AC_NODE_t;

/* The Ougoing Edge of the Node */
struct ac_edge
{
    char alpha; /* Edge alpha */
    AC_NODE_t * next; /* Target of the edge */
};


static void node_assign_id (AC_NODE_t * thiz);
static AC_NODE_t * node_find_next(AC_NODE_t *pAc_node, char ch);


/******************************************************************************
 * Create node
******************************************************************************/
AC_NODE_t *node_create()
{
    AC_NODE_t* pNode = (AC_NODE_t*)malloc(sizeof(AC_NODE_t));

    memset(pNode, 0, sizeof(AC_NODE_t));

    pNode->failure_node 	= NULL;
    pNode->parent 			= NULL;
    pNode->final 			= 0;

    /*init outgoing character edges*/
    pNode->outgoing_max 	= REALLOC_CHUNK_OUTGOING;
    pNode->outgoing_edge 	= (struct ac_edge *) malloc (pNode->outgoing_max*sizeof(struct ac_edge));

    node_assign_id(pNode);

    return pNode;
}

/******************************************************************************
 * assign a unique ID to the node (used for debugging purpose).
******************************************************************************/
static void node_assign_id (AC_NODE_t * thiz)
{
    static int unique_id = 0;
    thiz->id = unique_id ++;
}

/******************************************************************************
 * Establish an new edge between two nodes
******************************************************************************/
void node_add_outgoing (AC_NODE_t * thiz, AC_NODE_t * next, char alpha)
{
    if(thiz->outgoing_num >= thiz->outgoing_max)
    {
        thiz->outgoing_max += REALLOC_CHUNK_OUTGOING;
        thiz->outgoing_edge = (struct ac_edge *)realloc(thiz->outgoing_edge, thiz->outgoing_max*sizeof(struct ac_edge));
    }

    thiz->outgoing_edge[thiz->outgoing_num].alpha = alpha;
    thiz->outgoing_edge[thiz->outgoing_num++].next = next;
}

/******************************************************************************
 * Create a next node with the given alpha.
******************************************************************************/
AC_NODE_t * node_create_next (AC_NODE_t * pCur_node, char alpha)
{
    AC_NODE_t * pNext_node = NULL;
    pNext_node = node_find_next (pCur_node, alpha);

    if (pNext_node)
    {
        /* The (labeled alpha) edge already exists */
        return NULL;
    }

    /* Otherwise add new edge (node) */
    pNext_node = node_create ();
    node_add_outgoing(pCur_node, pNext_node, alpha);

    return pNext_node;
}

/******************************************************************************
 * Find out the next node for a given Alpha to move. this function is used in
 * the pre-processing stage in which edge array is not sorted. so it uses linear search.
******************************************************************************/
static AC_NODE_t * node_find_next(AC_NODE_t * pAc_node, char ch)
{
    int i = 0;

    if(NULL == pAc_node)
    {
        return NULL;
    }

    for (i=0; i < pAc_node->outgoing_num; i++)
    {
        if(pAc_node->outgoing_edge[i].alpha == ch)
            return (pAc_node->outgoing_edge[i].next);
    }

    return NULL;
}

/******************************************************************************
* add parent node's all leaf node(outgoing node) into queue
******************************************************************************/
int  queue_add_leaf_node(AC_NODE_t *parent, queue<AC_NODE_t*> &myqueue)
{
    int i;

    for (i = 0; i < parent->outgoing_num; i++)
    {
        myqueue.push (parent->outgoing_edge[i].next);
    }

    return 0;
}

/******************************************************************************
 * Initialize automata; allocate memories and add patterns into automata
 * pattern**  :	pointers to pattern string
 * pattern_num: number of pattern
******************************************************************************/
AC_NODE_t * ac_automata_create(char pattern[][255], int patterns_num)
{
    int iPattern_index, iChar_index;
    AC_NODE_t *root = node_create();/*创建新节点*/
    AC_NODE_t *pCur_node = NULL, *pNext_node = NULL;
    char alpha;

    for(iPattern_index=0; iPattern_index<patterns_num; iPattern_index++)
    {
        pCur_node = root;
        for(iChar_index=0; iChar_index<strlen(pattern[iPattern_index]); iChar_index++)
		{
            alpha = pattern[iPattern_index][iChar_index];
            pNext_node = node_find_next(pCur_node, alpha);
            if(NULL != pNext_node)
            {
                pCur_node = pNext_node;
            }
            else
            {
                pNext_node = node_create_next(pCur_node, alpha);
                if(NULL != pNext_node)
                {
                    pNext_node->parent = pCur_node;
                    pNext_node->depth = pCur_node->depth + 1;

                    pCur_node = pNext_node;
                }
            }
        }

        pCur_node->final = 1;
        pCur_node->patternNo = iPattern_index;
    }

    return root;
}

void ac_insert(AC_NODE_t * pCur_node,AC_NODE_t * parent, AC_NODE_t * root,char edge_ch)
{
	AC_NODE_t *pNext_Node;
	int i = 0;
	for (i = 0; i < parent->outgoing_num; i++)
	{
		if (edge_ch == parent->outgoing_edge[i].alpha)
			break;
	}
	if (i<parent->outgoing_num)
	{
		pCur_node->failure_node = parent->outgoing_edge[i].next;
		return;
	}
	pNext_Node = node_find_next(parent->failure_node, edge_ch);
	if (NULL == pNext_Node)
	{
		if (parent->failure_node == root)
		{
			pCur_node->failure_node = root;
			return;
		}
		else
		{
			parent = parent->failure_node;
			ac_insert(pCur_node,parent,root,edge_ch);
			return;
		}
	}
	else
	{
		pCur_node->failure_node = pNext_Node;
		return;
	}
}

/******************************************************************************
 * find failure node for all node, actually failure function maps a state into a new state.
 * the failure function is consulted whenever the goto function reports fail;
 * specificialy compute the failue node, we use it's parent node's failure node
******************************************************************************/
int ac_automata_setfailure(AC_NODE_t * root)
{
    int i =0;
    queue<AC_NODE_t*> myqueue;

    char edge_ch = '\0';
    AC_NODE_t *pCur_node = NULL, *parent = NULL, *pNext_Node = NULL;

    for(i= 0; i< root->outgoing_num; i++) //f(s) = 0 for all states s of depth 1
    {
        root->outgoing_edge[i].next->failure_node = root;
    }
	root->failure_node = root;
    queue_add_leaf_node(root, myqueue);

    while(!myqueue.empty())
    {
        parent = myqueue.front();
        myqueue.pop();
        queue_add_leaf_node(parent, myqueue);
        for(i = 0; i < parent->outgoing_num; i++)
        {
			//if (!edge_ch)
				edge_ch = parent->outgoing_edge[i].alpha;

			//if(!pCur_node)
				pCur_node = parent->outgoing_edge[i].next;

            pNext_Node = node_find_next(parent->failure_node, edge_ch);
            if(NULL == pNext_Node)
            {
                if(parent->failure_node == root)
                {
                    pCur_node->failure_node = root;
					//parent = pCur_node->parent;
                }
                else
                {
					ac_insert(pCur_node, parent->failure_node,root,edge_ch);
                }
            }
            else
            {
                pCur_node->failure_node = pNext_Node;
            }
			if (pCur_node->failure_node->final)
			{
				pCur_node->final = pCur_node->failure_node->final;
				pCur_node->patternNo = pCur_node->failure_node->patternNo;
			}
			{
				//pCur_node = NULL;
				//edge_ch = 0;
			}
        }
    }

    return 0;
}

/******************************************************************************
 * Search in the input text using the given automata.
******************************************************************************/
int ac_automata_search(AC_NODE_t * root, char* text, int txt_len, char pattern[][255])
{
    AC_NODE_t *pCur_node = root;
    AC_NODE_t *pNext_node = NULL;
    int position = 0;

    while(position < txt_len)
    {
        pNext_node = node_find_next(pCur_node, text[position]);
        if (NULL == pNext_node)
        {
            if(pCur_node == root)
            {
                position++;
            }
            else
            {
                pCur_node = pCur_node->failure_node;
            }
        }
        else
        {
            pCur_node = pNext_node;
            position++;
        }

        if(pCur_node->final == 1)    ///some pattern matched
        {
            cout<<position-strlen(pattern[pCur_node->patternNo])<< '\t' << '\t' <<pCur_node->patternNo<< '\t' << '\t' <<pattern[pCur_node->patternNo]<<endl;
        }
    }

    return 0;
}

/******************************************************************************
 * Prints the automata to output in human readable form.
******************************************************************************/
void ac_automata_display (AC_NODE_t * root)
{
    unsigned int i;
    AC_NODE_t * pCur_node = root;
    struct ac_edge * pEdge = NULL;

    if(root == NULL)
    {
        return;
    }

    printf("---------------------------------\n");

    queue<AC_NODE_t*> myqueue;
    myqueue.push( pCur_node );

    while(!myqueue.empty())
    {
        pCur_node = myqueue.front();
        myqueue.pop();

        printf("NODE(%3d)/----fail----> NODE(%3d)\n", pCur_node->id, (pCur_node->failure_node)?pCur_node->failure_node->id:0);

        for (i = 0; i < pCur_node->outgoing_num; i++)
        {
            myqueue.push (pCur_node->outgoing_edge[i].next);

            pEdge = &pCur_node->outgoing_edge[i];
            printf("         |----(");
            if(isgraph(pEdge->alpha))
                printf("%c)---", pEdge->alpha);
            else
                printf("0x%x)", pEdge->alpha);
            printf("--> NODE(%3d)\n", pEdge->next->id);
        }
        printf("---------------------------------\n");
    }
}

/******************************************************************************
 * Release all allocated memories to the automata
******************************************************************************/
int ac_automata_release(AC_NODE_t * root)
{
    if(root == NULL)
    {
        return 0;
    }

    queue<AC_NODE_t*> myqueue;
    AC_NODE_t *pCur_node = NULL;

    myqueue.push( root );
    root = NULL;

    while(!myqueue.empty())
    {
        pCur_node = myqueue.front();
        myqueue.pop();

        for (int i = 0; i < pCur_node->outgoing_num; i++)
        {
            myqueue.push (pCur_node->outgoing_edge[i].next);
        }
        free(pCur_node);
    }

    return 0;
}

int main(int argc,char* argv[])
{
    clock_t start=clock();
    unsigned int i = 0;
    char haystack[] = /*"annual_announce"*//*"AGATACGATATATATATAC";
	/*char a[] =*/"fdhdsfnvdnsalefvds.daelvmds.dma;ewlvmvz.dsawemfdas.;wafejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;\
    kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlmsa.vmdlvelmcs./aewlmd.sseemf.\
    dsljf;wafkeqfdsddakf;wlefkjdfqw;egf;wkjf;ewfk;wegfejg;efj;daslew;qkfsad;wewlkfdsfdejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    d;flrekfas;dlflrekfas;dlwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flejg;efd;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'we\
    lfkd;fkasdl;wkfdsald;wgkfdslwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwjgw;qkfsad;wewlkfdsfdle;wwwwwwwkfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdAGATACGATATATATATACsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlmsa.vmdlvelmcs./aewlmd.sseemf.\
    dsljf;wafkeqfdsddakf;wlefkjdfqw;egf;wkjf;ewfk;wegfejg;efj;daslew;qkfsad;wewlkfdsfdejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    d;flrekfas;dlflrekfas;dlwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flejg;efd;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'we\
    lfkd;fkasdl;wkfdsald;wgkfdslwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwjgw;qkfsad;wewlkfdsfdle;wwwwwwwkfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlmsa.vmdlvelmcs./aewlmd.sseemf.\
    dsljf;wafkeqfdsddakf;wlefkjdfqw;egf;wkjf;ewfk;wegfejg;efj;daslew;qkfsad;wewlkfdsfdejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    d;flrekfas;dlflrekfas;dlwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flejg;efd;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'we\
    lfkd;fkasdl;wkfdsald;wgkfdslwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwjgw;qkfsad;wewlkfdsfdle;wwwwwwwkfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlmsa.vmdlvelmcs./aewlmd.sseemf.\
    dsljf;wafkeqfdsddakf;wlefkjdfqw;egf;wkjf;ewfk;wegfejg;efj;daslew;qkfsad;wewlkfdsfdejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    d;flrekfas;dlflrekfas;dlwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flejg;efd;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'we\
    lfkd;fkasdl;wkfdsald;wgkfdslwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwjgw;qkfsad;wewlkfdsfdle;wwwwwwwkfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlmsa.vmdlvelmcs./aewlmd.sseemf.\
    dsljf;wafkeqfdsddakf;wlefkjdfqw;egf;wkjf;ewfk;wegfejg;efj;daslew;qkfsad;wewlkfdsfdejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    d;flrekfas;dlflrekfas;dlwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flejg;efd;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'we\
    lfkd;fkasdl;wkfdsald;wgkfdslwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwjgw;qkfsad;wewlkfdsfdle;wwwwwwwkfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsa               d;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    d;flrekfas;dlflrekfas;dlwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flejg;efd;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'we\
    lfkd;fkasdl;wkfdsald;wgkfdslwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwjgw;qkfsad;wewlkfdsfdle;wwwwwwwkfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    d;flrekfas;dlflrekfas;dlwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flejg;efd;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'we\
    lfkd;fkasdl;wkfdsald;wgkfdslwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwjgw;qkfsad;wewlkfdsfdle;wwwwwwwkfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    d;flrekfas;dlflrekfas;dlwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flejg;efd;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'we\
    lfkd;fkasdl;wkfdsald;wgkfdslwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwjgw;qkfsad;wewlkfdsfdle;wwwwwwwkfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dl;kfd;wfela;kfeejg俄文;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsa法文ld;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfsdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfelsdl;wkfdsald;wgkfdsjgfdsafsdl;wkfdsald;wgkfdsjgfdsa\
    fkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkda;kfew;lfk;ewfk;leakf's\
    afe'kwpfkdlfkdas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;le英文akf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    d;flrekfas;dlflrekfas;dlwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flejg;efd;wew文盲lkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'we\
    lfkd;fkasdl;wkfdsald;wgkfdslwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwjgw;qkfsad;wewlkfdsfdle;wwwwwwwkfd;wfela;\
    kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkjaejg;efj;\
    daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;\
    leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dl;kfd;wfela;kfeejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;\
    fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;ejg;efj;daslew;qkfsad;wewlkfdsfdle;\
    wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    d;flrekfas;dlflrekfas;dlwejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;\
    wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flejg;efj;daslew;qkfsad;wewlkfdsfdle;wwwwwwwwwwww\
    wwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;\
    dlrekfas;dl;lfk;eejg;efj;daslew;qkfsad;wewlkfds中文fdle;wwwwwwwwwwwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafk\
    ja;kfd;wfela;kfew;lfk;ewfk;leahekf'safe'kwnewplankdsa;'d;flrfas;dlwfk;leakf'safe'kwpfkdlfkdsa;'d;flrekfas;dlle;wwwwwwwww\
    wwwwwdlfk;ewlfkdssf'welfkd;fkasdl;wkfdsald;wgkfdsjgfdsafkja;kfd;wfela;kfew;lfk;ewfk;leakf'safe'kwpfkdlfkdsa;'\
    d;flrekfas;dlfke;l;kwalksdkjgfldsajgas.dfefmdscmdlew;l;wafkma/elke/a;elkfelfas.mfdsvmdlkmclkadal;";
    
    //char needle[][255]= {"he","rekfas;dl", "出差","hers","kwnewplankdsa"};/*failure*/
    //char needle[][255]= {"he","wwwwwwwwwwww", "出差","mfdsv"};/*success*/
    char needle[][255]= {"la;kf","fk;ewfk;le","kfas;dl;k","eakf'safe'k","文盲","rekfas;dlf","俄文","英文","fdsald;wgk","he","中文","wwwwwwwwwwww","法文","afkja;kfd;wfe", "ela;kfew;lf","newplanewcy","mfdsv","newccyy","ATATATA","TATAT", "ACGATAT"};/*failure*/
	//char needle[][255] = { "ATATATA","TATAT", "ACGATAT"};
	//char needle[][255] = { "announce","annual", "annually" };
    /* 1. create ac finite state automata match machine, compute goto and output func*/
    AC_NODE_t *root = ac_automata_create(needle, sizeof(needle)/sizeof(needle[0]));

#if 0
	ac_automata_display(root);
#endif

    /* 2. compute failure function*/
#if 2
    ac_automata_setfailure( root );
#endif
    /* 3. Display automata (if you are interested)*/
#if 2
    ac_automata_display( root );
#endif

#if 1
    cout << endl << "haystack : " << haystack << endl;
    cout << "needles : ";
    for(i = 0; i<sizeof(needle)/sizeof(needle[0]); i++)
    {
        cout << needle[i] << " ";
    }
    cout << endl << endl;
    cout << "match result : " << endl << "position\t" << "node_id\t\t" << "pattern" << endl;

    /* 3. seaching multi patterns use automata*/

    ac_automata_search(root, haystack, strlen(haystack), needle);

    /* 4. Release the automata */
#endif
    ac_automata_release ( root );

    clock_t send=clock();
    cout<<"Execute time is "<<send-start<<"(MS/千分之一秒)"<<endl;
    return 0;
}
