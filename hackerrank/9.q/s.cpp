#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    map<string, map<string, string>> hrml;
    vector<string> tag_stack;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        
        if (line.substr(0, 2) == "</") {
            tag_stack.pop_back();
        } else {
            line = line.substr(1, line.length() - 2); 
            stringstream ss(line);
            string tag_name, attr_name, eq, attr_val;
            
            ss >> tag_name;
            
        
            string current_path = "";
            if (!tag_stack.empty()) {
                for (const auto& t : tag_stack) current_path += t + ".";
            }
            current_path += tag_name;
            tag_stack.push_back(tag_name);

            while (ss >> attr_name >> eq >> attr_val) {
                
                if (attr_val.back() == '\"') attr_val.pop_back();
                if (attr_val.front() == '\"') attr_val.erase(0, 1);
                
                hrml[current_path][attr_name] = attr_val;
            }
        }
    }

    for (int i = 0; i < Q; ++i) {
        string query;
        getline(cin, query);
        
        size_t tilde_pos = query.find('~');
        string path = query.substr(0, tilde_pos);
        string attr = query.substr(tilde_pos + 1);
        
        if (hrml.count(path) && hrml[path].count(attr)) {
            cout << hrml[path][attr] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
