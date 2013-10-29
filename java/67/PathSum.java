import java.io.FileReader;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;

public class PathSum {

	private int[][] matrix;
	
	public PathSum(String fileName, int n) throws IOException {
		matrix = new int[n][];
		loadMatrix(fileName);
	}

	private void loadMatrix(String fileName) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(fileName));
		for (int i = 0; i < matrix.length; ++i) {
			String[] tokens = reader.readLine().split(" ");
			matrix[i] = new int[tokens.length];
			for (int j = 0; j < matrix[i].length; ++j) {
				matrix[i][j] = Integer.parseInt(tokens[j]);
			}
		}
	}

	public int getSum() {
		for (int i = matrix.length - 1; i > 0; --i) {
			for (int j = 0; j < matrix[i].length - 1; ++j) {
				matrix[i - 1][j] += Math.max(matrix[i][j], matrix[i][j + 1]);
			}
		}
		return matrix[0][0];
	}

	public static void main(String[] args) {
		try {
			PathSum pathSum = new PathSum("triangle.txt", 100);
			System.out.println(pathSum.getSum());
		} catch (IOException e) {
			System.err.println("Problem reading the file.");
		}
	}

}
