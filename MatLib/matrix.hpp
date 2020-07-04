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
        
        friend matrix operator + (const matrix& matrix1, const matrix& matrix2) noexcept { // static_assert for size
            for(auto&& i: matrix1){
                int i2;
                for(auto&& j: i){
                    i + matrix2[i2];
                    ++i2;
                }
            }
        }
        matrix operator - (const matrix&) noexcept {
            
        }
        matrix operator * (const matrix&) noexcept {
            
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
            
        }
        T front() noexcept {
            
        }
        T* begin() noexcept {
            return static_cast<T*>(&m_data[0][0]);
        }
        const T* begin() const noexcept {
            return static_cast<const T*>(&m_data[0][0]);
        }
        T* end() noexcept {
            return static_cast<T*>(&m_data[rows][cols]);
        }
        const T* end() const noexcept {
            return static_cast<const T*>(&m_data[rows][cols]);
        }
        T rbegin() noexcept {
            
        }
        T rend() noexcept {
            
        }
        void swap(const matrix& matrix1, const matrix& matrix2){
            
        }
    };
}


#endif //MATLIB_MATRIX_HPP
