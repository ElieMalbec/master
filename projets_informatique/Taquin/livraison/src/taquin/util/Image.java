package taquin.util;

import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

/**
 * Classe utilitaire pour effectuer des traitements sur des images.
 */
public class Image {

	/**
	 * Redimensionnement de l'image donnée aux dimensions données
	 * @param inputImage
	 * @return
	 */
	public static BufferedImage resize(BufferedImage inputImage, int width, int height) {
		BufferedImage outputImage = new BufferedImage(width, height, inputImage.getType());
		Graphics2D g2d = outputImage.createGraphics();
		g2d.drawImage(inputImage, 0, 0, width, height, null);
		g2d.dispose();
		return outputImage;
	}

	/**
	 * Liste de row*columns éléments BufferedImage qui sont les découpages de
	 * l'image donné. L'image est découpée en ligne puis en colonnes.
	 * 
	 * @param rows    Nombre de lignes de découpage
	 * @param columns Nombre de colonnes de découpage
	 * @param img     Image de base à découper
	 * @return Liste d'Images découpées
	 */
	public static ArrayList<BufferedImage> decoupeImage(int rows, int columns, BufferedImage img) {
		img = resize(img, 1200, 650);
		assert rows > 0 && columns > 0 : "Rows or columns must be positive";
		BufferedImage[][] images = new BufferedImage[columns][rows];
		ArrayList<BufferedImage> splits = new ArrayList<BufferedImage>();
		int miniRows = img.getHeight() / rows;
		int miniColumns = img.getWidth() / columns;
		for (int x = 0; x < columns; x++) {
			for (int y = 0; y < rows; y++) {
				images[x][y] = img.getSubimage(x * miniColumns, y * miniRows, miniColumns, miniRows);
			}
		}
		for (int x = 0; x < rows; x++) {
			for (int y = 0; y < columns; y++) {
				splits.add(images[y][x]);
			}
		}
		return splits;
	}
}
