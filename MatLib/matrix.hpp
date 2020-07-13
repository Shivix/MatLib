#ifndef MATLIB_MATRIX_HPP
#define MATLIB_MATRIX_HPP

#include <cstddef>
#include <array>
#include <cmath>
#include <tuple>

// TODO: range based for loop cuts of last element.
namespace MatLib{
    template<typename T, std::size_t cols, std::size_t rows>
    class matrix{
    public:
        // No explicit constructor/ destructor etc. for aggregate
        
        std::array<std::array<T, cols>, rows> m_data{};
        
        void fill(const T& value){
            std::fill(m_data[0][0], m_data[rows][cols], value);
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
                auto [tempMatrix, getSign] = this->getRowEchelon(); // row echelon is calculated first to reduce the complexity down closer to O(N^2)
                for(std::size_t i = 0; i < rows; ++i){ // determinate is the product of the main diagonal elements in a row echelon matrix
                    determinant *= tempMatrix[i][i];
                }
            }
            return determinant;
        }
        std::tuple<matrix, bool> getRowEchelon(){
            auto newData = m_data;
            
            bool isInverted = false;

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

            return std::make_tuple(tempMatrix, isInverted);
        }
        std::size_t size() const noexcept{
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
                    resultMatrix[i][j] = this->m_data[i][j] + other.m_data[i][j];
                }
            }
            return resultMatrix;
        }
        matrix operator + (const T& scalar) noexcept {
            matrix<T, cols, rows> resultMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){ 
                    resultMatrix[i][j] = this->m_data[i][j] + scalar;
                }
            }
            return resultMatrix;
        }
        matrix operator - (const matrix& other) noexcept {
            matrix<T, cols, rows> resultMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){ // m_data[x] will all have same .size()
                    resultMatrix[i][j] = this->m_data[i][j] - other.m_data[i][j];
                }
            }
            return resultMatrix;
        }
        matrix operator - (const T& scalar) noexcept {
            matrix<T, cols, rows> resultMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){ 
                    resultMatrix[i][j] = this->m_data[i][j] - scalar;
                }
            }
            return resultMatrix;
        }
        template<std::size_t otherRows, std::size_t otherCols>
        matrix operator * (const matrix<T, otherCols, otherRows>& other) noexcept { 
            matrix<T, cols, otherRows> resultMatrix = {};
            for(size_t i = 0; i < rows; ++i){
                for(size_t j = 0; j < cols; ++j){
                    resultMatrix.m_data[i][j] = m_data[i][j] * other.m_data[j][i];
                }
            }
            return resultMatrix;
        }
        matrix operator * (const T& scalar) noexcept {
            for(size_t i = 0; i < rows; ++i){
                for(size_t j = 0; j < cols; ++j){
                    m_data[i][j] * scalar;
                }
            }
        }
        matrix operator / (const matrix& other) noexcept {
            
            
            
        }
        matrix operator / (const T& scalar) noexcept {
            for(size_t i = 0; i < rows; ++i){
                for(size_t j = 0; j < cols; ++j){
                    m_data[i][j] * scalar;
                }
            }
        }
        std::array<T, cols> operator [] (const std::size_t& index) noexcept { // static_assert for boundaries
            return m_data[index];
        }
        constexpr std::array<T, cols> operator [] (const std::size_t& index) const noexcept {
            return m_data[index];
        }
        bool operator == (const matrix& other) noexcept {
            for(std::size_t i = 0; i < this->size() / cols; ++i){
                if(this[i] == other[i]){
                    return true;
                }
            }
            return false;
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
