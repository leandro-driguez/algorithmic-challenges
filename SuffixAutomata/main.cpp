#include <bits/stdc++.h>

using namespace std;

struct SuffixAutomaton {
  vector<map<char,int>> edges; // edges[i]  : the labeled edges from node i
  vector<int> link;            // link[i]   : the parent of i
  vector<int> length;          // length[i] : the length of the longest string in the ith class
  int last;                    // the index of the equivalence class of the whole string

  SuffixAutomaton(string s) {
    // add the initial node
    edges.push_back(map<char,int>());
    link.push_back(-1);
    length.push_back(0);
    last = 0;

    for(int i=0;i<s.size();i++) {
      // construct r
      edges.push_back(map<char,int>());
      length.push_back(i+1);
      link.push_back(0);
      int r = edges.size() - 1;

      // add edges to r and find p with link to q
      int p = last;
      while(p >= 0 && edges[p].find(s[i]) == edges[p].end()) {
        edges[p][s[i]] = r;
        p = link[p];
      }
      if(p != -1) {
        int q = edges[p][s[i]];
        if(length[p] + 1 == length[q]) {
          // we do not have to split q, just set the correct suffix link
          link[r] = q;
        } else {
          // we have to split, add q'
          edges.push_back(edges[q]); // copy edges of q
          length.push_back(length[p] + 1);
          link.push_back(link[q]); // copy parent of q
          int qq = edges.size()-1;
          // add qq as the new parent of q and r
          link[q] = qq;
          link[r] = qq;
          // move short classes pointing to q to point to q'
          while(p >= 0 && edges[p][s[i]] == q) {
            edges[p][s[i]] = qq;
            p = link[p];
          }
        }
      }
      last = r;
    }
  }
};

int main()
{
    string s;
    cin>>s;

    int k;
    cin>>k;

    vector<string> ss;
    for (int i = 0; i < k; i++) {
        string tmp;
        cin>>tmp;
        ss.push_back(tmp);
    }

    SuffixAutomaton a(s);

    for (int j = 0; j < ss.size(); j++) {
        string w = ss[j];
        bool fail = false;
        int n = 0;

        for(int i=0;i<w.size();i++) {   
            if(a.edges[n].find(w[i]) == a.edges[n].end()) {
                fail = true;
                break;
            }
            n = a.edges[n][w[i]];
        }
        if(!fail) cout<<a.edges[n].size()<<endl;
        else cout<<0<<endl;
    }

    return 0;
}