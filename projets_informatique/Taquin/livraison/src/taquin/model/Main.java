package taquin.model;

public class Main {

	/**
	 * Jeu en console du Taquin
	 * 
	 * @param args Arguments de taille du jeu
	 */
	public static void main(String[] args) {
		TaquinModel taquin = new TaquinModel(3, 3);
		taquin.shuffleElements(TaquinModel.DEFAULT_COMPLEXITY);
		taquin.printBoard();
		// Pour jouer, il est possible de donner des directions ou des nombres.
		taquin.play(Direction.SUD);
		taquin.printBoard();
	}

}
