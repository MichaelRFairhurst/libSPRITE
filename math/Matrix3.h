#ifndef __MATH_MATRIX3_H__
#define __MATH_MATRIX3_H__


#include <base/assertion.h>


namespace math
{
    /**
     * Forward declaration of classes.
     */
    template <typename T> class Vec3;
    class DCM;

    class Matrix3
    {

        public:

            /**
             * Default constructor
             */
            Matrix3();

            /**
             * Constructor with initial values.
             */
            Matrix3(double e11, double e12, double e13,
                    double e21, double e22, double e23,
                    double e31, double e32, double e33);

            /**
             * Constructor with initial array.
             */
            Matrix3(double e[9]);

            /**
             * Convert a DCM to a standard 3x3 matrix.
             */
            explicit Matrix3(const DCM& d);

            /**
             * Operator overload for accessing an element.
             * Used like this: double x = M(i,j);
             * @param row Matrix row number
             * @param col Matrix column number
             * @return Value of the specified element
             */
            double operator() (unsigned int row, unsigned int col) const
            {
                assert((row >= 1) && (row <= 3));
                assert((col >= 1) && (col <= 3));

                return m_[row-1][col-1];
            }

            /**
             * Operator overload for setting an element.
             * Used like this: M(i,j) = 3.14;
             * @param row Matrix row number
             * @param col Matrix column number
             * @return Reference to the element.
             */
            double &operator() (unsigned int row, unsigned int col)
            {
                assert((row >= 1) && (row <= 3));
                assert((col >= 1) && (col <= 3));

                return m_[row-1][col-1];
            }

            /**
             * Test for equality.
             * @param M right hand side operator.
             * @return true if the matrix element values are identical,
             * otherwise, false.
             */
            bool operator==(const Matrix3& M) const;

            /**
             * Test for inequality.
             * @param M right hand side operator.
             * @return false if the matrix element values are identical,
             * otherwise, true.
             */
            bool operator!=(const Matrix3& M) const
            {
                return !(*this == M);
            }

            /**
             * Scalar addition.
             * @param f Scalar to add to the matrix elements.
             * @return A new matrix M' = M + f;
             */
            Matrix3 operator+(double f) const;

            /**
             * Scalar subtraction.
             * @param f Scalar to subtract rom the matrix elements.
             * @return A new matrix M' = M - f;
             */
            Matrix3 operator-(double f) const;

            /**
             * Scalar multiplication.
             * @param f Scalar to multiply the matrix elements by.
             * @return A new matrix M' = M * f;
             */
            Matrix3 operator*(double f) const;

            /**
             * Scalar division.
             * @param f Scalar to divide the matrix elements by.
             * @return A new matrix M' = M / f;
             */
            Matrix3 operator/(double f) const;

            /**
             * Scalar addition.
             * @param f Scalar to add to the matrix elements.
             * @return A reference to the existing matrix with the new value
             * M = M + f;
             */
            Matrix3 & operator+=(double f);

            /**
             * Scalar subtraction.
             * @param f Scalar to subtract rom the matrix elements.
             * @return A reference to the existing matrix with the new value
             * M = M - f;
             */
            Matrix3 & operator-=(double f);

            /**
             * Scalar multiplication.
             * @param f Scalar to multiply the matrix elements by.
             * @return A reference to the existing matrix with the new value
             * M = M * f;
             */
            Matrix3 & operator*=(double f);

            /**
             * Scalar division.
             * @param f Scalar to divide the matrix elements by.
             * @return A reference to the existing matrix with the new value
             * M = M / f;
             */
            Matrix3 & operator/=(double f);

            /**
             * Matrix addition.
             * @param M Matrix on the right-hand side of the addition.
             * @return A new Matrix M' = A + B
             */
            Matrix3 operator+(const Matrix3& B) const;

            /**
             * Matrix subtraction.
             * @param M Matrix on the right-hand side of the subtraction.
             * @return A new Matrix M' = A - B
             */
            Matrix3 operator-(const Matrix3& B) const;

            /**
             * Matrix addition.
             * @param M Matrix on the right-hand side of the addition.
             * @return A reference to the existing matrix with the new value
             * A = A + B
             */
            Matrix3 & operator+=(const Matrix3& B);

            /**
             * Matrix subtraction.
             * @param M Matrix on the right-hand side of the subtraction.
             * @return A reference to the existing matrix with the new value
             * A = A - B
             */
            Matrix3 & operator-=(const Matrix3& B);

            /**
             * Matrix multiplication.
             * @param M Matrix on the right-hand side of the multiplication.
             * @return A new Matrix M' = A * B
             */
            Matrix3 operator*(const Matrix3& B) const;

            /**
             * Matrix multiplication.
             * @param M Matrix on the right-hand side of the multiplication.
             * @return A reference to the existing matrix with the new value
             * A = A * B
             */
            Matrix3 & operator*=(const Matrix3& B);

            /**
             * Vector muliplication.
             * @param v Three element vector on the right-hand side of the
             * multiplication.
             * @return A new vector with the value V' = M * v
             */
            math::Vec3<double> operator*(const Vec3<double>& v) const;

            /**
             * Matrix transpose.
             * @return A new matrix with the elements transposed.
             */
            Matrix3 transpose() const;

            /**
             * Matrix inverse.
             * @return A new matrix that is the inverse of the current matrix.
             */
            Matrix3 inverse() const;

            /**
             * Matrix determinant.
             * @return the determinant of the matrix.
             */
            double determinant() const;

            /**
             * Matrix trace.
             * @return the trace value of the matrix.
             */
            double trace() const;

        protected:
            /**
             * The elements of the matrix.
             */
            double m_[3][3];

    };

    /**
     * Matrix determinate operator.
     * This is a operator that allows the determinate operation to be written
     * in a manner consistant with standard mathmatical notation.
     * @param M Matrix to compute the determinant of.
     * @return the matrix determinant.
     */
    double det(const Matrix3& M);

} // namespace

#endif // __MATH_MATRIX3_H__
