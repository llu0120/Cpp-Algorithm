/*
Two sparse vector a, b, return the dot product between a and b. 

ex: 
A = [0, 0, 2, 0, 4] 
B = [1, 0, 1, 0, 5] 
return 21 
*/ 

class SparseVector {
public:
    int dotProduct(vector<int>& A, vector<int>& B) {
        int result = 0;
        unordered_map<int, int> mapA;
        unordered_map<int, int> mapB;
        
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != 0) {
                mapA[i] = A[i];
            }
            if (B[i] != 0) {
                mapB[i] = B[i];
            }
        }
        for (auto i : mapA) {
            int indA = i.first;
            int valA = i.second;
            if (mapB.find(indA) != mapB.end()) {
                result += valA * mapB[indA];
            }
        }
        return result;
    }
};
