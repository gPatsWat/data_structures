#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct MatchResult {
    string winning_team, losing_team;
};

unordered_map<string, unordered_set<string>> build_graph(const vector<MatchResult>& matches) {
    unordered_map<string, unordered_set<string>> adj_list;

    for(auto i : matches) {
        adj_list[i.winning_team].emplace(i.losing_team);
    }

    return adj_list;
}

bool isReachable(const unordered_map<string, unordered_set<string>>& graph, const string& cur, const string& dest, unordered_set<string>* visited) {
    if(cur == dest) return true;
    else if((graph.find(cur) == graph.end()) || (visited->find(cur) != visited->end())) return false;


    visited->emplace(cur);

    for(auto i : graph.at(cur)) {
        if(isReachable(graph, i, dest, visited)) return true;
    }
    return false;
}

bool CanTeamAbeatTeamB(const vector<MatchResult>& matches, const string& team_a, const string& team_b) {
    auto graph = build_graph(matches);
    return isReachable(graph, team_a, team_b, new unordered_set<string>());
}

int main() {
    vector<MatchResult> _matches {{"a", "b"}, {"b", "c"}, {"c", "d"}};

    if(CanTeamAbeatTeamB(_matches, "a", "e")) cout << "yes!!" << endl;
    else cout << "no!!" << endl;
}