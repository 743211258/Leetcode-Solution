void explore(char ** matrix, int row_boundary, int column_start, int column_end, int column_boundary, int row_start, int row_end, int * highest_area, int current_area, bool isDown, int total_row, int total_column) {
    if (isDown) {
        for (int i = column_start; i < column_end; i++) {
            if (matrix[row_boundary][i] == '0') {
                return;
            }
        }
        current_area = current_area + (column_end - column_start);   
    } else {
        for (int i = row_start; i < row_end; i++) {
            if (matrix[i][column_boundary] == '0') {
                return;
            }
        }
        current_area = current_area + (row_end - row_start);
    }
    if (current_area > *highest_area) {
        *highest_area = current_area;
    }
    if (isDown) {
        row_boundary++;
        row_end++;
    } else {
        column_boundary++;
        column_end++;
    }

    if (row_boundary < total_row && row_end < total_row) {
        explore(matrix, row_boundary, column_start, column_end, column_boundary, row_start, row_end, highest_area, current_area, true, total_row, total_column);
    }
    if (column_boundary < total_column && column_end < total_column) {
        explore(matrix, row_boundary, column_start, column_end, column_boundary, row_start, row_end, highest_area, current_area, false, total_row, total_column);
    }

}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int colSize = *matrixColSize;
    int highest_area = 0;
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < colSize; col++) {
            char pixel_value = matrix[row][col];
            if (pixel_value == '0') {
                continue;
            }
            if (1 > highest_area) {
                highest_area = 1;
            }
            if (row + 1 != matrixSize) {
                explore(matrix, row + 1, col, col + 1, col + 1, row, row + 1, &highest_area, 1, true, matrixSize, colSize);
            }
            if (col + 1 != colSize) {
                explore(matrix, row + 1, col, col + 1, col + 1, row, row + 1, &highest_area, 1, false, matrixSize, colSize);
            }
        }
    }
    return highest_area;
