#include<bits/stdc++.h>
using namespace std;

map<char,vector<string>> prod;
set<pair<char,char>> lead, trail;

void set_leading(char nt, char t) {
    if (lead.count({nt, t})) return;
    lead.emplace(nt, t);
    for (char x: nts) {
        for (string s: prod[x]) {
            if (s[0] == nt) set_leading(x, t);
    }
}
void set_trailing(char nt, char t) {
    if (trail.count({nt, t})) return;
    trail.emplace(nt, t);
    for (char x: nts) {
        for (string s: prod[x]) {
            if (s.back() == nt) set_trailing(x, t);
    }
}
int main() {
    
    int n;
    cout << "Enter the number of productions: " << endl;
    cout << "Enter " << n << " productions: " << endl;
    for (int i = 0; i < n; ++i) {
        string to; char from;
        cin >> from >> to;
        prod[from].push_back(to);
    }
    vector<char> nts;
    for (auto p: prod) nts.push_back(p.first);
    
    for (char nt: nts) {
        for (string s: prod[nt]) {
            int sz = (int) s.size();
            
            if (is_terminal(s[0]))
                set_leading(nt, s[0]);
            else if (sz > 1 && is_terminal(s[1]))
                set_leading(nt, s[1]);
            
            if (is_terminal(s[sz - 1]))
                set_trailing(nt, s[sz - 1]);
            else if (sz > 1 && is_terminal(s[sz - 2]))
                set_trailing(nt, s[sz - 2]);
        }
    }
    for (char nt: nts) {
        cout << "Leading of "
        for (auto p: lead) {
            if (p.first == nt) {
                cout << p.second << ' ';
            }
        }
    }
    
    return 0;
}
