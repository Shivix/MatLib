#ifndef MATLIB_MATRIX_HPP
#define MATLIB_MATRIX_HPP

#include <cstddef>
#include <array>

namespace MatLib{
    template<typename T, std::size_t rows, std::size_t cols>
    class matrix{
    public:
        std::array<std::array<T, rows>, cols> m_data{};
        
        void fill(const T& value){
            std::fill(m_data[0][0], m_data[rows][cols], value);
        }
        T getDeterminant(){
            return 0;
        }
        void swap(matrix& other){
            for(size_t i = 0; i < m_data.size(); ++i){
                m_data[i].swap(other.m_data[i]);
            }
        }
        
        matrix operator + (const matrix& other) noexcept { 
            matrix<T, rows, cols> resultMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){ // m_data[x] will all have same .size()
                    resultMatrix[i][j] = this->m_data[i][j] + other.m_data[i][j];
                }
            }
            return resultMatrix;
        }
        matrix operator + (const T& scalar) noexcept {
            matrix<T, rows, cols> resultMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){ // m_data[x] will all have same .size()
                    resultMatrix[i][j] = this->m_data[i][j] + scalar;
                }
            }
            return resultMatrix;
        }
        matrix operator - (const matrix& other) noexcept {
            matrix<T, rows, cols> resultMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){ // m_data[x] will all have same .size()
                    resultMatrix[i][j] = this->m_data[i][j] - other.m_data[i][j];
                }
            }
            return resultMatrix;
        }
        matrix operator - (const T& scalar) noexcept {
            matrix<T, rows, cols> resultMatrix = {};
            for(std::size_t i = 0; i < rows; ++i){
                for(std::size_t j = 0; j < cols; ++j){ // m_data[x] will all have same .size()
                    resultMatrix[i][j] = this->m_data[i][j] - scalar;
                }
            }
            return resultMatrix;
        }

        template<std::size_t otherRows, std::size_t otherCols>
        matrix operator * (const matrix<T, otherRows, otherCols>& other) noexcept { //array swap may help
            matrix<T, otherRows, cols> resultMatrix = {};
            for(size_t i = 0; i < rows; ++i){
                for(size_t j = 0; j < cols; ++j){
                    resultMatrix.m_data[i][j] = m_data[i][j] * other.m_data[j][i];
                }
            }
            return resultMatrix;
        }
        matrix operator * (const T& scalar) noexcept { //array swap may help
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
        std::array<T, rows> operator [] (const std::size_t& index) noexcept { // static_assert for boundaries
            return m_data[index];
        }
        std::array<T, rows> operator [] (const std::size_t& index) const noexcept { // static_assert for boundaries
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
        
        std::size_t size(){
            std::size_t iter = 0;
            for(auto&&i: m_data){
                iter += i.size();
            }
            return iter;
        }
        std::size_t size() const {
            std::size_t iter = 0;
            for(auto&&i: m_data){
                iter += i.size();
            }
            return iter;
        }
        T back() noexcept {
            return *end();
        }
        T front() noexcept {
            return *begin();
        }
        T* begin() noexcept {
            return static_cast<T*>(&m_data[0][0]);
        }
        const T* begin() const noexcept {
            return static_cast<T*>(&m_data[0][0]);
        }
        const T* cbegin() const noexcept {
            return static_cast<const T*>(&m_data[0][0]);
        }
        T* end() noexcept {
            return static_cast<T*>(&m_data[rows][cols]);
        }
        const T* end() const noexcept {
            return static_cast<T*>(&m_data[rows][cols]);
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
    };
}


#endif //MATLIB_MATRIX_HPP
