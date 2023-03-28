class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m_min = 0, m_max = matrix.size();
        int n_min = 0, n_max = matrix[0].size();
        vector<int> result;
        while(true) {
            int m, n;
            for (m = m_min, n = n_min; n < n_max; n++)
                result.push_back(matrix[m][n]);
            m_min++;
            if ((m_min >= m_max) || (n_min >= n_max)) return result;

            for (m = m_min, n = n_max-1; m < m_max; m++)
                result.push_back(matrix[m][n]);
            n_max--;
            if ((m_min >= m_max) || (n_min >= n_max)) return result;
            
            for (m = m_max-1, n = n_max-1; n >= n_min; n--)
                result.push_back(matrix[m][n]);
            m_max--;
            if ((m_min >= m_max) || (n_min >= n_max)) return result;
            
            for (m = m_max-1, n = n_min; m >= m_min; m--)
                result.push_back(matrix[m][n]);
            n_min++;
            
            if ((m_min >= m_max) || (n_min >= n_max)) return result;
                
        }
    }
};