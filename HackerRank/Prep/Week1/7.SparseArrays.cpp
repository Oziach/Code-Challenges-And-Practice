/*Question:

There is a collection of input strings and a collection of query strings. For each query string, determine how many times it occurs in the list of input strings. 
Return an array of the results. 

*/

//Solution
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    
    vector<int> results;
    
    for(int i = 0; i < queries.size(); i++){
        int count = 0;
        
        for(int j = 0; j < strings.size(); j++){
            if(strings[j] == queries[i]){
                count++;
            }
        }
        results.push_back(count);
    }
    return results;
}
