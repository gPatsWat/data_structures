#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

string ShortestEquivalentPath(const string& path) {
  if (path.empty()) return "";
  bool starts_root = false;
  if (path[0] == '/') starts_root = true;

  string token;
  std::stringstream ss(path);
  char delim = '/';

  std::deque<string> st;

  while (std::getline(ss, token, delim)) {
    if (token == "") {
      continue;
    } else if (token == ".") {
      continue;
    } else if (token == "..") {
      if (st.empty()) {
        throw;
      }
      else st.pop_front();
    }
    else {
      st.push_front(token);
    }

  }

  string retval = "";
  if (starts_root) retval += "/";

  while(!st.empty()) {
    retval += st.back();
    st.pop_back();
    retval += "/";
  }

  if(retval.size() > 1)
    retval.erase(retval.size()-1);
  return retval;
}

int main() {
    cout << ShortestEquivalentPath("/") << endl;
    cout << ShortestEquivalentPath("/foo/bar/../bat") << endl;
    cout << ShortestEquivalentPath("/foo/bar/..//./../bat") << endl;
    cout << ShortestEquivalentPath("foo/bar/..//./../bat") << endl;
    cout << ShortestEquivalentPath("/foo/bar/..//./../bat/..") << endl;
    cout << ShortestEquivalentPath("foo/bar/..//./../bat/..") << endl;
    cout << ShortestEquivalentPath("..") << endl;
}