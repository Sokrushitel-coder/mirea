public class MatrixTester {
    public static void main(String[] args) {
        Matrix matrix1 = new Matrix(2, 2);
        matrix1.setElement(0, 0, 1.0);
        matrix1.setElement(0, 1, 2.0);
        matrix1.setElement(1, 0, 3.0);
        matrix1.setElement(1, 1, 4.0);

        Matrix matrix2 = new Matrix(2, 2);
        matrix2.setElement(0, 0, 5.0);
        matrix2.setElement(0, 1, 6.0);
        matrix2.setElement(1, 0, 7.0);
        matrix2.setElement(1, 1, 8.0);

        Matrix sum = matrix1.add(matrix2);
        System.out.println("Sum of matrices:");
        sum.print();

        Matrix scaledMatrix = matrix1.multiplyByScalar(2.0);
        System.out.println("Matrix multiplied by 2:");
        scaledMatrix.print();
    }
}