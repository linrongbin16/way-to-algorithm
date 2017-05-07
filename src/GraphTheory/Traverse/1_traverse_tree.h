#ifndef WAY_TO_ALGORITHM_GRAPHTHEORY_TRAVERSE_TRAVERSE_TREE_H
#define WAY_TO_ALGORITHM_GRAPHTHEORY_TRAVERSE_TRAVERSE_TREE_H 1
//遍历树
//traverse tree

//先序遍历 中序遍历 后序遍历

//从根节点开始对树进行递归


#include <iostream>
using std::cout;
using std::endl;
#ifndef NULL
#define NULL 0
#endif

struct traverse_tree_node
{
    int     m_index;
    traverse_tree_node*     m_left;
    traverse_tree_node*     m_right;
};


void traverse_print_node(traverse_tree_node *p)
{
	if(p == NULL)
		return;
	cout << "(index:" << p->m_index << ")" << endl;
}

void preorder_traverse(traverse_tree_node *root) 
{//从根节点开始先序遍历
	//先序遍历的访问优先级是 节点>左子树>右子树
	//递归终止条件
	if(root == NULL)
		return;
	traverse_print_node(root);
	preorder_traverse(root->m_left);
	preorder_traverse(root->m_right);
}
void inorder_traverse(traverse_tree_node *root) 
{//从根节点开始中序遍历
	//中序遍历的访问优先级是 左子树>节点>右子树
	if(root == NULL)
		return;

	inorder_traverse(root->m_left);
	traverse_print_node(root);
	inorder_traverse(root->m_right);
}
void postorder_traverse(traverse_tree_node *root) 
{//从根节点开始后序遍历
	//后序遍历的访问优先级是 左子树>右子树>节点
	if(root == NULL)
		return;

	postorder_traverse(root->m_left);
	postorder_traverse(root->m_right);
	traverse_print_node(root);
}

#endif



C:\software\Python27\Lib\site-packages\PyQt4;C:\software\UnxUtils\usr\local\wbin;C:\software\Python27\;C:\software\Python27\Scripts;C:\Program Files\Java\jdk1.8.0_111\bin;C:\Program Files\Java\jdk1.8.0_111\jre\bin;C:\ProgramData\Oracle\Java\javapath;C:\Program Files\SlickEditV18.0.1 x64\win\;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\Lua\5.1;C:\Program Files (x86)\Lua\5.1\clibs;C:\Program Files\Microsoft\Web Platform Installer\;C:\Program Files (x86)\Microsoft ASP.NET\ASP.NET Web Pages\v1.0\;C:\Program Files\Microsoft SQL Server\110\Tools\Binn\;C:\Program Files\CMake\bin;C:\Program Files\MySQL\MySQL Server 5.5\bin;C:\Program Files (x86)\Windows Kits\8.1\Windows Performance Toolkit\;C:\Program Files\Git\cmd;C:\Program Files (x86)\GtkSharp\2.12\bin;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\TortoiseSVN\bin;C:\software\MINGW\bin;C:\software\MINGW\msys\1.0\bin;C:\Program Files (x86)\Gow\bin;C:\Program Files (x86)\Visual Leak Detector\bin\Win32;C:\Program Files (x86)\Visual Leak Detector\bin\Win64;C:\Program Files (x86)\Microsoft SQL Server\90\Tools\binn\;C:\Program Files (x86)\Xoreax\IncrediBuild;C:\Program Files\doxygen\bin;C:\software\apache-maven-3.3.9\bin;C:\Program Files\mingw-w64\x86_64-6.3.0-posix-seh-rt_v5-rev1\mingw64\bin;C:\Program Files\LLVM\bin;C:\Program Files\Sublime Text 3;C:\Users\linrongbin\AppData\Roaming\Sublime Text 3\Packages\User;C:\software\Go\bin