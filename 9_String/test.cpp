//test

#include "general_head.h"
#include "3_trie_tree.hpp"	//struct trie_tree
#include "4_aho_corasick_automation.hpp"	//struct aho_corasick_automation
extern void naive_string_match(string s, string t, vector<int>& pos);
extern void knuth_morris_pratt(string s, string t, vector<int>& pos);
void print_pos(string s, string t, vector<int> pos);
int main()
{	
	string t("ababacbabcbabababababcbdtdtdaabababac");
	//		  012345678901234567890123456789012
	cout << t << endl;
	cout << "012345678901234567890123456789012" << endl;
	vector<string> s;
	s.push_back("abc");	//0
	s.push_back("ababa");	//1
	s.push_back("dt");		//2
	s.push_back("baba");	//3
	s.push_back("asdf");	//4, not exist
	vector<int> pos;
	cout << "naive string match" << endl;
	naive_string_match(s[1], t, pos);	//1
	print_pos(s[1], t, pos);

	cout << "knuth morris pratt" << endl;
	knuth_morris_pratt(s[1], t, pos);	//2
	print_pos(s[1], t, pos);

	cout << "trie tree" << endl;
	trie_tree tt;			//3
	for(int i = 0; i < (int)s.size(); ++ i)
		tt.t_insert(s[i]);
	cout << "insert words: ";
	for(int i = 0; i < (int)s.size(); ++ i)
		cout << s[i] << ' ';
	cout << endl;
	cout << "word 'ababa' appear " << tt.t_search("ababa") << " times" << endl;
	cout << "word 'dt' appear " << tt.t_search("dt") << " times" << endl;
	cout << "word 'acd' appear " << tt.t_search("acd") << " times" << endl;

	cout << endl;
	cout << "text: " << t << endl << "aho corasick automation" << endl;
	aho_corasick_automation ac;
	ac.a_build(s);
	cout << "insert words: " << endl;
	for(int i = 0; i < (int)s.size(); ++ i)
		cout << s[i] << '\t';
	cout << endl;
	cout << "search over the text" << endl;
	multimap<string, int> pos2;
	ac.a_search(t, pos2);
	for(multimap<string, int>::iterator it = pos2.begin(); it != pos2.end(); ++ it)
		cout << "string: " << it->first << ", index: " << it->second << endl;
	return(0);
}
void print_pos(string s, string t, vector<int> pos)
{
	cout << "search word '" << s << "'" << endl;
	for(int i = 0; i < (int)pos.size(); ++ i){
		cout << "position: " << pos[i] << ",string: ";
		for(int j = 0; j < (int)s.length(); ++ j)
			cout << t[pos[i] + j];
		cout << endl;
	}
	cout << endl;
}
