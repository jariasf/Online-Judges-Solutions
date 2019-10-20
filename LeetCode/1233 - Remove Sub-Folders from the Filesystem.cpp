/*******************************************
 ***Problema: Remove Sub-Folders from the Filesystem
 ***ID: 1233
 ***Juez: LeetCode
 ***Tipo: Sorting + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Withoud hashing
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());      
        vector<string> res;
        string cur = folder[0];
        res.push_back(cur);
        for( int i = 1 ; i < n ; ++i ){
            if( folder[i].find(cur+ "/") != string::npos){
                continue;
            }
            cur = folder[i];
            res.push_back(cur);
        }
        return res;
    }
};

// With hashing
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());      
        vector<string> res;
        unordered_set<string> hash;
        for( int i = 0 ; i < n ; ++i ){
            string dir = folder[i];
            string prefix = "";
            bool subfolder = false;
            for( int j = 0 ; j < dir.size(); ++j ){
                if( dir[j] == '/'){
                    if( hash.find(prefix) != hash.end() ){
                        subfolder = true;
                        break;
                    }
                }
                prefix += dir[j];
            }
            if(!subfolder){
                hash.insert(dir);
                res.push_back(dir);
            }
        }
        return res;
    }
};
/*
["/a","/a/b","/c/d","/c/d/e","/c/f"]
["/a","/a/b/c","/a/b/d"]
["/a/b/c","/a/b/ca","/a/b/d"]
["/a/b/c","/a/b/ca","/a/b/d", "/a/b/ca/d"]
*/
