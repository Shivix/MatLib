#ifndef MATLIB_MATRIX_HPP
#define MATLIB_MATRIX_HPP

#include <cstddef>
#include <array>
#include <tuple>

// TODO: range based for loop cuts of last element.
namespace MatLib{
    template<typename T, std::size_t rows, std::size_t cols>
    class matrix{
    public:
        // No explicit constructor/ destructor etc. for aggregate
        
        std::array<std::array<T, cols>, rows> m_data{};
        
        void fill(const T& value){
            std::fill(m_data[0][0], m_data[rows][cols], value);
        }
        matrix<T, rows, cols * 2> getAugment(const matrix& other){ // returns a matrix where the other matrix is "attached" to the original
            matrix<T, rows, cols * 2> resultMatrix = {};
            
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < resultMatrix[0].size(); ++j){
                    if(j >= cols){
                        resultMatrix.m_data[i][j] = other.m_data[i][j - cols];
                    }
                    else{
                        resultMatrix.m_data[i][j] = this->m_data[i][j];
                    }
                }
            }
            return resultMatrix;
        }
        T getDeterminant(){
            static_assert(rows == cols, "Must be a square matrix");
            T determinant = 1;
            if(rows == 1){
                return m_data[0][0];
            }
            else if(rows == 2){
                return (m_data[0][0] * m_data[1][1]) - (m_data[1][0] * m_data[0][1]);
            }
            else{
                auto [rowEchelonFormMatrix, isNegative] = this->getRowEchelon(); // row echelon is calculated first to reduce the complexity down closer to O(N^2)
                for(std::size_t i = 0; i < rows; ++i){ // determinate is the product of the main diagonal elements in a row echelon matrix
                    if(isNegative){
                        determinant *= -rowEchelonFormMatrix[i][i];
                    }
                    else{
                        determinant *= rowEchelonFormMatrix[i][i];
                    }
                }
            }
            return determinant;
        }
        matrix getIdentity(){
            matrix identityMatrix = {};

            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){
                    if(i == j){
                        identityMatrix.m_data[i][j] = 1;
                    }
                    else{
                        identityMatrix.m_data[i][j] = 0;
                    }
                }
            }
            return identityMatrix;
        }
        matrix getInverse(){
            
            matrix<T, rows, cols * 2> augIdentMatrix = getAugment(getIdentity()); // gets the identity matrix and then augments it onto the original matrix
            
            const std::size_t AUG_ID_COLS = augIdentMatrix.m_data[0].size(); // all arrays within the first have the same size
            
            // replace elements based on a constant scalar from ANOTHER row
            for(std::size_t i = 0; i < cols; ++i){
                for(std::size_t j = 0; j < rows; ++j){
                    if(i != j){
                        T scalar = augIdentMatrix.m_data[j][i] / augIdentMatrix.m_data[i][i];
                        for(std::size_t k = 0; k < AUG_ID_COLS; ++k){
                            augIdentMatrix.m_data[j][k] -= augIdentMatrix.m_data[i][k] * scalar;
                        } 
                    }
                }
            }
            // divide each row element by the diagonal elements that were skipped previously
            for (std::size_t i = 0; i < rows; i++) {
                T scalar = augIdentMatrix.m_data[i][i];
                for (std::size_t j = 0; j < AUG_ID_COLS; j++) {
                    augIdentMatrix.m_data[i][j] = augIdentMatrix.m_data[i][j] / scalar;
                }
            }
            // add the inverted half of the augmented matrix to it's own matrix
            matrix inversedMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){
                    inversedMatrix.m_data[i][j] = augIdentMatrix.m_data[i][j + cols];
                }
            }
            
            return inversedMatrix;
        }
        std::tuple<matrix, bool> getRowEchelon(){ // returns the row echelon form matrix so that the original is kept
            auto newData = m_data;
            
            bool isInverted = false; // keeps track of the sign of the determinant (before multiplication)

            for(std::size_t pivotRow = 0; (rows < cols ? pivotRow < rows - 1 : pivotRow < cols - 1); ++pivotRow){
                if(newData[pivotRow][pivotRow] == 0){ 

                // swap pivot element with another non 0 element
                    std::size_t swapRow = pivotRow;
                    for(std::size_t i = pivotRow + 1; i < rows; i++){
                        if(newData[i][pivotRow] != 0){
                            swapRow = i;
                            break;
                        }
                    }
                    if(swapRow == pivotRow){
                        continue;
                    }
                    isInverted = !isInverted;
                    // swaps the swapRow and pivotRow
                    newData[swapRow].swap(newData[pivotRow]);
                }
                // eliminate elements in x col under x col
                for(std::size_t targetRow = pivotRow + 1; targetRow < rows; ++targetRow){
                    T scale = newData[targetRow][pivotRow] / newData[pivotRow][pivotRow];
                    
                    for(std::size_t targetCol = 0; targetCol < cols; ++targetCol){
                        newData[targetRow][targetCol] -= scale * newData[pivotRow][targetCol];
                    }
                }
            }
            //return isInverted;
            matrix tempMatrix = {};
            tempMatrix.m_data = newData;

            return std::make_tuple(tempMatrix, isInverted); // returns a tuple including the bool that keeps track of the sign determinant
        }
        matrix getTranspose(){
            matrix<T, rows, cols> transposedMatrix = {}; // rows and cols are in opposite order for transposed matrix
            
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){
                    transposedMatrix.m_data[i][j] = this->m_data[j][i];
                }
            }
            return transposedMatrix;
        }
        constexpr std::size_t size() const noexcept{
            return rows * cols;
        }
        void swap(matrix& other){
            for(std::size_t i = 0; i < m_data.size(); ++i){
                m_data[i].swap(other.m_data[i]);
            }
        }
        // Operators
        matrix operator + (const matrix& other) noexcept { 
            matrix<T, cols, rows> resultMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){ // m_data[x] will all have same .size()
                    resultMatrix.m_data[i][j] = this->m_data[i][j] + other.m_data[i][j];
                }
            }
            return resultMatrix;
        }
        matrix operator + (const T& scalar) noexcept {
            matrix<T, cols, rows> resultMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){ 
                    resultMatrix.m_data[i][j] = this->m_data[i][j] + scalar;
                }
            }
            return resultMatrix;
        }
        matrix operator - (const matrix& other) noexcept {
            matrix<T, cols, rows> resultMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){ // m_data[x] will all have same .size()
                    resultMatrix.m_data[i][j] = this->m_data[i][j] - other.m_data[i][j];
                }
            }
            return resultMatrix;
        }
        matrix operator - (const T& scalar) noexcept {
            matrix<T, cols, rows> resultMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){ 
                    resultMatrix.m_data[i][j] = this->m_data[i][j] - scalar;
                }
            }
            return resultMatrix;
        }
        template<std::size_t otherRows, std::size_t otherCols>
        matrix operator * (const matrix<T, otherCols, otherRows>& other) noexcept { 
            matrix<T, cols, otherRows> resultMatrix = {};
            for(size_t i = 0; i < otherRows; ++i){
                for(size_t j = 0; j < cols; ++j){
                    for(size_t k = 0; k < rows; ++k){
                        resultMatrix.m_data[i][j] += this->m_data[i][k] * other.m_data[k][j];
                    }
                }
            }
            return resultMatrix;
        }
        matrix operator * (const T& scalar) noexcept {
            matrix<T, cols, rows> resultMatrix = {};
            for(size_t i = 0; i < rows; ++i){
                for(size_t j = 0; j < cols; ++j){
                    resultMatrix.m_data[i][j] = this->m_data[i][j] * scalar;
                }
            }
            return resultMatrix;
        }
        matrix operator / (const matrix& other) noexcept {
            
            
            
        }
        matrix operator / (const T& scalar) noexcept {
            for(size_t i = 0; i < rows; ++i){
                for(size_t j = 0; j < cols; ++j){
                    this->m_data[i][j] * scalar;
                }
            }
        }
        std::array<T, cols> operator [] (const std::size_t& index) noexcept { // static_assert for boundaries
            return m_data[index];
        }
        constexpr std::array<T, cols> operator [] (const std::size_t& index) const noexcept {
            return m_data[index];
        }
        friend bool operator == (const matrix matrix1, const matrix matrix2) noexcept {
            for(std::size_t i = 0; i < matrix1.size() / cols; ++i){
                if(matrix1[i] == matrix2[i]){
                    return true;
                }
            }
            return false;
        }
        bool operator != (const matrix& other) noexcept {
            for(std::size_t i = 0; i < this->size() / cols; ++i){
                if(this[i] != other[i]){
                    return true;
                }
            }
            return false;
        }
        // Iterators
        T back() noexcept {
            return *end();
        }
        T front() noexcept {
            return *begin();
        }
        T* begin() noexcept {
            return &m_data[0][0];
        }
        const T* begin() const noexcept {
            return &m_data[0][0];
        }
        const T* cbegin() const noexcept {
            return static_cast<const T*>(&m_data[0][0]);
        }
        T* end() noexcept {
            return &m_data[rows - 1][cols - 1];
        }
        const T* end() const noexcept {
            return &m_data[rows - 1][cols - 1];
        }
        const T* cend() const noexcept {
            return static_cast<const T*>(&m_data[rows - 1][cols - 1]);
        }
        std::reverse_iterator<T*> rbegin() noexcept {
            return std::reverse_iterator<T*>(end());
        }
        std::reverse_iterator<T*> rend() noexcept {
            return std::reverse_iterator<T*>(begin());
        }
    private:
        
    };
}

#endif //MATLIB_MATRIX_HPP
