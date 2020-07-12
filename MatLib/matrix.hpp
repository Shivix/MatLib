#ifndef MATLIB_MATRIX_HPP
#define MATLIB_MATRIX_HPP

#include <cstddef>
#include <array>
#include <cmath>

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
            T determinant = 0;
            if(rows == 1){
                return m_data[0][0];
            }
            else if(rows == 2){
                return (m_data[0][0] * m_data[1][1]) - (m_data[1][0] * m_data[0][1]);
            }
            else if(rows == 3){
                return get3x3Determinant(0, 0);
            }
            else{
                // TODO: add recursion top solve for matrices of all sizes
            }
            return determinant;
        }
        std::size_t size() const noexcept{
            return rows * cols;
        }
        void swap(matrix& other){
            for(size_t i = 0; i < m_data.size(); ++i){
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
        std::array<T, cols> operator [] (const std::size_t& index) const noexcept {
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
            return &m_data[rows][cols];
        }
        const T* end() const noexcept {
            return &m_data[rows][cols];
        }
        const T* cend() const noexcept {
            return static_cast<const T*>(&m_data[rows][cols]);
        }
        std::reverse_iterator<T*> rbegin() noexcept {
            return std::reverse_iterator<T*>(end());
        }
        std::reverse_iterator<T*> rend() noexcept {
            return std::reverse_iterator<T*>(begin());
        }
    private:
        T get3x3Determinant(std::size_t row, std::size_t col){
            return (m_data[row][col] * ((m_data[row + 1][col + 1] * m_data[row + 2][col + 2]) - (m_data[row + 1][col + 2] * m_data[row + 2][col + 1])))
                 - (m_data[row][col + 1] * ((m_data[row + 1][col] * m_data[row + 2][col + 2]) - (m_data[row + 1][col + 2] * m_data[row + 2][col])))
                 + (m_data[row][col + 2] * ((m_data[row + 1][col] * m_data[row + 2][col + 1]) - (m_data[row + 1][col + 1] * m_data[row + 2][col])));
        }
    };
}

#endif //MATLIB_MATRIX_HPP
