/*******************************************
 ***Problem: Text Justification
 ***Judge: CodeSignal
 ***Type: Greedy + Simulation
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

std::vector<std::string> textJustification(std::vector<std::string> words, int l) {
    int n = words.size();
    vector<string> result;
    vector<int> indices;
    int i = 0, total_length;
    while( i < n ){
        total_length = words[i].size();
        int j = i + 1;

        while( j < n && total_length + 1 + words[j].size() <= l ){
            total_length += words[j].size() + 1;
            indices.push_back(j);
            j++;
        }

        int spaces_between_words = indices.size();
        int spaces = l - total_length + spaces_between_words;
        int eq_amount = spaces / spaces_between_words;
        int left_amount = spaces % spaces_between_words;

        // create line
        string line = words[i];
        if( j == n ){
            for( int ii = 0 ; ii < indices.size(); ++ii )
                line += " " + words[indices[ii]];           
        }else{
            for( int ii = 0 ; ii < indices.size(); ++ii ){
                // append spaces
                for( int k = 0 ; k < eq_amount ; ++k ){
                    line += " ";
                }
                if( left_amount > 0 ){
                    line += " ";
                    left_amount--;
                }
                line += words[indices[ii]];
            }

        }
 
        int line_size = line.size();
        for( int ii = 0 ; ii + line_size < l ; ++ii )
            line += " ";
        
        indices.clear();
        result.push_back(line);
        i = j;
    }
    return result;
}


