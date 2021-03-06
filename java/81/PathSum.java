import java.io.FileReader;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;

public class PathSum {

	private int[][] matrix;
	
	public PathSum(String fileName, int n, int m) throws IOException {
		matrix = new int[n][m];
		loadMatrix(fileName);
	}

	private void loadMatrix(String fileName) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(fileName));
		for (int i = 0; i < matrix.length; ++i) {
			String[] tokens = reader.readLine().split(",");
			for (int j = 0; j < matrix.length; ++j) {
				matrix[i][j] = Integer.parseInt(tokens[j]);
			}
		}
	}

	public int getSum() {
		for (int i = matrix.length - 1; i > 0; --i) {
			matrix[matrix.length - 1][i - 1] += matrix[matrix.length - 1][i];
			matrix[i - 1][matrix.length - 1] += matrix[i][matrix.length - 1];
		}
		for (int i = matrix.length - 2; i >= 0; --i) {
			for (int j = matrix.length - 2; j >= 0; --j) {
				matrix[i][j] += Math.min(matrix[i + 1][j], matrix[i][j + 1]);
			}
		}
		return matrix[0][0];
	}

	public static void main(String[] args) {
		try {
			PathSum pathSum = new PathSum("matrix.txt", 80, 80);
			System.out.println(pathSum.getSum());
		} catch (IOException e) {
			System.err.println("Problem reading the file.");
		}
	}

}
