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
            for(std::size_t i = 0; i < m_data.size(); ++i){
                for(std::size_t j = 0; j < m_data[0].size(); ++j){ // m_data[x] will all have same .size()
                    resultMatrix[i][j] = this->m_data[i][j] + other.m_data[i][j];
                }
            }
            return resultMatrix;
        }
        matrix operator + (const T& other) noexcept {
            matrix<T, rows, cols> resultMatrix = {};
            for(std::size_t i = 0; i < m_data.size(); ++i){
                for(std::size_t j = 0; j < m_data[0].size(); ++j){ // m_data[x] will all have same .size()
                    resultMatrix[i][j] = this->m_data[i][j] + other;
                }
            }
            return resultMatrix;
        }
        matrix operator - (const matrix& other) noexcept {
            matrix<T, rows, cols> resultMatrix = {};
            for(std::size_t i = 0; i < m_data.size(); ++i){
                for(std::size_t j = 0; j < m_data[0].size(); ++j){ // m_data[x] will all have same .size()
                    resultMatrix[i][j] = this->m_data[i][j] - other.m_data[i][j];
                }
            }
            return resultMatrix;
        }
        matrix operator - (const T& other) noexcept {
            matrix<T, rows, cols> resultMatrix = {};
            for(std::size_t i = 0; i < m_data.size(); ++i){
                for(std::size_t j = 0; j < m_data[0].size(); ++j){ // m_data[x] will all have same .size()
                    resultMatrix[i][j] = this->m_data[i][j] - other;
                }
            }
            return resultMatrix;
        }
        matrix operator * (const matrix&) noexcept { //array swap may help
            
        }
        matrix operator / (const matrix&) noexcept {
            
        }
        std::array<T, rows> operator [] (const std::size_t& index) noexcept { // static_assert for boundaries
            return m_data[index];
        }
        friend bool operator == (matrix& matrix1, matrix& matrix2) noexcept {
            for(std::size_t i = 0; i < matrix1.size() / cols; ++i){
                if(matrix1[i] == matrix2[i]){
                    return true;
                }
            }
            return false;
        }
        friend bool operator != (matrix& matrix1, matrix& matrix2) noexcept {
            for(std::size_t i = 0; i < matrix1.size() / cols; ++i){
                if(matrix1[i] != matrix2[i]){
                    return true;
                }
            }
            return false;
        }
        friend bool operator < (matrix& matrix1, matrix& matrix2) noexcept {
            return matrix1.getDeterminant() > matrix2.getDeterminant();
        }
        bool operator > (const matrix&) noexcept {
            return false;
        }
        bool operator >= (const matrix&) noexcept {
            return false;
        }
        bool operator <= (const matrix&) noexcept {
            return false;
        }
        
        std::size_t size(){
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
        const T* cbegin() const noexcept {
            return static_cast<const T*>(&m_data[0][0]);
        }
        T* end() noexcept {
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
