/*******************************************
 ***Problem: Single Number
 ***Judge: CodeSignal
 ***Type: Bitwise Operators
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

int singleNumber(std::vector<int> nums) {
	int res = 0;
 	for( int num : nums ) {
 	   res ^= num;
 	}
  	return res;
}

