public class Matrix {
    private double[][] data;
    private int rows;
    private int columns;

    public Matrix(int rows, int columns) {
        this.rows = rows;
        this.columns = columns;
        this.data = new double[rows][columns];
    }

    public void setElement(int row, int column, double value) {
        if (row >= 0 && row < rows && column >= 0 && column < columns) {
            data[row][column] = value;
        } else {
            System.out.println("Invalid row or column indices");
        }
    }

    public double getElement(int row, int column) {
        if (row >= 0 && row < rows && column >= 0 && column < columns) {
            return data[row][column];
        } else {
            System.out.println("Invalid row or column indices");
            return 0.0;
        }
    }

    public Matrix add(Matrix otherMatrix) {
        if (this.rows != otherMatrix.rows || this.columns != otherMatrix.columns) {
            System.out.println("Cannot perform addition: matrices have different dimensions");
            return null;
        }

        Matrix result = new Matrix(rows, columns);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.data[i][j] = this.data[i][j] + otherMatrix.data[i][j];
            }
        }

        return result;
    }

    public Matrix multiplyByScalar(double scalar) {
        Matrix result = new Matrix(rows, columns);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.data[i][j] = this.data[i][j] * scalar;
            }
        }

        return result;
    }

    public void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.print(data[i][j] + " ");
            }
            System.out.println();
        }
    }
}